// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iewia.pas' rev: 5.00

#ifndef iewiaHPP
#define iewiaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyiedefs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iewia
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct WIA_DATA_CALLBACK_HEADER
{
	int lSize;
	GUID guidFormatID;
	int lBufferSize;
	int lPageCount;
} ;
#pragma pack(pop)

typedef WIA_DATA_CALLBACK_HEADER *PWIA_DATA_CALLBACK_HEADER;

typedef bool __fastcall (__closure *TIEWGetPage)(PWIA_DATA_CALLBACK_HEADER header, void * data, int 
	datalen);

__interface IWiaDataCallback;
typedef System::DelphiInterface<IWiaDataCallback> _di_IWiaDataCallback;
__interface INTERFACE_UUID("{A558A866-A5B0-11D2-A08F-00C04F72DC3C}") IWiaDataCallback  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall BandedDataCallback(int lMessage, int lStatus, int lPercentComplete, int lOffset
		, int lLength, int lReserved, int lResLength, Windows::PByte pbBuffer) = 0 ;
};

#pragma pack(push, 1)
struct WIA_DATA_TRANSFER_INFO
{
	int ulSize;
	int ulSection;
	int ulBufferSize;
	BOOL bDoubleBuffer;
	int ulReserved1;
	int ulReserved2;
	int ulReserved3;
} ;
#pragma pack(pop)

typedef WIA_DATA_TRANSFER_INFO *PWIA_DATA_TRANSFER_INFO;

typedef bool __fastcall (__closure *TIEWiaOnProgress)(int percentage);

class DELPHICLASS TWiaDataCallBack;
class PASCALIMPLEMENTATION TWiaDataCallBack : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	#pragma pack(push, 1)
	WIA_DATA_CALLBACK_HEADER header;
	#pragma pack(pop)
	
	Byte *data;
	int datalen;
	TIEWGetPage OnGetPage;
	TIEWiaOnProgress OnProgress;
	bool WaitingData;
	HRESULT __stdcall BandedDataCallback(int lMessage, int lStatus, int lPercentComplete, int lOffset, 
		int lLength, int lReserved, int lResLength, Windows::PByte pbBuffer);
	__fastcall TWiaDataCallBack(void);
	__fastcall virtual ~TWiaDataCallBack(void);
private:
	void *__IWiaDataCallback;	/* Iewia::IWiaDataCallback */
	
public:
	operator IWiaDataCallback*(void) { return (IWiaDataCallback*)&__IWiaDataCallback; }
	
};


typedef TWiaDataCallBack* *PWiaDataCallBAck;

__interface IWiaEventCallback;
typedef System::DelphiInterface<IWiaEventCallback> _di_IWiaEventCallback;
__interface INTERFACE_UUID("{AE6287B0-0084-11D2-973B-00A0C9068F2E}") IWiaEventCallback  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall ImageEventCallback(System::PGUID pEventGUID, wchar_t * bstrEventDescription
		, wchar_t * bstrDeviceID, wchar_t * bstrDeviceDescription, unsigned dwDeviceType, wchar_t * bstrFullItemName
		, unsigned &pulEventType, unsigned ulReserved) = 0 ;
};

class DELPHICLASS TWiaEventCallBack;
class PASCALIMPLEMENTATION TWiaEventCallBack : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	System::TObject* WIA;
	HRESULT __stdcall ImageEventCallback(System::PGUID pEventGUID, wchar_t * bstrEventDescription, wchar_t * 
		bstrDeviceID, wchar_t * bstrDeviceDescription, unsigned dwDeviceType, wchar_t * bstrFullItemName, 
		unsigned &pulEventType, unsigned ulReserved);
	__fastcall TWiaEventCallBack(System::TObject* inWIA);
	__fastcall virtual ~TWiaEventCallBack(void);
private:
	void *__IWiaEventCallback;	/* Iewia::IWiaEventCallback */
	
public:
	operator IWiaEventCallback*(void) { return (IWiaEventCallback*)&__IWiaEventCallback; }
	
};


typedef TWiaEventCallBack* *PWiaEventCallBAck;

__interface IWiaDataTransfer;
typedef System::DelphiInterface<IWiaDataTransfer> _di_IWiaDataTransfer;
__interface INTERFACE_UUID("{A6CEF998-A5B0-11D2-A08F-00C04F72DC3C}") IWiaDataTransfer  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall idtGetData(void) = 0 ;
	virtual HRESULT __stdcall idtGetBandedData(PWIA_DATA_TRANSFER_INFO pWiaDataTransInfo, _di_IWiaDataCallback 
		pIWiaDataCallback) = 0 ;
	virtual HRESULT __stdcall idtQueryGetData(void) = 0 ;
	virtual HRESULT __stdcall idtEnumWIA_FORMAT_INFO(void) = 0 ;
	virtual HRESULT __stdcall idtGetExtendedTransferInfo(void) = 0 ;
};

__interface IEnumWiaItem;
typedef System::DelphiInterface<IEnumWiaItem> _di_IEnumWiaItem;
__interface IWiaItem;
typedef System::DelphiInterface<IWiaItem> _di_IWiaItem;
__interface INTERFACE_UUID("{5E8383FC-3391-11D2-9A33-00C04FA36145}") IEnumWiaItem  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Next(int celt, /* out */ _di_IWiaItem &ppIWiaItem, int &pceltFetched) = 0 
		;
	virtual HRESULT __stdcall Skip(void) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Clone(void) = 0 ;
	virtual HRESULT __stdcall GetCount(void) = 0 ;
};

typedef _di_IUnknown TIWiaItemArray[1];

typedef _di_IUnknown *PIWiaItemArray;

