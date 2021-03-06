
// P2015305069Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "P2015305069.h"
#include "P2015305069Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBmpDefault();
//	afx_msg void OnBmpWhale();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_COMMAND(ID_BMP_DEFAULT, &CAboutDlg::OnBmpDefault)
//	ON_COMMAND(ID_BMP_WHALE, &CAboutDlg::OnBmpWhale)
END_MESSAGE_MAP()


// CP2015305069Dlg 대화 상자



CP2015305069Dlg::CP2015305069Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_P2015305069_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CP2015305069Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CP2015305069Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_BMP_DEFAULT, &CP2015305069Dlg::OnBmpDefault)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CP2015305069Dlg::OnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_HINT, &CP2015305069Dlg::OnClickedButtonHint)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_START, &CP2015305069Dlg::OnClickedButtonStart)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_BMP_FOREST, &CP2015305069Dlg::OnBmpForest)
	ON_COMMAND(ID_BMP_ISLAND, &CP2015305069Dlg::OnBmpIsland)
	ON_COMMAND(ID_TIME_EASY, &CP2015305069Dlg::OnTimeEasy)
	ON_COMMAND(ID_TIME_HARD, &CP2015305069Dlg::OnTimeHard)
	ON_COMMAND(ID_TIME_NORMAL, &CP2015305069Dlg::OnTimeNormal)
	ON_COMMAND(ID_TIME_VERYHARD, &CP2015305069Dlg::OnTimeVeryhard)
	ON_COMMAND(ID_PRACTICE_EASY, &CP2015305069Dlg::OnPracticeEasy)
	ON_COMMAND(ID_PRACTICE_HARD, &CP2015305069Dlg::OnPracticeHard)
	ON_COMMAND(ID_PRACTICE_NORMAL, &CP2015305069Dlg::OnPracticeNormal)
END_MESSAGE_MAP()


// CP2015305069Dlg 메시지 처리기

BOOL CP2015305069Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_bStart = FALSE;
	SelectBitmap = 0;
	SelectDifficulty = 0;
	PuzzleSize = 3;
	Click_Number = 0;
	OnInitPuzzle();

	m_Bitmap[0].LoadBitmapW(IDB_BITMAP1);
	m_Bitmap[1].LoadBitmapW(IDB_BITMAP2);
	m_Bitmap[2].LoadBitmapW(IDB_BITMAP3);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CP2015305069Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CP2015305069Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	if (m_bStart == FALSE)
		DrawBmp();
	else {
		DrawRectangle();
		for (int y = 0; y < PuzzleSize; y++) {
			for (int x = 0; x < PuzzleSize; x++) {
				DrawPuzzle(y, x, m_Puzzle[y][x]);
			}
		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CP2015305069Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CP2015305069Dlg::OnBmpDefault()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("퍼즐그림 변경 시 진행하던 게임이 종료됩니다.\n정말로 퍼즐그림을 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectBitmap = 0;
			m_bStart = FALSE;
			Invalidate();
		}
	}
	else {
		SelectBitmap = 0;
		m_bStart = FALSE;
		Invalidate();
	}
}

void CP2015305069Dlg::OnBmpForest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("퍼즐그림 변경 시 진행하던 게임이 종료됩니다.\n정말로 퍼즐그림을 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectBitmap = 1;
			m_bStart = FALSE;
			Invalidate();
		}
	}
	else {
		SelectBitmap = 1;
		m_bStart = FALSE;
		Invalidate();
	}
}

void CP2015305069Dlg::OnBmpIsland()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("퍼즐그림 변경 시 진행하던 게임이 종료됩니다.\n정말로 퍼즐그림을 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectBitmap = 2;
			m_bStart = FALSE;
			Invalidate();
		}
	}
	else {
		SelectBitmap = 2;
		m_bStart = FALSE;
		Invalidate();
	}
}

void CP2015305069Dlg::OnPracticeEasy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("난이도 변경 시 진행하던 게임이 종료됩니다.\n정말로 난이도를 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectDifficulty = 0;
			m_bStart = FALSE;
			PuzzleSize = 3;
			OnInitPuzzle();
			Invalidate();
		}
	}
	else {
		SelectDifficulty = 0;
		m_bStart = FALSE;
		PuzzleSize = 3;
		OnInitPuzzle();
		Invalidate();
	}
}

void CP2015305069Dlg::OnPracticeNormal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("난이도 변경 시 진행하던 게임이 종료됩니다.\n정말로 난이도를 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectDifficulty = 0;
			m_bStart = FALSE;
			PuzzleSize = 4;
			OnInitPuzzle();
			Invalidate();
		}
	}
	else {
		SelectDifficulty = 0;
		m_bStart = FALSE;
		PuzzleSize = 4;
		OnInitPuzzle();
		Invalidate();
	}
}

