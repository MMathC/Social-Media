#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include <string>

#include "Publicacao.h"
#include "Perfil.h"

using namespace std;

class Evento : public Publicacao{
    public:
        Evento(Perfil* autor, string texto,string data);
        virtual ~Evento();

        string getData();
        void curtir(Perfil* quemCurtiu);

    private:
        string data;
};

#endif // EVENTO_H
