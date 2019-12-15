/***********************************************************************
 * Module:  ListaDoble.h
 * Author:  Jonathan
 * Modified: jueves, 12 de diciembre de 2019 7:49:13 a. m.
 * Purpose: Declaration of the class ListaDoble
 ***********************************************************************/

#include "Nodo.h"

class ListaDoble {
private:
    Nodo *lista;
    char jugador[50];
    int contadorNodo;
    int puntaje;

public:

    ListaDoble() {
        lista = NULL;
        contadorNodo = 0;
        puntaje = 0;
    }
    void insertarAlFinal(int);
    void impresionArchivos();
    void impresion();
    void impresionLista();
    void generarLista();
    void listaTetris(int, int);
    void juegoTetris(int);
    int posicionAIndice(int x);
    void deleteNumber(int, int);
    void siguienteNumero(int, Nodo *);
    void deleteNodo(Nodo *Actual);
    void guardar();

};

void ListaDoble::impresionArchivos() {
    Nodo* Aux = new Nodo();
    FILE *archivoPDF, *archivoQR;
    archivoQR = fopen("C:\\JuegoSnake\\PuntajeJugador.txt", "w");
    archivoPDF = fopen("C:\\JuegoSnake\\Puntajes.txt", "a+");

    Aux = lista;
    printf("Jugador: %s.\n\n", jugador);
    fprintf(archivoPDF, "Jugador: %s\n\n", jugador);
    fprintf(archivoQR, "Jugador: %s.\n\n", jugador);
    if (Aux == NULL) {
        printf("No Acerto Ningun Numero.\n\n");
        fprintf(archivoPDF, "No Acerto Ningun Numero.\n\n");
        fprintf(archivoQR, "No Acerto Ningun Numero.\n\n");
    } else {
        printf("\t\tLista de Numeros Acertados.\n\n ==> ");
        fprintf(archivoPDF, "\t\tNumeros Acertados.\n\n ==> ");
        fprintf(archivoQR, "\t\tNumeros Acertados.\n\n ==> ");
        while (Aux != NULL) {
            printf("%d, ", Aux->getNumero());
            fprintf(archivoPDF, "%d, ", Aux->getNumero());
            fprintf(archivoQR, "%d, ", Aux->getNumero());
            Aux = Aux->getSiguienteDireccion();
        }
        printf("\b\b. \n\nPUNTAJE: %d\n\n", puntaje);
        fprintf(archivoPDF, "\b\b\b. \n\nPUNTAJE: %d\n\n----------------------------------------------------\n", puntaje);
        fprintf(archivoQR, "\b\b\b. \n\nPUNTAJE: %d", puntaje);
    }
    fclose(archivoPDF);
    fclose(archivoQR);
}

void ListaDoble::impresion() {
    Nodo* Aux = new Nodo();

    Aux = lista;
    printf("Jugador: %s.\n\n", jugador);

    if (Aux == NULL)
        printf("No Acerto Ningun Numero.\n\n");
    else {
        printf("\t\tLista de Numeros Acertados\n\n ==> ");
        while (Aux != NULL) {
            printf("%d, ", Aux->getNumero());
            Aux = Aux->getSiguienteDireccion();
        }
        printf("\b\b. \n\nPUNTAJE: %d\n\n", puntaje);
    }
}

