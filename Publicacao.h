#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <iostream>
#include <string>

#include "Perfil.h"
class Perfil;

using namespace std;


class Publicacao{
    public:
        Publicacao(Perfil* autor, string texto);
        virtual ~Publicacao();

        Perfil* getAutor();
        string getTexto();

        virtual void curtir(Perfil* quemCurtiu) = 0;
        virtual int getCurtidas();
        virtual void imprimir();

    protected:
        string texto;
        Perfil* autor;
        int curtidas = 0;
};

#endif // PUBLICACAO_H
