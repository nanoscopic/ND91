#pragma once

#include "Module/BaseCommand.h"

namespace ND91Assistant
{
#define Ios_SB_Shutdown_Cookie 

	//注销手机命令
	class LogOffCommand: public BaseCommand
	{
	public:
		LogOffCommand(const DeviceData* pDevice);
		~LogOffCommand(void);

		// 执行命令
		virtual void Execute();

#pragma region 这四个方法是Command的主要内容，处理令格式与结果格式

		// 生成Android数据体，在GetAndroidDatagram()方法中调用本方法
		virtual std::string GetAndroidBodyData(){return "";};

		// 解析返回数据包
		virtual void SetAndroidReturnData(std::string data) {}

		// 解析ios设备的返回文件，解析后删除文件
		virtual void SetIosReturnFile(std::wstring filename){};

		virtual std::wstring GetIosResultFilePath(){return L"";}

    private:
        void IosExecute();

#pragma endregion
	};
}