#pragma once

namespace FemboyBanking
{
	public ref class Etherscan
	{
	public:
		static System::UInt64 FetchLinkBalance( System::String^, System::ComponentModel::BackgroundWorker^, System::ComponentModel::DoWorkEventArgs^ );
	private:
		static const char* BALANCE_URL_FMT = "http://api.etherscan.io/api?module=account&action=tokenbalance&contractaddress=%s&address=%s&tag=latest";
		static const char* LINK_CONTRACT = "0x514910771af9ca656af840dff83e8264ecf986ca";
	};
}
