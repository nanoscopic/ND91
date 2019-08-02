#pragma once
#include <string>
using namespace std;

namespace ND91Assistant
{
	enum ENUM_EQUIPMENT
	{
		Ep_DEVICEDESC,      //设备名
		Ep_HARDWAREID,      //硬件号
		Ep_COMPATIBLEIDS,   //兼容硬件号
		Ep_NTDEVICEPATHS,   //
		Ep_SERVICE,         //服务
		Ep_CONFIGURATION,
		Ep_CONFIGURATIONVECTOR,
		Ep_CLASS ,          //设备分类    例 网卡...
		Ep_CLASSGUID,       //GUID
		Ep_DRIVER,          //注册表位置
		Ep_CONFIGFLAGS,
		Ep_MFG,		        //厂商
		Ep_FRIENDLYNAME,    //别名
		Ep_LOCATION_INFORMATION,
		Ep_PHYSICAL_DEVICE_OBJECT_NAME,//设备对象
		Ep_CAPABILITIES,
		Ep_UI_NUMBER,
		Ep_UPPERFILTERS,
		Ep_LOWERFILTERS,
		Ep_MAXIMUM_PROPERTY,
		Ep_Count
	};
/*
	static string iPhone_HardID_List[] = {
		"USB\\VID_05AC&PID_1261",
		"USB\\VID_05AC&PID_1262",
		"USB\\VID_05AC&PID_1263",
		"USB\\VID_05AC&PID_1302",
		"USB\\VID_05AC&PID_1290",
		"USB\\VID_05AC&PID_1291",
		"USB\\VID_05AC&PID_1292",
		"USB\\VID_05AC&PID_1293",
		"USB\\VID_05AC&PID_1294",
		"USB\\VID_05AC&PID_1297",
		"USB\\VID_05AC&PID_1299",
		"USB\\VID_05AC&PID_129A",
		"USB\\VID_05AC&PID_129C",
		"USB\\VID_05AC&PID_129E",
		"USB\\VID_05AC&PID_12A2",
		"USB\\VID_05AC&PID_129F",
	};
	static string Android_HardID_List[] = {
		//"USB\\\\VID_0BB4&PID_0C01&MI_01"   to "USB\\\\VID_0BB4&PID_0EFF&MI_01"
		"USB\\VID_0BB4&PID_0C02&MI_01",
		"USB\\VID_12D1&PID_1501&MI_03",
		"USB\\VID_0489&PID_C001&MI_01",
		"USB\\VID_18D1&PID_D00D",
		"USB\\VID_18D1&PID_DEED&MI_01",
		"USB\\VID_05C6&PID_9018&MI_01",
		"USB\\VID_18D1&PID_0002&MI_01",
		"USB\\VID_22B8&PID_41DA&MI_04",
		"USB\\VID_22B8&PID_2D74&MI_04",
		"USB\\VID_22B8&PID_2D75&MI_02",
		"USB\\VID_22B8&PID_2D76&MI_02",
		"USB\\VID_22B8&PID_2D62",
		"USB\\VID_22B8&PID_2D61&MI_01",
		"USB\\VID_22B8&PID_2D64&MI_01",
		"USB\\VID_22B8&PID_2D66&MI_00",
		"USB\\VID_22B8&PID_41D1",
		"USB\\VID_22B8&PID_41DB&MI_01",
		"USB\\VID_22B8&PID_41DC&MI_01",
		"USB\\VID_22B8&PID_41E2&MI_04",
		"USB\\VID_22B8&PID_41EE&MI_04",
		"USB\\VID_04E8&PID_6640&MI_04", 
		"USB\\VID_17EF&PID_7401&MI_01",
		"USB\\VID_18D1&PID_4E12&MI_01",
		"USB\\VID_0BB4&PID_0C87&MI_01",
		"USB\\VID_0BB4&PID_0C97&MI_01",
		"USB\\VID_1004&PID_6171&MI_01",
		"USB\\VID_0FCE&PID_D12E&MI_01",
		"USB\\VID_04E8&PID_681C&MI_03",
		"USB\\VID_04E8&PID_6877&MI_03",
		"USB\\VID_1EBF&PID_6002&MI_01",
		"USB\\VID_0BB4&PID_0C99&MI_01",
		"USB\\VID_0FCE&PID_E12E&MI_01",
		"USB\\VID_0FCE&PID_212E&MI_01",
		"USB\\VID_0FCE&PID_312E&MI_01",
		"USB\\VID_0FCE&PID_D137&MI_00",
		"USB\\VID_0FCE&PID_E137&MI_00",
		"USB\\VID_0FCE&PID_2137&MI_00",
		"USB\\VID_0FCE&PID_3137&MI_00",
		"USB\\VID_0FCE&PID_D138&MI_00",
		"USB\\VID_0FCE&PID_E138&MI_00",
		"USB\\VID_0FCE&PID_2138&MI_00",
		"USB\\VID_0FCE&PID_3138&MI_00",
		"USB\\VID_19D2&PID_1350&MI_04",
		"USB\\VID_19D2&PID_1351&MI_01",
		"USB\\VID_19D2&PID_1354&MI_02",
		"USB\\VID_22B8&PID_2D7B&MI_03",
		"USB\\VID_22B8&PID_2D68&MI_01",
		"USB\\VID_22B8&PID_2D74",
		"USB\\VID_22B8&PID_2D76",
		"USB\\VID_22B8&PID_2D66",
		"USB\\VID_22B8&PID_41DA",
		"USB\\VID_22B8&PID_41DC",
		"USB\\VID_22B8&PID_41E2",
		"USB\\VID_0489&PID_C001",
		"USB\\VID_0489&PID_C004",
		"USB\\VID_04E8&PID_681C",
		"USB\\VID_04E8&PID_6880",
		"USB\\VID_04E8&PID_6877",
		"USB\\VID_04E8&PID_6850",
		"USB\\VID_04E8&PID_689C",
		"USB\\VID_04E8&PID_689E",
		"USB\\VID_1004&PID_618E",
		"USB\\VID_22B8&PID_2D75",
		"USB\\VID_22B8&PID_2D7B",
		"USB\\VID_22B8&PID_2D68",
		"USB\\VID_22B8&PID_2D61",
		"USB\\VID_22B8&PID_2D64",
		"USB\\VID_22B8&PID_41DB",
		"USB\\VID_22B8&PID_41EE",
		"USB\\VID_12D1&PID_1031",
		"USB\\VID_19D2&PID_0083",
		"USB\\VID_0BB4&PID_0C01",
		"USB\\VID_22B8&PID_2D63",
		"USB\\VID_22B8&PID_41D8",
		"USB\\VID_17EF&PID_7400",
		"USB\\VID_05C6&PID_9017",
		"USB\\VID_18D1&PID_4E11",
		"USB\\VID_0BB4&PID_0FF9",
		"USB\\VID_0FCE&PID_E12E",
		"USB\\VID_04E8&PID_681D",
		"USB\\VID_04E8&PID_6880&MI_02",
		"USB\\VID_18D1&PID_DDDD",
		"USB\\VID_0BB4&PID_0C81",
		"USB\\VID_0525&PID_A4A1",
		"USB\\VID_18D1&PID_0002",
		"USB\\VID_049F&PID_505A",
		"USB\\VID_0547&PID_2720",
		//NEW
		"USB\\VID_12D1&PID_1035&REV_0100&MI_03",    //华为
		"USB\\VID_04E8&PID_681C&MI_03",
		"USB\\VID_1EBF&PID_6045&REV_0216&MI_05",
		"USB\\VID_18D1&PID_4E22&REV_0227",			//三星NS
		"USB\\VID_18D1&PID_0005&MI_01",				//M9

	};
	*/
}

