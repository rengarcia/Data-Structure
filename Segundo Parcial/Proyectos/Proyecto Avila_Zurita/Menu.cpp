#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<fstream>
#include <sstream>
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;

class Menus{
	
	public:
		void menuInicio(){
system ("color 9F" );
	printf("\t\t\t================================================\n");
	gotoxy(5,1);
	cout<<"\t\t\t\t\t------MENU------"<<endl;
	gotoxy(5,2);
	cout<<"\t\t\t\t*  Pixelar imagen";
	gotoxy(5,3);
	cout<<"\t\t\t\t*  Generar PDF del resultado";
	gotoxy(5,4);
	cout<<"\t\t\t\t*  Generar QR";
	gotoxy(5,5);
	cout<<"\t\t\t\t*  Mostrar codigo de barras";
	gotoxy(5,6);
	cout<<"\t\t\t\t*  Encriptar";
	gotoxy(5,7);	
	cout<<"\t\t\t\t*  Desencriptar";
	gotoxy(5,8);
	cout<<"\t\t\t\t*  Empezar el juego";
	gotoxy(5,9);
	cout<<"\t\t\t\t*  Salir\n";
	printf("\t\t\t================================================");
}

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void Selector(int i)
{
	gotoxy(30,2+i);
}

void menuDinamico(){
	int i = 0;
	ifstream doc;
	char tecla;	
	menuInicio();
	Selector(i);
	while(true){
		tecla = getch();
		switch(tecla)
		{
			case ARRIBA:
				i--;
				if(i < 0)
				{
					i = 9;
				}
				Selector(i);
				break;
			case 59:
				system("cls");
				cout<<"Ayuda"<<endl;
				system("Tetris.chm");
				system("pause");
				system("cls");
				menuDinamico();
				break;
			case ABAJO:
				i++;
				if(i == 0)
				{
					i = 1;
				}
				if(i == 10)
				{
					i = 0;
				}
				Selector(i);
				break;
			case ENTER:
				Selector(7);
				switch(i)
				{
					case 0:
						system("cls");
						system("java -jar pixel.jar");
						system("macara.jpg");
						system("image_pixelated.jpg");
						cout<<"Su imagen fue pixelada\n";
						system("Pause");
						system("cls");
						menuDinamico();
						break;
					case 1:
						system("cls");
															
						doc.open("Lista.txt",fstream::in);
						if(doc.fail()){
							system("cls");
							cout<<"ERROR: El archivo de agenda no esta creado\n";
							system("pause");
							system("cls");
							menuDinamico();
						}
						else{
							doc.close();
							system("cls");
							system("txt2pdf.exe Lista.txt Lista.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
							cout<<"Archivo generado exitosamente\n";
							system("pause");
							system("cls");
							menuDinamico();
						}
						
					case 2: 
					system("cls");
					cout<<"Mostrar QR de lisencia\n";
					system("Pause");
					system("QRlisencia.jpg");
					system("cls");
					menuDinamico();	
					
					case 3: 
					system("cls");			
					cout<<"Mostrar codigo de barras de los autores";
					system("Pause");
					system("Codigodebarras.gif");
					system("cls");
					menuDinamico();	
					
					case 4:
					system("cls");	
					char original[FILENAME_MAX], encriptado[FILENAME_MAX];
   						char c, clave;
   						FILE *entrada, *salida;
   						unsigned temp;
   
   						puts("Introduzca el nombre del archivo original:");
   						scanf("%s", original);
   
   						puts("Nombre del archivo encriptado:");
   						scanf("%s", encriptado);
   
   						puts("Introduzca la clave (0-255)");
   						scanf("%u", &temp);
   						clave = temp & 0xFFU;
   
   						if((entrada = fopen(original, "rb")) == NULL){
      						printf("Error al tratar de leer el archivo %s", original);
      						//return EXIT_FAILURE;
   						}else if ((salida = fopen(encriptado, "wb")) == NULL){
      						printf("Error al tratar de leer el archivo %s", encriptado);
      						//return EXIT_FAILURE;
   						}
   
   						while ((c = getc(entrada)) != EOF)
      					putc((c + clave) & 0xFF, salida);
   
   						fclose(salida);
   						fclose(entrada);
						
						system("pause");
						system("cls");
						menuDinamico();
														
					case 5:
						system("cls");
						char secundario[FILENAME_MAX], desencriptado[FILENAME_MAX];
   						char d, codigo;
   						FILE *inicio, *fin;
   						unsigned aux;
   
   						puts("Introduzca el nombre del archivo original:");
   						scanf("%s", secundario);
   
   						puts("Nombre del archivo encriptado:");
   						scanf("%s", desencriptado);
   
   						puts("Introduzca la clave (0-255)");
   						scanf("%u", &aux);
   						clave = aux & 0xFFU;
   
   						if((inicio = fopen(secundario, "rb")) == NULL){
      						printf("Error al tratar de leer el archivo %s", secundario);
      						//return EXIT_FAILURE;
   						}else if ((fin = fopen(encriptado, "wb")) == NULL){
      						printf("Error al tratar de leer el archivo %s", desencriptado);
      						//return EXIT_FAILURE;
   						}
   
   						while ((d = getc(inicio)) != EOF)
      					putc((d - codigo) & 0xFF, fin);
   
   						fclose(inicio);
   						fclose(fin);
						
						system("pause");
						system("cls");
						menuDinamico();				
																		
					default:
					exit(0);
			}
		}
	}
}



void portada()
{
	system ("color 9F" );
	
	cout<<"\t\t\t\t\tBIENVENIDOS A NUESTRO PROGRAMA"<<endl;
	
	cout<<"\n\n"<<endl;

	cout<<"\t\t:::::::::::    :::::::::    :::::::::::   :::::::::     :::::::::::     ::::::::::     "<<endl;
	cout<<"\t\t    :::        :::              :::       :::    :::        :::        :::             "<<endl;
	cout<<"\t\t    :::        :::              :::       :::    :::        :::        :::             "<<endl;
	cout<<"\t\t    :::        :::::::          :::       :::::::::         :::         :::::::::      "<<endl;
	cout<<"\t\t    :::        :::              :::       :::   ::          :::                :::     "<<endl;
	cout<<"\t\t    :::        :::              :::       :::    ::         :::                :::     "<<endl;
	cout<<"\t\t    :::        :::::::::        :::       :::     ::    :::::::::::    ::::::::::      "<<endl;
	
	cout<<"\n";
	system("PAUSE");
}
};


int main()
{
	Menus menu;
	menu.portada();
	system("cls");
	menu.menuDinamico();
	return 0;
}

