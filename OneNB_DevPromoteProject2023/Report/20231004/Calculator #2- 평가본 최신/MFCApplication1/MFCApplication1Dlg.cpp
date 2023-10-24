#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <iostream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



#define plus 1
#define minus 2
#define multiply 3
#define divide 4


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.



protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()




CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)

	, m_result(_T(""))
	, m_recode(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}



void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	int a;
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	CString sMsg;
	a = m_result.GetLength();
	//m_result.Replace(_T(","), _T(""));
	//m_result.Replace(_T("."), _T(""));
	//m_result.Replace(_T("-"), _T(""));

	if (a <= 21)
	{

		DDX_Text(pDX, IDC_RESULT_DISPLAY, m_result);
		m_result.Replace(_T(","), _T(""));
		
	}
	else
	{
		GetDlgItem(IDC_BTN_0)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_4)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_9)->EnableWindow(FALSE);

	}
========
	a = m_result.GetLength();
	if (a < 16)
	{
		
		DDX_Text(pDX, IDC_RESULT_DISPLAY, m_result);

	}
	m_result.Replace(_T(","), _T(""));
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp


	DDX_Text(pDX, IDC_CALC, m_recode);

}



BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_0, &CMFCApplication1Dlg::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTN_1, &CMFCApplication1Dlg::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN_2, &CMFCApplication1Dlg::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN_3, &CMFCApplication1Dlg::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN_4, &CMFCApplication1Dlg::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN_5, &CMFCApplication1Dlg::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN_6, &CMFCApplication1Dlg::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN_7, &CMFCApplication1Dlg::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN_8, &CMFCApplication1Dlg::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN_9, &CMFCApplication1Dlg::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN_PLUS, &CMFCApplication1Dlg::OnBnClickedBtnPlus)
	ON_BN_CLICKED(IDC_BTN_MINUS, &CMFCApplication1Dlg::OnBnClickedBtnMinus)
	ON_BN_CLICKED(IDC_BTN_EQUAL, &CMFCApplication1Dlg::OnBnClickedBtnEqual)
	ON_BN_CLICKED(IDC_BTN_C, &CMFCApplication1Dlg::OnBnClickedBtnC)
	ON_BN_CLICKED(IDC_BTN_BC, &CMFCApplication1Dlg::OnBnClickedBtnBc)
	ON_BN_CLICKED(IDC_BTN_CHS, &CMFCApplication1Dlg::OnBnClickedBtnChs)
	ON_BN_CLICKED(IDC_BTN_DIV, &CMFCApplication1Dlg::OnBnClickedBtnDiv)
	ON_BN_CLICKED(IDC_BTN_MUL, &CMFCApplication1Dlg::OnBnClickedBtnMul)
	ON_BN_CLICKED(IDC_BTN_DOT, &CMFCApplication1Dlg::OnBnClickedBtnDot)
END_MESSAGE_MAP()



BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CFont font;
	font.CreatePointFont(320, L"D2Coding");
	GetDlgItem(IDC_RESULT_DISPLAY)->SetFont(&font);
	font.Detach();

	font.CreatePointFont(150, L"D2Coding");
	GetDlgItem(IDC_CALC)->SetFont(&font);
	font.Detach();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





//버튼 0 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn0()
{
	if (m_result == "" || (m_result != "0" && m_result != "-"))
	{
		CString sMsg;
		if (m_equalClk) {
			m_result.Empty();
			m_equalClk = false;
		}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
		m_result += _T("0");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(m_result);
========
		if (_tstof(m_result) < LLONG_MAX)
		{
			m_result += _T("0");
			m_result.Replace(_T(","), _T(""));
			m_result = Comma(_wtof(m_result));
		}



>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
		UpdateData(false);
	}
}

//버튼 1 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn1()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp

	m_result += _T("1");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
========
	if (_tstof(m_result) < LONG_MAX)
	{
		m_result += _T("1");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
	}

	UpdateData(false);

>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp

		UpdateData(false);
}

//버튼 2 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn2()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
========
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("2");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
	}
	UpdateData(false);
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp

	m_result += _T("2");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
	UpdateData(false);
}

//버튼 3 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn3()
{

	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
========
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("3");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
	}
	UpdateData(false);
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp

	m_result += _T("3");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
	UpdateData(false);
}

//버튼 4 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn4()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp

	m_result += _T("4");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
========
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("4");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
	}


>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	UpdateData(false);

}

//버튼 5 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn5()
{
	CString sMsg;

	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}

<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	m_result += _T("5");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
========
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("5");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
	}


>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	UpdateData(false);

}

//버튼 6 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn6()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp

	m_result += _T("6");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
========
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("6");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
	}

>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	UpdateData(false);

}

//버튼 7 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn7()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp

	m_result += _T("7");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
========
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("7");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
	}
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	UpdateData(false);

}

//버튼 8 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn8()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
========
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("8");
		printf("m_result : %f\n", _tstof(m_result));
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));

	}
	UpdateData(false);
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp

		m_result += _T("8");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(m_result);
		UpdateData(false);
}

//버튼 9 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn9()
{
	CString result, sMsg;
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp

	}

		m_result += _T("9");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(m_result);
		UpdateData(false);
