/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:16/10/2019                                     *
******************************************************************/
#ifndef DATO_H_INCLUDED
#define DATO_H_INCLUDED
class Dato
{
    private:
        int valor;
    public:
        Dato(int);
        Dato();
        int getValor();
        void setValor(int);
        int factorial(int);
};
Dato::Dato(int valor)
{
    this->valor=valor;
}
Dato::Dato()
{
    this->valor=0;
}
int Dato::getValor()
{
    return valor;
}
void Dato::setValor(int valor)
{
    this->valor=valor;
}
int Dato::factorial(int valor)
{
    if(valor==1)
    {
        return 1;
    }
    else{
        return valor*factorial(valor-1);
    }
}

#endif // DATO_H_INCLUDED
