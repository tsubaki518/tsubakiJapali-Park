#include "BalanceBoardInput.h"

//Trigger�C�x���g�̂������l((1=100g)��������Trigger)
#define TRIGGER_THRESHOLD (100)
//Release�C�x���g�̂������l
#define RELEASE_THRESHOLD (100)
//HANDLE hRsDevHandle;

const USHORT VID = 0x057e; // Nintendo
const USHORT PID = 0x0306; // Wii-Remote

 BALANCEBOARD balanceBoard[2];
 HIDP_CAPS Capabilities;

void BalanceBoard_Initialize(void) {
	OpenHidHandle(VID, PID);
	if (balanceBoard[BALANCEBOARD_1P].hRsDevHandle == NULL || balanceBoard[BALANCEBOARD_2P].hRsDevHandle == NULL) {
		MessageBox(NULL, "�o�����X�{�[�h���˂��I", "ERROR", MB_ICONHAND);
	}
	Wii_Remote_mode_0x31();
	Wii_Board_init();
}

void BalanceBoard_Finalize(void) {
	CloseHidHandle(balanceBoard[BALANCEBOARD_1P].hRsDevHandle);
	CloseHidHandle(balanceBoard[BALANCEBOARD_2P].hRsDevHandle);
}

void BalanceBoard_Update(void) {
	Wii_Remote_Input();
}

void BalanceBoard_Reset(void) {
	balanceBoard[BALANCEBOARD_1P].Brf_offset = balanceBoard[BALANCEBOARD_1P].Brf;
	balanceBoard[BALANCEBOARD_1P].Brb_offset = balanceBoard[BALANCEBOARD_1P].Brb;
	balanceBoard[BALANCEBOARD_1P].Blf_offset = balanceBoard[BALANCEBOARD_1P].Blf;
	balanceBoard[BALANCEBOARD_1P].Blb_offset = balanceBoard[BALANCEBOARD_1P].Blb;

	balanceBoard[BALANCEBOARD_2P].Brf_offset = balanceBoard[BALANCEBOARD_2P].Brf;
	balanceBoard[BALANCEBOARD_2P].Brb_offset = balanceBoard[BALANCEBOARD_2P].Brb;
	balanceBoard[BALANCEBOARD_2P].Blf_offset = balanceBoard[BALANCEBOARD_2P].Blf;
	balanceBoard[BALANCEBOARD_2P].Blb_offset = balanceBoard[BALANCEBOARD_2P].Blb;
	
}

bool BalanceBoard_isPress(int num, int key) {
	int* pKey = &balanceBoard[num].Mrf;
	int* pOff = &balanceBoard[num].Brf_offset;
	return pKey[key] > 100;
}
bool BalanceBoard_isTrigger(int num, int key) {
	int* pKey = &balanceBoard[num].Mrf;
	int* pOld = &balanceBoard[num].Mrf_old;
	return pKey[key] > pOld[key] + TRIGGER_THRESHOLD;
}
bool BalanceBoard_isRelease(int num, int key) {
	int* pKey = &balanceBoard[num].Mrf;
	int* pOld = &balanceBoard[num].Mrf_old;
	return pKey[key] + RELEASE_THRESHOLD < pOld[key];
}

int BalanceBoard_GetValue(int num, int key) {
	int* pKey = &balanceBoard[num].Mrf;
	return pKey[key];
}

NTSTATUS GetDeviceCapabilities(HANDLE hRsDevHandle) {
	PHIDP_PREPARSED_DATA PreparsedData;
	NTSTATUS Result = HIDP_STATUS_INVALID_PREPARSED_DATA;

	if (HidD_GetPreparsedData(hRsDevHandle, &PreparsedData)) {
		Result = HidP_GetCaps(PreparsedData, &Capabilities);
		HidD_FreePreparsedData(PreparsedData);
	}

	return Result;
}