void ListaDoble::impresionLista() {
    int x = 8, y;
    Nodo* Aux = new Nodo();
    Aux = lista;

    while (Aux != NULL) {
        y = 34;
        switch (Aux->getNumero()) {
            case 0:
                color(1);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf(" %c%c%c ", 219, 219, 219);
                break;

            case 1:
                color(2);
                gotoxy(x, y++);
                printf(" %c%c  \n", 219, 219);
                gotoxy(x, y++);
                printf("%c %c  \n", 219, 219);
                gotoxy(x, y++);
                printf("  %c   \n", 219);
                gotoxy(x, y++);
                printf("  %c   \n", 219);
                gotoxy(x, y++);
                printf("%c%c%c%c%c", 220, 220, 219, 220, 220, 220, 220);
                gotoxy(x, y++);
                break;


            case 2:
                color(3);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf("   %c \n", 219);
                gotoxy(x, y++);
                printf(" %c%c  \n", 220, 219);
                gotoxy(x, y++);
                printf("%c%c%c%c%c", 219, 220, 220, 220, 220, 220, 220);
                gotoxy(x, y++);
                break;


            case 3:
                color(4);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf("   %c \n", 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf(" %c%c%c ", 219, 219, 219);
                gotoxy(x, y++);
                break;

            case 4:
                color(6);
                gotoxy(x, y++);
                printf("   %c%c\n", 219, 219);
                gotoxy(x, y++);
                printf("  %c %c\n", 219, 219);
                gotoxy(x, y++);
                printf(" %c  %c\n", 219, 219);
                gotoxy(x, y++);
                printf("%c%c%c%c%c\n", 219, 220, 220, 220, 219);
                gotoxy(x, y++);
                printf("    %c\n", 219);
                gotoxy(x, y++);
                break;

            case 5:
                color(7);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 219);
                gotoxy(x, y++);
                printf(" %c   \n", 219);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 220);
                gotoxy(x, y++);
                printf("   %c \n", 219);
                gotoxy(x, y++);
                printf(" %c%c  ", 219, 219);
                gotoxy(x, y++);
                break;

            case 6:
                color(12);
                gotoxy(x, y++);
                printf("  %c%c \n", 220, 219);
                gotoxy(x, y++);
                printf(" %c   \n", 219);
                gotoxy(x, y++);
                printf("%c%c%c%c\n", 219, 220, 220, 220);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf(" %c%c%c ", 219, 219, 219);
                gotoxy(x, y++);
                break;

            case 7:
                color(9);
                gotoxy(x, y++);
                printf("%c%c%c%c%c\n", 220, 220, 220, 220, 220, 220, 220);
                gotoxy(x, y++);
                printf("    %c\n", 219);
                gotoxy(x, y++);
                printf("   %c\n", 219);
                gotoxy(x, y++);
                printf("  %c\n", 219);
                gotoxy(x, y++);
                printf(" %c   ", 219);
                gotoxy(x, y++);
                break;

            case 8:
                color(10);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf(" %c%c%c ", 219, 219, 219);
                gotoxy(x, y++);
                break;

            case 9:
                color(11);
                gotoxy(x, y++);
                printf(" %c%c%c \n", 219, 219, 219);
                gotoxy(x, y++);
                printf("%c   %c\n", 219, 219);
                gotoxy(x, y++);
                printf("%c%c%c%c%c\n", 219, 220, 220, 220, 219);
                gotoxy(x, y++);
                printf("    %c\n", 219);
                gotoxy(x, y++);
                printf(" %c%c%c ", 220, 220, 219);
                gotoxy(x, y++);
                break;
        }
        x += 6;
        Aux = Aux->getSiguienteDireccion();
    }
}

void ListaDoble::insertarAlFinal(int numero) {
    Nodo* Nuevo = new Nodo();
    Nodo* Actual = new Nodo();

    if (contadorNodo == 0) {
        Actual->setNumero(numero);
        Actual->setAnteriorDireccion(NULL);
        Actual->setSiguienteDireccion(NULL);
        lista = Actual;
    } else {
        Actual = lista;
        while (Actual->getSiguienteDireccion() != NULL) {
            Actual = Actual->getSiguienteDireccion();
        }
        Nuevo-> setNumero(numero);
        Nuevo-> setSiguienteDireccion(NULL);
        Actual->setSiguienteDireccion(Nuevo);
        Nuevo-> setAnteriorDireccion(Actual);
    }
    contadorNodo++;
}

//ANALLIZAR
void ListaDoble::generarLista() {
    Nodo* Aux = new Nodo();
    int numero, i;
    int selec =1;
    srand(time(NULL));
    for (i = 0; i < 4 + selec; i++) {
        numero = rand() % 10;
        insertarAlFinal(numero);
    }
}

int aleatorio(int caso) {
    if (caso == 1)
        return rand() % 10;
    else
        if (caso == 2)
        return rand() % (39 - 4 + 1) + 4;
    else
        return rand() % (99 - 2 + 1) + 2;
}

void margen() {
    color(121);
    for (int i = 2; i < 100; i++) {
        //PARTE SUPERIOR
        gotoxy(i, 3);
        printf("%c", 178);
        //PARTE INFERIOR
        gotoxy(i, 40);
        printf("%c", 178);
    }
    for (int j = 4; j < 40; j++) {
        //PARTE IZQUIERDA
        gotoxy(2, j);
        printf("%c", 178);
        //PARTE DERECHA
        gotoxy(100, j);
        printf("%c", 178);
    }
    //ESQUINAS
    gotoxy(2, 3);
    printf("%c", 178);
    gotoxy(2, 40);
    printf("%c", 178);
    gotoxy(100, 3);
    printf("%c", 178);
    gotoxy(100, 40);
    printf("%c", 178);
    color(15);
}