void CP2015305069Dlg::OnPracticeHard()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("난이도 변경 시 진행하던 게임이 종료됩니다.\n정말로 난이도를 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectDifficulty = 0;
			m_bStart = FALSE;
			PuzzleSize = 5;
			OnInitPuzzle();
			Invalidate();
		}
	}
	else {
		SelectDifficulty = 0;
		m_bStart = FALSE;
		PuzzleSize = 5;
		OnInitPuzzle();
		Invalidate();
	}
}

void CP2015305069Dlg::OnTimeEasy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("난이도 변경 시 진행하던 게임이 종료됩니다.\n정말로 난이도를 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectDifficulty = 1;
			m_bStart = FALSE;
			PuzzleSize = 3;
			OnInitPuzzle();
			Invalidate();
		}
	}
	else {
		SelectDifficulty = 1;
		m_bStart = FALSE;
		PuzzleSize = 3;
		OnInitPuzzle();
		Invalidate();
	}
}

void CP2015305069Dlg::OnTimeNormal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("난이도 변경 시 진행하던 게임이 종료됩니다.\n정말로 난이도를 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectDifficulty = 2;
			m_bStart = FALSE;
			PuzzleSize = 4;
			OnInitPuzzle();
			Invalidate();
		}
	}
	else {
		SelectDifficulty = 2;
		m_bStart = FALSE;
		PuzzleSize = 4;
		OnInitPuzzle();
		Invalidate();
	}
}

void CP2015305069Dlg::OnTimeHard()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.	if (m_bStart == TRUE)
	int iResults;
	iResults = AfxMessageBox(_T("난이도 변경 시 진행하던 게임이 종료됩니다.\n정말로 난이도를 변경하시겠습니까?"), MB_YESNO);
	if (iResults == IDYES) {
		SelectDifficulty = 3;
		m_bStart = FALSE;
		PuzzleSize = 4;
		OnInitPuzzle();
		Invalidate();
	}

	else {
		SelectDifficulty = 3;
		m_bStart = FALSE;
		PuzzleSize = 4;
		OnInitPuzzle();
		Invalidate();
	}
}

void CP2015305069Dlg::OnTimeVeryhard()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("난이도 변경 시 진행하던 게임이 종료됩니다.\n정말로 난이도를 변경하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			SelectDifficulty = 4;
			m_bStart = FALSE;
			PuzzleSize = 5;
			OnInitPuzzle();
			Invalidate();
		}
	}
	else {
		SelectDifficulty = 4;
		m_bStart = FALSE;
		PuzzleSize = 5;
		OnInitPuzzle();
		Invalidate();
	}
}

void CP2015305069Dlg::OnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}

void CP2015305069Dlg::OnClickedButtonHint()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);
	if (m_bStart == TRUE) {
		if (SelectDifficulty < 3) {
			CDC memDC;

			memDC.CreateCompatibleDC(&dc);
			CBitmap *oldBitPuzz = memDC.SelectObject(&m_Bitmap[SelectBitmap]);
			dc.StretchBlt(420, 20, 175, 175, &memDC, 0, 0, 300, 300, SRCCOPY);
			memDC.SelectObject(oldBitPuzz);
		}
		else {
			dc.SetBkColor(RGB(255, 255, 255));
			dc.TextOut(420, 95, _T("고급 난이도 이상인 경우"));
			dc.TextOutW(420, 115, _T("힌트를 보실 수 없습니다."));
		}
	}
	else {
		dc.TextOut(420, 95, _T("시작 버튼을 눌러주세요~~!!!"));
	}
}

void CP2015305069Dlg::OnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bStart == TRUE) {
		int iResults;
		iResults = AfxMessageBox(_T("정말로 다시 시작하시겠습니까?"), MB_YESNO);
		if (iResults == IDYES) {
			CString strtime = _T("0 분 0 초");
			CString strclick = _T("0 회");
			GetDlgItem(IDC_STATIC_TIME)->SetWindowText((LPCTSTR)strtime);
			GetDlgItem(IDC_STATIC_CLICK)->SetWindowText((LPCTSTR)strclick);
			m_bStart = TRUE;
			Click_Number = 0;
			htimer = SetTimer(1, 1000, NULL);
			StartTime = CTime::GetCurrentTime();
			Invalidate();
			DrawRectangle();
			MixPuzzle();
		}
	}
	else {
		CString strtime = _T("0 분 0 초");
		CString strclick = _T("0 회");
		GetDlgItem(IDC_STATIC_TIME)->SetWindowText((LPCTSTR)strtime);
		GetDlgItem(IDC_STATIC_CLICK)->SetWindowText((LPCTSTR)strclick);
		m_bStart = TRUE;
		Click_Number = 0;
		htimer = SetTimer(1, 1000, NULL);
		StartTime = CTime::GetCurrentTime();
		Invalidate();
		DrawRectangle();
		MixPuzzle();
	}
}

