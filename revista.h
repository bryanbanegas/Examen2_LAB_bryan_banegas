#ifndef REVISTA_H
#define REVISTA_H
#include "publicacion.h"

class revista : public publicacion
{
private:
    int numeroEdicion;
public:
    revista(QString& titulo, QString& autor, int anioPublicacion, bool disponible, int numeroEdicion):
        publicacion(titulo,autor,anioPublicacion,disponible), numeroEdicion(numeroEdicion){}

    QString getInfo(){
        QString info;
        if(disponible){
            info="Titulo: "+titulo+" Autor: "+autor+" Year: "+QString::number(anioPublicacion)+" Disponible para prestamo"+"\n";
            info+="Numero de Edicion: "+QString::number(numeroEdicion)+"\n";
        }else{
            info="Titulo: "+titulo+" Autor: "+autor+" Year: "+QString::number(anioPublicacion)+" No Disponible para prestamo"+"\n";
            info+="Numero de Edicion: "+QString::number(numeroEdicion)+"\n";
        }
        return info;
    }
};

#endif // REVISTA_H
