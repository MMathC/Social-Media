#include "Disciplina.h"
#include <vector>
#include <stdexcept>

Disciplina::Disciplina(string sigla, string nome, Professor* responsavel) : Perfil(nome){
    this->sigla = sigla;
    this->responsavel = responsavel;
    adicionarSeguidor(responsavel);
}

Disciplina::Disciplina(int id, string sigla, string nome, Professor* responsavel) : Perfil(nome){
    this->sigla = sigla;
    this->responsavel = responsavel;
    this->id = id;
}

Disciplina::~Disciplina(){
}

Professor* Disciplina::getResponsavel(){
    return responsavel;
}

string Disciplina::getSigla(){
    return sigla;
}

void Disciplina::receber(Publicacao* p){
}

void Disciplina::adicionarSeguidor(Perfil* seguidor){
    bool naoSegue = true;

    for(unsigned int i = 0; i < seguidores->size(); i++){
        if(seguidores->at(i) == seguidor){
            naoSegue = false;
        }
    }
    if(seguidor != this && naoSegue){
        seguidores->push_back(seguidor);
    }
    else{
        throw new invalid_argument("Perfil nao adicionado");
    }
}

