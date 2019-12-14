#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "ListaEnlazada.h"
 
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

char tecla;
 
void gotoxy(int x, int y) 
{ 
 HANDLE hCon; 
 COORD dwPos; 
 
 dwPos.X = x; 
 dwPos.Y = y; 
 hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
 SetConsoleCursorPosition(hCon,dwPos); 
}
void OcultaCursor() {
 CONSOLE_CURSOR_INFO cci = {100, FALSE};
 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void pintar(){ 
 for(int i=2; i < 78; i++){
 gotoxy (i, 3); printf ("%c", 205);
 gotoxy(i, 23); printf ("%c", 205); 
 }
 for(int v=4; v < 23; v++){
 gotoxy (2,v); printf ("%c", 186);
 gotoxy(77,v); printf ("%c", 186); 
 }
 gotoxy (2,3); printf ("%c", 201);
 gotoxy (2,23); printf ("%c", 200);
 gotoxy (77,3); printf ("%c", 187);
 gotoxy(77,23); printf ("%c", 188); 
 } 
void guardar_posicion(int *n, int *tam, int *x, int *y, int **cuerpo ){
 *(*(cuerpo+*n)+0) = *x;
 *(*(cuerpo+*n)+1) = *y;
 *n=*n+1;
 if(*n == *tam) *n = 1;
}
void dibujar_cuerpo(int *tam, int **cuerpo, char* line){
	
 for(int i = 1; i < *tam; i++){
 gotoxy(*(*(cuerpo+i)+0) , *(*(cuerpo+i)+1)); printf("%c",line[i-1]);
 }
}
void borrar_cuerpo(int **cuerpo, int *n){
 gotoxy(*(*(cuerpo+*n)+0) , *(*(cuerpo+*n)+1)); printf(" ");
 }
void teclear(int *dir){
 if(kbhit()){
 tecla = getch();
 switch(tecla){
 case ARRIBA : if(*dir != 2) *dir = 1; break;
 case ABAJO : if(*dir != 1) *dir = 2; break;
 case DERECHA : if(*dir != 4) *dir = 3; break;
 case IZQUIERDA : if(*dir != 3) *dir = 4; break;
 }
 }
}
void comida(int *x, int *y, int *xc, int *yc, int *tam, ListaEnlazada *listE, int *com)
{
 if(*x == *xc && *y == *yc)
 {	srand (time(NULL));
 	listE->insertar(*com);
 	*xc = (rand() % 73) + 4;
 	*yc = (rand() % 19) + 4;
 	*com = rand()%10;
 	*tam=*tam+1;
 	gotoxy(*xc, *yc); printf("%d", *com);
 }
}
bool game_over(int *tam, int *x, int *y, int** cuerpo)
{
 if(*y == 3 || *y == 23 || *x == 2 || *x == 77) return false;
 for(int j = *tam - 1; j > 0; j--){
 if(*(*(cuerpo+j)+0) == *x && *(*(cuerpo+j)+1) == *y)
 return false;
 }
 return true;
}
int main()
{
	ListaEnlazada listE;
	ListaEnlazada *listEn=&listE;
 	int **cuerpo;
	int n = 1, tam = 10, dir = 3, com, x = 10, y = 12, xc = 30, yc = 15, velocidad = 60;
	int *n1=&n, *tam1=&tam, *dir1=&dir, *com1=&com, *x1=&x, *y1=&y, *xc1=&xc, *yc1=&yc;
	cuerpo =(int **)malloc(200*sizeof(int *));
    for(int j=0;j<200;j++)
        *(cuerpo+j)=(int *)malloc(2*sizeof(int));
        for(int i=0; i<10; i++){
        	listE.insertar(0);
		}
	srand (time(NULL)); 
	com=rand()%10;
 OcultaCursor();
 
 pintar();
 gotoxy(xc, yc); printf("%d", com);
 
 while(tecla != ESC && game_over(tam1, x1, y1, cuerpo))
 {	
 	borrar_cuerpo(cuerpo, n1);
 	guardar_posicion(n1, tam1, x1, y1, cuerpo);
 	dibujar_cuerpo(tam1, cuerpo, listE.crearLinea());
 	comida(x1, y1, xc1, yc1, tam1, listEn, com1);
 	teclear(dir1);
 	teclear(dir1);
 
 if(*dir1 == 1) *y1=*y1-1;
 if(*dir1 == 2) *y1=*y1+1;
 if(*dir1 == 3) *x1=*x1+1;
 if(*dir1 == 4) *x1=*x1-1;
 
 Sleep(velocidad);
 }
 pintar();
 return 0;
}
