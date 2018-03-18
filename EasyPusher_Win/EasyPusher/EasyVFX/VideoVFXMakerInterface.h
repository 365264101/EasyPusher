
////////////////////////////////////////////////////////////////////
//
//	��Ƶ�ؼ�����Dll�����ඨ��
//  VideoVFXMakerInterface.h 
//
////////////////////////////////////////////////////////////////////

#ifndef VIDEOVFXMAKERINTERFACE_H
#define VIDEOVFXMAKERINTERFACE_H

#ifdef __cplusplus

//#define FENBUSHI_LUBO 1
//Ϊ��ʵ�ֶ����Ĵ��麯��
//��ΪC����������Ļ�����ҪԴ���룬Ȼ��������ȥ���Ļ�����ֻҪ�ļ�ͷ���ô����ˡ�

#define FILTER_NORESIZE 0
#define FILTER_RESIZEMIN 1
#define FILTER_RESIZEMAX 2
#define MAX_VIV_VFX_COUNT 6
/*
#ifndef WATERMARK_ENTRY_TYPE
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
#endif*/

class VideoVFXMaker_Interface
{
//�����ർ����������
public:
	virtual void WINAPI SetVideoPlatFormSpeed(int nWidthSpeed,int nHeightSpeed,int nFreezeSpeed) = 0;
	virtual void WINAPI SetVideoPlatFormVideo(int nVideoWidthSrc,int nVideoHeightSrc,char* strBytesSrc,int nVideoWidthDes,
		int nVideoHeightDes,char* strBytesDes) = 0;
	virtual void WINAPI SetVideoPlatFormModel(int nModePlatForm) = 0;
	virtual BOOL WINAPI SetPlatFormStart()= 0;
	virtual int WINAPI DoVideoPlatFormChange(BYTE *pSrc,BYTE *pDes,long lLen,BOOL bCopy=FALSE) = 0;
	virtual void WINAPI SetPlatFormState(int nStatePlatForm) = 0;
	virtual int WINAPI GetPlatFormState() = 0;
public:
	virtual void WINAPI DoVideoBackGroundChange(BYTE *pSrc,int nSrcLen=0) = 0;//VideoBackGroundChange(BYTE *pSrc,int nWidth,int nHeight,CString strBytes);
	virtual void WINAPI DefaultBackGroundData() = 0;
	virtual BOOL WINAPI SetBackGround(char*strBackGroundPath,char* strDesBytes,BOOL bAutoConver=TRUE,BOOL bDelSrc=TRUE) = 0;
	virtual void WINAPI ReleaseBackGroundData() = 0;
	virtual BYTE* WINAPI GetVideoHeaderBuf() = 0;
public:
	virtual void WINAPI RealseOverlayTitle() = 0;
	virtual void WINAPI CreateOverlayTitle(int nVideoWidth,int nVideoHeight,char* strRGBBtyes) = 0;
	virtual void WINAPI SetOverlayTitleInfo(char *pTitle,LOGFONTA fontTitle,int nColorRed,int nColorGreen,int nColorBlue,POINT pointStart) = 0;
	virtual void WINAPI SetOverlayTitleState(int nState) = 0;
	virtual int WINAPI  DoOverlayTitle(PBYTE pInData) = 0;
public:
	virtual int WINAPI SetBackGroundTitle(char *pTitle,LOGFONTA fontTitle,int nColorRed,int nColorGreen,int nColorBlue,POINT pointStart) = 0;
	virtual int WINAPI CreateBackGroundTitle() = 0;
	virtual void WINAPI ReSizeYUY2Data(BYTE*scrdata,int scrwidth,int scrheight,BYTE*desdata,int deswidth,int desheight,int desx=0,int desy=0) = 0;
//���û��л���Ƶ����
	virtual void WINAPI SetVideoInVideoParam(int nVivVfxMode,int nXPos, int nYPos, int nSrcWidth, 
		int nSrcHeight, int nDesWidth, int nDesHeight, int nFrameCount) = 0;
	virtual void WINAPI SetVideoInVideoVfxSpeed(int nWidthSpeed,int nHeightSpeed,int nFreezeSpeed) = 0;
	virtual BOOL WINAPI SetVIVStart(int nVivVfxMode) = 0;
//���л���Ч��������λ������
	virtual void WINAPI SetPlatDIY(int desx,int desy,int deswidth,int desheight,int flag=FILTER_RESIZEMIN) = 0;
//LOGˮӡ���
	virtual void WINAPI InitWaterMask(byte* prgb32, int x, int y, int width, int height,int color=32,WATERMARK_ENTRY_TYPE flag=WATERMARK_TYPE_COVER) = 0;
	virtual void WINAPI AddWaterMask(byte*scr) = 0;
//	virtual void WINAPI SetWaterMarkParam(BOOL bIsUseWaterMark, int nPosX, int nPosY, WATERMARK_ENTRY_TYPE eWaterMarkType = WATERMARK_TYPE_COVER) = 0;
	virtual int  WINAPI SetLogoImage(char* strPicPath, int nPosX, int nPosY,BOOL bIsUseWaterMark, WATERMARK_ENTRY_TYPE eWaterMarkType = WATERMARK_TYPE_COVER) = 0;
	virtual void WINAPI ReDrawYUY2DataBack(BYTE*scrdata,int scrwidth,int scrheight,int deep,int red,int green,int blue)=0;
	virtual void WINAPI SetVIVZoomType(int nVivZoomType=0) = 0;
};

//����ӿ�ָ������
typedef	VideoVFXMaker_Interface*	LPVideoVFXMaker;	

LPVideoVFXMaker	APIENTRY Create_VideoVFXMaker();//�������ƽӿ�ָ��
void APIENTRY Release_VideoVFXMaker(LPVideoVFXMaker lpVideoVFXMaker);//���ٿ��ƽӿ�ָ��


#endif

#endif