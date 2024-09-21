#ifndef ESTUDIANTEMAESTRIA_H
#define ESTUDIANTEMAESTRIA_H
#include "estudiante.h";

class estudianteMaestria : public estudiante
{
public:
    estudianteMaestria(QString& nombre, int edad):
        estudiante(nombre,edad){}

    double promedio(){
        int sumar=0;
        int contar=0;
        double promedio=0;
        for(int i=0;i<calificaciones.size();i++){
            if(calificaciones.at(i)>=60){
                sumar+=calificaciones.at(i);
            }
            contar++;
        }
        if(contar!=0){
            promedio=sumar/contar;
        }
        return promedio;
    }
};

#endif // ESTUDIANTEMAESTRIA_H
