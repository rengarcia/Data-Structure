#include "Tablero.h"
#include "Menu.h"
#include "Cifrador.h"
#include "Imagen.h"




int main()
{
	Tablero tablero;
	string s;
	bool nuevoJuego = true;
	Menu* menu = new Menu();
	string titulo = "MENU DE OPCIONES";
	string* opciones = new string[8];
	*(opciones + 0) = "Aplicacion";
	*(opciones + 1) = "Imagen";
	*(opciones + 2) = "Encriptar archivo";
	*(opciones + 3) = "Desencriptar archivo";
	*(opciones + 4) = "Generar barcode";
	*(opciones + 5) = "Generar PDF";
	*(opciones + 6) = "Ayuda";
	*(opciones + 7) = "Salir";

	int numOpciones = 8;
	int opcion;
	

	do {
		opcion = menu->menu(titulo, opciones, numOpciones);
		system("cls");
		switch (opcion) {
		case 1:
			while (nuevoJuego) {
				tablero.inicializarTablero();
				while (tablero.jugar());
				cout << "Quieres juegar de nuevo? (y para si, cualquier otra tecla para no) ";
				cin >> s;
				if (s != "y")
					nuevoJuego = false;
			}
			system("pause");
			break;
		case 2:
			hConWnd = GetConsoleWndHandle();
			if (hConWnd)
			{
				BCX_Bitmap((char*)"logo.bmp", hConWnd, 123, 1, 1, 0, 0);
				//system("pause");
				Sleep(10000);
			}
			system("pause");
			break;
		case 3:
			encriptar(2020, "Soluciones/solucion.txt", "Soluciones/solucionencriptada.txt");
			break;
		case 4:
			desencriptar(2020, "Soluciones/solucionencriptada.txt", "Soluciones/soluciondesencriptada.txt");
			break;
		case 5:
			system("java -jar Generar_barcode.jar");
			break;
		case 6:
			system("java -jar textToPdf.jar");
			break;
		case 7:
			system("ayuda.chm");
			break;
		case 8:
			cout << "Hasta pronto joven" << endl;
			break;
		}
	} while (opcion != 8);
	
	delete[] opciones;
	return 0;
}


