#include <iostream>
#include <vector>

class No {
	public:
	int valor;
	No* proximo;
    No(int v){
        valor = v;
        proximo = nullptr;
    }
    No* get_proximo() {
        return proximo;
    }
    int get_val(){
        return valor;
    }
};

class ListaSimples {
	int tam=0;
	No* inicio = nullptr;
	No* fim = nullptr;
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
            tam+=1;
        }
    }

    void append_pos(No* novo, int pos){
    
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
    void print_val(){
        No* n = inicio;
        std::cout << "A lista contém " << tam << " elementos.\n";
        for (int i=0; i<this->tam; i++){
            std::cout << "[" << i << "]" << n->get_val() << '\n';
            n = n->proximo;
        }
    }
};

int main(){
    No n1(5);
    No n2(50);
    No n3(10);
    No n4(70);
    No n5(700);
	ListaSimples l;
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    l.append(&n4);
    l.append_pos(&n5, 2);
    l.print_val();

}
