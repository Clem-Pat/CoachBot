//============================================================-
// CNT.H
// Headder file for CONTEC Counter device
// Supported Devices:
//       CNT24-2(USB)
// Ver1.00
//                                              CONTEC.Co.,Ltd.
//============================================================-

//-------------------------------------------------
// Prototype definition
//-------------------------------------------------
#ifdef __cplusplus
extern "C"{
#endif
// Common function
long WINAPI CntInit(char *DeviceName, short *Id);
long WINAPI CntExit(short Id);
long WINAPI CntResetDevice(short Id);
long WINAPI CntGetErrorString(long ErrorCode , char *ErrorString);
// Setting function (set)
long WINAPI CntSetZMode(short Id, short ChNo, short Mode);
long WINAPI CntSetZLogic(short Id, short ChNo, short ZLogic);
long WINAPI CntSelectChannelSignal(short Id, short ChNo, short SigType);
long WINAPI CntSetCountDirection(short Id, short ChNo, short Dir);
long WINAPI CntSetOperationMode(short Id, short ChNo, short Phase, short Mul, short SyncClr);
long WINAPI CntSetDigitalFilter(short Id, short ChNo, short FilterValue);
long WINAPI CntSetPulseWidth(short Id, short ChNo, short PlsWidth);
// Setting function (get)
long WINAPI CntGetZMode(short Id, short ChNo, short *Mode);
long WINAPI CntGetZLogic(short Id, short ChNo, short *ZLogic);
long WINAPI CntGetChannelSignal(short Id, short ChNo, short *SigType);
long WINAPI CntGetCountDirection(short Id, short ChNo, short *Dir);
long WINAPI CntGetOperationMode(short Id, short ChNo, short *Phase, short *Mul, short *SyncClr);
long WINAPI CntGetDigitalFilter(short Id, short ChNo, short *FilterValue);
long WINAPI CntGetPulseWidth(short Id, short ChNo, short *PlsWidth);
// Counter function
long WINAPI CntPreset(short Id, short *ChNo, short ChNum, DWORD *PresetData);
long WINAPI CntStartCount(short Id, short *ChNo, short ChNum);
long WINAPI CntStopCount(short Id, short *ChNo, short ChNum);
long WINAPI CntReadCount(short Id, short *ChNo, short ChNum, DWORD *CntDat);
long WINAPI CntReadStatus(short Id, short ChNo, short *Sts);
// Count match function
long WINAPI CntNotifyCountUp(short Id, short ChNo, short RegNo, DWORD Count, HANDLE hWnd);
long WINAPI CntStopNotifyCountUp(short Id, short ChNo, short RegNo);
// Timer function
long WINAPI CntNotifyTimeUp(short Id, DWORD TimeValue, HANDLE hWnd);
long WINAPI CntStopNotifyTimeUp(short Id);
// General purpose input function
long WINAPI CntInputDIByte(short Id, short Reserved, BYTE *bData);
// Information function
long WINAPI CntGetDeviceInfo(char *Device, short InfoType, void *Param1, void *Param2, void *Param3);
long WINAPI CntQueryDeviceName(short Index, char *DeviceName, char *Device);
long WINAPI CntGetDeviceType(char *Device, short *DeviceType);
long WINAPI CntGetMaxChannels(short Id, short *ChannelNum);
#ifdef __cplusplus
};
#endif
//-------------------------------------------------
// Type definition
//-------------------------------------------------

#define	DEVICE_TYPE_ISA					0	//ISA�܂���C�o�X
#define	DEVICE_TYPE_PCI					1	//PCI�o�X
#define	DEVICE_TYPE_PCMCIA				2	//PCMCIA
#define	DEVICE_TYPE_USB					3	//USB
#define	DEVICE_TYPE_FIT					4	//FIT

//-------------------------------------------------
// Mode definition
//-------------------------------------------------
// Z Phase Mode
#define	CNT_ZPHASE_NOT_USE			1
#define	CNT_ZPHASE_NEXT_ONE			2
#define	CNT_ZPHASE_EVERY_TIME		3
// Z Phase Logic
#define	CNT_ZLOGIC_POSITIVE			0
#define	CNT_ZLOGIC_NEGATIVE			1
// Signal Source
#define	CNT_SIGTYPE_ISOLATE			0
#define	CNT_SIGTYPE_TTL				1
#define	CNT_SIGTYPE_LINERECEIVER	2
// Count Direction
#define	CNT_DIR_DOWN				0
#define	CNT_DIR_UP					1
// 1Phase/2Phase
#define	CNT_MODE_1PHASE				0
#define	CNT_MODE_2PHASE				1
#define	CNT_MODE_GATECONTROL		2
// Mul
#define	CNT_MUL_X1					0
#define	CNT_MUL_X2					1
#define	CNT_MUL_X4					2
// Sync Clear
#define	CNT_CLR_ASYNC				0
#define	CNT_CLR_SYNC				1
// Gate Control
#define	CNT_UPDOWN					1
#define	CNT_GATECONTROL				0

