#ifndef AUTO_H
#define AUTO_H
#include "vehiculo.h"

class automovil : public vehiculo
{
public:
    automovil(QString& modelo, int year, float kilometraje):
        vehiculo(modelo,year,kilometraje){}

    double calcularMantenimiento(){
        double mantenimiento=kilometraje/5000;
        if(kilometraje>100000){
            double aumentar=mantenimiento+mantenimiento/0.2;
            mantenimiento+=aumentar;
        }
        return mantenimiento;
    }
};

#endif // AUTO_H
