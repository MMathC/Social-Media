#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include <iostream>
#include <string>
#include <vector>

#include "Perfil.h"
#include "PerfilInexistente.h"

using namespace std;

class RedeSocial{
    public:
        RedeSocial();
        virtual ~RedeSocial();

        vector<Perfil*>* getPerfis();
        Perfil* getPerfil(int id);
        void adicionar(Perfil* perfil);

        void imprimir();

    private:
        vector<Perfil*>* perfis;
};

#endif // REDESOCIAL_H
