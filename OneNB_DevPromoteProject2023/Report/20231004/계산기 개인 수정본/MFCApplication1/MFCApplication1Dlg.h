﻿
// MFCApplication1Dlg.h: 헤더 파일


#pragma once


// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);
	CFont R_font;
	CString m_num;
	CString m_recode;
	CString m_result;
	bool m_equalClk;
	int m_type;
	int result;
public:
	void M_Operate(int m_value_two);


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.



// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtnPlus();
	afx_msg void OnBnClickedBtnMinus();
	afx_msg void OnBnClickedBtnEqual();
	afx_msg void OnBnClickedBtnC();
	afx_msg void OnBnClickedBtnBc();
	afx_msg void OnBnClickedBtnChs();
};




