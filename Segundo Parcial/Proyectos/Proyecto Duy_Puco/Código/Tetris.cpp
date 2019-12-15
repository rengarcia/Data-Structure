/***********************************************************************
 * Module:  Tetris.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Implementation of the class Tetris
 ***********************************************************************/

#include "Marquesina.cpp"
#include "Tetris.h"
#include "VectorMatriz.cpp"
#include "Numero.cpp"
#include "Cifrado.cpp"

static HWND  hConWnd;
HWND BCX_Bitmap(char*, HWND = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
HWND GetConsoleWndHandle(void);
Numero *lista = new Numero();


/**
 * @brief guarda la posicion de la pantalla
 * @param void ()
 * @return void
 */
void Tetris::guardarPosicion() {
	*(*(cuerpo+n)+0) = x;
	*(*(cuerpo+n)+1) = y;
	n++;
	if(n == tamanio) {
		n = 1;
	}
}

/**
 * @brief mueve el numero por toda la pantalla
 * @param void ()
 * @return int
 */
int Tetris::moverNumero() {
	Pantalla pantalla;
	for(int i=1; i<tamanio; i++) {
		pantalla.gotoxy(*(*(cuerpo+i)+0), *(*(cuerpo+i)+1));
		cout << numero;
	}
	return numero;
}

/**
 * @brief mueve el numero por toda la pantalla
 * @param void ()
 * @return void
 */
void Tetris::borrarNumero() {
	Pantalla pantalla;
	pantalla.gotoxy(*(*(cuerpo+n)+0), *(*(cuerpo+n)+1));
	cout <<" ";
}

/**
 * @brief mueve el numero por toda la pantalla
 * @param void ()
 * @return void
 */
void Tetris::teclear() {
	if(kbhit()) {
		tecla = getch();
		switch(tecla) {
			case DERECHA:
				if(direccion != 4) {
					direccion=3;
				}
				break;
			case IZQUIERDA:
				if(direccion != 3) {
					direccion=4;
				}
				break;
		}
	}
}

/**
 * @brief mantiene el numero por toda la pantalla
 * @param void ()
 * @return void
 */
void Tetris::mantener() {
	Pantalla pantalla;
	pantalla.gotoxy(0,0);
}

/**
 * @brief aumenta la velocidad del numero por toda la pantalla
 * @param void ()
 * @return void
 */
void Tetris::moverAbajo() {
	if(direccion != 1) {
		direccion=2;
	}
}

/**
 * @brief ubica el numero por toda la pantalla
 * @param int ()
 * @return void
 */
void Tetris::ubicar(int auxiliarY) {
	Pantalla pantalla;
	auxiliarY = mantenerY;
	pantalla.pintar();
	cont++;
	if(y == auxiliarY) {
		pantalla.gotoxy(x,y-1);
		cout << numero;
		archivo << numero << endl;
		pantalla.gotoxy(1,1);
		cout << "La lista es: " << endl;
		pantalla.gotoxy(1,2);
		lista->insertarEntre(x,numero);
		lista->imprimir();
		numero = (rand()%9)+1;
		numero = moverNumero();
		y = 20;
		auxiliar++;
		if(auxiliar == 167) {
			auxiliar = 1;
			aumenta++;
			mantenerY--;
		}
	}
	if(x == 0) {
		x = 1;
	}
	if(x == 167) {
		x = 166;
	}
}

/**
 * @brief mueve el juego en si para las direcciones que se indique
 * @param void ()
 * @return void
 */
void Tetris::principal() {
	Pantalla pantalla;
	VectorMatriz generar;
	cuerpo = generar.inicializar(100);
	cuerpo = generar.encerar(100,cuerpo);
	pantalla.pintar();
	while(tecla != ESC) {
		borrarNumero();
		guardarPosicion();
		moverNumero();
		moverAbajo();
		teclear();
		ubicar(mantenerY);
		if(direccion == 2) {
			y++;
			Sleep(50);
		}
		if(direccion == 3) {
			x++;
			Sleep(50);
		}
		if(direccion == 4) {
			x--;
			Sleep(50);
		}
		Sleep(50);
	}
	pantalla.pintar();
}

/**
 * @brief hilo para relizar varias acciones 
 * @param void (*arg)
 * @return  void*
 */
void* funcion1(void *arg) {
	Tetris tetris;
    pthread_mutex_lock(&ptmutex1); 
    Sleep(50);   
    tetris.crearMenu(); 	
    pthread_mutex_unlock(&ptmutex1); 
    return NULL;
}

/* 	@brief Funcion que sirve para realizar el segundo hilo que contiene la marquesina 
	@param void*: necesario para crear hilos */

void* funcion2(void *arg) {
	Marquesina marquesina;
    pthread_mutex_lock(&ptmutex1);
    marquesina.hacerMarquesina();
    Sleep(5000);
    pthread_mutex_unlock(&ptmutex1);
    return NULL;
}

/**
 * @brief hilo para relizar varias acciones 
 * @param void (*arg)
 * @return  void* 
 */
void* funcion3(void *arg) {
    pthread_mutex_lock(&ptmutex1);
    hConWnd = GetConsoleWndHandle();
    Sleep(1000);
    BCX_Bitmap("logo.bmp", hConWnd, 123, 600, 400, 0, 0);
    Sleep(8000);
    pthread_mutex_unlock(&ptmutex1);
    return NULL;
}

/**
 * @brief controla el menu de inicio
 * @param void ()
 * @return void
 */
void Tetris::crearMenu() {
	Cifrado cifrar; //objeto para manejar el proceso
    char *nombreArchivo = (char*)malloc(30*sizeof(char)); //direccion del archivo
    char *claveArchivo = (char*)malloc(30*sizeof(char));
    *(claveArchivo+0)=0;
	Pantalla pantalla;
	pantalla.abrirPantalla();
	int opcion;
	const char *opciones[]={"1. Jugar","2. Abrir QR","3. Abrir codigo de barras","4. Abrir Ayuda","5. Seleccionar Archivo","6. Encriptar","7. Desencriptar", 
							"8. Salir"};
	opcion=pantalla.menu("TETRIS",opciones,8); 
	bool bandera=false;
	do {
		switch(opcion) {
			case 1: {
				system("cls");
				principal();
				muestraPDF();
				opcion=pantalla.menu("TETRIS",opciones,8);
				archivo.close();
				break;
			}
			case 2:
				system("cls");
				system("QR.png");
				opcion=pantalla.menu("TETRIS",opciones,8);
				break;
 
			case 3:
				system("cls");
				system("barra.jpeg");
				opcion=pantalla.menu("TETRIS",opciones,8);
				break;
 
			case 4:
				system("cls");
				system("tetris1.chm");
				opcion=pantalla.menu("TETRIS",opciones,8);
				break;
				
			case 5:
				system("cls");
				cout << "Nombre del archivo: ";
				cin >> nombreArchivo;
				//si la cadena esta vacia no hace nada
				if(*(nombreArchivo+0)==0 )break;
				cifrar.leer(nombreArchivo);
				opcion=pantalla.menu("TETRIS",opciones,8);
				break;
				
			case 6:
				system("cls");
				//si la cadena esta vacia no hace nada
				if(*(nombreArchivo+0)==0 )break;
				cout << "Ingrese la clave: ";
				cin >> claveArchivo;
				//si la clave esta vacia no hace nada
				if(*(claveArchivo+0)==0 )break;
				cifrar.cifrar(claveArchivo ); //cifra
				cifrar.grabar(nombreArchivo ); //guarda
				opcion=pantalla.menu("TETRIS",opciones,8);
				break;
				
			case 7:
				system("cls");
				//si la cadena esta vacia no hace nada
				if(*(nombreArchivo)==0 )break;
				cout << "Ingrese la clave: ";
				cin >> claveArchivo;
				//si la clave esta vacia no hace nada
				if(*(claveArchivo)==0 )break;
				cifrar.descifrar(claveArchivo ); //descifra
				cifrar.grabar(nombreArchivo ); //guarda
				opcion=pantalla.menu("TETRIS",opciones,8);
				break;
				
			case 8:
				exit(0);
 				break;
 				
			default:
				system("cls");
				cout << endl << endl << endl << endl << "Opcion no valida.\a\n";
				break;
		}
    }while(bandera!=true);
}

HWND BCX_Bitmap(char* Text, HWND hWnd, int id, int X, int Y, int W, int H, int Res, int Style, int Exstyle)
{
	HWND A;
	HBITMAP hBitmap;

	// set default style
	if (!Style) Style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_TABSTOP;

	// form for the image
	A = CreateWindowEx(Exstyle, "static", NULL, Style, X, Y, 0, 0, hWnd, (HMENU)id, GetModuleHandle(0), NULL);

	// Text contains filename
	hBitmap = (HBITMAP)LoadImage(0, Text, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// auto-adjust width and height
	if (W || H) hBitmap = (HBITMAP)CopyImage(hBitmap, IMAGE_BITMAP, W, H, LR_COPYRETURNORG);
	SendMessage(A, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
	if (W || H) SetWindowPos(A, HWND_TOP, X, Y, W, H, SWP_DRAWFRAME);
	return A;
}

/**
 * @brief crea la pantalla
 * @param void ()
 * @return HWND
 */
HWND GetConsoleWndHandle(void)
{
	HWND hConWnd;
	OSVERSIONINFO os;
	char szTempTitle[64], szClassName[128], szOriginalTitle[1024];

	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	// may not work on WIN9x
	if (os.dwPlatformId == VER_PLATFORM_WIN32s) return 0;

	GetConsoleTitle(szOriginalTitle, sizeof(szOriginalTitle));
	sprintf(szTempTitle, "%u - %u", GetTickCount(), GetCurrentProcessId());
	SetConsoleTitle(szTempTitle);
	Sleep(60);
	// handle for NT and XP
	hConWnd = FindWindow(NULL, szTempTitle);
	SetConsoleTitle(szOriginalTitle);

	// may not work on WIN9x
	if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
	{
		hConWnd = GetWindow(hConWnd, GW_CHILD);
		if (hConWnd == NULL) return 0;
		GetClassName(hConWnd, szClassName, sizeof(szClassName));
		// while ( _stricmp( szClassName, "ttyGrab" ) != 0 )
		while (strcmp(szClassName, "ttyGrab") != 0)
		{
			hConWnd = GetNextWindow(hConWnd, GW_HWNDNEXT);
			if (hConWnd == NULL) return 0;
			GetClassName(hConWnd, szClassName, sizeof(szClassName));
		}
	}
	return hConWnd;
}

