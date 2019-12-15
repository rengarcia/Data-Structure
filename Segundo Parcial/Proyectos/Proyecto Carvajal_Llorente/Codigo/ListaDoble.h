/**
	Universidad de las Fuerzas Armadas ESPE
    Nombre: Luis Carvajal, Elian Llorente
    NRC: 2967
    Fecha creacion: 30/11/2019
	Fecha ultima modificacion:	12/12/2019
	Docente: Ing. Fernando Solis
*/
#include "Nodo.h"
#include <iostream>
#include <cstdio>

using namespace std;


class ListaDoble
{
	private:
		Nodo *lista;
		string jugador;
		int contadorNodo;
		int puntaje;

	public:
		void insertarAlFinal(int);
		void impresion();
		void impresionLista();
		void generarLista();
		void listaTetris(int,int);

		void juegoTetris();
		int posicionAIndice(int x);
		void deleteNumber(int,int );
		void siguienteNumero(int,Nodo * );
		void deleteNodo(Nodo *Actual);
		ListaDoble()
		{
			lista=NULL;
			contadorNodo=0;
			puntaje=0;
		}

};

/**
 * @brief Funcion que imprime el resultado del Juego
 */

void ListaDoble::impresion()
{
	Nodo* Aux=new Nodo();

	Aux=lista;


	if(Aux == NULL){

		gotoxy(20,10);cout<<"\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
		cout<<"\n||||                                                                      ||||\n";
		cout<<"\n||||                NO HAS INICIADO EL JUEGO                              ||||";
		cout<<"\n||||                                                                      ||||";
		cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n";

	}

	else
    {
        fstream enter;
        enter.open("tetrisPixel.txt",fstream::out); //para leer in, para salir es out escribir
    	gotoxy(20,15);
		cout<<"Jugador: "<<jugador;
    	gotoxy(20,17);
	    cout<<"LA LISTA EN LA QUE PERDISTE ES: ";
	    gotoxy(20,19);
		while(Aux != NULL)
		{

	        printf("%d, ",Aux->getNumero());
	        Aux=Aux->getSiguienteDireccion();
	    }
		gotoxy(20,21);printf("Su Puntaje es: %d \n\n",puntaje);
		enter<<"Jugador: "<<jugador<<". Tu Puntaje es: "<<puntaje<<endl;
	}
}

/**
 * @brief Funcion que inserta al final de la lista la pieza en el Juego
 * @param numero que se agrega al final de la lista
 */
void ListaDoble::insertarAlFinal(int numero)
{
	Nodo* Nuevo=new Nodo();
	Nodo* Actual=new Nodo();

	if(contadorNodo==0)
	{
		Actual->setNumero(numero);
		Actual->setAnteriorDireccion(NULL);
		Actual->setSiguienteDireccion(NULL);
		lista=Actual;
	}
	else
	{
		Actual=lista;
		while(Actual->getSiguienteDireccion()!=NULL)
		{
			Actual=Actual->getSiguienteDireccion();
		}
		Nuevo->	setNumero(numero);
        Nuevo->	setSiguienteDireccion(NULL);
        Actual->setSiguienteDireccion(Nuevo);
        Nuevo->	setAnteriorDireccion(Actual);
	}
	contadorNodo++;
}
/**
 * @brief Funcion que genera la lista randomica en el fondo del tablero del Juego
 */

void ListaDoble::generarLista()
{
	Nodo* Aux=new Nodo();
	int numero;
	for(int i=0;i<17;i++)
	{
		numero=rand()%10;
		insertarAlFinal(numero);
	}
}
/**
 * @brief Funcion inserta los elementos en el tablero
 * @param posicion, lugar en el que se encuentra 
 * @param numero, el elemento que se insertara en esa posicion
 */
void ListaDoble::listaTetris(int posicion,int numero)
{
	Nodo *Aux=new Nodo();
	Nodo *Actual=new Nodo();
	Nodo *Nuevo=lista;
	int cont;

	while(Nuevo!=NULL)
	{
		if(numero==Nuevo->getNumero())
		{
			cont++;
			break;
		}
		Nuevo=Nuevo->getSiguienteDireccion();
	}

	switch(posicion)
	{
		case 1:
			if(cont>0)
			{
				Nuevo=Nuevo->getSiguienteDireccion();
				Nuevo->setAnteriorDireccion(NULL);
				lista=Nuevo;
				contadorNodo--;
			}
			else
			{

				Aux->setNumero(numero);
				Aux->setSiguienteDireccion(lista);
				Aux->setAnteriorDireccion(NULL);
				Actual->setAnteriorDireccion(Aux);
				lista=Aux;
				contadorNodo++;
			}
			break;
	}
}

int ListaDoble::posicionAIndice(int x){
	return (x-31)/4;
}

/**
 * @brief Funcion que elimina el nodo Actual para apuntar al siguiente
 * @param *Actual nodo
 */
