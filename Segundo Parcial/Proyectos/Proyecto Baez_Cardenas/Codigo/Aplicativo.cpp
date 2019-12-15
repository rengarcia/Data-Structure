#include "ClaseNodo.h"
#include "iostream"

int main()
{
	Nodo Obj;
	Nodo *Cabecera;
	Cabecera=NULL;
	int num;
	int opc=0;
	do
	{
		system("cls");
		printf("\n\t\t\t\t    UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n");
		printf("\t\t\t\t\t\tESTRUCTURA DE DATOS\n");
		printf("\nMENU\n");
		printf("====\n");
		std::cout<<"1.-Insertar\n";
		std::cout<<"2.-Verificar si la lista esta vacia\n";
		std::cout<<"3.-Imprimir lista\n";
		std::cout<<"4.-Salir\n";
		std::cout<<"Ingrese la opcion: ";
		std::cin>>opc;
		switch(opc)
		{
		case 1:
			std::cout<<"Ingrese el dato: ";
			std::cin>>num;
			Cabecera=Obj.Insertar(&Cabecera,num);
			Obj.Imprimir(Cabecera);
			system("pause");
			break;
		case 2:
			if(Obj.empty(Cabecera))
			{
				std::cout<<"La lista esta vacia\n";
				Obj.Imprimir(Cabecera);
			}
			else{
				std::cout<<"La lista no esta vacia y es: \n";
				Obj.Imprimir(Cabecera);
			}
			system("pause");
			break;
		case 3:
			printf("\nLos datos ingresados son: \n");
			Obj.Imprimir(Cabecera);
			system("pause");
			break;
		case 4:
			system("pause");
			break;	
		}
	}while(opc!=4);
}






