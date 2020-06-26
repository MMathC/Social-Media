#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Publicacao.h"
class Publicacao;


using namespace std;


class Perfil{
    public:
        Perfil(string nome);
        Perfil(int id, string nome);
        virtual ~Perfil();

        static void setUltimoId(int ultimoId);
        static int getUltimoId();

        int getId();
        string getNome();

        virtual void adicionarSeguidor(Perfil* seguidor) = 0;

        virtual void publicar(string texto);
        virtual void publicar(string texto, string data);

        virtual void receber(Publicacao* p) = 0;
        virtual list<Publicacao*>* getPublicacoesFeitas();
        virtual list<Publicacao*>* getPublicacoesRecebidas();

        virtual vector<Perfil*>* getSeguidores();

        virtual void imprimir();

    protected:
        string nome;
        vector<Perfil*>* seguidores;
        list<Publicacao*>* feitas;
        list<Publicacao*>* recebidas;

        static int ultimoId; //estatico
        int id = 0; //normal

};

#endif // PERFIL_H