void CP2015305069Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bStart == TRUE) {
		CTime tmpTime = CTime::GetCurrentTime();
		PlayTime = tmpTime - StartTime;
		CString time;
		time.Format(_T("%d 분 %d 초"), PlayTime.GetMinutes(), PlayTime.GetSeconds());
		GetDlgItem(IDC_STATIC_TIME)->SetWindowText((LPCTSTR)time);
		if ((SelectDifficulty == 1) || (SelectDifficulty == 3)) {
			if (PlayTime.GetMinutes() >= 5) {
				m_bStart = FALSE;
				MessageBox(_T("제한시간이 지났습니다.\n타임어택에 실패하셨습니다."), _T("실패 ㅠㅠ"));
			}
		}
		else if ((SelectDifficulty == 2) || (SelectDifficulty == 4)) {
			if (PlayTime.GetMinutes() >= 7) {
				m_bStart = FALSE;
				MessageBox(_T("제한시간이 지났습니다.\n타임어택에 실패하셨습니다."), _T("실패 ㅠㅠ"));
			}
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CP2015305069Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int MouseY = 0, MouseX = 0;
	int nZeroY = 0, nZeroX = 0;

	if (m_bStart == TRUE) {
		if (PosToIndex(point, MouseY, MouseX)) {
			if (IsSameLine(MouseY, MouseX, nZeroY, nZeroX)) {
				MovePuzzle(MouseY, MouseX, nZeroY, nZeroX);
				Click_Number++;
				CString str;
				str.Format(_T("%d 회"), Click_Number);
				GetDlgItem(IDC_STATIC_CLICK)->SetWindowText((LPCTSTR)str);
				if (CheckPuzzle()) {
					m_bStart = FALSE;
					CString strResult;
					CString strDifficulty;
					if (SelectDifficulty == 0)
						strDifficulty = _T("연습모드 클리어~~!!!");
					if (SelectDifficulty == 1)
						strDifficulty = _T("타임어택(초급모드) 클리어~~!!!");
					if (SelectDifficulty == 2)
						strDifficulty = _T("타임어택(중급모드) 클리어~~!!!");
					if (SelectDifficulty == 3)
						strDifficulty = _T("타임어택(고급모드) 클리어~~!!!");
					if (SelectDifficulty == 4)
						strDifficulty = _T("타임어택(초고급모드) 클리어~~!!!");
					strResult.Format(_T("퍼즐 맞추기 성공!\n경과시간 : %d분 %d초\n클릭수 : %d"), PlayTime.GetMinutes(), PlayTime.GetSeconds(), Click_Number);
					MessageBox(strResult, strDifficulty, NULL);
					Invalidate();
				}
			}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CP2015305069Dlg::DrawBmp() {
	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC(&dc);
	CBitmap *oldBitPuzz = memDC.SelectObject(&m_Bitmap[SelectBitmap]);
	dc.StretchBlt(40, 20, 300, 300, &memDC, 0, 0, 300, 300, SRCCOPY);
	memDC.SelectObject(oldBitPuzz);
}

void CP2015305069Dlg::OnInitPuzzle() {
	int Count = 0;
	for (int y = 0; y < PuzzleSize; y++) {
		for (int x = 0; x < PuzzleSize; x++) {
			m_Puzzle[y][x] = Count++;
		}
	}
	m_Puzzle[PuzzleSize-1][PuzzleSize-1] = -1;
}

void CP2015305069Dlg::MixPuzzle() {
	srand((unsigned)time(NULL));

	int RandY, RandX;
	int y, x;
	BOOL bBool = FALSE;

	for (int i = 0; i < 100; i++) {
		RandY = rand() % PuzzleSize;
		RandX = rand() % PuzzleSize;

		bBool = IsSameLine(RandY, RandX, y, x);
		if (bBool)
			MovePuzzle(RandY, RandX, y, x);
	}
}

bool CP2015305069Dlg::IsSameLine(int MouseY, int MouseX, int &ZeroY, int &ZeroX) {
	for (int i = 0; i < PuzzleSize; i++) {
		if (-1 == m_Puzzle[i][MouseX]) {
			ZeroY = i;
			ZeroX = MouseX;
			return TRUE;
		}
	}

	for (int i = 0; i < PuzzleSize; i++) {
		if (-1 == m_Puzzle[MouseY][i]) {
			ZeroY = MouseY;
			ZeroX = i;
			return TRUE;
		}
	}
	return FALSE;
}

void CP2015305069Dlg::MovePuzzle(int MouseY, int MouseX, int &ZeroY, int &ZeroX) {
	int Y = MouseY - ZeroY;
	int X = MouseX - ZeroX;

	if (Y > 0) {
		for (int i = ZeroY; i < MouseY; i++) {
			m_Puzzle[i][MouseX] = m_Puzzle[i + 1][MouseX];
			DrawPuzzle(i, MouseX, m_Puzzle[i + 1][MouseX]);
		}
	}
	if (Y < 0) {
		for (int i = ZeroY; i > MouseY; i--) {
			m_Puzzle[i][MouseX] = m_Puzzle[i - 1][MouseX];
			DrawPuzzle(i, MouseX, m_Puzzle[i - 1][MouseX]);
		}
	}
	if (X > 0) {
		for (int i = ZeroX; i < MouseX; i++) {
			m_Puzzle[MouseY][i] = m_Puzzle[MouseY][i + 1];
			DrawPuzzle(MouseY, i, m_Puzzle[MouseY][i + 1]);
		}
	}
	if (X < 0) {
		for (int i = ZeroX; i > MouseX; i--) {
			m_Puzzle[MouseY][i] = m_Puzzle[MouseY][i - 1];
			DrawPuzzle(MouseY, i, m_Puzzle[MouseY][i - 1]);
		}
	}

	m_Puzzle[MouseY][MouseX] = -1;
	DrawZero(MouseY, MouseX);
}

void CP2015305069Dlg::DrawPuzzle(int Row, int Col, int nNum) {
	int nSize = 300 / PuzzleSize;
	if (nNum == -1)
		DrawZero(Row, Col);
	int nX = int(nNum % PuzzleSize);
	int nY = int(nNum / PuzzleSize);

	CClientDC dc(this);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap *oldBitPuzz = memDC.SelectObject(&m_Bitmap[SelectBitmap]);

	dc.StretchBlt(40 + (Col*(nSize + 3)), 20 + (Row*(nSize + 3)), nSize, nSize, &memDC, nX*nSize, nY*nSize,nSize, nSize, SRCCOPY);
	memDC.SelectObject(oldBitPuzz);
}

void CP2015305069Dlg::DrawZero(int ZeroY, int ZeroX) {
	int nSize = 300 / PuzzleSize;

	CClientDC dc(this);
	CPen BlackPen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *oldBlackPen = dc.SelectObject(&BlackPen);
	CBrush WhiteBrush(RGB(255, 255, 255));
	CBrush *oldWhiteBrush = dc.SelectObject(&WhiteBrush);

	dc.Rectangle(40 + (ZeroX*(nSize + 3)),
		20 + (ZeroY*(nSize + 3)),
		40 + (ZeroX*(nSize + 3)) + nSize+1,
		20 + (ZeroY*(nSize + 3)) + nSize+1);

	dc.SelectObject(oldBlackPen);
	dc.SelectObject(oldWhiteBrush);
}

bool CP2015305069Dlg::PosToIndex(CPoint pos, int &nY, int &nX) {
	int y = 0, x = 0;
	int nSize = 300 / PuzzleSize;
	for (y = 0; y < PuzzleSize; y++) {
		if ((pos.y > 20 + y * nSize) && (pos.y < 20 + (y + 1) * nSize))
			break;
	}
	for (x = 0; x < PuzzleSize; x++) {
		if ((pos.x > 40 + x * nSize) && (pos.x < 40 + (x + 1) * nSize))
			break;
	}

	if (y == PuzzleSize || x == PuzzleSize)
		return FALSE;
	else {
		nY = y;
		nX = x;
		return TRUE;
	}
}

bool CP2015305069Dlg::CheckPuzzle() {
	for (int y = 0; y < PuzzleSize; y++) {
		for (int x = 0; x < PuzzleSize; x++) {
			if ((y == PuzzleSize -1) && (x == PuzzleSize-1)) {
				if (m_Puzzle[y][x] != -1)
					return FALSE;
			}
			else {
				if (m_Puzzle[y][x] != y * PuzzleSize + x)
					return FALSE;
			}
		}
	}
	return TRUE;
}

void CP2015305069Dlg::DrawRectangle() {
	CClientDC dc(this);
	int nSize = 300 / PuzzleSize;
	for (int i = 0; i < PuzzleSize; i++) {
		for (int j = 0; j < PuzzleSize; j++) {
			dc.Rectangle(39 + (i* (nSize + 3)), 19 + (j*(nSize + 3)), 39 + (i* (nSize + 3)) + nSize + 3, 19 + (j*(nSize + 3)) + nSize + 3);
		}
	}
}