========
	}
	if (_tstof(m_result) < LLONG_MAX)
	{

		m_result += _T("9");
		sMsg.Format(_T("m_result1 : %s\n"), m_result);/////////////////////////////////
		OutputDebugString(sMsg);//////////////////////////////////////////////////////
		m_result.Replace(_T(","), _T(""));

		sMsg.Format(_T("m_result1 : %s\n"), m_result);/////////////////////////////////
		OutputDebugString(sMsg);//////////////////////////////////////////////////////
		m_result = Comma(_wtof(m_result));

		sMsg.Format(_T("m_result1 : %s\n"), m_result);/////////////////////////////////
		OutputDebugString(sMsg);//////////////////////////////////////////////////////
	}

	UpdateData(false);


>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
}

//버튼 + 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnPlus()
{
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	m_type = plus;

	m_num = m_result;
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "+");
	m_result.Empty();

	m_equalClk = true;
	UpdateData(true);


========
	CString sMsg;

	m_type = plus;
	m_result.Replace(_T(","), _T(""));
	m_num = m_result;
	Calc();
	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	m_result = Comma(_wtof(m_result));
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_num + "+");
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp


	m_equalClk = true;
	UpdateData(true);
	//sMsg.Format(_T("+9 : %s\n"), m_result);/////////////////////////////////
	//OutputDebugString(sMsg);//////////////////////////////////////////////////////
	//sMsg.Format(_T("=================================%s\n"), m_result);/////////////////////////////////
	//OutputDebugString(sMsg);//////////////////////////////////////////////////////
}

//버튼 - 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnMinus()
{


<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
========

>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	m_type = minus;
	m_result.Replace(_T(","), _T(""));
	m_num = m_result;
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
========
	Calc();
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	m_result = Comma(_wtof(m_result));
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_num + "+");

	UpdateData(true);


}

//버튼 / 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnDiv()
{


	m_type = divide;
	m_num = m_result;
	Calc();

	m_result.Replace(_T(","), _T(""));
	m_result = Comma(_wtof(m_result));
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "/");
	m_result.TrimRight(L"0");
	m_result.TrimRight(L".");
	m_equalClk = true;
	UpdateData(true);

<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp

}

//버튼 / 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnDiv()
{



	m_type = divide;
	m_num = m_result;
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "÷");
	m_equalClk = true;
	UpdateData(true);


========
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
}

//버튼 * 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnMul()
{
	m_type = multiply;
	m_num = m_result;
	m_result.Replace(_T(","), _T(""));
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	m_result = Comma(m_result);
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
========
	m_result = Comma(_wtof(m_result));
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	Calc();
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "*");
	m_equalClk = true;
	UpdateData(true);
}

//버튼 = 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnEqual()
{
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	double op1, op2, result;
	op1 = _tstof(m_num);
	op2 = _tstof(m_result);
========
	CString sMsg;
	double op1, op2, result;
	op1, op2, result = 0;
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp


	switch (m_type)
	{
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	case plus:
		result = op1 + op2;
		break;
	case minus:
		result = op1 - op2;
		break;
	case multiply:
		result = op1 * op2;
		break;
	case divide:
		if (op2 != 0) {
			result = op1 / op2;
		}
		else result = atof("0");
		break;
	default:
		result = 0;
		break;
========

		op1 = _tstof(m_num);
		op2 = _tstof(m_result);

		switch (m_type)
		{
		case plus:
			result = op1 + op2;
			break;
		case minus:
			result = op1 - op2;
			break;
		case multiply:
			result = op1 * op2;
			break;
		case divide:
			if (op2 != 0) {
				result = op1 / op2;
			}
			else result = atof("0");
			break;
		default:
			break;

		}

		m_result.Format(_T("%.6f"), result);
		m_result.TrimRight(L"0");
		m_result.TrimRight(L".");
		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));

		m_equalClk = true;
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
	}

	m_result.Format(_T("%f"), result);
	m_result.TrimRight(L"0");
	m_result.TrimRight(L".");
	m_num_two.Format(_T("%f"), op2);
	m_num_two.TrimRight(L"0");
	m_num_two.TrimRight(L".");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);



	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	UpdateData(FALSE);
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	SetDlgItemText(IDC_CALC, m_recode + m_num_two + "=");



========
	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "=");
	m_equalClk = true;
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp

}