//OpenHidHandle:�w�肵��vendor_id,product_id�̃n���h�����擾���܂�
HANDLE OpenHidHandle(unsigned short vendor_id, unsigned short product_id)
{

	HANDLE hDevHandle;
	GUID HidGuid;
	HDEVINFO hDevInfo = 0;
	BOOL bDevDetected = FALSE;
	SP_DEVICE_INTERFACE_DATA devInfoData;
	PSP_DEVICE_INTERFACE_DETAIL_DATA detailData = NULL;
	HIDD_ATTRIBUTES Attributes;
	BOOL LastDevice = FALSE;
	DWORD MemberIndex = 0;
	LONG Result;
	DWORD Required;
	DWORD Length = 0;
	int id;
	hDevHandle = INVALID_HANDLE_VALUE;

	HidD_GetHidGuid(&HidGuid);
	hDevInfo = SetupDiGetClassDevs((LPGUID)&HidGuid, NULL, (HWND)NULL, DIGCF_INTERFACEDEVICE | DIGCF_PRESENT);

	//�����ŊY������f�o�C�X������������I���

	if (0 == hDevInfo) return INVALID_HANDLE_VALUE;


	do {
		bDevDetected = FALSE;
		devInfoData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

		//�f�o�C�X�̗�
		Result = SetupDiEnumDeviceInterfaces
		(hDevInfo,
			NULL,
			&HidGuid,
			MemberIndex,
			&devInfoData);

		if (Result != 0) {

			//�f�o�C�X�C���^�t�F�[�X�ڍׂ𓾂邽�߂̃������m��

			Result = SetupDiGetDeviceInterfaceDetail
			(hDevInfo,
				&devInfoData,
				NULL,
				0,
				&Length,
				NULL);

			detailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(Length);
			detailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

			//�񋓂����f�o�C�X�X�̏ڍׂ��擾
			Result = SetupDiGetDeviceInterfaceDetail
			(hDevInfo,
				&devInfoData,
				detailData,
				Length,
				&Required,
				NULL);

			//HID�ɃA�N�Z�X���邽�߂̃t�@�C�����쐬���n���h�����擾

			hDevHandle = CreateFile
			(detailData->DevicePath,
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				(LPSECURITY_ATTRIBUTES)NULL,
				OPEN_EXISTING,
				0,
				NULL);

			bDevDetected = FALSE;
			Attributes.Size = sizeof(Attributes);

			//�񋓂����f�o�C�X�̃A�g���r���[�g���擾

			if (HidD_GetAttributes(hDevHandle, &Attributes)) {

				//�x���_�[ID�ƃv���_�N�gID���擾�i������ProductID == 774, vendor_id = 1406�Ȃ�Wiimote�j

				if (Attributes.VendorID == vendor_id && Attributes.ProductID == product_id) {
					//�f�o�C�XCaps���擾�B���̏�����cWiiMote�ɂ͂Ȃ�

					if (HIDP_STATUS_SUCCESS == GetDeviceCapabilities(hDevHandle)) {
						if (balanceBoard[BALANCEBOARD_1P].hRsDevHandle == NULL) {
							balanceBoard[BALANCEBOARD_1P].hRsDevHandle = hDevHandle;
						} else {
							if (balanceBoard[BALANCEBOARD_2P].hRsDevHandle == NULL) {
								balanceBoard[BALANCEBOARD_2P].hRsDevHandle = hDevHandle;
								bDevDetected = TRUE;
							}
						}
					}

				} else {

					//�x���_�[ID�A�v���_�N�gID����v���Ȃ��̂ŃN���[�Y
					CloseHandle(hDevHandle);
				} // End of if (Attributes.VendorID == RS_VID && Attributes.ProductID == RS_PID)

			} else {

				//���������A�g���r���[�g���擾�ł��Ȃ��̂ŃN���[�Y
				CloseHandle(hDevHandle);
			} // End of if ( HidD_GetAttributes( hDevHandle, &Attributes ) )

			//�ڍ׃f�[�^���擾���邽�߂̃��������J��

			free(detailData);
		} else {

			//HID�f�o�C�X���񋓂ł��Ȃ������A���Ȃ킿����HID�f�o�C�X������
			LastDevice = TRUE;
		} //if (Result != 0)

		MemberIndex++; //����HID�f�o�C�X��(������Wiimote�ł͂Ȃ�)
		//�Ȍ�AHID�f�o�C�X�����݂��AWiimote��������Ȃ��Ȃ�J��Ԃ�Do
	} while ((LastDevice == FALSE) && (bDevDetected == FALSE)); //End of do

	if (bDevDetected == FALSE) {
		hDevHandle = INVALID_HANDLE_VALUE;
	} // End of (bDevDetected == FALSE)

	//�|��

	SetupDiDestroyDeviceInfoList(hDevInfo);

	return hDevHandle;
}


void ReadReport(HANDLE handle, unsigned char *InputReport, int *len)
{
	ReadFile(handle, InputReport, Capabilities.InputReportByteLength, (LPDWORD)len, NULL);
}

void WriteReport(HANDLE handle, unsigned char *OutputReport, int *len)
{
	WriteFile(handle, OutputReport, Capabilities.OutputReportByteLength, (LPDWORD)len, NULL);
}


void CloseHidHandle(HANDLE handle)
{
	CloseHandle(handle);
}

void Report_0x12(unsigned char data1, unsigned char data2)
{
	balanceBoard[BALANCEBOARD_1P].OutputReport[0] = 0x12; // Report ID
	balanceBoard[BALANCEBOARD_1P].OutputReport[1] = data1;
	balanceBoard[BALANCEBOARD_1P].OutputReport[2] = data2;
	WriteReport(balanceBoard[BALANCEBOARD_1P].hRsDevHandle, balanceBoard[BALANCEBOARD_1P].OutputReport, &balanceBoard[BALANCEBOARD_1P].OutputLength);

	balanceBoard[BALANCEBOARD_2P].OutputReport[0] = 0x12; // Report ID
	balanceBoard[BALANCEBOARD_2P].OutputReport[1] = data1;
	balanceBoard[BALANCEBOARD_2P].OutputReport[2] = data2;
	WriteReport(balanceBoard[BALANCEBOARD_2P].hRsDevHandle, balanceBoard[BALANCEBOARD_2P].OutputReport, &balanceBoard[BALANCEBOARD_2P].OutputLength);
}


void Wii_Remote_mode_0x31(void)
{
	// Set Report Type
	Report_0x12(0x00, 0x31);  // Acc Sensor + button  Report Mode
}

void Wii_Remote_mode_0x34(void)
{
	// Set Report Type
	Report_0x12(0x00, 0x34);  // Balance Board Report Mode
	//Report_0x12(0x00, 0x11);  // Balance Board Report Mode
	//Report_0x12(0x00, 0x10);  // Balance Board Report Mode
}


void Wii_Board_init(void)
{
	Wii_Remote_mode_0x34(); // mode 0x34 ... Balance Board Interrupt start
}


void Wii_Remote_Input(void)
{
	unsigned char r;
	int s;
	ReadReport(balanceBoard[BALANCEBOARD_1P].hRsDevHandle, balanceBoard[BALANCEBOARD_1P].InputReport, &balanceBoard[BALANCEBOARD_1P].InputLength);

	r = balanceBoard[BALANCEBOARD_1P].InputReport[0];
	if ((r & 0xF0) == 0x30) {
		balanceBoard[BALANCEBOARD_1P].button1 = balanceBoard[BALANCEBOARD_1P].InputReport[1]; balanceBoard[BALANCEBOARD_1P].button2 = balanceBoard[BALANCEBOARD_1P].InputReport[2];
		if (r & 0x04) {
			// Balance Wii Board
			balanceBoard[BALANCEBOARD_1P].Mrf_old = balanceBoard[BALANCEBOARD_1P].Mrf;
			balanceBoard[BALANCEBOARD_1P].Mrb_old = balanceBoard[BALANCEBOARD_1P].Mrb;
			balanceBoard[BALANCEBOARD_1P].Mlf_old = balanceBoard[BALANCEBOARD_1P].Mlf;
			balanceBoard[BALANCEBOARD_1P].Mlb_old = balanceBoard[BALANCEBOARD_1P].Mlb;

			balanceBoard[BALANCEBOARD_1P].Brf = balanceBoard[BALANCEBOARD_1P].InputReport[3] << 8;	// Balance Board Right Forward
			balanceBoard[BALANCEBOARD_1P].Brf += balanceBoard[BALANCEBOARD_1P].InputReport[4];
			balanceBoard[BALANCEBOARD_1P].Brb = balanceBoard[BALANCEBOARD_1P].InputReport[5] << 8;	// Balance Board Right Back
			balanceBoard[BALANCEBOARD_1P].Brb += balanceBoard[BALANCEBOARD_1P].InputReport[6];
			balanceBoard[BALANCEBOARD_1P].Blf = balanceBoard[BALANCEBOARD_1P].InputReport[7] << 8;	// Balance Board Left Forward
			balanceBoard[BALANCEBOARD_1P].Blf += balanceBoard[BALANCEBOARD_1P].InputReport[8];
			balanceBoard[BALANCEBOARD_1P].Blb = balanceBoard[BALANCEBOARD_1P].InputReport[9] << 8;	// Balance Board Left Forward
			balanceBoard[BALANCEBOARD_1P].Blb += balanceBoard[BALANCEBOARD_1P].InputReport[10];

			balanceBoard[BALANCEBOARD_1P].Mrf = balanceBoard[BALANCEBOARD_1P].Brf - balanceBoard[BALANCEBOARD_1P].Brf_offset;
			balanceBoard[BALANCEBOARD_1P].Mrb = balanceBoard[BALANCEBOARD_1P].Brb - balanceBoard[BALANCEBOARD_1P].Brb_offset;	// Mass of object (x10g)
			balanceBoard[BALANCEBOARD_1P].Mlf = balanceBoard[BALANCEBOARD_1P].Blf - balanceBoard[BALANCEBOARD_1P].Blf_offset;
			balanceBoard[BALANCEBOARD_1P].Mlb = balanceBoard[BALANCEBOARD_1P].Blb - balanceBoard[BALANCEBOARD_1P].Blb_offset;
			balanceBoard[BALANCEBOARD_1P].Msum = balanceBoard[BALANCEBOARD_1P].Mrf + balanceBoard[BALANCEBOARD_1P].Mrb + balanceBoard[BALANCEBOARD_1P].Mlf + balanceBoard[BALANCEBOARD_1P].Mlb;						// Total Mass
		}
	}


	ReadReport(balanceBoard[BALANCEBOARD_2P].hRsDevHandle, balanceBoard[BALANCEBOARD_2P].InputReport, &balanceBoard[BALANCEBOARD_2P].InputLength);
	r = balanceBoard[BALANCEBOARD_2P].InputReport[0];
	if ((r & 0xF0) == 0x30) {
		balanceBoard[BALANCEBOARD_2P].button1 = balanceBoard[BALANCEBOARD_2P].InputReport[1]; balanceBoard[BALANCEBOARD_2P].button2 = balanceBoard[BALANCEBOARD_2P].InputReport[2];
		if (r & 0x04) {
			// Balance Wii Board
			balanceBoard[BALANCEBOARD_2P].Mrf_old = balanceBoard[BALANCEBOARD_2P].Mrf;
			balanceBoard[BALANCEBOARD_2P].Mrb_old = balanceBoard[BALANCEBOARD_2P].Mrb;
			balanceBoard[BALANCEBOARD_2P].Mlf_old = balanceBoard[BALANCEBOARD_2P].Mlf;
			balanceBoard[BALANCEBOARD_2P].Mlb_old = balanceBoard[BALANCEBOARD_2P].Mlb;

			balanceBoard[BALANCEBOARD_2P].Brf = balanceBoard[BALANCEBOARD_2P].InputReport[3] << 8;	// Balance Board Right Forward
			balanceBoard[BALANCEBOARD_2P].Brf += balanceBoard[BALANCEBOARD_2P].InputReport[4];
			balanceBoard[BALANCEBOARD_2P].Brb = balanceBoard[BALANCEBOARD_2P].InputReport[5] << 8;	// Balance Board Right Back
			balanceBoard[BALANCEBOARD_2P].Brb += balanceBoard[BALANCEBOARD_2P].InputReport[6];
			balanceBoard[BALANCEBOARD_2P].Blf = balanceBoard[BALANCEBOARD_2P].InputReport[7] << 8;	// Balance Board Left Forward
			balanceBoard[BALANCEBOARD_2P].Blf += balanceBoard[BALANCEBOARD_2P].InputReport[8];
			balanceBoard[BALANCEBOARD_2P].Blb = balanceBoard[BALANCEBOARD_2P].InputReport[9] << 8;	// Balance Board Left Forward
			balanceBoard[BALANCEBOARD_2P].Blb += balanceBoard[BALANCEBOARD_2P].InputReport[10];

			balanceBoard[BALANCEBOARD_2P].Mrf = balanceBoard[BALANCEBOARD_2P].Brf - balanceBoard[BALANCEBOARD_2P].Brf_offset;
			balanceBoard[BALANCEBOARD_2P].Mrb = balanceBoard[BALANCEBOARD_2P].Brb - balanceBoard[BALANCEBOARD_2P].Brb_offset;	// Mass of object (x10g)
			balanceBoard[BALANCEBOARD_2P].Mlf = balanceBoard[BALANCEBOARD_2P].Blf - balanceBoard[BALANCEBOARD_2P].Blf_offset;
			balanceBoard[BALANCEBOARD_2P].Mlb = balanceBoard[BALANCEBOARD_2P].Blb - balanceBoard[BALANCEBOARD_2P].Blb_offset;
			balanceBoard[BALANCEBOARD_2P].Msum = balanceBoard[BALANCEBOARD_2P].Mrf + balanceBoard[BALANCEBOARD_2P].Mrb + balanceBoard[BALANCEBOARD_2P].Mlf + balanceBoard[BALANCEBOARD_2P].Mlb;						// Total Mass

		}
	}
}