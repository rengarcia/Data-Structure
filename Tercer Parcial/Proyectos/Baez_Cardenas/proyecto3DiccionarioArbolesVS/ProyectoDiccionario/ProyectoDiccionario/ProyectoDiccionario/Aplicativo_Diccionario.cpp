#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include<fstream>
#include<iostream>


#include "Clases.h"
#include<Windows.h>

//-------------------------------------------------------------------------------------
//							Estructura del Nodo
//-------------------------------------------------------------------------------------
struct nodos {
	char ingles[50];
	char espanol[50];
	struct nodos* der;
	struct nodos* izq;
	int Fe;
};
//-------------------------------------------------------------------------------------
//							--------------------
//-------------------------------------------------------------------------------------
typedef struct nodos Arbol;
typedef Arbol* ARBOL;
int listo;
char in[50], es[50];

void menu_agregar();
void menu_ingles();
void menu_espanol();
void menu_borrar();
void menu_listar();
void agregar(ARBOL* nodoarb);
void buscar_ingles(ARBOL nodoarb);
void buscar_espanol(ARBOL nodoarb);
void listar(ARBOL nodoarb);
void rotacionddsimple(ARBOL* nodoarb);
void rotaciondidoble(ARBOL* nodoarb);
void rotaciondd2(ARBOL* nodoarb);
void rotacionii2(ARBOL* nodoarb);
void rotacioniisimple(ARBOL* nodoarb);
void rotacioniddoble(ARBOL* nodoarb);
void menor(ARBOL nodoarb);
void actualizarbi(ARBOL* nodoarb, int* ban);
void actualizarbd(ARBOL* nodoarb, int* ban);
void eliminar(ARBOL* nodoarb, int* ban);
void borrar(ARBOL* nodoarb, int* ban);

