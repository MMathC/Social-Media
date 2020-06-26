#include "Perfil.h"
#include "Evento.h"
#include "Mensagem.h"
#include <stdexcept>

int Perfil::ultimoId = 0;

Perfil::Perfil(string nome){
    this->nome = nome;
    Perfil::ultimoId ++;
    id = Perfil::getUltimoId();
    recebidas = new list<Publicacao*>();
    feitas = new list<Publicacao*>();
    seguidores = new vector<Perfil*>();
}

Perfil::Perfil(int id, string nome){
    this->id = id;
    this->nome = nome;
}

Perfil::~Perfil(){//arrumar
    while(!feitas->empty()){
        Publicacao *f = feitas->front();
        feitas->pop_front();
        delete f;
    }
    delete feitas;

    while(!recebidas->empty()){
        Publicacao *f = recebidas->back();
        recebidas->pop_back();
        delete f;
    }
    delete recebidas;

    while(!seguidores->empty()){
        Perfil *ultimo = seguidores->back();
        seguidores->pop_back();
        delete ultimo;
    }
    delete seguidores;
}

void Perfil::setUltimoId(int ultimoId){
    Perfil::ultimoId = ultimoId;
}

int Perfil::getId(){
    return id;
}

int Perfil::getUltimoId(){
    if(ultimoId == 0){
        return 0;
    }
    return Perfil::ultimoId;
}

string Perfil::getNome(){
    return nome;
}

void Perfil::publicar(string texto){
    Mensagem* m;
    m = new Mensagem(this,texto);
    feitas->push_back(m);
    for(unsigned int i = 0; i < seguidores->size() ; i++){
        seguidores->at(i)->receber(m);
    }

}

void Perfil::publicar(string texto, string data){
    Evento* evento;
    evento = new Evento(this,texto,data);
    feitas->push_back(evento);
    for(unsigned int i = 0; i < seguidores->size() ; i++){
        seguidores->at(i)->receber(evento);
    }
}

list<Publicacao*>* Perfil::getPublicacoesFeitas(){
    return feitas;
}

list<Publicacao*>* Perfil::getPublicacoesRecebidas(){
    return recebidas;
}

vector<Perfil*>* Perfil::getSeguidores(){
    return seguidores;
}

void Perfil::imprimir(){
    cout << endl << "Nome: " << getNome() << " - id: "<< getId() << endl;
    if (seguidores->size() != 0){
        for(unsigned int i = 0 ; i < seguidores->size() ; i++){
            cout << "Seguidor "<< seguidores->at(i)->getNome() << endl;
        }
    }
    else{
        cout << "Sem seguidor " << endl;

        cout << "Numero de publicacoes feitas: " << feitas->size() << endl;
        list<Publicacao*>::iterator i = feitas->begin();
        while(i != feitas->end()){
            for(unsigned int j = 0 ; j < feitas->size(); j++){
                cout << "Publicacao " << j+1 << " - Texto: " << (*i)->getTexto() << endl;
            }
            i++;
            }
            cout << "Numero de publicacoes recebidas: " << recebidas->size() << endl;
            list<Publicacao*>::iterator it = recebidas->begin();

        while(it != recebidas->end()){
            for(unsigned int j = 0 ; j < recebidas->size(); j++){
                cout << "Publicacao " << j+1 << " - Texto: " << (*it)->getTexto() << endl;
            }
            it++;
        }

    }
}


