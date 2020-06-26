#include "Professor.h"
#include <vector>

Professor ::Professor (int numeroUSP, string nome, string email, string departamento) : Pessoa(numeroUSP, nome, email){
   this->departamento = departamento;
}

Professor::Professor(int id, int numeroUSP, string nome, string email, string departamento) : Pessoa(numeroUSP, nome, email){
    this->departamento = departamento;
    this->id = id;
}


Professor ::~Professor (){

}
string Professor::getDepartamento(){
    return departamento;
}

 void Professor::receber(Publicacao* p){
    recebidas->push_back(p);
 }
