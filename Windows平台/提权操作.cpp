#include"pch.h"
#include<MATLAB异常.h>
#include<共享头.h>
#include<Mex工具.hpp>
#include<shellapi.h>
#pragma comment(lib,"Shell32.lib")
#include<rpc.h>
#pragma comment(lib,"Rpcrt4.lib")
#include<objbase.h>
#pragma comment(lib,"Ole32.lib")
#include<filesystem>
static HANDLE 特权服务器 = nullptr;
static bool 已连接 = false;
extern HMODULE Module;
using namespace matlab::data;
using namespace Mex工具;
static void WriteString(std::ostringstream& 参数流, const String& 字符串)noexcept
{
	const size_t Size = 字符串.size();
	参数流.write((char*)&Size, sizeof(Size));
	参数流.write((char*)字符串.data(), Size * sizeof(std::remove_pointer_t<decltype(字符串.data())>));
}
static 懒加载 MatlabRoot参数头([]()noexcept
	{
		std::ostringstream 返回值;
		constexpr 提权操作函数 函数 = 提权操作函数::Shutdown_server;
		返回值.write((char*)&函数, sizeof(函数));
		WriteString(返回值, CharArray(MATLAB引擎->feval("matlabroot", std::vector<Array>())).toUTF16());
		return 返回值.str();
	});
static 懒加载 MatlabVersion([]()
	{
		return Mex工具::万能转码<String>(MATLAB引擎->feval("ver", 数组工厂.createScalar(u"MATLAB"))[0]["Version"].operator Array());
	});
static 懒加载 RootVersion参数头([]()noexcept
	{
		std::ostringstream 返回值(MatlabRoot参数头());
		返回值.seekp(0, std::ios::end);
		WriteString(返回值, MatlabVersion());
		return 返回值.str();
	});