__interface INTERFACE_UUID("{4DB1AD10-3391-11D2-9A33-00C04FA36145}") IWiaItem  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall GetItemType(int &pItemType) = 0 ;
	virtual HRESULT __stdcall AnalyzeItem(int lFlags) = 0 ;
	virtual HRESULT __stdcall EnumChildItems(/* out */ _di_IEnumWiaItem &ppIEnumWiaItem) = 0 ;
	virtual HRESULT __stdcall DeleteItem(int lFlags) = 0 ;
	virtual HRESULT __stdcall CreateChildItem(void) = 0 ;
	virtual HRESULT __stdcall EnumRegisterEventInfo(void) = 0 ;
	virtual HRESULT __stdcall FindItemByName(void) = 0 ;
	virtual HRESULT __stdcall DeviceDlg(HWND hwndParent, int lFlags, int lIntent, /* out */ int &plItemCount
		, /* out */ PIWiaItemArray &ppIWiaItem) = 0 ;
	virtual HRESULT __stdcall DeviceCommand(int lFlags, System::PGUID pCmdGUID, _di_IWiaItem &pIWiaItem
		) = 0 ;
	virtual HRESULT __stdcall GetRootItem(void) = 0 ;
	virtual HRESULT __stdcall EnumDeviceCapabilities(void) = 0 ;
	virtual HRESULT __stdcall DumpItemData(void) = 0 ;
	virtual HRESULT __stdcall DumpDrvItemData(void) = 0 ;
	virtual HRESULT __stdcall DumpTreeItemData(void) = 0 ;
	virtual HRESULT __stdcall Diagnostic(void) = 0 ;
};

__interface IWiaPropertyStorage;
typedef System::DelphiInterface<IWiaPropertyStorage> _di_IWiaPropertyStorage;
__interface INTERFACE_UUID("{98B5E8A0-29CC-491A-AAC0-E6DB4FDCCEB6}") IWiaPropertyStorage  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall ReadMultiple(int cpspec, void * rgpspec, void * rgpropvar) = 0 ;
	virtual HRESULT __stdcall WriteMultiple(int cpspec, void * rgpspec, void * rgpropvar, int propidNameFirst
		) = 0 ;
	virtual HRESULT __stdcall DeleteMultiple(void) = 0 ;
	virtual HRESULT __stdcall ReadPropertyNames(int cpropid, void * rgpspec, char * &name) = 0 ;
	virtual HRESULT __stdcall WritePropertyNames(void) = 0 ;
	virtual HRESULT __stdcall DeletePropertyNames(void) = 0 ;
	virtual HRESULT __stdcall Commit(void) = 0 ;
	virtual HRESULT __stdcall Revert(void) = 0 ;
	virtual HRESULT __stdcall Enum(void) = 0 ;
	virtual HRESULT __stdcall SetTimes(void) = 0 ;
	virtual HRESULT __stdcall SetClass(void) = 0 ;
	virtual HRESULT __stdcall Stat(void) = 0 ;
	virtual HRESULT __stdcall GetPropertyAttributes(int cpspec, void * rgpspec, int &rgflags, void * rgpropvar
		) = 0 ;
	virtual HRESULT __stdcall GetCount(void) = 0 ;
	virtual HRESULT __stdcall GetPropertyStream(void) = 0 ;
	virtual HRESULT __stdcall SetPropertyStream(void) = 0 ;
};

__interface IEnumWIA_DEV_INFO;
typedef System::DelphiInterface<IEnumWIA_DEV_INFO> _di_IEnumWIA_DEV_INFO;
__interface INTERFACE_UUID("{5E38B83C-8CF1-11D1-BF92-0060081ED811}") IEnumWIA_DEV_INFO  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Next(int celt, /* out */ _di_IWiaPropertyStorage &rgelt, int &pceltFetched
		) = 0 ;
	virtual HRESULT __stdcall Skip(void) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Clone(void) = 0 ;
	virtual HRESULT __stdcall GetCount(int &celt) = 0 ;
};

typedef _di_IEnumWIA_DEV_INFO *PIEnumWIA_DEV_INFO;

typedef PIEnumWIA_DEV_INFO *PPIEnumWIA_DEV_INFO;

__interface IWiaDevMgr;
typedef System::DelphiInterface<IWiaDevMgr> _di_IWiaDevMgr;
__interface INTERFACE_UUID("{5EB2502A-8CF1-11D1-BF92-0060081ED811}") IWiaDevMgr  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall EnumDeviceInfo(int lFlag, /* out */ _di_IEnumWIA_DEV_INFO &ppIEnum) = 0 ;
		
	virtual HRESULT __stdcall CreateDevice(wchar_t * bstrDeviceID, /* out */ _di_IWiaItem &ppWiaItemRoot
		) = 0 ;
	virtual HRESULT __stdcall SelectDeviceDlg(void) = 0 ;
	virtual HRESULT __stdcall SelectDeviceDlgID(HWND hwndParent, int lDeviceType, int lFlags, wchar_t * 
		&pbstrDeviceID) = 0 ;
	virtual HRESULT __stdcall GetImageDlg(void) = 0 ;
	virtual HRESULT __stdcall RegisterEventCallbackProgram(void) = 0 ;
	virtual HRESULT __stdcall RegisterEventCallbackInterface(int lFlags, wchar_t * bstrDeviceID, System::PGUID 
		pEventGUID, _di_IWiaEventCallback pIWiaEventCallback, _di_IUnknown &pEventObject) = 0 ;
	virtual HRESULT __stdcall RegisterEventCallbackCLSID(void) = 0 ;
	virtual HRESULT __stdcall AddDeviceDlg(void) = 0 ;
};

typedef IWiaDevMgr IID_IWiaDevMgr;
;

