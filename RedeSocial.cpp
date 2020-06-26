#include "RedeSocial.h"
#include <stdexcept>
#include <algorithm>

RedeSocial::RedeSocial(){
    perfis = new vector<Perfil*>();
}

RedeSocial::~RedeSocial(){
    while(!perfis->empty()){
        Perfil *ultimo = perfis->back();
        perfis->pop_back();
        delete ultimo;
    }
    delete perfis;

}

vector <Perfil*>* RedeSocial::getPerfis(){
    return perfis;
}

Perfil* RedeSocial::getPerfil(int id){
    vector<Perfil*>::iterator it = perfis->begin();
    for(;it != perfis->end(); it++){
        if((*it)->getId() == id){
            return (*it);
        }
    }
    throw new PerfilInexistente();
}

void RedeSocial::adicionar(Perfil* p){
    if(find(perfis->begin(),perfis->end(),p) != perfis->end()){
        throw new invalid_argument("Perfil ja pertence a Rede Social");
    }
    perfis->push_back(p);
}

void RedeSocial::imprimir(){
    cout << endl << "------------------------------ " << endl;
    cout << "RedeSocial: " << perfis->size() << " perfis" << endl;
    cout << "------------------------------ " << endl;
    for(unsigned int i = 0; i < perfis->size() ; i++){
        cout<< perfis->at(i)->getNome()<<endl;
    }
    if (perfis->size() == 0){
        cout << "Sem perfis" << endl;
        cout << "------------------------------ " << endl;
    }
    else{
        for(unsigned int i = 0; i < perfis->size(); i++){
            perfis->at(i);
            cout << "------------------------------ " << endl;
        }
    }
    cout << endl;
}

