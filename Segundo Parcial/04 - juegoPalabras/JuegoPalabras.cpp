/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
ESTRUCTURA DE DATOS
ZAMBRANO ANDRES
*/

#include <iostream>
#include "Lista.cpp"
#include "ingreso.h"
using namespace std;

void presentacion();
void perdida();
string pedirFrase();

int main(){
	Lista historia;
	bool flag;
	bool juego=true;
	string frase="";
	string ultPalabra="";
	
	presentacion();
	
	historia.ingresarDatoFinal(pedirFrase());
	cout<<"palabra ingresada correctamente"<<endl;
	system("pause");
	
	do{
		system("cls");
		fflush(stdin);

		frase = ingresarSoloTexto("Ingresa la/las palabra(s) anteriores y una palabra nueva: ");
		
		flag  = historia.verificarCadena(frase);
		
		if(flag){
			cout<<"BIEN HECHO :D !"<<endl;
			ultPalabra = historia.obtenerUltimaPalabra(frase);
			historia.ingresarDatoFinal(ultPalabra);
			historia.imprimir();
			juego = true;
			ultPalabra.clear();
			system("pause");
		}
		else
		{
			cout << "Error te equvocaste!!" << endl;
			historia.imprimir();
			perdida();
			juego = false;
			historia.~Lista();
			
		}

	}while(juego);
	system("pause");
	return 0;
}


void presentacion()
{
	cout<<"*****************************************************************"<<endl;
	cout<<"*************** BIENVENIDO AL JUEGO DE LA HISTORIA **************"<<endl;
	cout<<"*****************************************************************"<<endl;
}

void perdida()
{
	cout<<"*****************************************************************"<<endl;
	cout<<"*************** PERDISTE ----- FIN DE LA HISTORIA  **************"<<endl;
	cout<<"*****************************************************************"<<endl;
}

string pedirFrase(){
	string frase="";
	frase = ingresarSoloTexto("Ingresa nueva palabra: ");
	return frase;
}

