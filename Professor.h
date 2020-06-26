#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>

#include "Pessoa.h"
#include "Publicacao.h"

using namespace std;

class Professor : public Pessoa{
    public:
        Professor (int numeroUSP, string nome, string email, string departamento);
        Professor(int id, int numeroUSP, string nome, string email, string departamento);
        virtual ~Professor ();

        string getDepartamento();

        void receber(Publicacao* p);

    private:
        string departamento;
};


#endif // PROFESSOR_H
