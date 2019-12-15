/**************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Maria Belen Ceron, Alex Chicaiza
 *	NRC: 2967
 *	Fecha creacion: 08/11/2019
 *	Fecha ultima modificacion:	12/12/2019
 *	Docente: Ing. Fernando Solis
***************************************************************/
#include "Nodo.h"
#include <iostream>

#define __Tetris_Nodo_h

class ListaDoble
{
public:
    ListaDoble()
    {
        lista=NULL;
        contadorNodo=0;
        puntaje=0;
    }
    void insertarAlFinal(int);

    void impresion();
    void impresionLista();
    void generarLista();
    void listaTetris(int,int);
    void imprimir();

    void juegoTetris();
    int posicionAIndice(int x);
    void deleteNumber(int,int );
    void siguienteNumero(int,Nodo * );
    void deleteNodo(Nodo *Actual);
private:
    Nodo *lista;
    std::string jugador;
    int contadorNodo;
    int puntaje;
};

void ListaDoble::impresion()
{
	Nodo* Aux=new Nodo();

	Aux=lista;


	if(Aux == NULL){
	}

	else
    {
    	gotoxy(20,15);
		cout<<"Jugador: "<<jugador;
    	gotoxy(20,17);
	    cout<<"lista";
	    gotoxy(20,19);
		while(Aux != NULL)
		{

	        printf("%d, ",Aux->getNumero());
	        Aux=Aux->getSiguienteDireccion();
	    }
		gotoxy(20,21);printf("Su Puntaje es: %d \n\n",puntaje);
	}
}



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





void ListaDoble::generarLista()
{
	Nodo* Aux=new Nodo();
	int numero;
	for(int i=0;i<3;i++)
	{
		numero=rand()%10;
		insertarAlFinal(numero);
	}
}







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
				cout<<numero<<endl;
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






void ListaDoble::juegoTetris()
{

	bool primera=true;
	char tecla=0;
	int x=31,y=4;
	int col,fil,j=0;
	int numero;
	char nombre[200];
	int i=0;
	srand(time(NULL));
	lista=NULL;
	contadorNodo=puntaje=0;


		gotoxy(20,15);
		printf("NOMBRE DEL JUGADOR: ");
		cin>>jugador;
		fflush(stdin);
		system("cls");
		generarLista();
		margen();
		impresionLista();
		gotoxy(110,20);
		cout<<"Jugador: "<<jugador;
		gotoxy(110,21);cout<<"lista:";
		imprimir();


	do
	{

        Sleep(200);

			borrar(38);


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
			borrar(39);
			impresionLista();
			imprimir();
		}
		//impresionLista();
		gotoxy(x,y);
		numbers(numero,x,y);
		color(15);
		y++;
        if(y>=37){
                deleteNumber(posicionAIndice(x),numero);
                y=4;
                primera=true;
                borrar(39);
                impresionLista();
                imprimir();
        }

        if(kbhit()){
            switch(getch())
            {
                case TECLA_DERECHA:
                    x+=4;
                    if(x>95)
                        x=95;
                    break;
                case TECLA_IZQUIERDA:
                    x-=4;
                    if(x<31)
                        x=31;
                    break;
                case TECLA_ENTER:
                    tecla=TECLA_ENTER;
                    break;
            }
        }
		if(contadorNodo==18)
			tecla=TECLA_ENTER;
	}while(tecla!=TECLA_ENTER);
	system("cls");

}



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

				color(1);// num 0 azul
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 0 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);

				break;

			case 1:
				color(2);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 1 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
				break;


			case 2:
				color(11);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 2 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
				break;


			case 3:
				color(12);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 3 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
				break;

			case 4:
				color(5);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 4 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
				break;

			case 5:
				color(6);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 5 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
				break;

			case 6:
				color(15);
				gotoxy(x-1,y);
				printf("|   |");gotoxy(x,y++);
				printf("| 6 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
				break;

			case 7:
				color(8);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 7 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
				break;

			case 8:
				color(13);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 8 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
			    break;

			case 9:
				color(10);
				gotoxy(x-1,y-1);
				printf("|   |");gotoxy(x,y++);
				printf("| 9 |");gotoxy(x,y++);
				printf("|   |",219,219,219,219);gotoxy(x,y++);
			    break;
		}
		x+=4;//separacion entre cubos
        Aux=Aux->getSiguienteDireccion();
    }
}


void ListaDoble::imprimir()
{
	Nodo* Aux=new Nodo();
	Aux=lista;
    gotoxy(110,22);
    cout<<"                                                        ";
    gotoxy(110,22);
    fstream enter;
    enter.open("solucion.txt",fstream::app);
    enter<<"solucion "<<"*"<<endl<<endl;

	while(Aux != NULL)
	{
		cout<<Aux->getNumero()<<", ";
		enter<<Aux->getNumero();
		Aux=Aux->getSiguienteDireccion();
    }
    enter<<endl;
}

