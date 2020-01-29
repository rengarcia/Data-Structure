/*	***** UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ***** **
** Estructura de Datos									**
** Nombre: Jorge Galarza - Kevin Zurita					**
** NRC: 2742											**
** Fecha de realizacion: 01/12/2019						**
** Fecha de modificacion: 12/12/2019					**
** Ing. Fernando Solis									**
*/														
#include <iostream>
#include <winbgim.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define ENTER 13
#define F1 59
void* selloEspe(void *);
static HWND  hConWnd;
HWND BCX_Bitmap(char*, HWND = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
HWND GetConsoleWndHandle(void);



using namespace std;
// Funcion gotoxy
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
  
// Marquesina
void* marquesina(void *data){

	int a, b, c, n=0,letra=39,pos=1,cont=39,aux,cont1=39,auxg;
	char t[50] ="Diccionario: Proyecto Estructura de Datos",auxt[39]=" ";

	do{		
		for (a=0;a<42;a++){
			aux=pos;
			for(b=39;b>cont;b--){
				gotoxy(pos,1);
				cout<<t[b];
				pos--;
			}	
			aux++;
			pos=aux;
			cont--;
			Sleep (75);
			if(a==40){
				break;
			}
		}
		for(a=3;a<70;a++){	
			gotoxy(a-1,1);
			cout<<" ";
			gotoxy(a,1);
			cout<<t;
			Sleep (75);
		}
		
		pos=70;
		auxg=69;
		for (a=0;a<41;a++){
			gotoxy(auxg,1);
			cout<<" ";
			aux=pos;
			for(b=0;b<=cont1;b++){	
				gotoxy(pos,1);
				cout<<t[b];
				pos++;
			}	
			cont1--;
			aux++;
			pos=aux;
			auxg++;
			Sleep (75);
		}		
		cont1=39;	
		letra=39;
		pos=1;
		cont=39;
		c=0;
	}while (c=1);

}



// Cambia el color de la letras y dondo de la consola
void SetConsoleColour(WORD* Attributes, DWORD Colour){
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

// 		
void ResetConsoleColour(WORD Attributes){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

// Remarca el metodo uno en la consola
void uno (WORD Attributes){
	cout << endl;
	SetConsoleColour(&Attributes, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	cout<<"\tDiccionario ";
	ResetConsoleColour(Attributes);
	cout<<"\t CodigoQR \t Codigo de Barras \t Sello Pixeleado \t Salir "<<endl;
}

// Remarca el metodo dos en la consola
void dos(WORD Attributes){
	cout << endl;
	cout<<"\tDiccionario \t ";
	SetConsoleColour(&Attributes, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	cout<<"CodigoQR ";
	ResetConsoleColour(Attributes);
	cout<<"\t Codigo de Barras \t Sello Pixeleado \t Salir"<<endl;
	
}

// Remarca el metodo tres en la consola
void tres(WORD Attributes){
	cout << endl;
	cout<<"\tDiccionario \t CodigoQR \t ";
	SetConsoleColour(&Attributes, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	cout<<"Codigo de Barras";
	ResetConsoleColour(Attributes);
	cout<<"\t Sello Pixeleado \t Salir";
}

// Remarca el metodo cuatro en la consola
void cuatro(WORD Attributes){
	cout << endl;
	cout<<"\tDiccionario \t CodigoQR \t Codigo de Barras \t ";
	SetConsoleColour(&Attributes, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	cout<<"Sello Pixeleado";
	ResetConsoleColour(Attributes);
	cout << "\t Salir";
}
// Remarca el metodo cinco en la consola
void cinco(WORD Attributes){
	cout << endl;
	cout<<"\tDiccionario \t CodigoQR \t Codigo de Barras \t Sello Pixeleado \t";
	SetConsoleColour(&Attributes, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	cout<<"Salir";
	ResetConsoleColour(Attributes);
}
// funcion principal
int main()
{
	system("color F1");
//		system("color e");
    // declaracoion de variables
	WORD Attributes=0;
	pthread_t thread1;
	pthread_create(&thread1, NULL, marquesina, NULL);
	int met,tecla,opc=0;
		cout<<"\n\n"<<endl;
		cout<<"\t Seleccione el metodo que desea usar \t\t\t\t\t\t Pulse F1 para AYUDA"<<endl;
		cout << endl;
		cout<<"\tDiccionario \t CodigoQR \t Codigo de Barras \t Sello Pixeleado \t Salir "<<endl;
	do{
		// lee la tecla que se pulsa
		do{
		tecla=getch();
	}while(tecla!=TECLA_DERECHA && tecla!=TECLA_IZQUIERDA && tecla!=ENTER && tecla!=F1);
	system("cls");
	cout<<"\n\n"<<endl;
	cout<<"\t Seleccione el metodo que desea usar \t\t\t\t pulse F1 para ayuda"<<endl;;
	// Dependiendo de la tecla que se pulse se usa un contador o abre la ventana de ayuda
	switch (tecla){
		cout <<"\n\n"<<opc<<endl;
		case TECLA_DERECHA:
			opc++;
			 if(opc==6){
				opc=1;
			}
			break;
		case TECLA_IZQUIERDA:
			opc--;
			if(opc<=0){
				opc=5;
			}
			break;
		case ENTER:
			met=opc;
			break;
	// en caso de presionar la tecla f1 se abre una ventana de ayuda
		case F1:
		system("AyudaDiccionario.chm");
			break;
		}
		
		// Dependiendo del contador entra a un caso en el que pinta el metodo que se seleccionara
		switch(opc){
			case 1: 
			uno(Attributes);
				break;
			case 2:
				dos(Attributes);
				break;
			case 3:
				tres(Attributes);
				break;
			case 4:
				cuatro(Attributes);
				break;
			case 5: 
				cinco(Attributes);
				break;
		}
		
		// Cuando se pulsa enter entra al metodo que se encuentre seleccionado
		switch(met){
	// ejecuta jugar
	case 1:	
	SuspendThread(&thread1);
	system("Diccionario.exe");
	system("cls");
		opc=0;
		met=0;
	break;
	// Ejecuta código QR
	case 2:
		system("CodigoQR.png");
		opc=0;
		met=0;
	break;
	// Ejecuta codigo de barras
	case 3:
		system("CodigodeBarras.png");			
		opc=0;
		met=0;
	break;
	// Ejecuta el sello pixeleado
	case 4:
	system("cls");
	void *status;
	pthread_t thread2;
	pthread_create (&thread2 , NULL , selloEspe , (void *) & thread1);	
	pthread_join(thread2, &status);
		opc=0;
		met=0;
	break;	
	
	}
	}while(met!=5);
	// Termina el programa
	system("cls");
	cout<<"\n\n"<<endl;
	cout<<"Gracias por usar nuestro diccionario !!!"<<endl;
	system("PAUSE");
	return 0;
}
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
void* selloEspe(void *arg)
{
	pthread_mutex_t ptmutex1;
	pthread_mutex_lock(&ptmutex1);
	hConWnd = GetConsoleWndHandle();
	BCX_Bitmap("logo.bmp", hConWnd, 123, 150, 150, 0, 0);
	Sleep(5000);
	pthread_mutex_unlock(&ptmutex1);
}
