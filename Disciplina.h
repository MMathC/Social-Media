#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>


#include "Perfil.h"
#include "Professor.h"

using namespace std;


class Disciplina : public Perfil{
    public:
        Disciplina(string sigla, string nome, Professor* responsavel);
        Disciplina(int id, string sigla, string nome, Professor* responsavel);
        virtual ~Disciplina();

        string getSigla();
        Professor* getResponsavel();

        void receber(Publicacao* p);

        void adicionarSeguidor(Perfil* seguidor);

    private:
        string sigla;
        Professor* responsavel;
};

#endif // DISCIPLINA_H
