#ifndef ARTICULOCIENTIFICO_H
#define ARTICULOCIENTIFICO_H
#include "publicacion.h"

class articuloCientifico : public publicacion
{
private:
    QString comentario;
public:
    articuloCientifico(QString& titulo, QString& autor, int anioPublicacion, bool disponible, QString& comentario):
        publicacion(titulo,autor,anioPublicacion,disponible),comentario(comentario){}

    QString getInfo(){
        QString info;
        if(disponible){
            info="Titulo: "+titulo+" Autor: "+autor+" Year: "+QString::number(anioPublicacion)+" Disponible para prestamo"+"\n";
            info+="Comentario: "+comentario+"\n";
        }else{
            info="Titulo: "+titulo+" Autor: "+autor+" Year: "+QString::number(anioPublicacion)+" No Disponible para prestamo"+"\n";
            info+="Comentario: "+comentario+"\n";
        }
        return info;
    }
};

#endif // ARTICULOCIENTIFICO_H
