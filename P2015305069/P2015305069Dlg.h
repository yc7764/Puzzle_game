
// P2015305069Dlg.h: 헤더 파일
//

#pragma once


// CP2015305069Dlg 대화 상자
class CP2015305069Dlg : public CDialogEx
{
// 생성입니다.
public:
	CP2015305069Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	bool m_bStart;
	CBitmap m_Bitmap[3];
	int SelectBitmap;
	int SelectDifficulty;
	int Click_Number;
	int m_Puzzle[5][5];
	int PuzzleSize;
	UINT htimer;
	CTime StartTime;
	CTimeSpan PlayTime;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P2015305069_DIALOG };
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
	afx_msg void OnBmpDefault();
	afx_msg void OnBmpForest();
	afx_msg void OnBmpIsland();
//	afx_msg void OnDifficultyEasy();
//	afx_msg void OnDifficultyNormal();
//	afx_msg void OnDifficultyHard();
	afx_msg void OnClickedButtonExit();
	afx_msg void OnClickedButtonHint();
	afx_msg void OnClickedButtonStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void CP2015305069Dlg::DrawBmp();
	void CP2015305069Dlg::OnInitPuzzle();
	void CP2015305069Dlg::MixPuzzle();
	bool CP2015305069Dlg::IsSameLine(int MouseY, int MouseX, int &ZeroY, int &ZeroX);
	void CP2015305069Dlg::MovePuzzle(int MouseY, int MouseX, int &ZeroY, int &ZeroX);
	void CP2015305069Dlg::DrawZero(int nZeroY, int nZeroX);
	void CP2015305069Dlg::DrawPuzzle(int nRow, int nCol, int nNum);
	void CP2015305069Dlg::DrawRectangle();
	bool CP2015305069Dlg::PosToIndex(CPoint pos, int &nY, int &nX);
	bool CP2015305069Dlg::CheckPuzzle();
	afx_msg void OnTimeEasy();
	afx_msg void OnTimeHard();
	afx_msg void OnTimeNormal();
	afx_msg void OnTimeVeryhard();
	afx_msg void OnPracticeEasy();
	afx_msg void OnPracticeHard();
	afx_msg void OnPracticeNormal();
};
