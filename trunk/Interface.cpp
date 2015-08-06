//�����߼�����UI�Ľӿ�.
#include <afx.h>
#include <Windows.h>
#include "Interface.h"
#include "logic/DealEvent.h"
#include "logic/StartDebug.h"

CString csCallFunctionName = "";
CString csCallArgv	= "";
bool Breaking=false;
extern bool  Debugging;
bool bErrorCommandParsing = false;//�����н����Ƿ�������
extern DWORD dwAttachPID;//��ͼ����Ŀ����̵�PID
WCHAR *wcInputDebuggedPath;
extern bool	InputDebuggedPath;

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

//���������������,��λ
void BECP()
{
	bErrorCommandParsing=true;
	//���������Ͳ���
	csCallFunctionName	= "";
	csCallArgv			= "";
}

//�����Ҫִ�еĺ���
void AutoAnalysisCommandParsing()
{

	bErrorCommandParsing=false;
	//�ȶԺ�����,���ִ�д���,���ô�����.����UI�˼��.

	//�Ƿ��ڵ���״̬
	if (false==Debugging)
	{
		if (L"attach"==csCallFunctionName)
		{

			if(""==csCallArgv)
			{
				BECP();
				return;
			}
			//һ������dwAttachPID,�ͻᱻ�ȴ�״̬�ĳ���ѭ��������.����ǰ���Ǳ�����û���ڵ���״̬�Ż��ڴ�ѭ��.
			dwAttachPID= _wtoi(csCallArgv.GetBuffer(csCallArgv.GetLength()));
			

		}
		else if(L"load"==csCallFunctionName)
		{

			if(""==csCallArgv)
			{
				BECP();
				return;
			}
			InputDebuggedPath	=	true;//�����߳��Լ��Ḵλ�ñ�־.
			wcInputDebuggedPath = (WCHAR*)csCallArgv.GetBuffer(csCallArgv.GetLength());  


		}

		BECP();
		return ;

	}


	else

	{//�Ƿ����ж�״̬
		if (false==Breaking)
		{
			if(L"break"==csCallFunctionName)
			{

				if(""!=csCallArgv)
				{
					BECP();
					return;
				}
				BreakNow();
				

			}
			else if(L"kill"==csCallFunctionName)//�˺���������ntsd����ɱ����ʽ����������
			{

				if(""!=csCallArgv)
				{
					BECP();
					return;
				}
				KillDebuggedProcess();


			}
			else if(L"loveit"==csCallFunctionName)
			{

				if(""!=csCallArgv)
				{
					BECP();
					return;
				}

				LoveIt(true);//��ᵼ��ʲô�㶮��
				

			}
			BECP();
			return;

		}
		//�Ѿ��ж�
		else
		{
			if(L"bp"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}
				DWORD dwTempBp=0;
				dwTempBp=_wtoi(csCallArgv.GetBuffer(csCallArgv.GetLength()));

				WriteInt3((LPVOID)dwTempBp);

			}
			else if(L"bv"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}
				DWORD dwTempBv=0;
				dwTempBv=_wtoi(csCallArgv.GetBuffer(csCallArgv.GetLength()));

				WriteInt3((LPVOID)dwTempBv);


			}
			else if(L"bnv"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}

				DWORD dwTempBnv=0;
				dwTempBnv=_wtoi(csCallArgv.GetBuffer(csCallArgv.GetLength()));

				InvalidInt3(dwTempBnv);

			}
			else if(L"bc"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}

				DWORD dwTempBc=0;
				dwTempBc=_wtoi(csCallArgv.GetBuffer(csCallArgv.GetLength()));

				DeleteInt3(dwTempBc);


			}
			else if(L"bl"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}
				
				ListInt3();

			}
			//�������߳����
			else if(L"~*"==csCallFunctionName)
			{

				if(""!=csCallArgv)
				{
					BECP();
					return;
				}

				 ListThreads();

			}
			else if(L"~"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}
				DWORD dwTempCT=0;
				dwTempCT=_wtoi(csCallArgv.GetBuffer(csCallArgv.GetLength()));
				ChangeThread(dwTempCT);


			}
			else if(L"r"==csCallFunctionName)
			{

				if(""!=csCallArgv)
				{
					BECP();
					return;
				}



			}
			else if(L"ba"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}



			}
			else if(L"p"==csCallFunctionName)
			{

				if(""!=csCallArgv)
				{
					BECP();
					return;
				}



			}
			//�߳���ؽ�ֹ

			//�ڴ�ϵ���Ҫ˫����(��Χ)
			else if(L"bm"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}



			}
			//������int3�ϵ����
			else if(L"bp"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}



			}
			else if(L"bv"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}



			}
			else if(L"bnv"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}



			}
			else if(L"bc"==csCallFunctionName)
			{

				if(""==csCallArgv)
				{
					BECP();
					return;
				}



			}
			else if(L"bl"==csCallFunctionName)
			{

				if(""!=csCallArgv)
				{
					BECP();
					return;
				}



			}

			BECP();
			return;


		}
	}



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
			break;
		}
	case MINIF_ANTIASM:
		{
			break;
		}
	case MINIF_HARDWARE_BREAKPOINT:
		{
			break;
		}
	case MINIF_INT3:
		{
			break;
		}
	case MINIF_MODULE:
		{
			break;
		}
	case MINIF_REGISTER:
		{
			break;
		}
	case MINIF_SOFTWARE_BREAKPOINT:
		{
			break;
		}
	case MINIF_ERROR:
		{
			break;
		}
	case MINIF_WARMING:
		{
			break;
		}
	case MINIF_TIPS:
		{
			break;
		}
	case MINIF_LIST_THREADS:
		{
			break;
		}
	case MINIF_STEP_BY_STEP:
		{
			break;
		}


	default:
		break;
	};

	return true;
}