void ListaDoble::deleteNodo(Nodo *Actual){
	Nodo* Siguiente=new Nodo();
	Nodo* Anterior=new Nodo();
	if(Actual->getAnteriorDireccion()!=NULL&&Actual->getSiguienteDireccion()!=NULL){
		Anterior=Actual->getAnteriorDireccion();
		Siguiente=Actual->getSiguienteDireccion();
		Anterior->setSiguienteDireccion(Siguiente);
		Siguiente->setAnteriorDireccion(Anterior);
		delete(Actual);
	}else if(Actual->getAnteriorDireccion()==NULL){
		lista=Actual->getSiguienteDireccion();
		delete(Actual);
	}else if(Actual->getSiguienteDireccion()==NULL){
		Anterior=Actual->getAnteriorDireccion();
		Anterior->setSiguienteDireccion(NULL);
		delete(Actual);
	}
}

/**
 * @brief Funcion que hace que el anterior apunte al siguiente del que se eliminira
 * @param numero que coincide con otro elemento de la lista
 * @param *aux guarda el siguiente y mueve la lista
 */
void ListaDoble::siguienteNumero(int numero,Nodo *aux){
	if(aux==NULL||(aux->getNumero()!=(numero+1))){
		return ;
	}else{
		if(aux->getNumero()==(numero+1)){
			puntaje++;
			deleteNodo(aux);
		}
	}
}

/**
 * @brief Funcion que elimina cuando ambos elementos coninciden
 * @param indice posicion en la que se encuentra
 * @param numero numero en lista
 */
void ListaDoble::deleteNumber(int indice,int numero){
	int cont=0;
	Nodo* Actual=new Nodo();
	Actual=lista;
	while(Actual!=NULL){
		if(indice==cont){
			if(Actual->getNumero()==numero)//borra el numero
			{
				contadorNodo--;
				puntaje++;
				deleteNodo(Actual);
				siguienteNumero(numero,Actual);
			}
			else
			{
				insertarAlFinal(numero);
			}
			Actual=NULL;
		}
		else
		{
			Actual=Actual->getSiguienteDireccion();
		}
		cont++;
	}
}

/**
 * @brief Funcion general del Juego
 */

void ListaDoble::juegoTetris()
{

	bool primera=true;
	char tecla=0;
	int x=31,y=4;
	int col,fil,j=0;
	int numero;
	int i=0;
	srand(time(NULL));
	lista=NULL;
	contadorNodo=puntaje=0;
    gotoxy(20,15);
    printf("NOMBRE DEL JUGADOR: ");
    cin>>jugador;
    fflush(stdin);
    generarLista();

	do
	{
        Sleep(200);
		system("cls");

			margen();


		if(primera)
		{
			numero=0+rand()%9;
			primera=false;
			gotoxy(4,45);
		}
		if((x==10)&&(y==23)) /// aqui mandar cuando encuentre el numero
		{
			listaTetris(1,numero);
			numero=0+rand()%9;
			x=34;y=3;
		}
		impresionLista();
		gotoxy(x,y);
		numbers(numero,x,y);
		color(15);

        y++;
        if(y>=37){
			deleteNumber(posicionAIndice(x),numero);
			y=4;
            primera=true;
        }
        if(kbhit()){
            switch(getch())
            {
                case TECLA_DERECHA:
                    x+=4;
                    if(x>95)
                        x=31;
                    break;
                case TECLA_IZQUIERDA:
                    x-=4;
                    if(x<31)
                        x=95;
                    break;
                case TECLA_ENTER:
                    tecla = TECLA_ENTER;
                    break;

            }

        }

		if(contadorNodo==18)
			tecla=TECLA_ENTER;
	}while(tecla!=TECLA_ENTER);
	system("cls");

}

/**
 * @brief Funcion que imprime las piezas en el tablero
 */

void ListaDoble::impresionLista()
{
	int x=31,y;
	Nodo* Aux=new Nodo();
	Aux=lista;

	while(Aux != NULL)
	{
		y=38;
		switch(Aux->getNumero())
		{
			case 0:
				color(1);//num 0 azul
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c0%c%c",219,219,219);gotoxy(x,y++);
				color(15);//num 0 azul

				break;

			case 1:
				color(2);// 1 verde
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c1%c%c",219,219,219);gotoxy(x,y++);
				break;


			case 2:
				color(11);// 2 celeste
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c2%c%c",219,219,219);gotoxy(x,y++);
				break;


			case 3:
				color(12);// 3 rojo
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c3%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 4:
				color(5);// 4 morado
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c4%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 5:
				color(6);// 5 amarillo
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c5%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 6:
				color(15);// 6 blanco
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c6%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 7:
				color(8);// 7 gris
				gotoxy(x,y++);
			    printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c7%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 8:
				color(13);// 8 mas celeste
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c8%c%c",219,219,219);gotoxy(x,y++);
			    break;

			case 9:
				color(10);// 9 verde claro
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c9%c%c",219,219,219);gotoxy(x,y++);
			    break;
		}
		x+=4;//separacion entre cubos
        Aux=Aux->getSiguienteDireccion();
    }
}
