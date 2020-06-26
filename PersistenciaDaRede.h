#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H

#include <fstream>
#include <iostream>
#include "RedeSocial.h"

using namespace std;

class PersistenciaDaRede{
    public:
        PersistenciaDaRede(string arquivo);
        virtual ~PersistenciaDaRede();

        void salvar(RedeSocial* r);
        RedeSocial* carregar();

    private:
        string arquivo;
};

#endif // PERSISTENCIADAREDE_H
