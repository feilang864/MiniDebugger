//�����߼�����UI�Ľӿ�.
#include <afx.h>
#include <Windows.h>
#include "Interface.h"

CString csCallFunctionName = "";
CString csCallArgv	= "";

//UI to Logic

/*
�����н���
*/
void CommandParsing(CString CommandText)
{
	int iBlackIndex=0;
	CString m_functionName="";
	CString m_argv="";

	iBlackIndex=CommandText.Find(L" ");
	if (-1==iBlackIndex)
	{
		m_functionName=CommandText;
	}
	else
	{
		m_functionName=CommandText.Left(iBlackIndex);
		m_argv=CommandText.Mid(iBlackIndex+1);
	}
	csCallFunctionName=m_functionName;
	csCallArgv=m_argv;

	return;

}

//�����Ҫִ�еĺ���
void AutoAnalysisCommandParsing()
{

	//�ȶԺ�����,���ִ�д���,���ô�����.����UI�˼��.

	if (L"bp"==csCallFunctionName)
	{
		//int3�ϵ�,��������Ϊ��
		if(""==csCallArgv)
		{
			return;
		}
		//�ȶ�������



	}
	else
	{

	}













	//�������Ͳ���
	csCallFunctionName	= "";
	csCallArgv			= "";

	return;
}





//Logic to UI


/*
�Դ�����ַ������и�ʽ������,ת�����UI����
DWORD dwCode:��ʶ��ӡ��ʽ����Ҫ���ӵ���Դ��
*/
bool Printf2UI(CString stPrint,DWORD dwCode)
{
	switch (dwCode)
	{
	case MINIF_DEBUG_STRING:
		{

		}




	default:
		break;
	};

	return true;
}









