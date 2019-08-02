#pragma once

#include "Module/BaseCommand.h"

namespace ND91Assistant
{
    // 取手机串号命令
    class GetIMEICommand : public BaseCommand
    {
    public:
        GetIMEICommand(const DeviceData* pDevice);
        virtual ~GetIMEICommand();

        // 执行命令
        virtual void Execute();

        // 生成Android命令数据包
        virtual std::string GetAndroidBodyData();

        // 解析Android返回结果数据包
        virtual void SetAndroidReturnData(std::string data);

		// 从IOS上获取的命令结果文件名（全路径）
		virtual std::wstring GetIosResultFilePath() { return L""; }

		// 解析ios设备的返回文件，解析后删除文件
		virtual void SetIosReturnFile(std::wstring filename);

        std::wstring GetIMEI(){return _strIMEI;};

    private:
        std::wstring _strIMEI;
    };
}