#include "Publicacao.h"

Publicacao::Publicacao(Perfil* autor, string texto){
    this->autor = autor;
    this->texto = texto;
}

Publicacao::~Publicacao(){

}
string Publicacao::getTexto(){
    return texto;
}

Perfil* Publicacao::getAutor(){
    return autor;
}

int Publicacao::getCurtidas(){
    return curtidas;
}

void Publicacao::imprimir(){
    cout<<autor->getNome()<<" publicou: "<<getTexto()<<endl;
    cout<<"Curtidas: "<<getCurtidas()<<endl;
}