void ListaDoble::listaTetris(int posicion, int numero) {
    Nodo *Aux = new Nodo();
    Nodo *Actual = new Nodo();
    Nodo *Nuevo = lista;
    int cont;

    while (Nuevo != NULL) {
        if (numero == Nuevo->getNumero()) {
            cont++;
            break;
        }
        Nuevo = Nuevo->getSiguienteDireccion();
    }

    switch (posicion) {
        case 1:
            if (cont > 0) {
                Nuevo = Nuevo->getSiguienteDireccion();
                Nuevo->setAnteriorDireccion(NULL);
                lista = Nuevo;
                contadorNodo--;
            } else {

                Aux->setNumero(numero);
                Aux->setSiguienteDireccion(lista);
                Aux->setAnteriorDireccion(NULL);
                Actual->setAnteriorDireccion(Aux);
                lista = Aux;
                contadorNodo++;
            }
            break;
    }
}

int ListaDoble::posicionAIndice(int x) {
    return (x - 8) / 6;
}

void ListaDoble::deleteNodo(Nodo *Actual) {
    Nodo* Siguiente = new Nodo();
    Nodo* Anterior = new Nodo();
    if (Actual->getAnteriorDireccion() != NULL && Actual->getSiguienteDireccion() != NULL) {
        Anterior = Actual->getAnteriorDireccion();
        Siguiente = Actual->getSiguienteDireccion();
        Anterior->setSiguienteDireccion(Siguiente);
        Siguiente->setAnteriorDireccion(Anterior);
        delete(Actual);
    } else if (Actual->getAnteriorDireccion() == NULL) {
        lista = Actual->getSiguienteDireccion();
        delete(Actual);
    } else if (Actual->getSiguienteDireccion() == NULL) {
        Anterior = Actual->getAnteriorDireccion();
        Anterior->setSiguienteDireccion(NULL);
        delete(Actual);
    }
}

void ListaDoble::siguienteNumero(int numero, Nodo *aux) {
    if (aux == NULL || (aux->getNumero() != (numero + 1))) {
        return;
    } else {
        if (aux->getNumero() == (numero + 1)) {
            puntaje++;
            deleteNodo(aux);
        }
    }
}

void ListaDoble::deleteNumber(int indice, int numero) {
    int cont = 0;
    Nodo* Actual = new Nodo();
    Actual = lista;
    while (Actual != NULL) {
        if (indice == cont) {
            if (Actual->getNumero() == numero)
            {
                contadorNodo--;
                puntaje++;
                deleteNodo(Actual);
                siguienteNumero(numero, Actual);
            } else {
                insertarAlFinal(numero);
            }
            Actual = NULL;
        } else {
            Actual = Actual->getSiguienteDireccion();
        }
        cont++;
    }
}

void ListaDoble::juegoTetris(int j) {
    bool primera = true;
    char tecla = 0;
    int x = 32, y = 4;
    int col, fil;
    int numero;
    char nombre[200];
    int i = 0;
    srand(time(NULL));
    lista = NULL;
    contadorNodo = puntaje = 0;

    do {
        printf("NICKNAME: ");
        gets(jugador);
        fflush(stdin);
    } while (validacionCaracter(jugador));

    if (j == 0) {
        generarLista();
    }
    do {
        system("cls");
        margen();
        if (contadorNodo == 13)
            tecla = 's';
        gotoxy(0, 0);
        printf("\t\t\t::::::::::::::::::::Juego Tipo Tetris::::::::::::::::");
        if (primera) {
            numero = aleatorio(1);
            primera = false;
            gotoxy(4, 45);
        }
        if ((x == 10)&&(y == 33)) {
            listaTetris(1, numero);
            numero = aleatorio(1);
            x = 34;
            y = 4;
        }
        impresionLista();
        gotoxy(x, y);
        numbers(numero, x, y);
        color(15);
        tecla = getch();
        if (contadorNodo == 13)
            tecla = 's';
        switch (tecla) {
            case TECLA_ABAJO:
                y++;
                if (y >= 28) {
                    deleteNumber(posicionAIndice(x), numero);
                    y = 4;
                    primera = true;
                }
                break;
            case TECLA_DERECHA:
                x += 6;
                if (x >= 92)
                    x = 8;
                break;
            case TECLA_IZQUIERDA:
                x -= 6;
                if (x <= 2)
                    x = 92;
                break;
            case 's': case 'S':
                gotoxy(3, 43);
                printf("Presiona una tecla para continuar.");
                getch();
                tecla = TECLA_ENTER;
                break;
        }
        if (contadorNodo == 13)
            tecla = TECLA_ENTER;
    } while (tecla != TECLA_ENTER);
    system("cls");
    impresionArchivos();
}
