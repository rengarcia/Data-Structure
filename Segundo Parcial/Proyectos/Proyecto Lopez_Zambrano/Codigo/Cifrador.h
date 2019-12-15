#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

void encriptar(int aumento, const char* newNombreArchivo, const char* newNombreArchivoEncriptado) {
	char c;
	const char* nombreArchivo = newNombreArchivo;//"solucion.txt"
	const char* nombreArchivoEncriptado = newNombreArchivoEncriptado;//"solucionencriptada.txt";

	FILE* ptr;
	FILE* ptr2;
	#pragma warning (disable : 4996)
	ptr = fopen(nombreArchivo, "r");
	ptr2 = fopen(nombreArchivoEncriptado, "w");

	if (ptr == NULL || ptr2 == NULL) {
		cout<<"No se pudo abrir los archivos..."<<endl;
		system("pause");
		return;
	}

	//ABRO EL ARCHIVO Y A CADA CARACTER LO MODIFICO
	while (fscanf(ptr, "%c", &c) != EOF) {
		putc((c + aumento), ptr2);

	}
	cout<<"Se escribio correctamente en el archivo..."<<endl;
	fclose(ptr);
	fclose(ptr2);
	system("pause");
}

void desencriptar(int aumento, const char* newNombreArchivoEncriptado, const char* newNombreArchivoDesencriptado) {
	char c;
	const char* nombreArchivoEncriptado = newNombreArchivoEncriptado;//"solucionencriptada.txt";
	const char* nombreArchivoDesencriptado = newNombreArchivoDesencriptado;//"soluciondesencriptado.txt";

	FILE* ptr;
	FILE* ptr2;

	ptr = fopen(nombreArchivoEncriptado, "r");
	ptr2 = fopen(nombreArchivoDesencriptado, "w");

	if (ptr == NULL || ptr2 == NULL) {
		printf("No se pudo abrir los archivos...\n");
		system("pause");
		return;
	}

	//ABRO EL ARCHIVO Y A CADA CARACTER LO MODIFICO
	while (fscanf(ptr, "%c", &c) != EOF) {
		putc((c - aumento), ptr2);

	}
	printf("\nSe desencripto correctamente en el archivo...\n");
	fclose(ptr);
	fclose(ptr2);
	system("pause");
}
