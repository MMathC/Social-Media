#include <iostream>
#include <string>
#include <list>

#include "Evento.h"
#include "Disciplina.h"
#include "Professor.h"
#include "Aluno.h"
#include "RedeSocial.h"
#include "PersistenciaDaRede.h"
#include "Publicacao.h"

using namespace std;

int escolha(){
    int opcao;

    cout<<"Escolha uma opcao: "<<endl;
    cout<<"1) Cadastrar Perfil"<<endl;
    cout<<"2) Cadastrar Disciplina"<<endl;
    cout<<"3) Logar"<<endl;
    cout<<"0) Terminar"<<endl;
    cin>>opcao;
    cout<<endl;

    return opcao;
}

void opcao1(RedeSocial* rede){
    int numeroUSP;
    string nome, email, eProfessor, departamento;

    cout<<"Informe os dados do perfil"<<endl;

    cout<<"Numero USP: ";
    cin>>numeroUSP;
    cin.ignore(100, '\n');

    cout<<"Nome: ";
    getline(cin,nome);

    cout<<"Email: ";
    cin>>email;

    cout<<"Professor (s/n): ";
    cin>>eProfessor;
    if(eProfessor == "s"){
        cout<<"Departamento: ";
        cin>>departamento;
        Professor* pr = new Professor(numeroUSP,nome,email,departamento);
        rede->adicionar(pr);
    }
    else if(eProfessor == "n"){
        Aluno* a = new Aluno(numeroUSP,nome ,email);
        rede->adicionar(a);
    }
    cout<<endl;
}

void opcao2(RedeSocial* rede){
    string sigla, nome;
    int escolhaDoResponsavel;
    Perfil* pr;

    cout<<"Informe os dados da disciplina"<<endl;

    cout<<"Sigla: ";
    cin>>sigla;
    cin.ignore(100, '\n');

    cout<<"Nome: ";
    getline(cin,nome);

    cout<<"Responsavel:"<<endl;

    for(unsigned int i = 0 ; i < rede->getPerfis()->size(); i++){
        pr = rede->getPerfis()->at(i);
        cout<< pr->getId() <<") "<< pr->getNome() <<endl;
    }
    cout<<"Digite o numero ou 0 para cancelar: ";
    cin>>escolhaDoResponsavel;
    cout<<endl;

    if (escolhaDoResponsavel != 0){
        pr = rede->getPerfil(escolhaDoResponsavel);
        Professor* pr1 = dynamic_cast<Professor*>(pr);
        if(pr1 != NULL){
            rede->adicionar(new Disciplina(sigla,nome,pr1));
        }
        else{
            cout<<"Somente professores podem ser responsaveis por disciplinas"<<endl;
        }
    }
    cout<<endl;
}

