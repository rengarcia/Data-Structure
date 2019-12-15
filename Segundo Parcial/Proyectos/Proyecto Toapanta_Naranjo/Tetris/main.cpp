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
#include "miniwin.h"
#include <iostream>
#include<stdlib.h>
#include "Piezas.h"
#include <windows.h>
#include "ManejoMemoria.h"
#include<time.h>
#include "ListaCircularDoble.h"
#include "ManejoTablero.h"
using namespace miniwin;
using namespace std;
int main()
{
    vredimensiona(900, 800);
    srand(time(NULL));
    int numPieza,tic=0,t,**tablero,numPiezaS,puntos=0,nivel=1,tiempo=60;
    ListaCircularDoble lista;
    bool salir=true,bandera=true;
    Piezas p;
    tablero=reservar(15,30);
    encerar(tablero,15,30);
    //Inicio de mi lista
    *(*(tablero+13)+1)=3;
    lista.ingresoFinal(3);
    *(*(tablero+13)+2)=2;
    lista.ingresoFinal(2);
    *(*(tablero+13)+3)=1;
    lista.ingresoFinal(1);
    numPieza=1+rand()%(10-1);//Saca un numero aleatorio que da el numero de mi pieza a ingresar
    //Fin de mi lista
    //Empezara de aqui mi funcion
    do//Por el momento se repite n veces no hay salida toca buscar
    {
        numPiezaS=1+rand()%(10-1);
        int x=10,y=0;
        bool bandera=false ;
        p.setX(x);//cambia la posicion de mi pieza
        p.setY(y);
        agregarPosicion(tablero,x,y,p.unaPieza(numPieza));//coloca la pieza en la parte de arriba con cordenadas x y
        t=tecla();

        cout<<endl;
        refresca();
        bandera=true;
        while(y!=13 && bandera==true)
        {
            //sale de mi bucle cuado bandera=pieza toca la otra pieza y y sea ==19= tamaño del tablero
            if(t==ESCAPE)
            {
                break;
            }
            if(tic>5)//funcion para que se baje solo las piesas
            {
                tic=0;
                t=ABAJO;
            }
            if(t==DERECHA)//se mueve hacia la derecha
            {
                if(x<=11)//no puede pasar el borde de la patalla
                {
                    agregarPosicion(tablero,x,y,0);
                    x++;
                }
            }
            else if(t==IZQUIERDA)//izquierda
            {
                if(x>1)// no pude pasar fuera de la pantalla
                {
                    agregarPosicion(tablero,x,y,0);
                    x--;
                }
            }
            else if(t==ABAJO)// se mueva para abajo
            {
                agregarPosicion(tablero,x,y,0);
                y++;
                agregarPosicion(tablero,x,y,p.unaPieza(numPieza));
                lista.imprimirDatos();
                margenJuego(numPiezaS,nivel,puntos,lectura());
                escribirArchivo(tablero,14,13);
            }
            if(t!=NINGUNA)//si no resive ninguna tecla
            {
                borra();//borra la anterior para dar una simulacion de movimiento
                p.setX(x);//cambio la posiciones
                p.setY(y);
                if(colision(tablero,p))//comprueba si existe una pieza abajo de ella
                {
                    margenJuego(numPiezaS,nivel,puntos,lectura());
                    pintar(tablero,14,13);
                    p.unaPieza(numPieza);
                    refresca();
                    bandera=false;
                }
                else
                {
                    margenJuego(numPiezaS,nivel,puntos,lectura());
                    pintar(tablero,14,13);
                    p.unaPieza(numPieza);
                    lista.imprimirDatos();
                    cout<<endl;
                    refresca();
                }
            }
            espera(tiempo);
            tic++;
            t=tecla();
        }
        lista.insertarPosicion(numPieza,x);
        lista.borrarIguales(puntos);
        encerar(tablero,15,30);
        llenarNuevaTabla(tablero,lista);
        system("cls");
        lista.imprimirDatos();
        numPieza=numPiezaS;
        manejoNiveles(puntos,nivel,tiempo);
    }
    while(t!=ESCAPE);
    //terminara aqui
    system("txt2pdf.exe MovimientoTetris.csv Movimiento.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
    archivoJuego(lectura(),nivel,puntos);
    liberarMemoria(tablero,16);
    mensaje("FIN DEL JUEGO :D\nESTE ES TU LISTA :3");
    vcierra();
    system("cls");
    lista.imprimirDatos();
    refresca();
    return 0;
}
