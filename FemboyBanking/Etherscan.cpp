#include "StdAfx.h"
#include "Etherscan.h"
#pragma comment (lib, "wininet.lib")

using namespace FemboyBanking;
using namespace rapidjson;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;

UInt64 Etherscan::FetchLinkBalance(String^ address, BackgroundWorker^ worker, DoWorkEventArgs^ e)
{
	HINTERNET connect = InternetOpenA("EtherscanQuery", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (!connect)
	{
		MessageBox::Show( dynamic_cast<Form^>(worker->Container), "Failed to open Internet handle", "Network Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return -1;
	}
	worker->ReportProgress(25);

	char url[256];
	sprintf_s(url, sizeof(url), Etherscan::BALANCE_URL_FMT, Etherscan::LINK_CONTRACT, address);
	HINTERNET OpenAddress = InternetOpenUrlA(connect, url, NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION, 0);

	if (!OpenAddress)
	{
		DWORD err = GetLastError();
		MessageBox::Show( dynamic_cast<Form^>(worker->Container), String::Format("Failed to open URL, error {0}", err), "Network Error", MessageBoxButtons::OK, MessageBoxIcon::Error );
		InternetCloseHandle(connect);
		return -1;
	}
	worker->ReportProgress(50);

	char DataReceived[4096];
	char* temp = DataReceived;
	DWORD NumberOfBytesRead = 0;
	while ( InternetReadFile(OpenAddress, DataReceived, sizeof(DataReceived), &NumberOfBytesRead) && NumberOfBytesRead )
	{
		temp += NumberOfBytesRead;
	}
	*temp = '\0';
	worker->ReportProgress(75);

	Document response;
	response.Parse(DataReceived);
	worker->ReportProgress(90);

	if (strcmp(response["status"].GetString(), "1") != 0)
	{
		if (response.HasMember("result"))
		{
			const char* error = response["result"].GetString();
			MessageBox::Show( dynamic_cast<Form^>(worker->Container), gcnew String(error), "API Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			MessageBox::Show( dynamic_cast<Form^>(worker->Container), "Unknown error", "API Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return -1;
	}

	InternetCloseHandle(OpenAddress);
	InternetCloseHandle(connect);

	const char* result = response["result"].GetString();
	String^ balanceStr = gcnew String(result);
	UInt64 balance = UInt64::Parse(balanceStr);

	worker->ReportProgress(100);
	return balance;
}