#pragma option push -b-
enum iewia__4 { iewScanner, iewDigitalCamera, iewStreamingVideo };
#pragma option pop

class DELPHICLASS TIEWiaDeviceInfo;
class PASCALIMPLEMENTATION TIEWiaDeviceInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString Name;
	AnsiString ID;
	iewia__4 DeviceType;
	AnsiString DriverVersion;
	AnsiString PortName;
	AnsiString ServerName;
	AnsiString Vendor;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIEWiaDeviceInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEWiaDeviceInfo(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum iewia__5 { witFree, witImage, witFile, witFolder, witRoot, witAnalyze, witAudio, witDevice, witDeleted, 
	witDisconnected, witHPanorama, witVPanorama, witBurst, witStorage, witTransfer, witGenerated, witHasAttachments, 
	witVideo, witTwainCapabilityPassThrough, witRemoved, witMask };
#pragma option pop

typedef Set<iewia__5, witFree, witMask>  TIEWiaItemType;

class DELPHICLASS TIEWiaItem;
class PASCALIMPLEMENTATION TIEWiaItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	_di_IWiaItem This;
	Classes::TList* Children;
	TIEWiaItemType ItemType;
	__fastcall TIEWiaItem(void);
	__fastcall virtual ~TIEWiaItem(void);
};


#pragma pack(push, 1)
struct TIEWProcessingInfo
{
	int DPIX;
	int DPIY;
} ;
#pragma pack(pop)

#pragma option push -b-
enum iewia__7 { iewaRead, iewaWrite, iewaSyncRequired, iewaNone, iewaRange, iewaList, iewaFlag, iewaCacheable 
	};
#pragma option pop

typedef Set<iewia__7, iewaRead, iewaCacheable>  TIEWiaAttrib;

typedef Variant variantarray[67108864];

typedef Variant *pvariantarray;

class DELPHICLASS TIEWiaValues;
class PASCALIMPLEMENTATION TIEWiaValues : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Variant *fValues;
	Variant __fastcall GetValues(int idx);
	
public:
	Variant max;
	Variant min;
	int count;
	Variant normal;
	Variant step;
	__fastcall TIEWiaValues(void);
	__fastcall virtual ~TIEWiaValues(void);
	__property Variant values[int idx] = {read=GetValues};
};


#pragma option push -b-
enum TIETransferFormat { ietfDefault, ietfBitmap, ietfJpeg };
#pragma option pop

#pragma option push -b-
enum TIEWiaEvent { ieeNone, ieeTreeUpdated, ieeItemCreated, ieeItemDeleted };
#pragma option pop

class DELPHICLASS TIEWia;
class PASCALIMPLEMENTATION TIEWia : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	_di_IWiaDevMgr fIWiaDevMgr;
	Classes::TList* fDevicesInfo;
	TIEWiaItem* fRoot;
	Classes::TComponent* fCtrlParent;
	Hyieutils::TIEMultiCallBack fMultiCallBack;
	_di_IUnknown fEventCallBack1;
	_di_IUnknown fEventCallBack2;
	_di_IUnknown fEventCallBack3;
	TIEWiaOnProgress fOnProgress;
	bool fTakePicture;
	bool fDeleteTakenPicture;
	AnsiString fSaveTransferBufferAs;
	TIETransferFormat fTransferFormat;
	int fCurrentIndex;
	Classes::TNotifyEvent fItemsTreeUpdated;
	TIEWiaEvent fLastEvent;
	void __fastcall FillDevices(void);
	void __fastcall FillItemChildren(TIEWiaItem* parent);
	TIEWiaDeviceInfo* __fastcall GetDevicesInfo(int idx);
	int __fastcall GetDevicesInfoCount(void);
	void __fastcall EmptyDeviceInfo(void);
	TIEWiaItem* __fastcall GetRoot(void);
	bool __fastcall GetPage(PWIA_DATA_CALLBACK_HEADER header, void * data, int datalen);
	void __fastcall ConnectToDefault(void);
	bool __fastcall GetDefaultItem(TIEWiaItem* &item, bool LastItem);
	void __fastcall DoItemsTreeUpdated(void);
	
public:
	Hyieutils::TIEBitmap* ProcessingBitmap;
	#pragma pack(push, 1)
	TIEWProcessingInfo ProcessingInfo;
	#pragma pack(pop)
	
	__fastcall TIEWia(Classes::TComponent* parent);
	__fastcall virtual ~TIEWia(void);
	__property TIEWiaDeviceInfo* DevicesInfo[int idx] = {read=GetDevicesInfo};
	__property int DevicesInfoCount = {read=GetDevicesInfoCount, nodefault};
	bool __fastcall ConnectToUsingDialog(void);
	__property TIEWiaItem* Device = {read=GetRoot};
	void __fastcall UpdateItems(void);
	bool __fastcall ConnectTo(int idx);
	bool __fastcall ShowAcquireDialog(bool SystemDialog);
	bool __fastcall Transfer(TIEWiaItem* item, bool MultiPage);
	__property bool TakePicture = {read=fTakePicture, write=fTakePicture, nodefault};
	__property bool DeleteTakenPicture = {read=fDeleteTakenPicture, write=fDeleteTakenPicture, nodefault
		};
	__property TIEWiaOnProgress OnProgress = {read=fOnProgress, write=fOnProgress};
	__property Hyieutils::TIEMultiCallBack OnGetPage = {read=fMultiCallBack, write=fMultiCallBack};
	__property Classes::TNotifyEvent OnItemsTreeUpdated = {read=fItemsTreeUpdated, write=fItemsTreeUpdated
		};
	__property TIEWiaEvent LastEvent = {read=fLastEvent, nodefault};
	Variant __fastcall GetDeviceProperty(unsigned PropId);
	bool __fastcall SetDeviceProperty(unsigned PropId, int val);
	bool __fastcall SetItemProperty(unsigned PropId, int val, TIEWiaItem* item);
	bool __fastcall SetDevicePropertyVariant(unsigned PropId, const Variant &val);
	bool __fastcall SetItemPropertyVariant(unsigned PropId, const Variant &val, TIEWiaItem* item);
	Variant __fastcall GetItemProperty(unsigned PropId, TIEWiaItem* item);
	void __fastcall GetItemPropertyAttrib(unsigned PropId, TIEWiaItem* item, TIEWiaAttrib &attrib, TIEWiaValues* 
		&values);
	void __fastcall FillTreeView(Comctrls::TTreeNodes* Items, bool IncludeDescription);
	__property AnsiString SaveTransferBufferAs = {read=fSaveTransferBufferAs, write=fSaveTransferBufferAs
		};
	__property TIETransferFormat TransferFormat = {read=fTransferFormat, write=fTransferFormat, nodefault
		};
	bool __fastcall GetItemThumbnail(TIEWiaItem* item, Hyieutils::TIEBitmap* destBitmap);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID WiaImgFmt_UNDEFINED;
