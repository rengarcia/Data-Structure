#if !defined(Elemento)
#define __Elemento_h

#pragma once

#include <iostream>
class Elemento {
public:
    int dato;
    Elemento* siguiente;
    Elemento() : dato(0), siguiente(NULL) {
    } 
};

#endif


