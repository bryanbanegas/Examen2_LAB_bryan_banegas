#ifndef VEHICULO_H
#define VEHICULO_H
#include "QString"

class vehiculo
{
protected:
    QString modelo;
    int year;
    float kilometraje;
public:
    vehiculo(QString& modelo, int year, float kilometraje):
        modelo(modelo), year(year), kilometraje(kilometraje){}

    QString getModelo(){
        return modelo;
    }

    int getYear(){
        return year;
    }

    float getKilometraje(){
        return kilometraje;
    }

    double virtual calcularMantenimiento(){}
};

#endif // VEHICULO_H
