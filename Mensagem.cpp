#include "Mensagem.h"
#include <stdexcept>

Mensagem::Mensagem(Perfil* autor, string texto) : Publicacao(autor, texto){
}

Mensagem::~Mensagem(){
}

void Mensagem::curtir(Perfil* quemCurtiu){
    if(quemCurtiu != autor){
        curtidas+=1;
    }
    else{
        throw new invalid_argument("Voce nao pode curtir sua propria publicacao");
    }
}
