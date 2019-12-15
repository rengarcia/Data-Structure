/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JONNY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:09/12/2019                                     *
******************************************************************/
#include <iostream>
#include "ListaCircularDoble.h"
#include "Nodo.h"
#include "PersonalLibrary.h"
////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoInicio(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoInicio()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaCircularDoble::ingresoInicio(int obj)
{
    Nodo *p = new Nodo();
    p->setDatos(obj);

	if (primero == NULL)
	{
		p->setSiguiente(p);
		p->setAnterior(p);
		primero = p;
	}
	else
	{
		Nodo* ultimo = primero->getAnterior();
		p->setSiguiente(primero);
		p->setAnterior(ultimo);
		primero->setAnterior(p);
		ultimo->setSiguiente(p);
		primero = p;
	}
	//cout<<"Ingresado al inicio"<<endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaCircularDoble::ingresoFinal(int obj)
{
    Nodo *p = new Nodo();
    p->setDatos(obj);

    if (primero == NULL)
	{
	    ingresoInicio(obj);
	}
	else
	{
		Nodo* ultimo = primero->getAnterior();
		p->setSiguiente(primero);
		p->setAnterior(ultimo);
		primero->setAnterior(p);
		ultimo->setSiguiente(p);
	//	cout<<"Ingresado al final"<<endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::imprimirDatos()
// Purpose:    Implementation of ListaSimple::imprimirDatos()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaCircularDoble::imprimirDatos()
{
    int x=8,y;
	Nodo* Aux=new Nodo();
	Aux=primero;


	do{
        y=5;
		switch(Aux->getDatos())
		{
			case 0:
				color(1);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);
				break;

			case 1:
				color(2);
				gotoxy(x,y++);
				printf(" %c%c  \n",219,219);gotoxy(x,y++);
				printf("%c %c  \n",219,219);gotoxy(x,y++);
				printf("  %c   \n",219);gotoxy(x,y++);
				printf("  %c   \n",219);gotoxy(x,y++);
				printf("%c%c%c%c%c",220,220,219,220,220,220,220);gotoxy(x,y++);
				break;


			case 2:
				color(3);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("   %c \n",219);gotoxy(x,y++);
				printf(" %c%c  \n",220,219);gotoxy(x,y++);
				printf("%c%c%c%c%c",219,220,220,220,220,220,220);gotoxy(x,y++);
				break;


			case 3:
				color(4);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("   %c \n",219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);gotoxy(x,y++);
				break;

			case 4:
				color(6);
				gotoxy(x,y++);
				printf("   %c%c\n",219,219);gotoxy(x,y++);
				printf("  %c %c\n",219,219);gotoxy(x,y++);
				printf(" %c  %c\n",219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c\n",219,220,220,220,219);gotoxy(x,y++);
				printf("    %c\n",219);gotoxy(x,y++);
				break;

			case 5:
				color(7);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf(" %c   \n",219);gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,220);gotoxy(x,y++);
				printf("   %c \n",219);gotoxy(x,y++);
				printf(" %c%c  ",219,219);gotoxy(x,y++);
				break;

			case 6:
				color(12);
				gotoxy(x,y++);
				printf("  %c%c \n",220,219);gotoxy(x,y++);
				printf(" %c   \n",219);gotoxy(x,y++);
				printf("%c%c%c%c\n",219,220,220,220);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);gotoxy(x,y++);
				break;

			case 7:
				color(9);
				gotoxy(x,y++);
			    printf("%c%c%c%c%c\n",220,220,220,220,220,220,220);gotoxy(x,y++);
				printf("    %c\n",219);gotoxy(x,y++);
				printf("   %c\n",219);gotoxy(x,y++);
				printf("  %c\n",219);gotoxy(x,y++);
				printf(" %c   ",219);gotoxy(x,y++);
				break;

			case 8:
				color(10);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf(" %c%c%c ",219,219,219);gotoxy(x,y++);
			    break;

			case 9:
				color(11);
				gotoxy(x,y++);
				printf(" %c%c%c \n",219,219,219);gotoxy(x,y++);
				printf("%c   %c\n",219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c\n",219,220,220,220,219);gotoxy(x,y++);
				printf("    %c\n",219);gotoxy(x,y++);
				printf(" %c%c%c ",220,220,219);gotoxy(x,y++);
			    break;
		}
		x+=6;
        Aux=Aux->getSiguiente();
	}while(Aux!=primero);
}


////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
int ListaCircularDoble::tamLista()
{
    int i=0;
    if(!vacia())
    {
        Nodo *p = primero;
        do
        {
            cout << p->getDatos()<<" ";
            p = p->getSiguiente();
            i++;
        }
    while (p != primero);
    cout << "\n";
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return i;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
ListaCircularDoble::ListaCircularDoble(){
    primero = NULL;
}


////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
void ListaCircularDoble::destruir(){
    Nodo *p = primero->getSiguiente();
    Nodo *actual;
    while( p != primero){
        actual = p;
        p = p->getSiguiente();
        delete actual;
    }
    delete primero;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
void ListaCircularDoble::setPrimero(Nodo *newPrimero){
    primero = newPrimero;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
Nodo* ListaCircularDoble::getPrimero(){
   return primero;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
bool ListaCircularDoble::vacia()
{
	if (primero == NULL)
		return true;
	else
		return false;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
int ListaCircularDoble::cantidad()
{
	int cant = 0;
	if (!vacia())
	{
		Nodo* reco = primero;
		do {
			cant++;
			reco = reco->getSiguiente();
		}while (reco != primero);
	}
	return cant;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
void ListaCircularDoble::borrarPosicion(int pos)
{
    if (pos <= cantidad())
    {
        if (pos == 1)
        {
            if (cantidad() == 1)
            {
                delete primero;
                primero = NULL;
                //cout<<"Elemento eliminado en la posicion "<<pos<<endl;
            }
            else
            {
                Nodo* bor = primero;
                Nodo* ultimo = primero->getAnterior();
                primero = primero->getSiguiente();
                ultimo->setSiguiente(primero);
                primero->setAnterior(ultimo);
                delete bor;
               // cout<<"Elemento eliminado en la posicion "<<pos<<endl;
            }
        }
        else
        {
            Nodo* reco = primero;
            for (int f = 1; f <= pos - 1; f++){
                reco = reco->getSiguiente();
            }
            Nodo* bor = reco;
            Nodo* anterior = reco->getAnterior();
            reco = reco->getSiguiente();
            anterior->setSiguiente(reco);
            reco->setAnterior(anterior);
            delete bor;
            //cout<<"Elemento eliminado en la posicion "<<pos<<endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
void ListaCircularDoble::recursivo(Nodo *p, int posicion, bool bandera,int&puntos){
    p = primero;
    posicion = 1;
    do
    {
        if(cantidad() != 1)
        {
            if(primero == NULL)
            {
                bandera = false;
                break;
            }
            else
            {
                if(p->getDatos() == p->getSiguiente()->getDatos())
                {
                    borrarPosicion(posicion);
                    borrarPosicion(posicion);
                    puntos=puntos+25;
                    bandera = true;
                    break;
                }

                if(p->getDatos() == p->getAnterior()->getDatos())
                {
                    borrarPosicion(posicion);
                    if(posicion == 1)
                    {
                        borrarPosicion(cantidad());
                    }
                    else
                    {
                        borrarPosicion(posicion-1);
                    }
                    puntos=puntos+25;
                    bandera = true;
                    break;
                }
                bandera = false;

            }
            bandera = false;
        }
        bandera = false;
        posicion++;
        p = p->getSiguiente();
    }
    while(p != primero);
    if(!bandera){
        return;
    }else{
        recursivo(p,posicion,bandera,puntos);
    }

}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
void ListaCircularDoble::borrarIguales(int &puntos)
{
    Nodo *p = new Nodo();
    p = primero;
    int posicion = 1;
    recursivo(p,posicion,false,puntos);
}


////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
void ListaCircularDoble::insertarPosicion(int obj, int pos)
{

    if (pos <= cantidad())
    {
        if (pos == 1)
        {
            ingresoInicio(obj);
        }
        else
        {
            Nodo* reco = primero;
            for (int f = 1; f < pos - 1; f++){
                reco = reco->getSiguiente();
            }
            Nodo* nuevo = new Nodo();
            nuevo->setDatos(obj);
            nuevo->setSiguiente(reco->getSiguiente());
            nuevo->setAnterior(reco);
            reco->getSiguiente()->setAnterior(nuevo);
            reco->setSiguiente(nuevo);
        }
    }else{
        if(pos>=cantidad()){
            ingresoFinal(obj);
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////
int ListaCircularDoble::buscarPosicion(int posicion)
{
    int cont = 1;
    Nodo *p = primero;
    do{
        if(cont == posicion){
            return p->getDatos();
        }else{
             p = p->getSiguiente();
        }
        cont++;
    }while(p != primero);

    return 0;
}