static void 特权调用(const std::string& 参数)
{
	static RPC_WSTR Parameters = []() 
		{
			RPC_WSTR 返回值;
			UUID Uuid;
			UuidCreate(&Uuid);
			UuidToStringW(&Uuid, &返回值);
			自动析构(返回值, [](void* 指针)
				{
					RpcStringFreeW((RPC_WSTR*)&指针);
					CoUninitialize();
				});
			return 返回值;
		}();
	static std::unique_ptr<wchar_t[]>Filename;
	if (!特权服务器)
	{
		const std::filesystem::path Name = std::filesystem::path(L"\\\\.\\pipe") / (wchar_t*)Parameters;
		DWORD BufferSize = 128;
		特权服务器 = CreateNamedPipeW(Name.c_str(), PIPE_ACCESS_DUPLEX, 0, 1, BufferSize, BufferSize, 0, NULL);
		for (;;)
		{
			Filename = std::make_unique_for_overwrite<wchar_t[]>(BufferSize);
			GetModuleFileNameW(Module, Filename.get(), BufferSize);
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
				BufferSize *= 2;
			else
				break;
		}
		CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
		自动析构(特权服务器, [](HANDLE 特权服务器)noexcept 
			{
				if (已连接)
				{
					constexpr 提权操作函数 ShutdownServer = 提权操作函数::Shutdown_server;
					DWORD NumberOfBytesWritten;
					WriteFile(特权服务器, &ShutdownServer, sizeof(ShutdownServer), &NumberOfBytesWritten, NULL);
				}
				if (特权服务器)
					CloseHandle(特权服务器);
			});
	}
	if (!已连接)
	{
		if ((INT_PTR)ShellExecuteW(NULL, L"runas", (std::filesystem::path(Filename.get()).parent_path().parent_path() / L"提权操作C.exe").c_str(), (LPCWSTR)Parameters, NULL, 0) == SE_ERR_ACCESSDENIED)
			EnumThrow(MATLAB::Exception::User_denied_access);
		ConnectNamedPipe(特权服务器, NULL);
		已连接 = true;
	}
	static DWORD NumberOfBytes;
	WriteFile(特权服务器, 参数.data(), 参数.size(), &NumberOfBytes, NULL);
	MATLAB::Exception 结果;
	if (!ReadFile(特权服务器, &结果, sizeof(结果), &NumberOfBytes, NULL))
	{
		const DWORD 错误码 = GetLastError();
		if (错误码 == ERROR_BROKEN_PIPE)
		{
			DisconnectNamedPipe(特权服务器);//不先断连就不能连新的
			已连接 = false;
		}
		EnumThrow(MATLAB::Exception::Failed_to_communicate_with_the_privilege_server, WindowsErrorMessage(错误码).get());
	}
	switch (结果)
	{
	case MATLAB::Exception::Successful:
		break;
	case MATLAB::Exception::SEH_exception:
	{
		decltype(GetExceptionCode())异常码;
		ReadFile(特权服务器, &异常码, sizeof(异常码), &NumberOfBytes, NULL);
		char16_t* 错误消息;
		FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, 异常码, MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), (LPWSTR)&错误消息, 1, NULL);
		std::unique_ptr<char16_t[], decltype(LocalFree)*>自动释放(错误消息, LocalFree);
		EnumThrow(MATLAB::Exception::SEH_exception, 错误消息);
	}
	default:
		EnumThrow(结果);
	}
}
Mex工具API(Install_path_manager)
{
	static const std::string 参数 = []()
		{
			std::ostringstream 返回值(RootVersion参数头());
			constexpr 提权操作函数 函数 = 提权操作函数::Install_Path_Manager;
			返回值.write((char*)&函数, sizeof(函数));
			return 返回值.str();
		}();
		特权调用(参数);
}
Mex工具API(Uninstall_path_manager)
{
	static const std::string 参数 = []()
		{
			std::ostringstream 返回值(MatlabRoot参数头());
			constexpr 提权操作函数 函数 = 提权操作函数::Uninstall_Path_Manager;
			返回值.write((char*)&函数, sizeof(函数));
			return 返回值.str();
		}();
		特权调用(参数);
}
static void SAR_shared_path(matlab::mex::ArgumentList& 输入, 提权操作函数 SAR)
{
	std::ostringstream 参数;
	参数.write((char*)&SAR, sizeof(SAR));
	WriteString(参数, Mex工具::万能转码<String>(std::move(输入[1])));
	特权调用(参数.str());
}
Mex工具API(Set_shared_path)
{
	SAR_shared_path(输入, 提权操作函数::Set_shared_path);
}
Mex工具API(Add_shared_path)
{
	SAR_shared_path(输入, 提权操作函数::Add_shared_path);
}
Mex工具API(Remove_shared_path)
{
	SAR_shared_path(输入, 提权操作函数::Remove_shared_path);
}
Mex工具API(Builtin_bug_fix)
{
	TypedArray<int8_t>Command(std::move(输入[1]));
	std::ostringstream 参数(MatlabRoot参数头());
	constexpr 提权操作函数 函数 = 提权操作函数::Builtin_bug_fix;
	参数.write((char*)&函数, sizeof(函数));
	参数.seekp(0, std::ios_base::end);
	WriteString(参数, MatlabVersion());
	const size_t Size = Command.getNumberOfElements();
	参数.write((char*)&Size, sizeof(Size));
	const buffer_ptr_t<int8_t>Buffer = Command.release();
	参数.write((char*)Buffer.get(), Size);
	特权调用(参数.str());
}
Mex工具API(Associate_prj_extension)
{
	static const std::string 参数 = []()
		{
			std::ostringstream 返回值(MatlabRoot参数头());
			constexpr 提权操作函数 函数 = 提权操作函数::Associate_prj_extension;
			返回值.write((char*)&函数, sizeof(函数));
			返回值.seekp(0, std::ios_base::end);
			WriteString(返回值, MatlabVersion());
			return 返回值.str();
		}();
		特权调用(参数);
}
Mex工具API(Get_pathdef_permission)
{
	static const std::string 参数 = []()
		{
			std::ostringstream 返回值;
			constexpr 提权操作函数 函数 = 提权操作函数::Get_pathdef_permission;
			返回值.write((char*)&函数, sizeof(函数));
			WriteString(返回值, CharArray(MATLAB引擎->feval("which", Mex工具::万能转码<CharArray>(L"pathdef"))).toUTF16());
			return 返回值.str();
		}();
		特权调用(参数);
}
Mex工具API(Serialport_snatch)
{
	std::ostringstream 参数;
	static const struct {
		提权操作函数 函数 = 提权操作函数::Serialport_snatch;
		DWORD CurrentProcessId = GetCurrentProcessId();
	}固定参数头;
	参数.write((char*)&固定参数头, sizeof(固定参数头));
	WriteString(参数, Mex工具::万能转码<String>(std::move(输入[1])));
	特权调用(参数.str());
	uint64_t PID;
	DWORD NumberOfBytesRead;
	ReadFile(特权服务器, &PID, sizeof(PID), &NumberOfBytesRead, NULL);
	输出[0] = Mex工具::万能转码(PID);
}