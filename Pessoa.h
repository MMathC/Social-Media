#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

#include "Perfil.h"

using namespace std;


class Pessoa : public Perfil{
    public:
        Pessoa(int numeroUSP, string nome, string email);
        Pessoa(int id, int numeroUSP, string nome, string email);
        virtual ~Pessoa();

        virtual string getEmail();
        virtual int getNumeroUSP();
        void adicionarSeguidor(Perfil* seguidor);

        virtual void receber(Publicacao* p) = 0;

    protected:
        int numeroUSP;
        string email;

};

#endif // PESSOA_H
