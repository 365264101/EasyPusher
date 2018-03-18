/* ��׼ͷ�ļ� */
#ifndef __EASYDEFINE_H__
#define __EASYDEFINE_H__

#if defined(WIN32)
#include <windows.h>
#include <mmsystem.h>
#include <tchar.h>
#define  usleep(us)  Sleep((us)/1000)
#else
// todo..
#endif

//ˮӡ�ṹ��Ϣ
// //ö�ٱ�ʶ̨��LOGO���ڵ�λ��
typedef enum tagWATER_MARK_POS
{
	POS_LEFT_TOP = 1,
	POS_RIGHT_TOP,
	POS_LEFT_BOTTOM,
	POS_RIGHT_BOTTOM

}WATER_MARK_POS;

typedef enum tagWATERMARK_ENTRY_TYPE
{
	WATERMARK_TYPE_COVER			   = 0,
	WATERMARK_TYPE_OVERLYING		   = 1,
	WATERMARK_TYPE_OVERLYING_COVER	   = 2,
	WATERMARK_TYPE_ROLL_TO_LEFT		   = 3,
	WATERMARK_TYPE_JUMP_UP_DOWN		   = 4,
	WATERMARK_TYPE_ROLL_AND_JUMP	   = 5,
	WATERMARK_TYPE_TROTTING_HORSE_LAMP = 6

}WATERMARK_ENTRY_TYPE;

// //��Ļ��Ϣ
typedef struct tagVideoTittleInfo
{
	int nState;//��Ļ״̬��	nState==1���У�nState==0��ͣ��nState==-1����
	//�����������Ϣ
	int nTittleWidth;
	int nTittleHeight;
	int nFontWeight;//Ȩ�� FW_NORMAL FW_BOLD������
	char strFontType[64];//���� "������κ");//"��������");"����"
	char strTittleContent[512];//��Ļ����
	// ��Ļ��ɫ
	int nColorR;
	int nColorG;
	int nColorB;
	POINT ptStartPosition;//��Ļ���ƿ�ʼ��
	int   nMoveType;//0--�̶�λ�ã�1--�������ң�2--��������
	BOOL bResetTittleInfo;
}VideoTittleInfo;

typedef struct tagWaterMarkInfo
{
	BOOL bIsUseWaterMark;//�Ƿ�ʹ��ˮӡ
	WATER_MARK_POS eWaterMarkPos;//̨��λ�ã�1==leftttop 2==righttop 3==leftbottom 4==rightbottom
	int nLeftTopX;//ˮӡ���Ͻ�λ��x
	int nLeftTopY;//ˮӡ���Ͻ�λ��y
	int nWidth;//��
	int nHeight;//��
	char strWMFilePath[512];//ˮӡͼƬ·��
	WATERMARK_ENTRY_TYPE eWatermarkStyle;//ˮӡ�ķ��
	BOOL bResetWaterMark;

}WaterMarkInfo;

//�ؼ������ṹ
typedef struct tagVFXMakerInfo
{
	WaterMarkInfo warkMarkInfo;
	VideoTittleInfo tittleInfo;//��Ļ��Ϣ123
}VFXMakerInfo;

#if 0
typedef struct tagMediaInfo
{
	//for stream
	int nBitsRate;
	//for Video
	int nVCodec;
	char sVCodec[32];
	char sVCodecDetails[64];
	int nWidth;
	int nHeight;
	int nFrameRate;
	int video_bit_rate;
	int video_total_bit_rate;
	//for Audio
	int nACodec;
	char sACodec[32];
	char sACodecDetails[64];
	int nSampleRate;
	int nChannels;
	int nBitsPerSample;
	int audio_bit_rate;

}MediaInfo;
#endif

#endif


