#include "PersistenciaDaRede.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include <stdexcept>
#include <vector>

PersistenciaDaRede::PersistenciaDaRede(string arquivo){
    this->arquivo = arquivo;
}

PersistenciaDaRede::~PersistenciaDaRede(){

}

void PersistenciaDaRede::salvar(RedeSocial* r){
    int quantidadeAlunos = 0, quantidadeProfessores = 0, quantidadeDisciplinas = 0;
    ofstream output;
    output.open(arquivo);


    if(output.fail()){
        throw new logic_error("Erro ao salvar o arquivo: "+arquivo);
    }
    else{
        output << Perfil::getUltimoId()<<endl;
        for(unsigned int i = 0; i < r->getPerfis()->size(); i++){
            Aluno* a = dynamic_cast<Aluno*>(r->getPerfis()->at(i));
            Professor* prof = dynamic_cast<Professor*>(r->getPerfis()->at(i));
            Disciplina* disc = dynamic_cast<Disciplina*>(r->getPerfis()->at(i));
            if(a != NULL){
                quantidadeAlunos++;
            }
            else if(prof != NULL){
                quantidadeProfessores++;
            }
            else if(disc != NULL){
                quantidadeDisciplinas++;
            }
        }

        output << quantidadeAlunos << endl;
        for(unsigned int i = 0; i < r->getPerfis()->size(); i++){
            Aluno* a = dynamic_cast<Aluno*>(r->getPerfis()->at(i));
            if(a != NULL){
                output << r->getPerfis()->at(i)->getId() << " " << a->getNumeroUSP()<< " " << a->getNome() << " " << a->getEmail() << endl;
            }
        }

        output << quantidadeProfessores << endl;
        for(unsigned int i = 0; i< r->getPerfis()->size(); i++){
            Professor* prof = dynamic_cast<Professor*>(r->getPerfis()->at(i));
            if(prof != NULL){
                output << r->getPerfis()->at(i)->getId() << " " << prof->getNumeroUSP()<< " " << prof->getNome() << " " << prof->getEmail() << " " << prof->getDepartamento()<< endl;
            }
        }

        output << quantidadeDisciplinas << endl;
        for(unsigned int i = 0; i< r->getPerfis()->size(); i++){
            Disciplina* disc = dynamic_cast<Disciplina*>(r->getPerfis()->at(i));
            if(disc != NULL){
                output << r->getPerfis()->at(i)->getId() << " " << disc->getSigla() << " " << disc->getNome() << " " << disc->getResponsavel()->getId() << endl;
            }
        }
        for(unsigned int i = 0; i < r->getPerfis()->size(); i++){
            for(unsigned int j = 0; j < r->getPerfis()->at(i)->getSeguidores()->size(); j++){
                output << r->getPerfis()->at(i)->getId() <<" "<< r->getPerfis()->at(i)->getSeguidores()->at(j)->getId()<< endl;
            }
        }
    }
    output.close();
}

RedeSocial* PersistenciaDaRede::carregar(){
    ifstream input;
    input.open(arquivo);

    RedeSocial* rede = new RedeSocial();

    int ultId,quantA,quantP,quantD;
    int id,nUSP, idResponsa;
    int segue,eSeguido;
    string nome,email,depart,sigla;

    input>>ultId;

    input>>quantA;

    if(!input){ //caso o arquivo nao exista
        Perfil::setUltimoId(0);
        return rede;
    }
    for(int i = 0; i < quantA; i++){
        input>>id>>nUSP>>nome>>email;
        if(!input){
            delete rede;
            throw new logic_error("Erro na leitura do arquivo");
        }
        Aluno* a = new Aluno(id,nUSP, nome, email);
        rede->adicionar(a);
    }

    input>>quantP;
    for(int i = 0; i < quantP; i++){
        input>>id>>nUSP>>nome>>email>>depart;
        if(!input){
            delete rede;
            throw new logic_error("Erro na leitura do arquivo");
        }
        Professor* p = new Professor(id,nUSP, nome, email, depart);
        rede->adicionar(p);
    }

    input>>quantD;
    for(int i = 0; i < quantD; i++){
        input>>id>>sigla>>nome>>idResponsa;
        if(!input){
            delete rede;
            throw new logic_error("Erro na leitura do arquivo");
        }
        Professor* responsa = static_cast<Professor*>(rede->getPerfil(idResponsa));
        Disciplina* d = new Disciplina(id,sigla, nome,responsa);
        rede->adicionar(d);
    }
    input>>eSeguido>>segue;
    while(input){
        rede->getPerfil(eSeguido)->adicionarSeguidor(rede->getPerfil(segue));
        input>>eSeguido>>segue;
    }
    if(!input.eof()){
        delete rede;
        throw new logic_error("Erro na leitura do arquivo");
    }

    input.close();

    return rede;
}
