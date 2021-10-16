// CalculadoraDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Calculadora.h"
#include "CalculadoraDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
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


// Cuadro de diálogo de CCalculadoraDlg



CCalculadoraDlg::CCalculadoraDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CALCULADORA_DIALOG, pParent)
	, m_resultado(_T(""))
	, m_resultado_ent(0)
	, m_binario(FALSE)
	, m_decimal(FALSE)
	, m_hexadecimal(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculadoraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULT_EDIT, m_resultado);
	DDX_Text(pDX, IDC_RESULT_STATIC, m_resultado_ent);
	DDX_Check(pDX, IDC_BIN_CHECK, m_binario);
	DDX_Check(pDX, IDC_DEC_CHECK, m_decimal);
	DDX_Check(pDX, IDC_HEX_CHECK, m_hexadecimal);
}

BEGIN_MESSAGE_MAP(CCalculadoraDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0_BUTTON, &CCalculadoraDlg::OnBnClicked0Button)
	ON_BN_CLICKED(IDC_1_BUTTON, &CCalculadoraDlg::OnBnClicked1Button)
	ON_BN_CLICKED(IDC_2_BUTTON, &CCalculadoraDlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_3_BUTTON, &CCalculadoraDlg::OnBnClicked3Button)
	ON_BN_CLICKED(IDC_4_BUTTON, &CCalculadoraDlg::OnBnClicked4Button)
	ON_BN_CLICKED(IDC_5_BUTTON, &CCalculadoraDlg::OnBnClicked5Button)
	ON_BN_CLICKED(IDC_6_BUTTON, &CCalculadoraDlg::OnBnClicked6Button)
	ON_BN_CLICKED(IDC_7_BUTTON, &CCalculadoraDlg::OnBnClicked7Button)
	ON_BN_CLICKED(IDC_8_BUTTON, &CCalculadoraDlg::OnBnClicked8Button)
	ON_BN_CLICKED(IDC_9_BUTTON, &CCalculadoraDlg::OnBnClicked9Button)
	ON_BN_CLICKED(IDC_SUMA_BUTTON, &CCalculadoraDlg::OnBnClickedSumaButton)
	ON_BN_CLICKED(IDC_RESTA_BUTTON, &CCalculadoraDlg::OnBnClickedRestaButton)
	ON_BN_CLICKED(IDC_MULT_BUTTON, &CCalculadoraDlg::OnBnClickedMultButton)
	ON_BN_CLICKED(IDC_DIVI_BUTTON, &CCalculadoraDlg::OnBnClickedDiviButton)
	ON_BN_CLICKED(IDC_IGUAL_BUTTON, &CCalculadoraDlg::OnBnClickedIgualButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CCalculadoraDlg::OnBnClickedClearButton)
	ON_BN_CLICKED(IDC_BIN_CHECK, &CCalculadoraDlg::OnBnClickedBinCheck)
	ON_BN_CLICKED(IDC_A_BUTTON, &CCalculadoraDlg::OnBnClickedAButton)
	ON_BN_CLICKED(IDC_B_BUTTON, &CCalculadoraDlg::OnBnClickedBButton)
	ON_BN_CLICKED(IDC_C_BUTTON, &CCalculadoraDlg::OnBnClickedCButton)
	ON_BN_CLICKED(IDC_D_BUTTON, &CCalculadoraDlg::OnBnClickedDButton)
	ON_BN_CLICKED(IDC_E_BUTTON, &CCalculadoraDlg::OnBnClickedEButton)
	ON_BN_CLICKED(IDC_F_BUTTON, &CCalculadoraDlg::OnBnClickedFButton)
	ON_BN_CLICKED(IDC_DEC_CHECK, &CCalculadoraDlg::OnBnClickedDecCheck)
	ON_BN_CLICKED(IDC_HEX_CHECK, &CCalculadoraDlg::OnBnClickedHexCheck)
END_MESSAGE_MAP()


// Controladores de mensajes de CCalculadoraDlg

BOOL CCalculadoraDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CCalculadoraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CCalculadoraDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CCalculadoraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//area para declarar las variables númericas y no númericas 
//que realizan operaciones y muestran resultados
int conteo; // almacena el numero(#) de clicks para un solo operador numerico
int op1; //backup del numero generado
int op2;  //entero que alamcena de forma local en cada función el resultado
int codigo_de_operacion;
//backuo de variables temporales
int op1Suma;
int op2Suma;
int resultadoSuma;
int A = 10;
int B = 11;
int C = 12;
int D = 13;
int E = 14;
int F = 15;


