#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>
#include <string>

#include "Publicacao.h"
#include "Perfil.h"

using namespace std;

class Mensagem : public Publicacao{
    public:
        Mensagem(Perfil* autor, string texto);
        virtual ~Mensagem();

        void curtir(Perfil* quemCurtiu);

};

#endif // MENSAGEM_H
