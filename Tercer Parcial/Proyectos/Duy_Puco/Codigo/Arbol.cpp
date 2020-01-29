/***********************************************************************
 * Module:  Arbol.cpp
 * Author:  Carlos Puco, Kevin Duy
 * Modified: Sabado, 11 de enero de 2020 20:20:06
 * Purpose: Implementation of the class Arbol
 ***********************************************************************/

#include "Marquesina.cpp"
#include "Arbol.h"
#include <iostream>
#include <string.h>
#include <windows.h>
#include "Virus.cpp"
#include "Cifrado.cpp"
#include "ingreso.h"

static HWND  hConWnd;
HWND BCX_Bitmap(char*, HWND = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
HWND GetConsoleWndHandle(void);

Arbol::Arbol() {
	cima = NULL;
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  void 
 * @return limpia
 */
void Arbol::limpiar() {
	cima = NULL;
}

/** 	
 * @brief Funcion implica el arbol 
 * @param  void 
 * @return agrega el nodo al arbol
 */

void Arbol::agregar(Nodo *nodo) {
	if (cima == NULL) {
		cima = new Pila(nodo);
	}else {
        Pila *pila = new Pila(nodo);
        pila->siguiente = cima;
        cima = pila;
    }
}

Nodo* Arbol::mover() {
	if (cima == NULL) {
        cout << "Invalido" << endl;
    }else {
        Nodo *nodo = cima->raiz;
        cima = cima->siguiente;
        return nodo;
    }
}

Nodo* Arbol::dirigir() {
	return cima->raiz;
}

void Arbol::insertar(char newDato) {
	if(digito(newDato)) {
        Nodo *nodo = new Nodo(newDato);
        agregar(nodo);
        mostrar(nodo,80,2);
    }else if(operador(newDato)) {
        Nodo *nodo = new Nodo(newDato);
        nodo->izquierda = mover();
        nodo->derecha = mover();
        agregar(nodo);
        mostrar(nodo,80,2);
    }else{
        cout << "Expresion no valida" << endl;
        return;
    }
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  char
 * @return digito
 */

bool Arbol::digito(char caracter) {
	return caracter >= '0' && caracter <= '9';
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  char
 * @return operador
 */

bool Arbol::operador(char caracter) {
	return caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/';
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  char
 * @return numero convertido 
 */

int Arbol::convertirANumero(char caracter) {
	return caracter - '0';
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  string
 * @return cinstruye el arbol
 */

void Arbol::construirArbol(string expresion) {
	char *convertido = (char*)malloc(100*sizeof(char*));
	strcpy(convertido,expresion.c_str());
	for(int i=expresion.length()-1; i>=0; i--) {
		insertar(*(convertido+i));
	}
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  void 
 * @return evaluar
 */

double Arbol::evaluar() {
	return calcular(dirigir());
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  nodo*
 * @return calcular
 */


double Arbol::calcular(Nodo *nodo) {
	if(nodo->izquierda == NULL && nodo->derecha == NULL) {
		return convertirANumero(nodo->dato);
	}else {
        double resultado = 0.0;
       	double izquierda = calcular(nodo->izquierda);
    	double derecha = calcular(nodo->derecha);
    	char opcion = nodo->dato;
        switch (opcion) {
        	case '+': 
            	resultado = izquierda + derecha; 
            break;
            case '-': 
                resultado = izquierda - derecha; 
            break;
            case '*': 
                resultado = izquierda * derecha; 
            break;
            case '/': 
                resultado = izquierda / derecha; 
            break;
        }
        return resultado;
    }
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  int 
 * @return grafica 
 */
void Arbol::gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  void 
 * @return funcion
 */

void Arbol::mostrar(Nodo *nodo, int x, int y){
	if(nodo!=NULL){
		gotoxy(x,y);
		cout << nodo->dato << endl;
		x=x-3;
		y=y+3;
		mostrar(nodo->izquierda,x,y);
		x=x+6;
		mostrar(nodo->derecha,x,y);
		y=y-3;
	}
}

void Arbol::principal() {
	Ingreso leer;
	string expresion;
    int resultado;
    Virus virus;
    Arbol arbol;
    cout<<"Ingrese una expresion matematica en forma prefija: ";
    cin >> expresion;
    archivo << expresion << " ";
    arbol.construirArbol(expresion);
    cout<<"Ingrese el resultado esperado: ";
    cin >> resultado;
    cout<<"El resultado real es: "<< arbol.evaluar();
    system("pause");
    virus.comprobar(resultado,arbol.evaluar());
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  void 
 * @return funcion
 */
void* funcion1(void *arg) {
	int argc;
	char **argv;
	Arbol arbol;
    pthread_mutex_lock(&ptmutex1); 
    Sleep(50);   
    arbol.crearMenu(); 	
    pthread_mutex_unlock(&ptmutex1); 
    return NULL;
}

/** 	
 * @brief Funcion implica el arbol 
 * @param  void 
 * @return funcion
 */
void* funcion2(void *arg) {
	Marquesina marquesina;
    pthread_mutex_lock(&ptmutex1);
    marquesina.hacerMarquesina();
    Sleep(5000);
    pthread_mutex_unlock(&ptmutex1);
    return NULL;
}
/** 	
 * @brief Funcion implica el arbol 
 * @param  void 
 * @return funcion
 */

void* funcion3(void *arg) {
	Pantalla pantalla;
    pthread_mutex_lock(&ptmutex1);
    hConWnd = GetConsoleWndHandle();
    Sleep(1000);
    BCX_Bitmap("logo.bmp", hConWnd, 123, 600, 200, 0, 0);
    Sleep(8000);
    pthread_mutex_unlock(&ptmutex1);
    return NULL;
}
/** 	
 * @brief Funcion menu 
 * @param  void 
 * @return genera un menu 
 */


void Arbol::crearMenu() {
	Cifrado cifrar; //objeto para manejar el proceso
    char *nombreArchivo = (char*)malloc(30*sizeof(char)); //direccion del archivo
    char *claveArchivo = (char*)malloc(30*sizeof(char));
    *(claveArchivo+0)=0;
	Pantalla pantalla;
	int opcion;
	const char *opciones[]={"1. Jugar","2. Abrir QR","3. Abrir codigo de barras","4. Abrir Ayuda","5. Seleccionar Archivo","6. Encriptar","7. Desencriptar", 
							"8. Salir"};
	opcion=pantalla.menu("Calcula el numero",opciones,8); 
	bool bandera=false;
	do {
		switch(opcion) {
			case 1: {
				system("cls");
				principal();
				muestraPDF();
				opcion=pantalla.menu("Calcula el numero",opciones,8);
				archivo.close();
				break;
			}
			case 2:
				system("cls");
				system("QR.png");
				opcion=pantalla.menu("Calcula el numero",opciones,8);
				break;
 
			case 3:
				system("cls");
				system("barra.jpeg");
				opcion=pantalla.menu("Calcula el numero",opciones,8);
				break;
 
			case 4:
				system("cls");
				system("Arbol.chm");
				opcion=pantalla.menu("Calcula el numero",opciones,8);
				break;
				
			case 5:
				system("cls");
				cout << "Nombre del archivo: ";
				cin >> nombreArchivo;
				//si la cadena esta vacia no hace nada
				if(*(nombreArchivo+0)==0 )break;
				cifrar.leer(nombreArchivo);
				opcion=pantalla.menu("Calcula el numero",opciones,8);
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
				opcion=pantalla.menu("Calcula el numero",opciones,8);
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
				opcion=pantalla.menu("Calcula el numero",opciones,8);
				break;
				
			case 8:
				exit(0);
 				break;
 				
			default:
				system("cls");
				cout << endl << endl << endl << endl << "Opcion no valida.\a\n";
				opcion=pantalla.menu("Calcula el numero",opciones,8);
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
