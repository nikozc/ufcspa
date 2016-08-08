#include <vector>
#include "../catch.hpp"

int contaElementosNegativos( std::vector<int> vetor ){
    int contadorNegativos = 0;
    for(const int valor : vetor) {
        if (valor < 0) {
            contadorNegativos++;
        }
    }
    return contadorNegativos;
}

int contaOcorrenciasValor( std::vector<int> vetor, int valor ){
    int contadorOcorrencias = 0;
    for(const int valorAtual : vetor) {
        if (valorAtual == valor) {
            contadorOcorrencias++;
        }
    }
    return contadorOcorrencias;
}

bool temElementosDistintos( std::vector<int> vetor ){
    for(const int valorAtual : vetor) {
        if (valorAtual != vetor[0]) {
            return true;
        }
    }
    return false;
}

int retornaPosicaoMaiorElemento( std::vector<int> vetor ){
    /* A contagem do indice começa no 0 (zero) */
    int posicao = 0;
    int maior = vetor[0];
    for(int i=0; i<vetor.size(); i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao = i;
        }
    }
    return posicao;
}
