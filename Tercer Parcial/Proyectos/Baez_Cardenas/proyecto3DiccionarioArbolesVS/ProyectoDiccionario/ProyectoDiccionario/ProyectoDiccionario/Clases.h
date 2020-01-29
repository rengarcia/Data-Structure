#include <stdio.h>
#include <iostream>
#include<Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <time.h>

using namespace std;
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
typedef std::basic_ifstream<TCHAR> tifstream; 
typedef std::basic_string<TCHAR> tstring;

//clase para el usuario y la contraseña
class Acceso{
private:
	char usuario[30],clave[30];
public:
	Acceso() {};
	Acceso (char *usuario,char *clave);
    char *getUsuario();
	void setUsuario(char *cad);
	char *getClave();
	void setClave(char *cad1);
	void creararchivo();
	int validarusuario(Acceso obj);
	int validarclave(Acceso obj);
	void encriptarclave();
	void desencriptarclave();
	void consola();
};
class Opciones{ //pestañas
public:
	void gotoxy(short x, short y);
	friend void gotoxy(int x, int y);
	friend char tecla(unsigned char pulsacion);
	friend int mover();
    void Palabras();
	void consola();
	void Agregar();
	void Traducir();
	void Backup();
	void Ayuda();
	void Salir();
};

void gotoxy(int x, int y)//activacion de gotoxy
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char tecla(unsigned char pulsacion)
{
	if (pulsacion == 224) //se hace esta condición por si no se llegase a ingresar flechas para mover 
		pulsacion = _getch();
	return pulsacion;
}
int mover() // movimiento de flechas de navegacion
{
	int i = 0, j = 0, mov = 0;
	do
	{
		mov = tecla(_getch());
		if (mov == 77) //DERECHA
		{
			if (i == 79)
			{
				gotoxy(0, j++);
			};
			gotoxy(i++, j);
			
		}
		if (mov == 75) //IZQUIERDA
		{
			if (i == 0 && j != 0)
			{
				gotoxy(79, j--);
			};
			if (i == 0 && j == 0)
			{
				gotoxy(i, j);
			}
			gotoxy(i--, j);
			
		}
		if (mov == 72)//ARRIBA
		{
			if (j == 0)
			{
				//j = 0
				gotoxy(i, 0);
				//j = j;
			}
			gotoxy(i, j--);
			
		
		}
		if (mov == 80)
		{
			gotoxy(i, j++);
		}
	} while (mov != 13||(i>75||j!=0));
	return i;
}
void Opciones::gotoxy(short x, short y)
{	
	COORD pantalla;
	pantalla.X=(short) x;
	pantalla.Y=(short) y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pantalla);
}
////*
void Opciones::consola(){
	printf("\n\n\t\t\t     |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");//62
	printf("\t\t\t     |||||||||||||||||||||||DICCIONARIO TRADUCTOR|||||||||||||||||||||\n");
	printf("\t\t\t     |||||||||||||||||||||||||Espa%col a Ingl%cs|||||||||||||||||||||||\n",164,130);
	printf("\t\t\t     |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
}
void Opciones::Palabras(){// pestañas
	SetConsoleTextAttribute(color,10);
	gotoxy(0,0);
	cout<<"Palabras/"<<endl;
	gotoxy(0,1);
	printf("%c%c%c%c%c%c%c%c",238,238,238,238,238,238,238,238);

}
void Opciones::Agregar(){
	SetConsoleTextAttribute(color,11);
	gotoxy(11,0);
	cout<<"Agregar/"<<endl;
	gotoxy(11,1);
	printf("%c%c%c%c%c%c%c",238,238,238,238,238,238,238);
}
void Opciones::Traducir(){
	SetConsoleTextAttribute(color,13);
	gotoxy(21,0);
	cout<<"Traducir/"<<endl;
	gotoxy(21,1);
	printf("%c%c%c%c%c%c%c%c",238,238,238,238,238,238,238,238);
}
void Opciones::Backup(){
	SetConsoleTextAttribute(color,15);
	gotoxy(32,0);
	cout<<"Encriptacion/"<<endl;
	gotoxy(32,1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c",238,238,238,238,238,238,238, 238, 238, 238, 238, 238);
}
void Opciones::Ayuda(){
	SetConsoleTextAttribute(color,14);
	gotoxy(46,0);
	cout<<"Ayuda?/"<<endl;
	gotoxy(46,1);
	printf("%c%c%c%c%c%c",238,238,238,238,238,238);
}
void Opciones::Salir(){
	SetConsoleTextAttribute(color,7);
	gotoxy(54,0);
	cout<<"Salir/"<<endl;
	gotoxy(54,1);
	printf("%c%c%c%c%c",238,238,238,238,238);
}
//Constructor de la clase acceso
Acceso::Acceso(char *u,char *c){
	strcpy(usuario,u);
	strcpy(clave,c);
}
//implementacion de los get y set
void Acceso::setUsuario(char *cad){
	strcpy(usuario,cad);
}
char* Acceso::getUsuario(){
	return usuario;
}
void Acceso::setClave(char *cad1){
	strcpy_s(clave,cad1);
}
char* Acceso::getClave(){
	return clave;
}
///////////////////////////////////////
void Acceso::creararchivo(){
	ofstream fs("usuario.txt");  // Crea un fichero de salida
	fs << "Edison" << endl; // Enviamos una cadena al fichero de salida
	fs << "Angel" << endl;
	fs.close(); // Cerrar el fichero, para luego poder abrirlo para lectura:
	 // Leeremos mediante getline, si lo hiciéramos mediante el operador << sólo leeríamos parte de la cadena
	ofstream ft("clave.txt");  // Crea un fichero de salida
	ft << "miespe" << endl; // Enviamos una cadena al fichero de salida
	ft << "m1espe1" << endl;
	ft.close(); // Cerrar el fichero, para luego poder abrirlo para lectura:
}
int Acceso::validarusuario(Acceso obj){
	char us1[30],us2[30],us3[30],us4[30],us5[30];
	ifstream fe("usuario.txt"); // Abre un fichero de entrada
	fe.getline(us1, 30);
	fe.getline(us2, 30);
	if((strcmp(us1,obj.getUsuario())== 0)||(strcmp(us2,obj.getUsuario())== 0)){
		return -1;	
	}
	else{
		printf_s("\n\t\t\t\t\t !!Acceso Denegado. El usuario es incorrecto!! ");
		_getch();
	}	
}
int Acceso::validarclave(Acceso obj){
	char cl1[30],cl2[30];
	ifstream fp("clave.txt"); // Abre un fichero de entrada
	fp.getline(cl1, 30);
	fp.getline(cl2, 30);
	if((strcmp(cl1,obj.getClave())==0&&strcmp("Edison",obj.getUsuario())==0)||(strcmp(cl2,obj.getClave())==0&&strcmp("Angel",obj.getUsuario())==0)){
		return -1;
	}
	else{
		printf_s("\n\n\t\t\t\t\t     !!Acceso Denegado. Clave incorrecta!! ");
		_getch();
	}
}
void Acceso::encriptarclave() {
	ifstream salida;
	char cl[20];
	FILE* archivo;
	char arch[50];
	strcpy(arch, "encriptado.txt");
	archivo = fopen(arch, "w");
	SetConsoleTextAttribute(color, 13);
	salida.open("clave.txt");
	SetConsoleTextAttribute(color, 11);
	salida >> cl;
	while (!salida.eof())
	{
		SetConsoleTextAttribute(color, 15);
		for (int i = 0; i < strlen(cl); ++i)
		{
			//convierte las minuscalas a mayuscula.
			*(cl + i) = toupper(*(cl + i));
			//descarta los digitos
			if (isalpha(*(cl + i)))
			{
				//verifica los casos especiales X-Y-Z
				if (*(cl + i) > 87)
				{
					*(cl + i) = *(cl + i) - 23;
				}
				else
				{
					*(cl + i) = *(cl + i) + 3;
				}
			}
		}
		fprintf(archivo, "%s\n", cl);
		salida >> cl;
		SetConsoleTextAttribute(color, 15);
	}
	cout << endl;
	SetConsoleTextAttribute(color, 15);
	salida.close();
	fclose(archivo);
}
void Acceso::desencriptarclave() {
	ifstream salida;
	char cl[20];
	FILE* archivo1;
	char arch[50];
	strcpy(arch, "desencriptado.txt");
	archivo1 = fopen(arch, "w");
	SetConsoleTextAttribute(color, 13);
	salida.open("encriptado.txt");
	SetConsoleTextAttribute(color, 11);
	salida >> cl;
	while (!salida.eof())
	{
		SetConsoleTextAttribute(color, 15);
		for (int i = 0; i < strlen(cl); ++i)
		{
			*(cl + i) = tolower(*(cl + i));
			if (isalpha(*(cl + i)))
			{
				if (*(cl + i) < 87)
				{
					*(cl + i) = *(cl + i) + 23;
				}
				else
				{
					*(cl + i) = *(cl + i) - 3;
				}
			}
		}
		fprintf(archivo1, "%s\n", cl);
		salida >> cl;
		SetConsoleTextAttribute(color, 15);
	}
	cout << endl;
	SetConsoleTextAttribute(color, 15);
	salida.close();
	fclose(archivo1);
}
void Acceso::consola(){
	SetConsoleTextAttribute(color,10);
	printf("\n\n\t                 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",	179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179      ,179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179,			179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179,	179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179);
    printf("\t                 %c%c%c%c%c::::::::::::. %c%c%c%c%c:::::::::::. %c%c%c%c//////////%c%c%c%c%c %c%c%c%c%c::::::::::::.\n",
	179,219,219,219,177,            179,219,219,219,177,       179,219,219,219,47,219,219,177,179,        179,219,219,219,177);
	printf("\t                 %c%c%c%c%c```````       %c%c%c%c%c``````````   %c%c%c%c           %c%c%c%c %c%c%c%c%c```````      \n",
	179,219,219,219,177,         179,219,219,219,177,       179,219,219,219,  219,219,177,179,   179,219,219,219,177);
    printf("\t                 %c%c%c%c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c..........-%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c     \n",
	179,219,219,219,219,219,219,219,219,219,177,179,         179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179,     
	179,219,219,219,219,219,177,179,        	179,219,219,219,219,219,219,219,219,219,177,179);
    printf("\t                 %c%c%c%c%c------.        `.----------%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c------.     \n",
	179,219,219,219,177,          219,219,177,179,      179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179,     179,219,219,219,177);
    printf("\t                 %c%c%c%c%c-...........` .............%c%c%c%c %c%c%c%c%c%c..........`   %c%c%c%c%c-...........`\n",
	179,219,219,219,177,            219,219,177,179,             179,219,219,219,177,179,          179,219,219,219,177);
    printf("\t                 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c              %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
	179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179,            179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179,      179,219,219,219,177,179,  
	179,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,177,179);

    printf("\n\n");
	SetConsoleTextAttribute(color,15);
    printf("\n\t\t\t\t\t\t   ESTRUCTURA DE DATOS");
    printf("\n\t\t\t\t\t Realizado por: Baez Edison, Cardenas Angel");
	SetConsoleTextAttribute(color,14);
	printf("\n");
	printf("\t\t\t\t     _____ ___    _   ___  _   _  ___ _____ ___  ___ \n");
	printf("\t\t\t\t    |_   _| _ %c  /_%c |   %c| | | |/ __|_   _/ _ %c| _ %c\n", 92, 92, 92, 92, 92);
	printf("\t\t\t\t      | | |   / / _ %c| |) | |_| | (__  | || (_) |   /\n",92);
	printf("\t\t\t\t      |_| |_|_%c/_/ %c_%c___/ %c___/ %c___| |_| %c___/|_|_%c\n", 92, 92, 92, 92, 92,92,92);
	SetConsoleTextAttribute(color,15);
}
