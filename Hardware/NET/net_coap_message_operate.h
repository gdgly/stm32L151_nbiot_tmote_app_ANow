#ifndef __NET_COAP_MESSAGE_OPERATE_H
#define   __NET_COAP_MESSAGE_OPERATE_H

#include "sys.h"

typedef __packed struct
{
	u8	DataLen;
	u8	ProtocolType:3;
	u8	Reserved1:2;
	u8	ProtocolVersion:3;
	u8	Reserved2:4;
	u8	PacketType:4;
	u8	PacketNumber;
	u32	DeviceSN;
}COAP_PacketHeadTypeDef;													//���ݰ�ͷ8Byte

typedef __packed struct
{
	u32	DestSN;
	u8	Version;
	u8	Type;
}COAP_PacketMsgTypeDef;													//��Ϣ��ͷ6Byte

typedef __packed struct
{
	COAP_PacketHeadTypeDef HeadPacket;
	COAP_PacketMsgTypeDef MsgPacket;
	u32	DateTime;
	u16	SpotCount;
	u8	SpotStatus;
}COAP_PacketShortTypeDef;												//�̰�21Byte

typedef __packed struct
{
	COAP_PacketHeadTypeDef HeadPacket;
	COAP_PacketMsgTypeDef MsgPacket;
	u32	DateTime;
	u16	SpotCount;
	u8	SpotStatus;
	u16	MagneticX;
	u16	MagneticY;
	u16	MagneticZ;
	u16	MagneticDiff;
	u8	RadarDistance;
	u8	RadarStrength;
	u8	RadarCoverCount;
	u8	RadarDiff;
}COAP_PacketLongTypeDef;													//����33Byte

typedef __packed struct
{
	COAP_PacketHeadTypeDef HeadPacket;
	COAP_PacketMsgTypeDef MsgPacket;
	u8	InfoData[100];
}COAP_PacketInfoTypeDef;													//Info��114Byte

#define COAP_SEND_BUFFER_SIZE				128
#define COAP_RECV_BUFFER_SIZE				64
#define COAP_SEND_PARK_NUM				10
#define COAP_RECV_PARK_NUM				5

/* �������ݶ��� */
typedef struct
{
	unsigned char						Front;
	unsigned char						Rear;
	
	struct SendParkTypeDef
	{
		unsigned char					Buffer[COAP_SEND_BUFFER_SIZE];
		unsigned short					Length;
	}Park[COAP_SEND_PARK_NUM];
}COAP_SwapSendDataTypeDef;

/* �������ݶ��� */
typedef struct
{
	unsigned char						Front;
	unsigned char						Rear;
	
	struct RecvParkTypeDef
	{
		unsigned char					Buffer[COAP_RECV_BUFFER_SIZE];
		unsigned short					Length;
	}Park[COAP_RECV_PARK_NUM];
}COAP_SwapRecvDataTypeDef;

void NET_Coap_Message_SendDataEnqueue(unsigned char* dataBuf, unsigned short dataLength);							//��������д�����
void NET_Coap_Message_RecvDataEnqueue(unsigned char* dataBuf, unsigned short dataLength);							//��������д�����
bool NET_Coap_Message_SendDataDequeue(unsigned char* dataBuf, unsigned short* dataLength);						//�������ݶ�������
bool NET_Coap_Message_RecvDataDequeue(unsigned char* dataBuf, unsigned short* dataLength);						//�������ݶ�������
bool NET_Coap_Message_SendDataOffSet(void);																//�������ݶ���(����ͷƫ��1)
bool NET_Coap_Message_RecvDataOffSet(void);																//�������ݶ���(����ͷƫ��1)
unsigned char NET_Coap_Message_SendDataRear(void);														//�������ݶ�βֵ
unsigned char NET_Coap_Message_RecvDataRear(void);														//�������ݶ�βֵ




#endif