#pragma once

namespace FemboyBanking
{
	public ref class Etherscan
	{
	public:
		static System::UInt64 FetchLinkBalance( System::String^, System::ComponentModel::BackgroundWorker^, System::ComponentModel::DoWorkEventArgs^ );
	private:
		static const char* BALANCE_URL_FMT = "http://api.etherscan.io/api?module=account&action=tokenbalance&contractaddress=%s&address=%s&tag=latest";
		static const char* LINK_CONTRACT = "0x57d90b64a1a57749b0f932f1a3395792e12e7055";
	};
}