// Generic I/O Signal
#define	CNT_GENIO_LINERECEIVER		0
#define	CNT_GENIO_TTL				1

// Device Information
#define	ICNT_DEVICE_TYPE			0	// device type.						Param1:short
#define	ICNT_NUMBER_OF_CH			1	// ���ِ�							Param1:int
#define	ICNT_BIT					2	// �ޯĐ�							Param1:int
#define	ICNT_IS_DIGITAL_FILTER		3	// �޼���̨�������邩�H				Param1:BOOL(True/False)
#define	ICNT_IS_DEFF				4	// �ėp���͂̍����؂�ւ����邩�H	Param1:BOOL(True/False)
#define	ICNT_CNTSOURCE				5	// �J�E���^�̐M�����@�@�@�@�@�@�@�@ Param1:int(BIT0:TTL, BIT1:PHOTO, BIT2:LINERECEIVER)

#define	ICNT_CNTSOURCE_TTL			0x01
#define	ICNT_CNTSOURCE_PHOTO		0x02
#define	ICNT_CNTSOURCE_LINERECEIVER	0x04
//-------------------------------------------------
// Message
//-------------------------------------------------
#define	CNTM_COUNTUP_CH0	0x1100		// �J�E���g�A�b�v�A�`���l���ԍ�0
#define	CNTM_COUNTUP_CH1	0x1101		//         "                   1
#define	CNTM_COUNTUP_CH2	0x1102		//         "                   2
#define	CNTM_COUNTUP_CH3	0x1103		//         "                   3
#define	CNTM_COUNTUP_CH4	0x1104		//         "                   4
#define	CNTM_COUNTUP_CH5	0x1105		//         "                   5
#define	CNTM_COUNTUP_CH6	0x1106		//         "                   6
#define	CNTM_COUNTUP_CH7	0x1107		//         "                   7

#define	CNTM_TIME_UP		0x1140		// �^�C���A�b�v

// Count Match Direction(UP=1, DOWN=2)
#define	CNTM_DIR_UP			1			// �A�b�v�J�E���g�ň�v
#define	CNTM_DIR_DOWN		2			// �_�E���J�E���g�ň�v


//-------------------------------------------------
// Error codes
//-------------------------------------------------
// Initialize Error
// Common
#define	CNT_ERR_SUCCESS						0		//	�F����I��
#define CNT_ERR_INI_RESOURCE				1		//	�F���\�[�X�̎擾�Ɏ��s���܂���
#define	CNT_ERR_INI_INTERRUPT				2		//	�F���荞�݃��[�`���̓o�^�Ɏ��s���܂���
#define	CNT_ERR_INI_MEMORY					3		//	�F�������̊��蓖�ĂɎ��s���܂���
#define	CNT_ERR_INI_REGISTRY				4		//	�F���W�X�g���̃A�N�Z�X�Ɏ��s���܂���
// CNT

// DLL Error
// Common
#define	CNT_ERR_DLL_DEVICE_NAME			10000	//	�F�f�o�C�X�}�l�[�W���[�ɓo�^����Ă��Ȃ��f�o�C�X�����w�肳��܂���
#define	CNT_ERR_DLL_INVALID_ID			10001	//	�F������ID���w�肳��܂���
#define	CNT_ERR_DLL_CALL_DRIVER			10002	//	�F�h���C�o���Ăяo���܂���B(�f�o�C�XI/O�R���g���[���Ɏ��s)
#define	CNT_ERR_DLL_CREATE_FILE			10003	//	�F�t�@�C���̍쐬�Ɏ��s���܂���(CreateFile���s)
#define	CNT_ERR_DLL_CLOSE_FILE			10004	//	�F�t�@�C���̃N���[�Y�Ɏ��s���܂���(CloseFile���s)
#define	CNT_ERR_DLL_CREATE_THREAD		10005	//	�F�X���b�h�̍쐬�Ɏ��s���܂���(CreateThread���s)
#define	CNT_ERR_INFO_INVALID_DEVICE		10050	//	�F�w�肵���f�o�C�X���̂�������܂���B�X�y�����m�F���Ă��������B
#define	CNT_ERR_INFO_NOT_FIND_DEVICE	10051	//	�F���p�\�ȃf�o�C�X��������܂���B
#define	CNT_ERR_INFO_INVALID_INFOTYPE	10052	//	�F�w�肵���f�o�C�X���^�C�v���͈͊O�ł��B
// CNT
#define	CNT_ERR_DLL_MODE				10100	//	�F���[�h���ݒ�\�͈͊O�ł�
#define CNT_ERR_DLL_BUFF_ADDRESS		10101	//	�F�f�[�^�o�b�t�@�A�h���X���s���ł�
#define	CNT_ERR_DLL_HWND				10200	//	�F�E�B���h�E�n���h�����w��\�͈͊O�ł�

