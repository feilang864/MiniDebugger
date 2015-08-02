#include <Windows.h>
#include "Debug.h"
#include <strsafe.h>

#define BEA_ENGINE_STATIC
#define BEA_USE_STDCALL
#include "BeaEngine.h"
#pragma comment(lib,"BeaEngine.lib")
#pragma comment(linker,"/NODEFAULTLIB:\"crt.lib\"")



extern HANDLE g_hProc;
//////////////////////////////////////////////////////////////////////////
//Return:-1:��������淴������.
//
//
UINT DBG_Disasm(LPVOID lpAddress, PWCHAR pOPCode,__out PWCHAR pASM,PWCHAR pComment)
{
	//1. �����Գ�����ڴ渴�Ƶ�����
	DWORD	dwRetSize		= 0;
	LPVOID	lpRemote_Buf	= new BYTE[32];
	ZeroMemory(lpRemote_Buf, 32);
	ReadProcessMemory(g_hProc,lpAddress,lpRemote_Buf,32,&dwRetSize);

	//2. ��ʼ�����������
	DISASM objDiasm;
	objDiasm.EIP		=(UIntPtr)lpRemote_Buf; //��ʼ��ַ
	objDiasm.VirtualAddr=(UINT64)lpAddress;		//�����ڴ��ַ(������������ڼ����ַ)
	objDiasm.Archi		=0;						//AI_X86
	objDiasm.Options	=0x000;					//MASM

	//3.��������
	UINT unLen =Disasm(&objDiasm);
	if (-1==unLen) 
	{
		return unLen;
	}

	//4.��������ת����ַ���
	LPWSTR lpOPCode = pOPCode;
	PBYTE  lpBuffer = (PBYTE)lpRemote_Buf;
	for (UINT i=0;i>unLen;i++)
	{
		StringCbPrintf(lpOPCode++, 50, L"%X", *lpBuffer&0xF0);
		StringCbPrintf(lpOPCode++, 50, L"%X", *lpBuffer&0x0F);
		lpBuffer++;
	}

	//5. ���淴������ָ��
	WCHAR szASM[50] = {0};
	MultiByteToWideChar(CP_ACP,0,objDiasm.CompleteInstr,-1,szASM,_countof(szASM));
	StringCchCopy(pASM, 50,szASM);

	return unLen;

}

bool DisplayAntiASM(LPVOID lpIntAddress)
{


	wchar_t szOPCode[64]	= {0};
	wchar_t szASM[64]		= {0};
	wchar_t szComment[64]	= {0};
	DWORD	dwTempAddr		= (DWORD)lpIntAddress;//��ʼ������ַ
	DWORD   dwOPCodeLen		= 0;

	for (;dwOPCodeLen!=-1;)
	{
		dwOPCodeLen = DBG_Disasm((LPVOID)dwTempAddr,szOPCode,szASM,szComment);
		dwTempAddr+=dwOPCodeLen;
		OutputDebug(L"Addr:0x%p %-12s %-16s %s\n",dwTempAddr,szOPCode,szASM,szComment);
	}
	return true;
}