//계산 함수 
void CMFCApplication1Dlg::Calc()
{
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	double op1, op2,op3, result;
	if (!m_num.IsEmpty() && !m_result.IsEmpty())
	{
		op1 = _tstof(m_num);
		op2 = _tstof(m_result);
		op3 = _tstof(m_num);
========
	double op1, op2, result;
	result = 0;

	if (!m_num.IsEmpty() && !m_result.IsEmpty())
	{

		op1 = _tstof(m_num);
		op2 = _tstof(m_result);

>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
		switch (m_type)
		{
		case plus:
			result = op1 + op2;
			break;
		case minus:
			result = op1 - op2;
			break;
		case multiply:
			result = op1 * op2;
			break;
		case divide:
			if (op2 != 0) {
				result = op1 / op2;
			}
			else result = atof("0");
			break;
		default:
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
			result = 0.0;
			break;

		}
	}
	m_result.Format(_T("%f"), result);
	m_result.TrimRight(L"0");
	m_result.TrimRight(L".");
	m_num_two.Format(_T("%f"), op2);
	m_num_two.TrimRight(L"0");
	m_num_two.TrimRight(L".");
	m_result.Replace(_T(","), _T(""));
	m_result = Comma(m_result);

	//m_type = 0;

	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	UpdateData(FALSE);
	SetDlgItemText(IDC_CALC, m_recode + m_num_two + "=");

	//m_equalClk = true;
========
			break;
		}

		m_result.Replace(_T(","), _T(""));
		m_result = Comma(_wtof(m_result));
		m_result.Format(_T("%.f"));
		m_result.TrimRight(L"0");
		m_result.TrimRight(L".");


		m_equalClk = true;
		UpdateData(true);

	}
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp


}
//버튼 C 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnC()
{
	m_recode.Empty();
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	m_result.Empty();
	UpdateData(false);
	GetDlgItem(IDC_BTN_1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_9)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_0)->EnableWindow(TRUE);

}
// dot 출력
void CMFCApplication1Dlg::OnBnClickedBtnDot()
{
	CString sMsg;
	if ((m_result != "." && m_result != ""))
	{	

		if (m_equalClk) {
			m_result.Empty();
			m_equalClk = false;
		}
		m_result = Comma(m_result);
		m_result += _T(".");
		UpdateData(false);
	}

========
	m_num.Empty();
	m_result.Empty();
	UpdateData(false);
}
// dot 출력
void CMFCApplication1Dlg::OnBnClickedBtnDot()
{
	if (m_result == "" || (m_result != "." && m_result != ""))
	{
		if (m_equalClk) {

			m_result.Empty();
			m_equalClk = false;
		}
		m_result += _T(".");

		UpdateData(false);

	}
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
}
//버튼 BC 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnBc()
{
	m_result.Delete(m_result.GetLength() - 1, 1);
	m_result = Comma(m_result);
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	GetDlgItem(IDC_BTN_1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_9)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_0)->EnableWindow(TRUE);


========
>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
}

//버튼 Chs 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnChs()
{
<<<<<<<< HEAD:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본 최신/MFCApplication1/MFCApplication1Dlg.cpp
	CString sMsg;
	double Chs = _tstof(m_result); /*= GetDlgItemInt(IDC_RESULT_DISPLAY);*/


	m_result.Format(L"%f", -1.0 * Chs);
	m_result.TrimRight(L"0");
	m_result.TrimRight(L".");
	m_result = Comma(m_result);
	UpdateData(false);
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);



//	sMsg.Format(_T("7 : %s\n"), m_result);/////////////////////////////////
//OutputDebugString(sMsg);//////////////////////////////////////////////////////
//	sMsg.Format(_T("=================================%s\n"), m_result);/////////////////////////////////
//OutputDebugString(sMsg);//////////////////////////////////////////////////////
}

CString CMFCApplication1Dlg::Comma(CString nData)
{
	CString sMsg;	
	CString str, strReturn = _T("");
	str = nData;
	str.Replace(_T(","), _T(""));
	int Dot1 = 0;// = str.GetLength() - str.Find(_T("."));
	


		for (int i = 0; i < str.GetLength(); i++)
		{

			if (str.Find(_T(".")) == -1)
			{
				Dot1 = str.GetLength();

			}
			else
			{
				Dot1 = str.Find(_T("."));

			}

				strReturn += str.GetAt(i);
				if (((Dot1 - i) != 1 && (Dot1 - i) % 3 == 1) && nData.Find(_T(".")) == -1)//str.GetLength()
					strReturn += ',';

		}
	
		return strReturn;
========
	double m_value_two = GetDlgItemInt(IDC_RESULT_DISPLAY);
	printf("m_result : %f\n", _tstof(m_result));////////////////////////

	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	printf("m_result : %f\n", _tstof(m_result));////////////////////////

	SetDlgItemText(IDC_CALC, m_result);

	m_result.Format(L"%.6f", -1 * m_value_two);
	printf("m_result : %f\n", _tstof(m_result));////////////////////////

	m_result.TrimRight(L"0");
	printf("m_result : %f\n", _tstof(m_result));////////////////////////

	m_result.TrimRight(L".");
	printf("m_result : %f\n", _tstof(m_result));////////////////////////

	UpdateData(false);

}

CString CMFCApplication1Dlg::Comma(double nData)
{
	CString str, strReturn = _T("");

	str.Format(_T("%.0f"), nData);

	for (int i = 0; i < str.GetLength(); i++)
	{
		strReturn += str.GetAt(i);
		if ((str.GetLength() - i) != 1 && (str.GetLength() - i) % 3 == 1)
			strReturn += ',';

	}

	return strReturn;

>>>>>>>> 920e8466072cc9cce14d527826e36bda05af2a0d:OneNB_DevPromoteProject2023/Report/20231004/Calculator #2- 평가본/MFCApplication1/MFCApplication1Dlg.cpp
}