void main()
{
		int ban = 1;
		ARBOL raiz = NULL;
		char x[20],y[20]="miespe";
		char sonido[20],sonidoi[20];
		char mp3[10]=".wav";
		int x1,y1,cl[9],inc,i=0, aux,m;
		char op,opcion,u[30],c[30];
		inc=0;
		Acceso archivo(u,c);
		archivo.creararchivo();
		do{
			system("cls");
			fflush(stdin);
			archivo.consola();
			printf_s("\n\n\n\t\t\t\t\t\t      USUARIO: ");
			
			gets_s(u);
			Acceso archivou(u,c);
			x1=archivou.validarusuario(archivou);
		}while(x1!=-1);
		do{
			system("cls");
			archivo.consola();
			printf_s("\n\n\n\t\t\t\t\t\t      USUARIO: ");
			printf_s("%s",u);
			printf_s("\n\n\t\t\t\t\t\t      CLAVE: ");
			while((*cl = _getch()) != 13){ //Validar tecla borrar
				if(*cl == 8){
					printf("\b \b");
					inc--;
				} 
				else{
					putchar('*');
					c[inc++] = *cl;
				}
			}
			c[inc] = '\0';
			inc = 0;
			Acceso archivoc(u,c);
			x1=archivoc.validarclave(archivoc);
		}while(x1!=-1);
		system("cls");
		Opciones obj;
		obj.Palabras();
		obj.Agregar();
		obj.Traducir();
		obj.Backup();
		obj.Ayuda();
		obj.Salir();
		y1=mover();// llama a func mover --> retorna valor de la posicion en dond se encuentra l cursor
		do{
			if(y1>=0&&y1<=7){
				system("cls");
				menu_listar();
				listar(raiz);
				_getch();
			}
			if(y1>=11&&y1<=17){
				system("cls");
				std::cout<<"\n\t\t\t      !!Las palabras solo pueden ser agregadas por el administrador!!";
				SetConsoleTextAttribute(color,11);
				obj.consola();
				fflush(stdin);
				printf("\t\t\t\t\t          Administrador: ");
				while((*cl = _getch()) != 13){ //Validar tecla borrar
					if(*cl == 8){
						printf("\b \b");
						inc--;
					}
					else{
						putchar('*');
						x[inc++] = *cl;
					}
				}
				x[inc] = '\0';
				inc = 0;
				if(strcmp(x,y)!= 0||strcmp(x,y)==1){
					SetConsoleTextAttribute(color,13);
					printf("\n\t\t\t\t           !!Acceso Denegado. Contrase%ca incorrecta!! ",164);
					getch();
				}
				else{
					do{
						SetConsoleTextAttribute(color,15);
						system("cls");
						obj.consola();
						std::cout << "Introduzca Palabra en Ingles : ";
						std::cin >> in;
						std::cout << "Introduzca Palabra en Espanol : ";
						std::cin >> es;
						agregar(&raiz);
						std::cout<<"\n\n\t\t\t\t\t\tDesea ingresar mas datos?? 's'.\n\t\t\t\t\t\tCaso contrario cualquier tecla.";
						std::cin >> op;
					}while(op=='s' || op=='S');
				}
			}
			if(y1>=21&&y1<=28){
				system("cls");
				obj.consola();
				do{
					do{
						m=0;
						fflush(stdin);
						system("cls");
			     		system("cls");
						SetConsoleTextAttribute(color,15);
						obj.consola();
						SetConsoleTextAttribute(color,15);
						printf("\nMENU\n");
						printf("====\n");
						SetConsoleTextAttribute(color,14);
						printf("1.-English-Spanish\n",164,130);
						SetConsoleTextAttribute(color,10);
						printf("2.-Espa%col-Ingl%cs\n");
						SetConsoleTextAttribute(color,7);
						std::cout<<"3.-Salir\n";
						SetConsoleTextAttribute(color,15);
						cout<< "\n-->Ingrese la opcion a elegir: "; 
					
						gets_s(c);
						try{
							int sw,i=0,k;
							sw=0;
							k=strlen(c);
							while(i<k && sw==0){
								if(isdigit(c[i])!=0||c[i]=='.')
									i++;
								else
									throw(0);
							}
						}
						catch(...){
							cout<<"ERROR!!!\n\n";
							m=1;
						}
				}while(m!=0);
				aux=atoi(c);
				switch(aux){
				case 1:
						std::cout << "Que Palabra en Ingles desea Buscar? : ";
						std::cin >> in;
						listo = 0;
						buscar_ingles(raiz);
						if (listo == 0)
							std::cout << "Elemento no encontrado!\n";
						else {
							std::cout << "\n";
							strcpy(sonidoi, strcat(in, mp3));
							system(sonidoi);
						}
						_getch();
						listo = 0;
						system("pause");
						break;
					case 2:
						std::cout << "Que Palabra en Espanol desea Buscar? : ";
						std::cin >> es;
						listo = 0;
						buscar_espanol(raiz);
						if (listo == 0)
							std::cout << "Elemento no encontrado!\n";
						else {
							std::cout << "\n";
							strcpy(sonido, strcat(es, mp3));
							system(sonido);
						}
						_getch();
						listo = 0;
						system("pause");
						break;
					case 3:
						system("pause");
						break;	
				}
			}while(aux!=3);
			}
			if(y1>=32&&y1<=43){
				do{
					Acceso obj1;
					do{
						m=0;
					system("cls");
					SetConsoleTextAttribute(color,15);
					obj.consola();
					SetConsoleTextAttribute(color,15);
					printf("\nMENU\n");
					printf("====\n");
					SetConsoleTextAttribute(color,14);
					std::cout<<"1.-Encriptar\n";
					SetConsoleTextAttribute(color,10);
					std::cout<<"2.-Desencriptar\n";
					SetConsoleTextAttribute(color,7);
					std::cout<<"3.-Salir\n";
					SetConsoleTextAttribute(color,15);
					std::cout<<"\nIngrese la opcion: ";
					gets_s(c);
						try{
							int sw,i=0,k;
							sw=0;
							k=strlen(c);
							while(i<k && sw==0){
								if(isdigit(c[i])!=0||c[i]=='.')
									i++;
								else
									throw(0);
							}
						}
						catch(...){
							cout<<"ERROR!!!\n\n";
							m=1;
						}
						}while(m!=0);
				aux=atoi(c);
					switch(aux)
					{
					case 1:
						obj1.encriptarclave();
						system("encriptado.txt");
						system("pause");
						break;
					case 2:
						obj1.desencriptarclave();
						system("desencriptado.txt");
						system("pause");
						break;
					case 3:
						system("pause");
						break;	
					}
				}while(aux!=3);
			}
			if(y1>=46&&y1<=50){
			}
			system("cls");
			obj.Palabras();
			obj.Agregar();
			obj.Traducir();
			obj.Backup();
			obj.Ayuda();
			obj.Salir();
			y1=mover();
	}while(y1!=54&&y1!=55&&y1!=56&&y1!=57&&y1!=58);			
	SetConsoleTextAttribute(color,14);
	printf("\n\n\n\n\t\t\t\t\t\t  !!! FIN DE PROGRAMA !!!\n\n\t\t\t\t\t\t");
}

