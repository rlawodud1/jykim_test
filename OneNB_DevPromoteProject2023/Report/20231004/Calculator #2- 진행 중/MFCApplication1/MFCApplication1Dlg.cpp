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

void CMFCApplication1Dlg::M_Operate(int m_value_two)
{
	
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULT_DISPLAY, m_result);
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
	font.CreatePointFont (320, L"D2Coding");
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
	//m_selectedOP = NONE;

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
		if (m_equalClk) {
			m_result.Empty();
			m_equalClk = false;
		}
		if (_tstof(m_result) < LLONG_MAX)
		{
			m_result += _T("0");
			printf("m_result : %f\n", _tstof(m_result));

		}



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
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("1");
		printf("m_result : %f\n", _tstof(m_result));
	}
	
	UpdateData(false);


}

//버튼 2 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn2()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("2");
		printf("m_result : %f\n", _tstof(m_result));

	}
	UpdateData(false);

}

//버튼 3 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn3()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("3");
		printf("m_result : %f\n", _tstof(m_result));
	}
	UpdateData(false);

}

//버튼 4 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn4()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("4");
		printf("m_result : %f\n", _tstof(m_result));
	}
	UpdateData(false);

}

//버튼 5 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn5()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}

	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("5");
		printf("m_result : %f\n", _tstof(m_result));
	}


	UpdateData(false);

}

//버튼 6 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn6()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("6");
		printf("m_result : %f\n", _tstof(m_result));
	}
	UpdateData(false);

}

//버튼 7 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn7()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("7");
		printf("m_result : %f\n", _tstof(m_result));
	}
	UpdateData(false);

}

//버튼 8 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn8()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("8");
		printf("m_result : %f\n", _tstof(m_result));

	}
	UpdateData(false);

}

//버튼 9 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtn9()
{
	if (m_equalClk) {
		m_result.Empty();
		m_equalClk = false;
	}
	if (_tstof(m_result) < LLONG_MAX)
	{
		m_result += _T("9");
		printf("m_result : %f\n", _tstof(m_result));
	}
	printf("m_result,comma : %f\n", _tstof(m_result));

	UpdateData(false);
}

//버튼 + 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnPlus()
{
	CString recodeStr;
	recodeStr.Format(m_result);

	double reclength = recodeStr.GetLength();

	if (m_result.IsEmpty() || (!m_result.IsEmpty() && (recodeStr[reclength - 1] == '+' )))
	{
		return; 
	}
	if (m_equalClk || recodeStr[reclength - 1] == '+') {
		m_equalClk = false; 
	}

	m_type = plus;
	m_num = m_result;
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	Calc();

	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "+");
	m_equalClk = true;
	UpdateData(true);

}

//버튼 - 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnMinus()
{
	CString recodeStr;
	recodeStr.Format(m_result);
	double reclength = recodeStr.GetLength();

	if (m_result.IsEmpty() || (!m_result.IsEmpty() && (recodeStr[reclength - 1] == '-' )))
	{
		return; 
	}
	if (m_equalClk || recodeStr[reclength - 1] == '+') {
		m_equalClk = false; 
	}

	m_type = minus;
	m_num = m_result;
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	Calc();

	m_result.Empty();
	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "-");

	m_equalClk = true;
	UpdateData(true);


}

//버튼 = 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnEqual()
{

	double op1, op2, result;
	if (!m_num.IsEmpty() && !m_result.IsEmpty())
	{		

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
				result = op1 / op2;
				break;
			default:
				break;

			}
		if (result == static_cast<int>(result) || result >= 1000000.0) {
			m_result.Format(_T("%d"), static_cast<int>(result));
			m_recode.Format(m_result,_T("%d""="), static_cast<int>(result));

			}

			else {
				CString resultStr;
				resultStr.Format(_T("%.f"), result); // 소수점 이하 6자리까지 출력
				int length = resultStr.GetLength();
				while (resultStr[length - 1] == '0') { //소수점 이하의 0을 제거 
					length--;
				}
				if (resultStr[length - 1] == '.') { //마지막 소수점 문자 제거 
					length--;
				}
				m_result = resultStr.Left(length);
				}
			m_equalClk = true;
	}
	m_type = 0;
	UpdateData(FALSE);

}

//버튼 C 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnC()
{
	m_recode.Empty();
	m_num.Empty();
	m_result.Empty();
	UpdateData(false);
}



//버튼 BC 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnBc()
{
	m_result.Delete(m_result.GetLength() - 1, 1);
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
}

//버튼 Chs 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnChs()
{
	double m_value_two = GetDlgItemInt(IDC_RESULT_DISPLAY);
	GetDlgItemText(IDC_RESULT_DISPLAY,m_result);
	SetDlgItemText(IDC_CALC, m_result);

	m_result.Format(L"%f", -1 * m_value_two);
	printf("m_result : %f\n", _tstof(m_result));////////////////////////

	UpdateData(false);

}

//Calc를 함수로 지정
void CMFCApplication1Dlg::Calc()
{
	double op1,op2,result;

	if (!m_num.IsEmpty() && !m_result.IsEmpty())
	{

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
			result = trunc(op1 / op2);
			break;
		default:
			break;
		}

		if (result == static_cast<double>(result) || result >= 1000000.0) {
			m_result.Format(_T("%d"), static_cast<double>(result));
			m_recode.Format(m_result,_T("%d""="), static_cast<double>(result));
		}
		else {
			CString resultStr;
			resultStr.Format(_T("%.6f"), result); // 소수점 이하 6자리까지 출력
			double length = resultStr.GetLength();
			while (resultStr[length - 1] == '0') { //소수점 이하의 0을 제거 
				length--;
			}
			if (resultStr[length - 1] == '.') { //마지막 소수점 문자 제거 
				length--;
			}
			m_result = resultStr.Left(length);
			



			m_equalClk = true;
		}
	}


}


//버튼 / 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnDiv()
{
	CString recodeStr;
	recodeStr.Format(m_result);
	double reclength = recodeStr.GetLength();

	if (m_result.IsEmpty() || (!m_result.IsEmpty() && (recodeStr[reclength - 1] == '/')))
	{
		return;
	}

	if (m_equalClk || recodeStr[reclength - 1] == '+') {
		m_equalClk = false;
	}

	m_type = divide;
	m_num = m_result;
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	Calc();

	m_result.Empty();

	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "/");
	m_equalClk = true;
	UpdateData(true);
}

//버튼 * 클릭 이벤트
void CMFCApplication1Dlg::OnBnClickedBtnMul()
{
	CString recodeStr;
	recodeStr.Format(m_result);
	double reclength = recodeStr.GetLength();

	if (m_result.IsEmpty() || (!m_result.IsEmpty() && (recodeStr[reclength - 1] == '-')))
	{
		return;
	}

	if (m_equalClk || recodeStr[reclength - 1] == '+') {
		m_equalClk = false;
	}


	m_type = multiply;
	m_num = m_result;
	SetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	Calc();

	m_result.Empty();

	GetDlgItemText(IDC_RESULT_DISPLAY, m_result);
	SetDlgItemText(IDC_CALC, m_result + "*");
	m_equalClk = true;
	UpdateData(true);
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
}



