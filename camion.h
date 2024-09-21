#ifndef CAMION_H
#define CAMION_H
#include "vehiculo.h"

class camion : public vehiculo
{
private:
    int peso;
public:
    camion(QString& modelo, int year, float kilometraje, int peso):
        vehiculo(modelo,year,kilometraje), peso(peso){}

    double calcularMantenimiento(){
        double mantenimiento=kilometraje/5000;
        if(kilometraje>100000){
            double aumentar=mantenimiento+mantenimiento/0.2;
            mantenimiento+=aumentar;
        }
        return mantenimiento;
    }
};

#endif // CAMION_H