// SYS Error
// Common
#define	CNT_ERR_SYS_MEMORY				20000	//	�F�������̊m�ۂɎ��s���܂���
#define	CNT_ERR_SYS_NOT_SUPPORTED		20001	//�@�F���̃{�[�h�ł͂��̊֐��͎g�p�ł��܂���
#define	CNT_ERR_SYS_BOARD_EXECUTING		20002	//�@�F�{�[�h�����쒆�̂��ߎ��s�ł��܂���
#define	CNT_ERR_SYS_USING_OTHER_PROCESS	20003	//�@�F���̃v���Z�X���f�o�C�X���g�p���Ă��邽�߁A���s�ł��܂���

#ifndef STATUS_SYS_USB_CRC
#define	STATUS_SYS_USB_CRC						20020	// �G���h�|�C���g����󂯎�����Ō�̃f�[�^�p�P�b�g��CRC�G���[�����݂��Ă��܂��B
#define	STATUS_SYS_USB_BTSTUFF					20021	// �G���h�|�C���g����󂯎�����Ō�̃f�[�^�p�P�b�g�Ƀr�b�g�l�߈ᔽ�̃G���[�����݂��Ă��܂��B
#define	STATUS_SYS_USB_DATA_TOGGLE_MISMATCH		20022	// �G���h�|�C���g����󂯎�����Ō�̃f�[�^�p�P�b�g�Ɋ��҂����l�Ƀ}�b�`���Ȃ��f�[�^�g�O���p�P�b�g
#define	STATUS_SYS_USB_STALL_PID				20023	// �G���h�|�C���g��STALL�p�P�b�g���ʎq��Ԃ��܂����B
#define	STATUS_SYS_USB_DEV_NOT_RESPONDING		20024	// �f�o�C�X���g�[�N��(IN)�ɉ������Ă��Ȃ����n���h�V�F�[�N���T�|�[�g���Ă��܂���B
#define	STATUS_SYS_USB_PID_CHECK_FAILURE		20025	// �G���h�|�C���g����󂯎�����p�P�b�g���ʎq��̃`�F�b�N�r�b�g�ɖ�肪����܂��B
#define	STATUS_SYS_USB_UNEXPECTED_PID			20026	// �󂯎�����p�P�b�g���ʎq������������`�ł��B
#define	STATUS_SYS_USB_DATA_OVERRUN				20027	// �G���h�|�C���g����߂��ꂽ�f�[�^�̗ʂ����e���ꂽ�f�[�^�p�P�b�g�̍ő咷���邢�̓o�b�t�@�̎c�ʂ𒴂��Ă��܂��B
#define	STATUS_SYS_USB_DATA_UND0RRUN			20028	// �G���h�|�C���g����߂��ꂽ�f�[�^�̗ʂ����҂����f�[�^�̃T�C�Y�ɑ���܂���B
#define	STATUS_SYS_USB_BUFFER_OVERRUN			20029	// IN�]���ɂ����Ďw�肳�ꂽ�o�b�t�@�����������ăf�o�C�X����󂯎�����f�[�^�����ׂĊi�[���邱�Ƃ��ł��܂���B
#define	STATUS_SYS_USB_BUFFER_UNDERRUN			20030	// OUT�]���ɂ����Ďw�肳�ꂽ�o�b�t�@�ɂ̓f�o�C�X�ɑ��o���邽�߂̏\���ȃf�[�^���i�[����Ă��܂���B
#define	STATUS_SYS_USB_ENDPOINT_HALTED			20031	// �G���h�|�C���g��STALL��Ԃ̂��ߓ]���Ɏ��s���܂����B
#define	STATUS_SYS_USB_NOT_FOUND_DEVINFO		20032	// ���擾�Ńf�o�C�X�̏�񂪌�����܂���ł����B
#define STATUS_SYS_USB_ACCESS_DENIED			20033	//�@�n�[�h�E�F�A�ւ̃A�N�Z�X�����ۂ���܂����B
#define STATUS_SYS_USB_INVALID_HANDLE			20034	//�@�w�肵���n���h���͖����ł��B
#endif
// CNT
#define	CNT_ERR_SYS_MODE				20100	//	�F���[�h���ݒ�\�͈͊O�ł�
#define	CNT_ERR_SYS_CH_NO				20201	//	�F�`���l���ԍ����ݒ�\�͈͊O�ł�
#define	CNT_ERR_SYS_CH_NUM				20202	//	�F�`���l�������ݒ�\�͈͊O�ł�
#define	CNT_ERR_SYS_CH_VALUE			20203	//	�F�J�E���^�l���ݒ�\�͈͊O�ł�
#define	CNT_ERR_SYS_REGNO			20204	//	�F��r���W�X�^�ԍ����ݒ�\�͈͊O�ł�
#define	CNT_ERR_SYS_TIMER_VALUE			20300	//	�F�^�C�}�l���ݒ�\�͈͊O�ł�
