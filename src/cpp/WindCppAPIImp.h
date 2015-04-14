#ifndef _WINDCPPAPIIMP_H
#define _WINDCPPAPIIMP_H

#include <memory>

class WindDataComSink;
class WindData;
enum ErrMsgLang;

// �ص���������
typedef LONG (WINAPI *WsqAsynCallBack)(const WindData &windData);

//�ӿ���
class WindCppAPIImp {

public:

	static WindCppAPIImp& getIntance();

	//��������
	//////////////////////////////////////////////////////////////////////////
	//Wind�ӿ���������
	LONG start(LPCWSTR options = L"", LPCWSTR options2 = L"", LONG timeout = 5000);

	//Wind�ӿ���ֹ����
	LONG stop();

	//�ж�����״̬
	LONG isconnected();

	//�� requestId Ϊ0 ȡ���������󣻷���ֻȡ������ID�ŵ�����
	VOID cancelRequest(ULONGLONG requestId);

	//ȡ����������
	VOID cancelAllRequest();

	LONG readdata(ULONGLONG requestid, WindData& outWindData, LONG& requestState);

	//��ȡ��������Ӧ�Ĵ�����Ϣ
	BOOL getErrorMsg(LONG errCode, ErrMsgLang lang, WCHAR msg[], int& nBufferLength);
	BOOL getErrorMsg(LONG errCode, ErrMsgLang lang, VARIANT &msg);
	//////////////////////////////////////////////////////////////////////////

	//���ݺ���
	//////////////////////////////////////////////////////////////////////////
	//��ֵ����wsd�������������
	LONG wsd(LPCWSTR windCodes, LPCWSTR fields, LPCWSTR startTime, LPCWSTR endTime, LPCWSTR options, WindData& outWindData);

	//��ֵ����wss�������ʷ����
	LONG wss(LPCWSTR windCodes, LPCWSTR fields, LPCWSTR options, WindData& outWindData);

	//��ֵ����wsi����÷�������
	LONG wsi(LPCWSTR windCodes, LPCWSTR fields, LPCWSTR startTime, LPCWSTR endTime, LPCWSTR options, WindData& outWindData);

	//��ֵ����wst�������������
	LONG wst(LPCWSTR windCodes, LPCWSTR fields, LPCWSTR startTime, LPCWSTR endTime, LPCWSTR options, WindData& outWindData);

	//��ֵ����wsq�����ʵʱ����
	//�Ƕ���ģʽ��ȡһ���Կ�������
	LONG wsqSync(LPCWSTR windCodes, LPCWSTR fields, LPCWSTR options, WindData& outWindData, bool isTD = false);

	//����ģʽ������ʵʱ���ݣ�����ͨ���ص���������
	LONG wsqAsyn(LPCWSTR windCodes, LPCWSTR fields, LPCWSTR options, WsqAsynCallBack callBack, BOOL updateAllFields, ULONGLONG &reqId, bool isTD = false);

	//��ֵ����wset�����ָ�����ݼ�
	LONG wset(LPCWSTR reportName, LPCWSTR options, WindData& outWindData);

	//��ֵ����edb����þ�������
	LONG edb(WindData& outWindData, LPCWSTR windCodes, LPCWSTR startTime, LPCWSTR endTime, LPCWSTR options);

	//��ϱ�����
	LONG wpf(LPCWSTR portfolioName, LPCWSTR viewName, LPCWSTR options, WindData& outWindData);

	//����ϴ�����
	LONG wupf(LPCWSTR portfolioName, LPCWSTR tradeDate, LPCWSTR windCodes, LPCWSTR quantity, LPCWSTR costPrice, LPCWSTR options, WindData& outWindData);

	//֤��ɸѡ����
	LONG weqs(LPCWSTR planName, LPCWSTR options, WindData& outWindData);

	//�����ա������ա������յ��������к���
	LONG tdays(LPCWSTR startTime, LPCWSTR endTime, LPCWSTR options, WindData& outWindData);

	//�����ա������ա������յ�����ƫ�Ƽ���
	LONG tdaysoffset(LPCWSTR startTime, LONG offset, LPCWSTR options, DATE& outDate);

	//�����ա������ա������յ�������������
	LONG tdayscount(LPCWSTR startTime, LPCWSTR endTime, LPCWSTR options, LONG& outCount);
	//////////////////////////////////////////////////////////////////////////

	//���׺���
	//////////////////////////////////////////////////////////////////////////
	//�����˺ŵ�½
	LONG tlogon(LPCWSTR brokerID, LPCWSTR departmentID, LPCWSTR accountID, LPCWSTR password, LPCWSTR accountType, LPCWSTR options, WindData& outWindData);

	//�����˺ŵǳ�����optionsΪ��¼ID����ʽ�磺"LogonID=1"
	LONG tlogout(LPCTSTR options);

	//�µ�
	LONG torder(LPCWSTR windCodes, LPCWSTR tradeSide, LPCWSTR orderPrice, LPCWSTR orderVolume, LPCWSTR options, WindData& outWindData);

	//ƽ��
	LONG tcovered(LPCWSTR windCodes, LPCWSTR tradeSide, LPCWSTR orderVolume, LPCWSTR options, WindData& outWindData);

	//����
	LONG tcancel(LPCWSTR orderNumber, LPCWSTR options);

	//���������ѯ
	LONG tquery(LPCWSTR qryCode, LPCWSTR options, WindData& outWindData);
	//////////////////////////////////////////////////////////////////////////

	//�ز⺯��
	//////////////////////////////////////////////////////////////////////////
	//�ز⿪ʼ
	LONG bktstart(LPCWSTR strategyName, LPCWSTR startDate, LPCWSTR endDate, LPCWSTR options, WindData& outWindData);

	//�ز��ѯ
	LONG bktquery(LPCWSTR qrycode, LPCWSTR qrytime, LPCWSTR options, WindData& outWindData);

	//�ز��µ�
	LONG bktorder(LPCWSTR tradeTime, LPCWSTR securityCode, LPCWSTR tradeSide, LPCWSTR tradeVol, LPCWSTR options, WindData& outWindData);

	//�ز����
	LONG bktend(LPCWSTR options, WindData& outWindData);

	//�鿴�ز�״̬
	LONG bktstatus(LPCWSTR options, WindData& outWindData);

	//�ز��Ҫ
	LONG bktsummary(LPCWSTR bktID, LPCWSTR view, LPCWSTR options, WindData& outWindData);

	//�ز�ɾ��
	LONG bktdelete(LPCWSTR bktID, LPCWSTR options, WindData& outWindData);

	//���ز����б�
	LONG bktstrategy(LPCWSTR options, WindData& outWindData);

	//////////////////////////////////////////////////////////////////////////
	~WindCppAPIImp();
private:
	WindCppAPIImp();
	

	BOOL initialize();
	VOID release();
public:
	static VOID InitWindData(WindData& windData);
	static VOID ClearWindData(WindData& windData);
	static VOID EmptyWindData(WindData& windData);

private:

	WindDataCOMLib::_DWindDataCOMPtr	m_pDWindData;
	WindDataComSink*					m_pSink;
	DWORD								m_dwAdvise;
};

#endif