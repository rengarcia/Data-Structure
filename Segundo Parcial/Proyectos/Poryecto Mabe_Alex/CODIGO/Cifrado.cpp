#include "Cifrado.h"

void Cifrado::encriptado() {
    char car;
    archivo = fopen("solucion.txt", "rb");
    nuevo = fopen("SolucionActualizada.txt", "wb");
    if (nuevo == NULL) {
        cout << "Error al abrir el archivo nuevo\n";
    }

    if (archivo == NULL) {
        cout << "Error al abrir el archivo\n";
    }
    while (fread(&car, 1, 1, archivo) != 0) {
        car += 20;
        fwrite(&car, 1, 1, nuevo);
    }
    fclose(nuevo);
    fclose(archivo);
}
void Cifrado::desencriptado() {
    char car;
    archivo = fopen("solucion.txt", "wb"); //FALTA
    nuevo = fopen("SolucionActualizada.txt", "rb");

    if (nuevo == NULL) {
        cout << "Error al abrir el archivo nuevo\n";
    }

    if (archivo == NULL) {
        cout << "Error al abrir el archivo\n";
    }

    while (fread(&car, 1, 1, nuevo) != 0) {
        car -= 20;
        fwrite(&car, 1, 1, archivo);
    }
    fclose(nuevo);
    fclose(archivo);
}
