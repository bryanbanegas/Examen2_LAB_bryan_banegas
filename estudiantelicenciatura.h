#ifndef ESTUDIANTELICENCIATURA_H
#define ESTUDIANTELICENCIATURA_H
#include "estudiante.h";

class estudianteLicenciatura : public estudiante
{
public:
    estudianteLicenciatura(QString& nombre, int edad):
        estudiante(nombre,edad){}

    double promedio(){
        int sumar=0;
        int contar=0;
        double promedio=0;
        for(int i=0;i<calificaciones.size();i++){
            sumar+=calificaciones.at(i);
            contar++;
        }
        if(contar!=0){
            promedio=sumar/contar;
        }
        return promedio;
    }
};

#endif // ESTUDIANTELICENCIATURA_H
