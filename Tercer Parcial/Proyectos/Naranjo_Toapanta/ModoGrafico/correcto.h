/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JHONY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:26/01/2020                                     *
******************************************************************/
#ifndef CORRECTO_H
#define CORRECTO_H

#include <QDialog>

namespace Ui {
class Correcto;
}

class Correcto : public QDialog
{
    Q_OBJECT

public:
    explicit Correcto(QWidget *parent = nullptr);
    ~Correcto();

private:
    Ui::Correcto *ui;
};

#endif // CORRECTO_H
