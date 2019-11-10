/***********************************************************************
 * Module:  Grafico.cpp
 * Author:  kevin
 * Modified: Saturday, November 9, 2019 11:56:57 AM
 * Purpose: Implementation of the class grafico
 ***********************************************************************/

#include "Grafico.h"
#include <conio.h>
#include <Windows.h>

////////////////////////////////////////////////////////////////////////
// Name:       Grafico::gotoxy(int x, int y)
// Purpose:    Implementation of grafico::gotoxy()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void Grafico::gotoxy(int x, int y) {
    HANDLE h_con;
    h_con = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(h_con, dwPos);
}

////////////////////////////////////////////////////////////////////////
// Name:       Grafico::ocultarCursor()
// Purpose:    Implementation of grafico::ocultarCursor()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Grafico::ocultarCursor(void) {
    HANDLE h_con;
    h_con = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 28;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(h_con, &cci);
}