extern PACKAGE GUID WiaImgFmt_RAWRGB;
extern PACKAGE GUID WiaImgFmt_MEMORYBMP;
extern PACKAGE GUID WiaImgFmt_BMP;
extern PACKAGE GUID WiaImgFmt_EMF;
extern PACKAGE GUID WiaImgFmt_WMF;
extern PACKAGE GUID WiaImgFmt_JPEG;
extern PACKAGE GUID WiaImgFmt_PNG;
extern PACKAGE GUID WiaImgFmt_GIF;
extern PACKAGE GUID WiaImgFmt_TIFF;
extern PACKAGE GUID WiaImgFmt_EXIF;
extern PACKAGE GUID WiaImgFmt_PHOTOCD;
extern PACKAGE GUID WiaImgFmt_FLASHPIX;
extern PACKAGE GUID WiaImgFmt_ICO;
extern PACKAGE GUID WiaImgFmt_CIFF;
extern PACKAGE GUID WiaImgFmt_PICT;
extern PACKAGE GUID WiaImgFmt_JPEG2K;
extern PACKAGE GUID WiaImgFmt_JPEG2KX;
extern PACKAGE GUID WiaImgFmt_RTF;
extern PACKAGE GUID WiaImgFmt_XML;
extern PACKAGE GUID WiaImgFmt_HTML;
extern PACKAGE GUID WiaImgFmt_TXT;
extern PACKAGE GUID WiaImgFmt_MPG;
extern PACKAGE GUID WiaImgFmt_AVI;
extern PACKAGE GUID WiaImgFmt_ASF;
extern PACKAGE GUID WiaImgFmt_SCRIPT;
extern PACKAGE GUID WiaImgFmt_EXEC;
extern PACKAGE GUID WiaImgFmt_UNICODE16;
extern PACKAGE GUID WiaImgFmt_DPOF;
extern PACKAGE GUID WiaAudFmt_WAV;
extern PACKAGE GUID WiaAudFmt_MP3;
extern PACKAGE GUID WiaAudFmt_AIFF;
extern PACKAGE GUID WiaAudFmt_WMA;
static const Shortint WIA_DIP_DEV_ID = 0x2;
static const Shortint WIA_DIP_DEV_NAME = 0x7;
static const Shortint WIA_DIP_SERVER_NAME = 0x8;
static const Shortint WIA_DIP_DEV_DESC = 0x4;
static const Shortint WIA_DIP_DEV_TYPE = 0x5;
static const Shortint WIA_DIP_DRIVER_VERSION = 0xf;
static const Shortint WIA_DIP_PORT_NAME = 0x6;
static const Shortint WIA_DIP_VEND_DESC = 0x3;
static const Shortint StiDeviceTypeDefault = 0x0;
static const Shortint StiDeviceTypeScanner = 0x1;
static const Shortint StiDeviceTypeDigitalCamera = 0x2;
static const Shortint StiDeviceTypeStreamingVideo = 0x3;
static const Shortint WiaItemTypeFree = 0x0;
static const Shortint WiaItemTypeImage = 0x1;
static const Shortint WiaItemTypeFile = 0x2;
static const Shortint WiaItemTypeFolder = 0x4;
static const Shortint WiaItemTypeRoot = 0x8;
static const Shortint WiaItemTypeAnalyze = 0x10;
static const Shortint WiaItemTypeAudio = 0x20;
static const Shortint WiaItemTypeDevice = 0x40;
static const Byte WiaItemTypeDeleted = 0x80;
static const Word WiaItemTypeDisconnected = 0x100;
static const Word WiaItemTypeHPanorama = 0x200;
static const Word WiaItemTypeVPanorama = 0x400;
static const Word WiaItemTypeBurst = 0x800;
static const Word WiaItemTypeStorage = 0x1000;
static const Word WiaItemTypeTransfer = 0x2000;
static const Word WiaItemTypeGenerated = 0x4000;
static const Word WiaItemTypeHasAttachments = 0x8000;
static const int WiaItemTypeVideo = 0x10000;
static const int WiaItemTypeTwainCapabilityPassThrough = 0x20000;
static const unsigned WiaItemTypeRemoved = 0x80000000;
static const unsigned WiaItemTypeMask = 0x8003ffff;
static const Shortint TYMED_HGLOBAL = 0x1;
static const Shortint TYMED_FILE = 0x2;
static const Shortint TYMED_ISTREAM = 0x4;
static const Shortint TYMED_ISTORAGE = 0x8;
static const Shortint TYMED_GDI = 0x10;
static const Shortint TYMED_MFPICT = 0x20;
static const Shortint TYMED_ENHMF = 0x40;
static const Shortint TYMED_NULL = 0x0;
static const Shortint IT_MSG_DATA_HEADER = 0x1;
static const Shortint IT_MSG_DATA = 0x2;
static const Shortint IT_MSG_STATUS = 0x3;
static const Shortint IT_MSG_TERMINATION = 0x4;
static const Shortint IT_MSG_NEW_PAGE = 0x5;
static const Shortint IT_MSG_FILE_PREVIEW_DATA = 0x6;
static const Shortint IT_MSG_FILE_PREVIEW_DATA_HEADER = 0x7;
static const Byte WIA_TYMED_CALLBACK = 0x80;
static const Word WIA_TYMED_MULTIPAGE_FILE = 0x100;
static const Word WIA_TYMED_MULTIPAGE_CALLBACK = 0x200;
static const Word WIA_RESERVED_FOR_NEW_PROPS = 0x400;
static const Shortint WIA_DIP_FIRST = 0x2;
static const Word WIA_DPA_FIRST = 0x402;
static const Word WIA_DPC_FIRST = 0x802;
static const Word WIA_DPS_FIRST = 0xc02;
static const Word WIA_IPA_FIRST = 0x1002;
static const Word WIA_IPC_FIRST = 0x1402;
static const Shortint WIA_DIP_REMOTE_DEV_ID = 0x9;
static const Shortint WIA_DIP_UI_CLSID = 0xa;
static const Shortint WIA_DIP_HW_CONFIG = 0xb;
static const Shortint WIA_DIP_BAUDRATE = 0xc;
static const Shortint WIA_DIP_STI_GEN_CAPABILITIES = 0xd;
static const Shortint WIA_DIP_WIA_VERSION = 0xe;
static const Word WIA_DPA_FIRMWARE_VERSION = 0x402;
static const Word WIA_DPA_CONNECT_STATUS = 0x403;
static const Word WIA_DPA_DEVICE_TIME = 0x404;
static const Word WIA_DPA_LAST = 0x405;
static const Word WIA_IPS_FIRST = 0x1802;
static const Word WIA_IPS_CUR_INTENT = 0x1802;
static const Word WIA_IPS_XRES = 0x1803;
static const Word WIA_IPS_YRES = 0x1804;
static const Word WIA_IPS_XPOS = 0x1805;
static const Word WIA_IPS_YPOS = 0x1806;
static const Word WIA_IPS_XEXTENT = 0x1807;
static const Word WIA_IPS_YEXTENT = 0x1808;
static const Word WIA_IPS_PHOTOMETRIC_INTERP = 0x1809;
static const Word WIA_IPS_BRIGHTNESS = 0x180a;
static const Word WIA_IPS_CONTRAST = 0x180b;
static const Word WIA_IPS_ORIENTATION = 0x180c;
static const Word WIA_IPS_ROTATION = 0x180d;
static const Word WIA_IPS_MIRROR = 0x180e;
static const Word WIA_IPS_THRESHOLD = 0x180f;
static const Word WIA_IPS_INVERT = 0x1810;
static const Word WIA_IPS_WARM_UP_TIME = 0x1811;
static const Word WIA_DPS_HORIZONTAL_BED_SIZE = 0xc02;
static const Word WIA_DPS_VERTICAL_BED_SIZE = 0xc03;
static const Word WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE = 0xc04;
static const Word WIA_DPS_VERTICAL_SHEET_FEED_SIZE = 0xc05;
static const Word WIA_DPS_SHEET_FEEDER_REGISTRATION = 0xc06;
static const Word WIA_DPS_HORIZONTAL_BED_REGISTRATION = 0xc07;
static const Word WIA_DPS_VERTICAL_BED_REGISTRATION = 0xc08;
static const Word WIA_DPS_PLATEN_COLOR = 0xc09;
static const Word WIA_DPS_PAD_COLOR = 0xc0a;
static const Word WIA_DPS_FILTER_SELECT = 0xc0b;
static const Word WIA_DPS_DITHER_SELECT = 0xc0c;
static const Word WIA_DPS_DITHER_PATTERN_DATA = 0xc0d;
static const Word WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES = 0xc0e;
static const Word WIA_DPS_DOCUMENT_HANDLING_STATUS = 0xc0f;
static const Word WIA_DPS_DOCUMENT_HANDLING_SELECT = 0xc10;
static const Word WIA_DPS_DOCUMENT_HANDLING_CAPACITY = 0xc11;
static const Word WIA_DPS_OPTICAL_XRES = 0xc12;
static const Word WIA_DPS_OPTICAL_YRES = 0xc13;
static const Word WIA_DPS_ENDORSER_CHARACTERS = 0xc14;
static const Word WIA_DPS_ENDORSER_STRING = 0xc15;
static const Word WIA_DPS_SCAN_AHEAD_PAGES = 0xc16;
static const Word WIA_DPS_MAX_SCAN_TIME = 0xc17;
static const Word WIA_DPS_PAGES = 0xc18;
static const Word WIA_DPS_PAGE_SIZE = 0xc19;
static const Word WIA_DPS_PAGE_WIDTH = 0xc1a;
static const Word WIA_DPS_PAGE_HEIGHT = 0xc1b;
static const Word WIA_DPS_PREVIEW = 0xc1c;
static const Word WIA_DPS_TRANSPARENCY = 0xc1d;
static const Word WIA_DPS_TRANSPARENCY_SELECT = 0xc1e;
static const Word WIA_DPS_SHOW_PREVIEW_CONTROL = 0xc1f;
static const Word WIA_DPS_MIN_HORIZONTAL_SHEET_FEED_SIZE = 0xc20;
static const Word WIA_DPS_MIN_VERTICAL_SHEET_FEED_SIZE = 0xc21;
static const Word WIA_IPA_ITEM_NAME = 0x1002;
static const Word WIA_IPA_FULL_ITEM_NAME = 0x1003;
static const Word WIA_IPA_ITEM_TIME = 0x1004;
static const Word WIA_IPA_ITEM_FLAGS = 0x1005;
static const Word WIA_IPA_ACCESS_RIGHTS = 0x1006;
static const Word WIA_IPA_DATATYPE = 0x1007;
static const Word WIA_IPA_DEPTH = 0x1008;
static const Word WIA_IPA_PREFERRED_FORMAT = 0x1009;
static const Word WIA_IPA_FORMAT = 0x100a;
static const Word WIA_IPA_COMPRESSION = 0x100b;
static const Word WIA_IPA_TYMED = 0x100c;
static const Word WIA_IPA_CHANNELS_PER_PIXEL = 0x100d;
static const Word WIA_IPA_BITS_PER_CHANNEL = 0x100e;
static const Word WIA_IPA_PLANAR = 0x100f;
static const Word WIA_IPA_PIXELS_PER_LINE = 0x1010;
static const Word WIA_IPA_BYTES_PER_LINE = 0x1011;
static const Word WIA_IPA_NUMBER_OF_LINES = 0x1012;
static const Word WIA_IPA_GAMMA_CURVES = 0x1013;
static const Word WIA_IPA_ITEM_SIZE = 0x1014;
static const Word WIA_IPA_COLOR_PROFILE = 0x1015;
static const Word WIA_IPA_MIN_BUFFER_SIZE = 0x1016;
static const Word WIA_IPA_BUFFER_SIZE = 0x1016;
static const Word WIA_IPA_REGION_TYPE = 0x1017;
static const Word WIA_IPA_ICM_PROFILE_NAME = 0x1018;
static const Word WIA_IPA_APP_COLOR_MAPPING = 0x1019;
static const Word WIA_IPA_PROP_STREAM_COMPAT_ID = 0x101a;
static const Word WIA_IPA_FILENAME_EXTENSION = 0x101b;
static const Word WIA_IPA_SUPPRESS_PROPERTY_PAGE = 0x101c;
static const Word WIA_IPA_LAST = 0x101c;
static const Word WIA_DPC_PICTURES_TAKEN = 0x802;
static const Word WIA_DPC_PICTURES_REMAINING = 0x803;
static const Word WIA_DPC_EXPOSURE_MODE = 0x804;
static const Word WIA_DPC_EXPOSURE_COMP = 0x805;
static const Word WIA_DPC_EXPOSURE_TIME = 0x806;
static const Word WIA_DPC_FNUMBER = 0x807;
static const Word WIA_DPC_FLASH_MODE = 0x808;
static const Word WIA_DPC_FOCUS_MODE = 0x809;
static const Word WIA_DPC_FOCUS_MANUAL_DIST = 0x80a;
static const Word WIA_DPC_ZOOM_POSITION = 0x80b;
static const Word WIA_DPC_PAN_POSITION = 0x80c;
static const Word WIA_DPC_TILT_POSITION = 0x80d;
static const Word WIA_DPC_TIMER_MODE = 0x80e;
static const Word WIA_DPC_TIMER_VALUE = 0x80f;
static const Word WIA_DPC_POWER_MODE = 0x810;
static const Word WIA_DPC_BATTERY_STATUS = 0x811;
static const Word WIA_DPC_THUMB_WIDTH = 0x812;
static const Word WIA_DPC_THUMB_HEIGHT = 0x813;
static const Word WIA_DPC_PICT_WIDTH = 0x814;
static const Word WIA_DPC_PICT_HEIGHT = 0x815;
static const Word WIA_DPC_DIMENSION = 0x816;
static const Word WIA_DPC_COMPRESSION_SETTING = 0x817;
static const Word WIA_DPC_FOCUS_METERING = 0x818;
static const Word WIA_DPC_TIMELAPSE_INTERVAL = 0x819;
static const Word WIA_DPC_TIMELAPSE_NUMBER = 0x81a;
static const Word WIA_DPC_BURST_INTERVAL = 0x81b;
static const Word WIA_DPC_BURST_NUMBER = 0x81c;
static const Word WIA_DPC_EFFECT_MODE = 0x81d;
static const Word WIA_DPC_DIGITAL_ZOOM = 0x81e;
static const Word WIA_DPC_SHARPNESS = 0x81f;
static const Word WIA_DPC_CONTRAST = 0x820;
static const Word WIA_DPC_CAPTURE_MODE = 0x821;
static const Word WIA_DPC_CAPTURE_DELAY = 0x822;
static const Word WIA_DPC_EXPOSURE_INDEX = 0x823;
static const Word WIA_DPC_EXPOSURE_METERING_MODE = 0x824;
static const Word WIA_DPC_FOCUS_METERING_MODE = 0x825;
static const Word WIA_DPC_FOCUS_DISTANCE = 0x826;
static const Word WIA_DPC_FOCAL_LENGTH = 0x827;
static const Word WIA_DPC_RGB_GAIN = 0x828;
static const Word WIA_DPC_WHITE_BALANCE = 0x829;
static const Word WIA_DPC_UPLOAD_URL = 0x82a;
static const Word WIA_DPC_ARTIST = 0x82b;
static const Word WIA_DPC_COPYRIGHT_INFO = 0x82c;
static const Word WIA_IPC_THUMBNAIL = 0x1402;
static const Word WIA_IPC_THUMB_WIDTH = 0x1403;
static const Word WIA_IPC_THUMB_HEIGHT = 0x1404;
static const Word WIA_IPC_AUDIO_AVAILABLE = 0x1405;
static const Word WIA_IPC_AUDIO_DATA_FORMAT = 0x1406;
static const Word WIA_IPC_AUDIO_DATA = 0x1407;
static const Word WIA_IPC_NUM_PICT_PER_ROW = 0x1408;
static const Word WIA_IPC_SEQUENCE = 0x1409;
static const Word WIA_IPC_TIMEDELAY = 0x140a;
static const Shortint WIA_WHITEBALANCE_MANUAL = 0x1;
static const Shortint WIA_WHITEBALANCE_AUTO = 0x2;
static const Shortint WIA_WHITEBALANCE_ONEPUSH_AUTO = 0x3;
static const Shortint WIA_WHITEBALANCE_DAYLIGHT = 0x4;
static const Shortint WIA_WHITEBALANCE_FLORESCENT = 0x5;
static const Shortint WIA_WHITEBALANCE_TUNGSTEN = 0x6;
static const Shortint WIA_WHITEBALANCE_FLASH = 0x7;
static const Shortint WIA_FOCUSMODE_MANUAL = 0x1;
static const Shortint WIA_FOCUSMODE_AUTO = 0x2;
static const Shortint WIA_FOCUSMODE_MACROAUTO = 0x3;
static const Shortint WIA_EXPOSUREMETERING_AVERAGE = 0x1;
static const Shortint WIA_EXPOSUREMETERING_CENTERWEIGHT = 0x2;
static const Shortint WIA_EXPOSUREMETERING_MULTISPOT = 0x3;
static const Shortint WIA_EXPOSUREMETERING_CENTERSPOT = 0x4;
static const Shortint WIA_FLASHMODE_AUTO = 0x1;
static const Shortint WIA_FLASHMODE_OFF = 0x2;
static const Shortint WIA_FLASHMODE_FILL = 0x3;
static const Shortint WIA_FLASHMODE_REDEYE_AUTO = 0x4;
static const Shortint WIA_FLASHMODE_REDEYE_FILL = 0x5;
static const Shortint WIA_FLASHMODE_EXTERNALSYNC = 0x6;
static const Shortint WIA_EXPOSUREMODE_MANUAL = 0x1;
static const Shortint WIA_EXPOSUREMODE_AUTO = 0x2;
static const Shortint WIA_EXPOSUREMODE_APERTURE_PRIORITY = 0x3;
static const Shortint WIA_EXPOSUREMODE_SHUTTER_PRIORITY = 0x4;
static const Shortint WIA_EXPOSUREMODE_PROGRAM_CREATIVE = 0x5;
static const Shortint WIA_EXPOSUREMODE_PROGRAM_ACTION = 0x6;
static const Shortint WIA_EXPOSUREMODE_PORTRAIT = 0x7;
static const Shortint WIA_CAPTUREMODE_NORMAL = 0x1;
static const Shortint WIA_CAPTUREMODE_BURST = 0x2;
static const Shortint WIA_CAPTUREMODE_TIMELAPSE = 0x3;
static const Shortint WIA_EFFECTMODE_STANDARD = 0x1;
static const Shortint WIA_EFFECTMODE_BW = 0x2;
static const Shortint WIA_EFFECTMODE_SEPIA = 0x3;
static const Shortint WIA_FOCUSMETERING_CENTERSPOT = 0x1;
static const Shortint WIA_FOCUSMETERING_MULTISPOT = 0x2;
static const Shortint WIA_POWERMODE_LINE = 0x1;
static const Shortint WIA_POWERMODE_BATTERY = 0x2;
static const Shortint WIA_LEFT_JUSTIFIED = 0x0;
static const Shortint WIA_CENTERED = 0x1;
static const Shortint WIA_RIGHT_JUSTIFIED = 0x2;
static const Shortint WIA_TOP_JUSTIFIED = 0x0;
static const Shortint WIA_BOTTOM_JUSTIFIED = 0x2;
static const Shortint WIA_PORTRAIT = 0x0;
static const Shortint WIA_LANSCAPE = 0x1;
static const Shortint WIA_ROT180 = 0x2;
static const Shortint WIA_ROT270 = 0x3;
static const Shortint WIA_MIRRORED = 0x1;
static const Shortint WIA_FEEDER = 0x1;
static const Shortint WIA_FLATBED = 0x2;
static const Shortint WIA_DUPLEX = 0x4;
static const Shortint WIA_FRONT_FIRST = 0x8;
static const Shortint WIA_BACK_FIRST = 0x10;
static const Shortint WIA_FRONT_ONLY = 0x20;
static const Shortint WIA_BACK_ONLY = 0x40;
static const Byte WIA_NEXT_PAGE = 0x80;
static const Word WIA_PREFEED = 0x100;
static const Word WIA_AUTO_ADVANCE = 0x200;
static const Shortint WIA_LIGHT_SOURCE_PRESENT_DETECT = 0x1;
static const Shortint WIA_LIGHT_SOURCE_PRESENT = 0x2;
static const Shortint WIA_LIGHT_SOURCE_DETECT_READY = 0x4;
static const Shortint WIA_LIGHT_SOURCE_READY = 0x8;
static const Shortint WIA_LIGHT_SOURCE_SELECT = 0x1;
static const Shortint WIA_SCAN_AHEAD_ALL = 0x0;
static const Shortint WIA_ALL_PAGES = 0x0;
static const Shortint WIA_FINAL_SCAN = 0x0;
static const Shortint WIA_PREVIEW_SCAN = 0x1;
static const Shortint WIA_SHOW_PREVIEW_CONTROL = 0x0;
static const Shortint WIA_DONT_SHOW_PREVIEW_CONTROL = 0x1;
#define WIA_ENDORSER_TOK_DATE "$DATE$"
#define WIA_ENDORSER_TOK_TIME "$TIME$"
#define WIA_ENDORSER_TOK_PAGE_COUNT "$PAGE_COUNT$"
#define WIA_ENDORSER_TOK_DAY "$DAY$"
#define WIA_ENDORSER_TOK_MONTH "$MONTH$"
#define WIA_ENDORSER_TOK_YEAR "$YEAR$"
static const Shortint WIA_PAGE_A4 = 0x0;
static const Shortint WIA_PAGE_LETTER = 0x1;
static const Shortint WIA_PAGE_CUSTOM = 0x2;
static const Shortint WIA_COMPRESSION_NONE = 0x0;
static const Shortint WIA_COMPRESSION_BI_RLE4 = 0x1;
static const Shortint WIA_COMPRESSION_BI_RLE8 = 0x2;
static const Shortint WIA_COMPRESSION_G3 = 0x3;
static const Shortint WIA_COMPRESSION_G4 = 0x4;
static const Shortint WIA_COMPRESSION_JPEG = 0x5;
static const Shortint WIA_PACKED_PIXEL = 0x0;
static const Shortint WIA_PLANAR = 0x1;
static const Shortint WIA_DATA_THRESHOLD = 0x0;
static const Shortint WIA_DATA_DITHER = 0x1;
static const Shortint WIA_DATA_GRAYSCALE = 0x2;
static const Shortint WIA_DATA_COLOR = 0x3;
static const Shortint WIA_DATA_COLOR_THRESHOLD = 0x4;
static const Shortint WIA_DATA_COLOR_DITHER = 0x5;
static const Shortint WIA_PROPPAGE_SCANNER_ITEM_GENERAL = 0x1;
static const Shortint WIA_PROPPAGE_CAMERA_ITEM_GENERAL = 0x2;
static const Shortint WIA_INTENT_IMAGE_TYPE_COLOR = 0x1;
static const Shortint WIA_INTENT_IMAGE_TYPE_GRAYSCALE = 0x2;
static const Shortint WIA_INTENT_IMAGE_TYPE_TEXT = 0x4;
static const Shortint WIA_INTENT_IMAGE_TYPE_MASK = 0xf;
static const int WIA_INTENT_MINIMIZE_SIZE = 0x10000;
static const int WIA_INTENT_MAXIMIZE_QUALITY = 0x20000;
static const int WIA_INTENT_BEST_PREVIEW = 0x40000;
static const int WIA_INTENT_SIZE_MASK = 0xf0000;
static const Shortint WIA_PHOTO_WHITE_1 = 0x0;
static const Shortint WIA_PHOTO_WHITE_0 = 0x1;
static const Shortint WIA_RANGE_MIN = 0x0;
static const Shortint WIA_RANGE_NOM = 0x1;
static const Shortint WIA_RANGE_MAX = 0x2;
static const Shortint WIA_RANGE_STEP = 0x3;
static const Shortint WIA_RANGE_NUM_ELEMS = 0x4;
static const Shortint WIA_LIST_COUNT = 0x0;
static const Shortint WIA_LIST_NOM = 0x1;
static const Shortint WIA_LIST_VALUES = 0x2;
static const Shortint WIA_LIST_NUM_ELEMS = 0x2;
static const Shortint WIA_FLAG_NOM = 0x0;
static const Shortint WIA_FLAG_VALUES = 0x1;
static const Shortint WIA_FLAG_NUM_ELEMS = 0x2;
static const Shortint WIA_PROP_READ = 0x1;
static const Shortint WIA_PROP_WRITE = 0x2;
static const Shortint WIA_PROP_RW = 0x3;
static const Shortint WIA_PROP_SYNC_REQUIRED = 0x4;
static const Shortint WIA_PROP_NONE = 0x8;
static const Shortint WIA_PROP_RANGE = 0x10;
static const Shortint WIA_PROP_LIST = 0x20;
static const Shortint WIA_PROP_FLAG = 0x40;
static const int WIA_PROP_CACHEABLE = 0x10000;
static const Byte WIA_ITEM_CAN_BE_DELETED = 0x80;
static const Shortint WIA_ITEM_READ = 0x1;
static const Shortint WIA_ITEM_WRITE = 0x2;
static const Byte WIA_ITEM_RD = 0x81;
static const Byte WIA_ITEM_RWD = 0x83;
static const Shortint WIA_DEVICE_NOT_CONNECTED = 0x0;
static const Shortint WIA_DEVICE_CONNECTED = 0x1;
static const Shortint WIA_FEED = 0x1;
static const Shortint WIA_FLAT = 0x2;
static const Shortint WIA_DUP = 0x4;
static const Shortint WIA_DETECT_FLAT = 0x8;
static const Shortint WIA_DETECT_SCAN = 0x10;
static const Shortint WIA_DETECT_FEED = 0x20;
static const Shortint WIA_DETECT_DUP = 0x40;
static const Byte WIA_DETECT_FEED_AVAIL = 0x80;
static const Word WIA_DETECT_DUP_AVAIL = 0x100;
static const Shortint WIA_FEED_READY = 0x1;
static const Shortint WIA_FLAT_READY = 0x2;
static const Shortint WIA_DUP_READY = 0x4;
static const Shortint WIA_FLAT_COVER_UP = 0x8;
static const Shortint WIA_PATH_COVER_UP = 0x10;
static const Shortint WIA_PAPER_JAM = 0x20;
extern PACKAGE bool IEOleInitialized;

}	/* namespace Iewia */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iewia;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iewia