void menu_agregar()
{
	system("cls");
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                      AGREGAR PALABRAS AL TRADUCTOR                             \n";
	std::cout << "                                                                                \n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Buscar Ingles
//-------------------------------------------------------------------------------------
void menu_ingles()
{
	system("cls");
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                         BUSCAR PALABRA EN INGLES                               \n";
	std::cout << "                                                                                \n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Buscar Espanol
//-------------------------------------------------------------------------------------
void menu_espanol()
{
	system("cls");
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                        BUSCAR PALABRA EN ESPANOL                               \n";
	std::cout << "                                                                                \n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Borrar
//-------------------------------------------------------------------------------------
void menu_borrar()
{
	system("cls");
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                      BORRAR PALABRA DEL DICCIONARIO                            \n";
	std::cout << "                                                                                \n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
	std::cout << "                                                                                \n";
}
//-------------------------------------------------------------------------------------
//						    	Funcion Menu Listar
//-------------------------------------------------------------------------------------
void menu_listar()
{
	system("cls");
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
	std::cout << "                      LISTAR PALABRAS DEL TRADUCTOR                             \n";
	std::cout << "                                                                                \n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "                                                                                \n";
}

//-------------------------------------------------------------------------------------
//  			    	Funcion Agregar palabras al Diccionario
//-------------------------------------------------------------------------------------

void agregar(ARBOL* nodoarb)
{

	int det;
	if (*nodoarb == NULL) {
		*nodoarb = new(Arbol);
		if (*nodoarb != NULL) {
			strcpy_s((*nodoarb)->ingles, in);
			strcpy_s((*nodoarb)->espanol, es);
			(*nodoarb)->der = NULL;
			(*nodoarb)->izq = NULL;
		}
		else {
			system("cls");
			std::cout << "No hay memoria suficiente!";
		}
	}
	else
	{
		det = strcmp(in, (*nodoarb)->ingles);

		if (det < 0)
			agregar(&(*nodoarb)->izq);
		else
			if (det > 0)
				agregar(&((*nodoarb)->der));
			else
			{
				std::cout << "¡¡¡ Dato duplicado !!!";
			}
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion Buscar Ingles
//-------------------------------------------------------------------------------------

void buscar_ingles(ARBOL nodoarb)
{
	if (nodoarb != NULL) {
		buscar_ingles(nodoarb->izq);
		if (strcmp(in, nodoarb->ingles) == 0)
		{
			std::cout;
			std::cout;
			std::cout;
			std::cout << "                        " << nodoarb->ingles << " -> " << nodoarb->espanol;
			listo = 1;
			return;
		}
		buscar_ingles(nodoarb->der);
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion Buscar Ingles
//-------------------------------------------------------------------------------------

void buscar_espanol(ARBOL nodoarb)
{
	if (nodoarb != NULL) {
		buscar_espanol(nodoarb->izq);
		if (strcmp(es, nodoarb->espanol) == 0)
		{
			std::cout;
			std::cout;
			std::cout;
			std::cout << "                        " << nodoarb->espanol << " -> " << nodoarb->ingles;
			listo = 1;
			return;
		}
		buscar_espanol(nodoarb->der);
	}
}
//-------------------------------------------------------------------------------------
//						    	Funcion listar Palabras
//-------------------------------------------------------------------------------------


void listar(ARBOL nodoarb)
{
	if (nodoarb != NULL) {
		listar(nodoarb->izq);
		std::cout << "                            " << nodoarb->ingles << " -> " << nodoarb->espanol<<"\n";
		listar(nodoarb->der);
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacionddsimple
//-------------------------------------------------------------------------------------

void rotacionddsimple(ARBOL* nodoarb)
{
	ARBOL nda = NULL;
	nda = (*nodoarb)->der;
	(*nodoarb)->der = nda->izq;
	nda->izq = (*nodoarb);
	nda->Fe = 0;
	(*nodoarb)->Fe = 0;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotaciondidoble
//-------------------------------------------------------------------------------------

void rotaciondidoble(ARBOL* nodoarb)
{
	ARBOL nda1 = NULL, nda2 = NULL;
	nda1 = (*nodoarb)->der;
	nda2 = nda1->der;

	nda1->izq = nda2->der;
	nda2->der = nda1;
	(*nodoarb)->der = nda2->izq;
	nda2->izq = (*nodoarb);

	if (nda2->Fe == 1)
		(*nodoarb)->Fe = -1;
	else
		(*nodoarb)->Fe = 0;
	if (nda2->Fe == -1)
		(*nodoarb)->Fe = 1;
	else
		(*nodoarb)->Fe = 0;

	nda2->Fe = 0;
	(*nodoarb) = nda2;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotaciondd2
//-------------------------------------------------------------------------------------

void rotaciondd2(ARBOL* nodoarb)
{
	ARBOL nda = NULL;
	nda = (*nodoarb)->der;
	(*nodoarb)->der = nda->izq;
	nda->izq = (*nodoarb);
	nda->Fe = -1;
	(*nodoarb)->Fe = 1;
	(*nodoarb) = nda;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacionii2
//-------------------------------------------------------------------------------------

void rotacionii2(ARBOL* nodoarb)
{
	ARBOL nda = NULL;
	nda = (*nodoarb)->izq;
	(*nodoarb)->izq = nda->der;
	nda->der = (*nodoarb);
	nda->Fe = 1;
	(*nodoarb)->Fe = -1;
	(*nodoarb) = nda;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacionsimple
//-------------------------------------------------------------------------------------


void rotacioniisimple(ARBOL* nodoarb)
{
	ARBOL nda = NULL;
	nda = (*nodoarb)->izq;
	(*nodoarb)->izq = nda->der;
	nda->der = (*nodoarb);
	nda->Fe = 0;
	(*nodoarb)->Fe = 0;
	*nodoarb = nda;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacioniddoble
//-------------------------------------------------------------------------------------

void rotacioniddoble(ARBOL* nodoarb)
{
	ARBOL nda1 = NULL, nda2 = NULL;

	nda1 = (*nodoarb)->izq;
	nda2 = nda1->der;
	nda1->der = nda2->izq;
	nda2->izq = nda1;

	(*nodoarb)->izq = nda2->der;
	nda2->der = (*nodoarb);

	if (nda2->Fe == 1)
		nda1->Fe = -1;
	else
		nda1->Fe = 0;
	if (nda2->Fe == -1)
		(*nodoarb)->Fe = 1;
	else
		(*nodoarb)->Fe = 0;

	nda2->Fe = 0;
	(*nodoarb) = nda2;
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menor
//-------------------------------------------------------------------------------------

void menor(ARBOL nodoarb)
{
	if (nodoarb->izq == NULL)
	{
		strcpy_s(in, nodoarb->ingles);
		strcpy_s(es, nodoarb->espanol);
	}
	else
		menor(nodoarb->izq);
}

//-------------------------------------------------------------------------------------
//						    	Funcion Actualizarbi
//-------------------------------------------------------------------------------------

void actualizarbi(ARBOL* nodoarb, int* ban)
{
	switch ((*nodoarb)->Fe) {
	case -1:
		(*nodoarb)->Fe = 0;
		break;
	case 0:
		(*nodoarb)->Fe = 1;
		*ban = 0;
		break;
	case 1:
		switch ((*nodoarb)->der->Fe) {
		case 1:
			rotacionddsimple(&(*nodoarb));
			break;
		case -1:
			rotaciondidoble(&(*nodoarb));
			break;
		case 0:
			rotaciondd2(&(*nodoarb));
			*ban = 0;
			break;

		}
		break;
	}
}
//-------------------------------------------------------------------------------------
//						    	Funcion Actualizarbd
//-------------------------------------------------------------------------------------


void actualizarbd(ARBOL* nodoarb, int* ban)
{
	switch ((*nodoarb)->Fe) {
	case 1:
		(*nodoarb)->Fe = 0;
		break;
	case 0:
		(*nodoarb)->Fe = -1;
		*ban = 0;
		break;
	case -1:
		switch ((*nodoarb)->izq->Fe) {
		case -1:
			rotacioniisimple(&(*nodoarb));
			break;
		case 1:
			rotacioniddoble(&(*nodoarb));
			break;
		case 0:
			rotacionii2(&(*nodoarb));
			*ban = 0;
			break;

		}
		break;
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion Eliminar
//-------------------------------------------------------------------------------------

void eliminar(ARBOL* nodoarb, int* ban)
{
	ARBOL aux = NULL;

	if ((*nodoarb)->izq == NULL) {
		aux = *nodoarb;
		*nodoarb = (*nodoarb)->der;
		free(aux);
		*ban = 1;
	}
	else {
		if ((*nodoarb)->der == NULL) {
			aux = *nodoarb;
			*nodoarb = (*nodoarb)->izq;
			free(aux);
			*ban = 1;
		}
		else {
			menor((*nodoarb)->der);
			borrar(&(*nodoarb)->der, &(*ban));
			if (*ban)
				actualizarbd(&(*nodoarb), &(*ban));
		}
	}
}


//-------------------------------------------------------------------------------------
//						    	Funcion Borrar
//-------------------------------------------------------------------------------------


void borrar(ARBOL* nodoarb, int* ban)
{
	if (nodoarb == NULL)
		*ban = 0;
	else
		if (strcmp((*nodoarb)->ingles, in) == 0)
			eliminar(&(*nodoarb), &(*ban));

		else
			if (strcmp((*nodoarb)->ingles, in) > 0) {
				borrar(&(*nodoarb)->izq, &(*ban));
				if (*ban)
					actualizarbi(&(*nodoarb), &(*ban));
			}
			else {
				borrar(&(*nodoarb)->der, &(*ban));
				if (*ban)
					actualizarbd(&(*nodoarb), &(*ban));

			}
}

//-------------------------------------------------------------------------------------
//						               FIN
//-------------------------------------------------------------------------------------