void CCalculadoraDlg::OnBnClicked0Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "0";
		m_resultado_ent = 0;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10;
		op1 = op2;
		m_resultado_ent = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}

	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked1Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "1";
		m_resultado_ent = 1;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 1;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked2Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "2";
		m_resultado_ent = 2;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 2;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked3Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "3";
		m_resultado_ent = 3;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 3;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked4Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "4";
		m_resultado_ent = 4;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 4;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked5Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "5";
		m_resultado_ent = 5;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 5;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked6Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "6";
		m_resultado_ent = 6;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 6;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked7Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "7";
		m_resultado_ent = 7;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 7;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked8Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "8";
		m_resultado_ent = 8;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 8;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClicked9Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "9";
		m_resultado_ent = 9;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + 9;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedSumaButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 1; // la suma = + es la opracion 1
	//backuo de variables temporales
	op1Suma = op1;
	op2Suma = op2;
	resultadoSuma = m_resultado_ent;
	//borrado de variables 
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_ent = 0;

	CString MyCadena;
	MyCadena.Format(L"%d +", resultadoSuma);
	m_resultado = MyCadena;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedRestaButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 2; // la suma = + es la opracion 1
	//backuo de variables temporales
	op1Suma = op1;
	op2Suma = op2;
	resultadoSuma = m_resultado_ent;
	//borrado de variables 
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_ent = 0;

	CString MyCadena;
	MyCadena.Format(L"%d -", resultadoSuma);
	m_resultado = MyCadena;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedMultButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 3; // la suma = + es la opracion 1
	//backuo de variables temporales
	op1Suma = op1;
	op2Suma = op2;
	resultadoSuma = m_resultado_ent;
	//borrado de variables 
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_ent = 0;

	CString MyCadena;
	MyCadena.Format(L"%d x", resultadoSuma);
	m_resultado = MyCadena;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedDiviButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 4; // la suma = + es la opracion 1
	//backuo de variables temporales
	op1Suma = op1;
	op2Suma = op2;
	resultadoSuma = m_resultado_ent;
	//borrado de variables 
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_ent = 0;

	CString MyCadena;
	MyCadena.Format(L"%d /", resultadoSuma);
	m_resultado = MyCadena;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedIgualButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	switch (codigo_de_operacion)
	{
	case 1:
		m_resultado_ent = resultadoSuma + op1;
		break;
	case 2:
		m_resultado_ent = resultadoSuma - op1;
		break;
	case 3:
		m_resultado_ent = resultadoSuma * op1;
		break;
	case 4:
		m_resultado_ent = resultadoSuma / op1;
		break;

	default:
		break;
	}
	//madamos a imprimir a la cadena de edicion
	CString MyCadena;
	MyCadena.Format(L"%d", m_resultado_ent);
	m_resultado = MyCadena;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedClearButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	//borrado de variables 
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_ent = 0;
	resultadoSuma = 0;

	CString MyCadena;
	MyCadena.Format(L"%d", m_resultado_ent);
	m_resultado = MyCadena;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedBinCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (m_binario == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_A_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_C_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_D_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_E_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_F_BUTTON)->EnableWindow(FALSE);
		m_decimal = FALSE;
		m_hexadecimal = FALSE;
	
		//Agrege aqui su codigo de controlador de notificación de control
		int a[10], n, i;
		//actualizamos el numero a convertir 
		UpdateData(TRUE);
		n = m_resultado_ent;
		for (i = 0; n > 0; i++) {
			a[i] = n % 2;
			n = n / 2;
		}
		//limpiar cadena y generar ciclo para presentar dato convertido
		m_resultado = "";
		UpdateData(FALSE);
		for (i = i - 1; i >= 0; i--) {
			m_resultado_ent = a[i];
			CString MyCadena;
			MyCadena.Format(L"%d", m_resultado_ent);
			m_resultado += MyCadena;
		}

	}
	else {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_A_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_C_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_D_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_E_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_F_BUTTON)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}



void CCalculadoraDlg::OnBnClickedAButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "A";
		m_resultado_ent = A;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + A;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}



void CCalculadoraDlg::OnBnClickedBButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "B";
		m_resultado_ent = B;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + B;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedCButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "C";
		m_resultado_ent = C;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + C;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedDButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "D";
		m_resultado_ent = D;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + D;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedEButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "E";
		m_resultado_ent = E;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + E;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedFButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "F";
		m_resultado_ent = F;
		op1 = m_resultado_ent;
	}
	else {
		op2 = m_resultado_ent * 10; //op2 es el 1 convertido en decenas
		op1 = op2 + F;
		m_resultado_ent = op1;
		//codigo para mandar a imprimir resultado en EDIT_BOX como CString
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedDecCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (m_decimal == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_A_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_C_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_D_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_E_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_F_BUTTON)->EnableWindow(FALSE);
		m_binario = FALSE;
		m_hexadecimal = FALSE;
		CString MyCadena;
		MyCadena.Format(L"%d", m_resultado_ent);
		m_resultado = MyCadena;
	}
	else {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_A_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_C_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_D_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_E_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_F_BUTTON)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedHexCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (m_hexadecimal == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_A_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_C_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_D_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_E_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_F_BUTTON)->EnableWindow(TRUE);
		m_binario = FALSE;
		m_decimal = FALSE;
		CString MyCadena;
		MyCadena.Format(L"%X", m_resultado_ent);
		m_resultado = MyCadena;
	
	}
	else {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_A_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_C_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_D_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_E_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_F_BUTTON)->EnableWindow(TRUE);
	}
	
	UpdateData(FALSE);
}
BEGIN_EVENTSINK_MAP(CCalculadoraDlg, CDialogEx)
	//ON_EVENT(CCalculadoraDlg, IDC_INKPICTURE3, 1, CCalculadoraDlg::OnStrokeInkpicture3, VTS_DISPATCH VTS_DISPATCH VTS_PBOOL)
END_EVENTSINK_MAP()


void CCalculadoraDlg::OnStrokeInkpicture3(LPDISPATCH Cursor, LPDISPATCH Stroke, BOOL* Cancel)
{

}
	