void opcao3(RedeSocial* rede){
    int escolhaDoPerfil;

    cout<<"Escolha um perfil: "<<endl;
    for(unsigned int i = 0 ; i < rede->getPerfis()->size(); i++){
        cout<<rede->getPerfis()->at(i)->getId()<<") "<<rede->getPerfis()->at(i)->getNome()<<endl;
    }
    cout<<"Digite o numero ou 0 para cancelar: "<<endl;
    cin>>escolhaDoPerfil;
    cout<<endl;
    if(escolhaDoPerfil != 0){
        int opcaoDaRede = 1000;
        Perfil* c = rede->getPerfil(escolhaDoPerfil);

            while(opcaoDaRede != 0){
                Disciplina* d = dynamic_cast<Disciplina*>(c);
                Professor* pr = dynamic_cast<Professor*>(c);
                Aluno* a = dynamic_cast<Aluno*>(c);

                if(d != NULL){
                    cout<<d->getSigla()<<" - "<<d->getNome()<<endl;
                }
                else if(pr != NULL){
                    cout<<pr->getNumeroUSP()<<" - "<<pr->getNome()<<endl;
                    cout<<"Departamento "<<pr->getDepartamento()<<endl;
                }
                else{
                    cout<<a->getNumeroUSP()<<" - "<<a->getNome()<<endl;
                }
                cout<<"Seguidores: " <<c->getSeguidores()->size()<<endl;
                cout<<"---"<<endl;
                cout<<"Escolha uma opcao:"<<endl;
                cout<<"1) Ver publicacoes feitas"<<endl;
                cout<<"2) Ver publicacoes recebidas"<<endl;
                cout<<"3) Fazer publicacao"<<endl;
                if(d == NULL){
                    cout<<"4) Seguir perfil"<<endl;
                }
                cout<<"0) Deslogar"<<endl;
                cin>>opcaoDaRede;
                cout<<endl;

                if(opcaoDaRede == 1){//erro
                    cout<<"Publicacoes feitas:"<<endl;
                    list<Publicacao*>* feitas = c->getPublicacoesFeitas();
                    list<Publicacao*>::iterator i = feitas->begin();

                    while(i != c->getPublicacoesFeitas()->end()){
                        cout<<(*i)->getTexto()<<" ("<< c->getNome()<<") ["<<(*i)->getCurtidas()<<"]"<<endl;
                        i++;
                    }

                    while(i != feitas->end()){
                        for(unsigned int j = 0 ; j < feitas->size(); j++){
                            cout << (*i)->getTexto() << " (" << (*i)->getAutor()->getNome() << ") [" << (*i)->getCurtidas() << "]" << endl;

                        i++;
                        }
                        cout<<endl;
                    }
                }
                else if(opcaoDaRede == 2){//erro
                    int curtiu;
                    cout<<"Publicacoes recebidas:"<<endl;
                    int r = 1;
                    list<Publicacao*>* p = c->getPublicacoesRecebidas();
                    int tp = c->getPublicacoesRecebidas()->size();
                    list<Publicacao*>::iterator j = p->begin();
                    while(j != p->end()&& r <= tp){
                        cout<<r<<") "<<(*j)->getTexto()<<" ("<< (*j)->getAutor()->getNome()<<") ["<<(*j)->getCurtidas()<<"]"<<endl;
                        j++;
                        r++;
                    }
                    cout<<"Digite o numero da mensagem para curtir ou 0 para voltar: ";
                    cin>>curtiu;

                    list<Publicacao*>::iterator k = p->begin();
                    if (curtiu != 0 && k != p->end()){
                        for(int i = 0; i<tp;i++){
                            if(i == curtiu-1){
                                (*k)->curtir(c);
                            }
                            k++;
                        }
                    }
                    cout<<endl;
                }
                else if(opcaoDaRede == 3){
                    string eEvento, data, texto;

                    cout<<"Evento (s/n): ";
                    cin>>eEvento;

                    if(eEvento == "s"){
                        cout<<"Data: ";
                        cin>>data;
                        cin.ignore(100, '\n');
                        cout<<"Texto: ";
                        getline(cin,texto);
                        c->publicar(texto,data);
                    }
                    else if(eEvento == "n"){
                        cin.ignore(100, '\n');
                        cout<<"Texto: ";
                        getline(cin,texto);
                        c->publicar(texto);
                    }
                    cout<<endl;
                }
                else if(opcaoDaRede == 4){
                    if(d == NULL){
                        int seguirPerfil;
                        Perfil* pe;

                        cout<<"Perfil:"<<endl;
                        for(unsigned int i = 0; i < rede->getPerfis()->size();i++){
                            pe = rede->getPerfis()->at(i);
                            cout<<pe->getId()<<") "<<pe->getNome()<<endl;
                        }
                        cout<<"Digite um numero ou 0 para cancelar: ";
                        cin>>seguirPerfil;

                        if(seguirPerfil != 0){
                            rede->getPerfil(seguirPerfil)->adicionarSeguidor(c);
                        }
                    }
                }
                cout<<endl;
            }
    }
}

int main(){
    try{
        int opcao;
        string nomeArquivo,save;

        cout<<"Arquivo: ";
        cin>>nomeArquivo;

        PersistenciaDaRede* arquivo = new PersistenciaDaRede(nomeArquivo);

        RedeSocial* rede = arquivo->carregar();
        cout<<endl;

        opcao = escolha();

        while(opcao != 0){
            if(opcao == 1){
               opcao1(rede);
            }
            else if(opcao == 2){
                opcao2(rede);
            }
            else if(opcao == 3){
                opcao3(rede);
            }
            opcao = escolha();
        }

        cout<<"Deseja salvar? (s/n) ";
        cin>>save;

        if(save == "s"){
            arquivo->salvar(rede);
        }
        //delete rede;
    }
    catch(invalid_argument *e){
        cout<<endl;
        cout<<"Erro: "<<e->what();
        delete e;
    }
    catch(PerfilInexistente *e){
        cout<<endl;
        cout<<"Erro: "<<e->what();
        delete e;
    }
    catch(logic_error *e){
        cout<<endl;
        cout<<"Erro: "<<e->what();
        delete e;
    }
    return 0;
}


