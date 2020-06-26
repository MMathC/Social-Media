#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>

#include "Pessoa.h"
#include "Publicacao.h"

using namespace std;

class Aluno : public Pessoa{
    public:
        Aluno(int numeroUSP, string nome, string email);
        Aluno(int id, int numeroUSP, string nome, string email);
        virtual ~Aluno();

        void receber(Publicacao* p);
};

#endif // ALUNO_H
