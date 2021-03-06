/**
 * @file Interface_S2J.h
 * @brief C结构体转JSON文件的对外接口程序文件
 * @copyright Copyright (c) 2020 Beijing SOJO Electric CO., LTD.
 * @company  SOJO
 * @date 2020.04.29
 *
 * @author Lei.L
 * @version ver 1.0
 */

#ifndef _INTERFACE_S2J_H_
#define _INTERFACE_S2J_H_

#define IEC101_SLAVE_MAX 20
#define IEC104_SLAVE_MAX 20

/*
 * 边缘网关系统信息
 */
typedef struct TagSystemInfomation{
	char deviceName[40];
	char deviceModel[20];
	char serialNumber[20];
	char firmwareVersion[10];
	char bootloaderVersion[10];
}SystemInfomation;


/*
 * 串口转网口透传功能相关配置信息
 */
typedef struct TagUartToNetConfig{
    int ProtocolType;
    char uartName[20];
    int bandrate;
    int uartType;
    char localIP[20];
    int localPort;
    char remoteIP[20];
    int remotePort;
}UartToNetConfig;


/*
 * Modbus通信相关配置信息
 */
typedef struct TagModbusConfig{
	char uartName[20];
	int bandrate;
	int uartType;
	int slaveNumber;
	int slaveID[256];
	char dataFilename[30];
}ModbusConfig;


/*
 * 101通信相关配置信息
 */
typedef struct TagIEC101Config{
	char uartName[20];
	int bandrate;
	int parity;
	int uartType;

	int balanMode;
	int sourceAddr;
	int linkAddrSize;
	int ASDUCotSize;
	int ASDUAddr;
	int ASDUAddrSize;
	int infoAddrSize;

	int slaveNumber;
	int sModuleId[IEC101_SLAVE_MAX];
	int sMstate;
	int sMsourceAddr[IEC101_SLAVE_MAX];
	int sMportNo;

	char dataFilename[30];
}IEC101Config;


/*
 * 104通信相关配置信息
 */
typedef struct TagIEC104Config{
	char localIP[20];
	int balanMode;
	int sourceAddr;
	int linkAddrSize;
	int ASDUCotSize;
	int ASDUAddr;
	int ASDUAddrSize;
	int infoAddrSize;

	int slaveNumber;
	int sModuleId[IEC104_SLAVE_MAX];
	int sMstate;
	int sMsourceAddr[IEC104_SLAVE_MAX];
	int sMnetEn;
	char sMip1[20];
	char sMip2[20];
	char sMip3[20];
	char sMip4[20];
	char sMip5[20];
	char sMip6[20];
	char sMip7[20];
	char sMip8[20];
	char sMip9[20];
	char sMip10[20];
	char sMip11[20];
	char sMip12[20];
	char sMip13[20];
	char sMip14[20];
	char sMip15[20];
	char sMip16[20];
	char sMip17[20];
	char sMip18[20];
	char sMip19[20];
	char sMip20[20];

	char dataFilename[30];
}IEC104Config;


/*
 * mqtt通信相关配置信息
 */
typedef struct TagMqttConfig{
	int mqttNumber;
	char clondIP[20];
	char username1[20];
	char username2[20];
	char username3[20];
	char username4[20];
	char username5[20];
}MqttConfig;


/*
 * 边缘网关配置信息结构体
 */
typedef struct TagEdgeGatewayConfig{
	SystemInfomation systemInfo;
	int uartToNetNumber;
	UartToNetConfig uartToNet1;
	UartToNetConfig uartToNet2;
	UartToNetConfig uartToNet3;
	UartToNetConfig uartToNet4;
	UartToNetConfig uartToNet5;
	int noiseNumber;
	ModbusConfig noiseSersor1;
	ModbusConfig noiseSersor2;
	ModbusConfig noiseSersor3;
	ModbusConfig noiseSersor4;
	ModbusConfig noiseSersor5;
	int airNumber;
	ModbusConfig airSersor1;
	ModbusConfig airSersor2;
	ModbusConfig airSersor3;
	ModbusConfig airSersor4;
	ModbusConfig airSersor5;
	int tempNumber;
	ModbusConfig tempSersor1;
	ModbusConfig tempSersor2;
	ModbusConfig tempSersor3;
	ModbusConfig tempSersor4;
	ModbusConfig tempSersor5;
	IEC101Config iec101;
	IEC104Config iec104;
	MqttConfig mqttAccess;
}EdgeGatewayConfig;

#define JSON_CONFIG_FILENAME "./GoAhead/bin/EdgeGateway.json"

extern EdgeGatewayConfig *g_EdgeGatewayConfig;
extern EdgeGatewayConfig g_DefaultConfig;

void Struct2JsonInit(void);
int CreateJsonFile(char *filename, EdgeGatewayConfig *edgeGatewayStruct);
int GetJsonFile(char *filename, EdgeGatewayConfig **edgeGatewayStruct);
void S2J_StructFree(EdgeGatewayConfig *orignal_obj);
void ConfigPrintf(EdgeGatewayConfig *edgeGatewayConfig);
int S2J_test(void);

#endif

