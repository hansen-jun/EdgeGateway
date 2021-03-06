/**
 * @file MqttPublish.h
 * @brief MQTT发布消息程序文件
 * @copyright Copyright (c) 2020 Beijing SOJO Electric CO., LTD.
 * @company  SOJO
 * @date 2020.04.24
 *
 * @author Lei.L
 * @version ver 1.0
 */

#ifndef _MQTT_PUBLISH_H_
#define _MQTT_PUBLISH_H_


#define MQTT_PUBLISH_INTERVAL	60			//MQTT发布消息时间间隔
#define ADDRESS     "iot.shangshan.info"			//MQTT代理服务器地址
#define CLIENTID    "0"								//客户端ID
#define TOPIC       "v1/devices/me/telemetry"		//信息主题
#define QOS         1								//消息质量
#define TIMEOUT     10000L							//超时时间


int CreatMqttProcess(void);
int MqttPublish(char *accessUser);

#endif

