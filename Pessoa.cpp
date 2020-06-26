#include "Pessoa.h"
#include "Mensagem.h"
#include <stdexcept>

Pessoa::Pessoa(int numeroUSP, string nome, string email) : Perfil(nome){
    this->numeroUSP = numeroUSP;
    this->email = email;

}

Pessoa::~Pessoa(){

}

int Pessoa::getNumeroUSP(){
    return numeroUSP;
}

string Pessoa::getEmail(){
    return email;
}

void Pessoa::adicionarSeguidor(Perfil* seguidor){ //fazer as novas verificacoes
    bool naoSegue = true;

    for(unsigned int i = 0; i < seguidores->size(); i++){
        if(seguidores->at(i) == seguidor){
            naoSegue = false;
        }
    }
    if(seguidor != this && naoSegue){
        seguidores->push_back(seguidor);
        Publicacao* p = new Mensagem(this,"Novo Seguidor: "+seguidor->getNome());
        recebidas->push_back(p);
    }
    else{
        throw new invalid_argument("Perfil nao adicionado");
    }
}
