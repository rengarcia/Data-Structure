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
#pragma once
#ifndef TSI_H
#define TSI_H
#include <QDialog>
namespace Ui {
class Tsi;
}

class Tsi : public QDialog
{
    Q_OBJECT

public:
    explicit Tsi(QWidget *parent = nullptr);
    ~Tsi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Tsi *ui;
};

#endif // TSI_H
