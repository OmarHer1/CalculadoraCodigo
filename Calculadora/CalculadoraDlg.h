
// CalculadoraDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CCalculadoraDlg
class CCalculadoraDlg : public CDialogEx
{
// Construcción
public:
	CCalculadoraDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULADORA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDivButton();
	CString m_resultado;
	int m_resultado_ent;
	afx_msg void OnBnClicked0Button();
	afx_msg void OnBnClicked1Button();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnBnClicked3Button();
	afx_msg void OnBnClicked4Button();
	afx_msg void OnBnClicked5Button();
	afx_msg void OnBnClicked6Button();
	afx_msg void OnBnClicked7Button();
	afx_msg void OnBnClicked8Button();
	afx_msg void OnBnClicked9Button();
	afx_msg void OnBnClickedSumaButton();
	afx_msg void OnBnClickedRestaButton();
	afx_msg void OnBnClickedMultButton();
	afx_msg void OnBnClickedDiviButton();
	afx_msg void OnBnClickedIgualButton();
	afx_msg void OnBnClickedClearButton();
	BOOL m_binario;
	BOOL m_decimal;
	BOOL m_hexadecimal;
	afx_msg void OnBnClickedBinCheck();
	afx_msg void OnBnClickedAButton();
	afx_msg void OnBnClickedBButton();
	afx_msg void OnBnClickedCButton();
	afx_msg void OnBnClickedDButton();
	afx_msg void OnBnClickedEButton();
	afx_msg void OnBnClickedFButton();
	afx_msg void OnBnClickedDecCheck();
	afx_msg void OnBnClickedHexCheck();
	DECLARE_EVENTSINK_MAP()
	void OnStrokeInkpicture3(LPDISPATCH Cursor, LPDISPATCH Stroke, BOOL* Cancel);
};
