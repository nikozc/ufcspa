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
        if (this->inicio == nullptr){
            this->inicio = novo;
            this->tam = 1;
        }
        else {
            No* x ;
            x = get_last_no();
            x->proximo = novo;
            tam+=1;
        }
    }
    No* get_last_no() {

        No* n;
        No* tmp;
        n = inicio;
        for (int i=0; i<(tam-1); i++){
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

class ListaContigua{
    std::vector<int> dados;
    int tam;
    int ocupados;
    public:
    ListaContigua(int t){
        tam = t;
        ocupados = 0;
        dados.reserve(t);
    }
    void append( int valor) {
        if ( ocupados < tam){
            dados[ocupados] = valor;
            ocupados+= 1;
        }
    }
    void append_front (int valor) {
        if ( ocupados < tam){
            for (int i=ocupados; i>0; i--){
                dados[i] = dados[i-1];
            }
            dados[0] = valor;
            ocupados+=1;
        }
    }

    void append_pos(int valor, int pos){
        if ( ocupados < tam){
            if ( pos < ocupados ) {
                for (int i=ocupados; i>pos; i--){
                    dados[i] = dados[i-1];
                }
                dados[pos] = valor;
                ocupados+=1;
            }
        }
    }

    void print_val(){
        for (int i =0; i< ocupados; i++){
            std::cout << dados[i] << '\n';
        }
    }
};

int main(){
    /* No n1(5); */
    /* No n2(50); */
    /* No n3(10); */
    /* No n4(70); */
    /* /1* std::cout << n1.get_val(); *1/ */
	/* ListaSimples l; */
    /* l.append(&n1); */
    /* l.append(&n2); */
    /* l.append(&n3); */
    /* l.append(&n4); */
    /* l.print_val(); */


    ListaContigua ll(8);
    for (int i =0; i< 2; i++){
        ll.append(i);
    }
    ll.append_front(9);
    ll.append_front(8);
    ll.append_pos(66, 2);
    for (int i =0; i< 4; i++){
        ll.append(i);
    }
    ll.print_val();
	return 0;
}
