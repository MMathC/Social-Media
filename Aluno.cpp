#include "Aluno.h"

Aluno::Aluno(int numeroUSP, string nome, string email) : Pessoa(numeroUSP, nome, email){
}

Aluno::Aluno(int id, int numeroUSP, string nome, string email) : Pessoa(numeroUSP, nome, email){
    this->id = id;
}


Aluno::~Aluno(){

}

 void Aluno::receber(Publicacao* p){
    recebidas->push_back(p);
 }
