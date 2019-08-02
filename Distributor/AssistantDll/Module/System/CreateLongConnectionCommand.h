#pragma once

#include "Module/BaseCommand.h"

namespace ND91Assistant
{
    // 发起长连接(心跳线程)
    // 由于不使用连接池且跟普通命令差距较大
    // 所以这个命令不继承BaseCommand !!!
    class CreateLongConnectionCommand
    {
    public:
        // 生成Android数据体
        // 参数 port : 长连接的本地端口
        static std::string GetAndroidDatagram(short port, wstring pcName=L"");

        void setLongConnectSign();

        // 解析返回数据包
        void ParseturnDatagram(std::string data);

        // 检查数据包头的格式
        // 返回true表示正确，返回false表示错误
        bool VerifyPackageHead();

        // 将数据内容转为字符串输出
        std::wstring ToString();

        int GetDataLength() { return _nDataLength; }

        int GetCommandId() { return _nCommandID; }
    private:
        char _pHead[5];      // 包头字符串
        int _nFlag;          // 数据包标志
        int _nDataLength;    // 数据包长度
        int _nCommandID;     // 命令类型
    };
}