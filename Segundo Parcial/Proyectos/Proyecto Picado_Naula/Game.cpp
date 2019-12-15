/******************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
 * CARRERA: Ingenieria de Software                                 *
 * SEMESTRE: Tercer semestre                                       *
 * MATERIA: Estructura de Datos                                    *
 * NRC: 2967                                                       *
 * ESTUDIANTES: Jonathan Picado                                    *
 *              Cesar Naula                                        *
 ******************************************************************/

#include "PersonalLibrary.h"
#include "ListaDoble.h"

void encriptarArchivo() {
    FILE *encriptame;
    FILE *encriptado;

    system("cls");
    printf("Importante:\n");
    printf(" * El archivo a ser encriptado debe llamarse 'encriptame.txt'.\n");
    printf(" * El archivo 'encriptame.txt' debe estar en la raiz del ejecutable.\n");
    printf("Pulse Enter para proceder con el proceso de encriptacion.\n");

    getchar();

    encriptame = fopen("encriptame.txt", "r");
    encriptado = fopen("encriptado.txc", "w");

    while (!feof(encriptame)) {
        fputc(fgetc(encriptame) + 3, encriptado);
    }

    fclose(encriptame);
    fclose(encriptado);

    printf("Listo. Pulsa Enter para salir.\n");

    getchar();

    exit(0);
}

void desencriptarArchivo() {
    FILE *encriptado;
    FILE *desencriptado;

    system("cls");
    printf("Importante:\n");
    printf(" * El archivo a ser desencriptado debe llamarse 'encriptado.txc'.\n");
    printf(" * El archivo 'encriptado.txc' debe estar en la raiz del ejecutable.\n");
    printf("Pulse Enter para proceder con el proceso de desencriptacion.\n");

    getchar();

    encriptado = fopen("encriptado.txc", "r");
    desencriptado = fopen("desencriptado.txt", "w");

    while (!feof(encriptado)) {
        fputc(fgetc(encriptado) - 3, desencriptado);
    }

    fclose(encriptado);
    fclose(desencriptado);

    printf("Listo. Pulsa Enter para salir.\n");

    getchar();

    exit(0);
}

void encrip(){
    int opcion;

    printf("Escoja una opcion(1-3):\n");
    printf(" 1 - Encriptar archivo .txt.\n");
    printf(" 2 - Desencriptar archivo .txc\n");
    //printf(" 3 - Salir\n");
    printf("Opcion: ");
    scanf("%i", &opcion);
    if (opcion == 1) {
        encriptarArchivo();
    } else if (opcion == 2) {
        desencriptarArchivo();
    } else {
        exit(0);
    }
}


int main(int argc, char** argv) {
    bool flag = true, flagGame = true;
    int opcion, opcionJuego;
    const char *opciones[] = {"1) Juego.", "2) Imagen Pixeleada.", "3) Generar PDF.", "4) Codigo QR.", "5) Ayuda\"F1\".","6) Encriptar y desecriptar\".", "7) Salir / Exit."};
    const char *opcionesJuego[] = {"1) Comenzar juego.", "2) Volver al Menu Principal."};
    ListaDoble *ObjJuego = new ListaDoble;
    AltEnter();
    do {
        flag = true;
        opcion = menu("Menu Principal", opciones, 7);
        system("cls");
        switch (opcion) {
            case 1:
                do {
                    flagGame = true;
                    opcionJuego = menu("Juego", opcionesJuego, 2);
                    system("cls");
                    switch (opcionJuego) {
                        case 1:
                            color(15);
                            printf("\n\n\t\t\t\t");
                            ObjJuego->juegoTetris(0);
                            ShellExecute(NULL, TEXT("open"), TEXT("Extras\\WinAppMSAgentsManagementQR.exe"), NULL, NULL, SW_SHOWNORMAL);
                            system("start Extras\\CreateCodigoQR.jar");
                            break;
                        case 2:
                            flagGame = false;
                            break;
                    }
                    if (opcionJuego != 4) {
                        printf("Presione cualquier tecla para volver al menu . . .");
                        getch();
                    }
                } while (flagGame);
                break;
            case 2:
/*
                    system("cls");
                    system("java -jar pixel.jar");
                    system("macara.jpg");
                    system("image_pixelated.jpg");
                    cout<<"Imagen Pixeleada\n";
                    system("Pause");
                    system("cls");*/

                ShellExecute(NULL, TEXT("open"), TEXT("Extras\\WinAppMSAgentsManagementImage.exe"), NULL, NULL, SW_SHOWNORMAL);
                ShellExecute(NULL, TEXT("open"), TEXT("Extras\\image.exe"), NULL, NULL, SW_SHOWNORMAL);
                break;
            case 3:
                ShellExecute(NULL, TEXT("open"), TEXT("Extras\\WinAppMSAgentsManagementPDF.exe"), NULL, NULL, SW_SHOWNORMAL);
                system("start Extras\\CreatePDF.jar");
                break;
            case 4:
                ShellExecute(NULL, TEXT("open"), TEXT("Extras\\WinAppMSAgentsManagementQR.exe"), NULL, NULL, SW_SHOWNORMAL);
                system("start Extras\\CreateCodigoQR.jar");
                break;
            case 5:
                ShellExecute(NULL, TEXT("open"), TEXT("Extras\\Ayuda.chm"), NULL, NULL, SW_SHOWNORMAL);
                break;
            case 6:
                encrip();
                break;
            case 7:
                ShellExecute(NULL, TEXT("open"), TEXT("Extras\\WinAppMSAgentsManagementExit.exe"), NULL, NULL, SW_SHOWNORMAL);
                color(13);
                printf("\t\t%c%c Gracias por Jugar %c%c\n\n", 245, 245, 245, 245);
                color(15);
                flag = false;
                break;
        }
    } while (flag);
    delete(ObjJuego);
}
