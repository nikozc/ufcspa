#include <iostream>
#include <vector>

class No {
    public:
    int valor;
    No* proximo;
    No* anterior;

    No(int v){
        valor = v;
        proximo = nullptr;
        anterior = nullptr;
    }
    bool set_proximo( No* prx ) {
        proximo = prx;
        return true;
    }

    bool set_anterior( No* ant ) {
        anterior  = ant;
        return true;
    }

    No* get_proximo() {
        /* std::cout << "p> " << proximo; */
        return proximo;
    }

    No* get_anterior() {
        /* if (anterior == nullptr) { */
            /* std::cout << "retornando ponteiro nulo\n"; */
        /* } */
        return anterior;
    }

    int get_val(){
        return valor;
    }
};

class ListaDupla {
    int tam=0;
    No* inicio = nullptr;
    int size(){
        return this->tam;
    }
    public:

    void append(No* novo){
        if (inicio == nullptr){
            inicio = novo;
            tam = 1;
        }
        else {
            No* x ;
            x = get_last_no();
            x->proximo = novo;
            novo->anterior = x;
            tam+=1;
        }
    }

        void preppend(No* n){
            /* Adiciona na frente da lista */
            n->set_proximo(inicio);
            inicio = n;
            tam++;
        }

        void append_pos(No* novo, int pos){
            /* Adiciona o nó ANTES da posição */
            /* append_pos(&no, 1) irá adicionar o nó ANTES do elemento 1, */
            /*     ou seja na segunda posição */
            No* n;
            No* tmp;
            n = inicio;
        for (int i=0; i<(pos-1); i++){
            tmp = n->get_proximo();
            n = tmp;
        }
        tmp = n->get_proximo();
        n->proximo = novo;
        novo->proximo = tmp;
        tam+=1;
    }

    No* get_last_no() {
        No* n;
        No* tmp;
        n = inicio;
        while (n->get_proximo() != nullptr ){
            tmp = n->get_proximo();
            n = tmp;
        }
        return n;
    }

    No* get_node( int pos) {
        /* Retorna um ponteiro para o nó que está na posição desejada */
        No* n;
        No* tmp;
        n = inicio;
        int i=0;
        while ( i  < tam-1){
            if ( i == pos) {
                return n;
            }
            tmp = n->get_proximo();
            n = tmp;
            i++;
        }
        return nullptr;
    }
        
    bool del_node( int pos ) {
        /* Deve haver uma maneira melhor de fazer isso! */
        /* a <=> b <=> c
         * a.proximo = c;
         * c.anterior = a; 
         * a <=> c */
        No* remocao;
        if ((pos > 0) && (pos < tam-1)){
            remocao = get_node(pos);
            No* tmp = remocao->get_proximo();
            remocao->anterior->set_proximo(tmp);
            tmp = remocao->get_anterior();
            remocao->proximo->set_anterior(tmp);
        }
        else {
            remocao = get_node(pos);
            if (pos == 0) {
                /* Removendo o primeiro elemento */
                inicio = remocao->get_proximo();
                remocao->get_proximo()->set_anterior(nullptr);
            }
            else {
                /* Removendo o último elemento */
                if ( remocao != nullptr ) {
                    remocao->get_anterior()->set_proximo(nullptr);
                }
            }
        }
        tam--;
        return true;
    }

    void print_val(){
        No* n = inicio;
        std::cout << "A lista contém " << tam << " elementos.\n";
        for (int i=0; i<this->tam; i++){
            std::cout << "[" << i << "]" << n->get_val() << '\n';
            n = n->proximo;
        }
    }
    
    No* search_by_value(int valor) {
        /* Retorna o ponteiro para o PRIMEIRO elemento da lista que possui o valor
         * Caso o valor não exista na lista retorna nullptr */
        No* n;
        No* tmp;
        n = inicio;
        for ( auto i = 0; i < tam; i++) {
            if (n->get_val() == valor) {
                return n;
            }
            tmp = n->get_proximo();
            n = tmp;
        }
        return nullptr;
    }

    std::vector<int> get_vector_repr(){
        /* Retorna um vetor que representa os valores da lista, útil para testes */
        std::vector<int> res;
        res.reserve(tam);
        No* n = inicio;
        for (auto i=0; i<tam; i++) {
           res.push_back(n->get_val());
           n = n->get_proximo();
        }
        return res;
    }
};

/* int main(){ */
/*     No n1(5); */
/*     No n2(50); */
/*     No n3(10); */
/*     No n4(70); */
/*     No n5(700); */
/*     /1* ListaSimples l; *1/ */
/*     ListaDupla l; */
/*     l.append(&n1); */
/*     l.append(&n2); */
/*     l.append(&n3); */
/*     l.append(&n4); */
/*     l.preppend(&n5); */
/*     /1* l.append_pos(&n5, 2); *1/ */
/*     for (auto a: l.get_vector_repr()) { */
/*         std::cout << a << '\n'; */
/*     } */
/*     l.print_val(); */
/*     /1* l.del_node(0); *1/ */
/*     /1* l.del_node(3); *1/ */
/*     /1* l.print_val(); *1/ */
/*     /1* std::cout << l.search_by_value(71); *1/ */
/*     /1* if (l.search_by_value(71) == nullptr ) { *1/ */
/*     /1*     std::cout << "igual"; *1/ */
/*     /1* } *1/ */
/*     /1* if (l.search_by_value(70) != nullptr ) { *1/ */
/*     /1*     std::cout << l.search_by_value(70)->get_val(); *1/ */
/*     /1* } *1/ */
/*     /1* else { *1/ */
/*     /1*     std::cout << "Valor não encontrado!\n"; *1/ */
/*     /1* } *1/ */

/* } */
