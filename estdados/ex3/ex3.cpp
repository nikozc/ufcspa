#include <vector>

void logica_qs(std::vector<int>&,int,int);
int divide(std::vector<int>&, int,int);

std::vector<int> shell_sort( std::vector<int> vetor ) {
    /* Este método de ordenação consiste em "dividir" o vetor em vaŕios
     * sub-vetores e ordenar cada um destes sub-vetores ao invés de ordenar
     * todo o vetor de uma vez só.
     *
     * A ideia principal para a motivação deste método é que esses sub-vetores
     * estão, em geral, quase ordenado. O que torna o método bastante eficiente.
     *
     * Por questão de comodidade e performance estamos utilizando a
     * função std::swap() [http://www.cplusplus.com/reference/vector/vector/swap/]
     * ela realiza a troca de dois elementos dentro de um vetor.
     * Ela pode ser substituida pelo seguinte código:
     *      temp = vetor[indice1];
     *      vetor[indice1] = vetor[indice2];
     *      vetor[indice2] = temp; */

    std::vector<int> intervalos = {701, 301, 132, 57, 23, 10, 4, 1};
    for ( int intervalo:intervalos ) {
        if ( intervalo < vetor.size() ) {
            for (int i = intervalo; i < vetor.size(); i += 1){
                int temp = vetor[i];
                int j =0;
                for ( j=i; j>=intervalo; j-=intervalo) {
                    if ( vetor[j-intervalo] > temp) {
                        std::swap(vetor[j], vetor[j-intervalo]);
                    }
                }
            }
        }
    }
    return vetor;
}

std::vector<int> bubble_sort( std::vector<int> vetor ){
    /* Este método de ordenação consiste em realizar a comparação
     * de todos os pares adjacentes do vetor e realizar as trocas
     * de forma que cada par fique ordenado.
     *
     * Por questão de comodidade e performance estamos utilizando a
     * função std::swap() [http://www.cplusplus.com/reference/vector/vector/swap/]
     * ela realiza a troca de dois elementos dentro de um vetor.
     * Ela pode ser substituida pelo seguinte código:
     *      temp = vetor[indice1];
     *      vetor[indice1] = vetor[indice2];
     *      vetor[indice2] = temp; */

    bool f = false;
    for( int i=0; i< vetor.size(); i++) {
        for( int j=0; j < ( vetor.size()-1 ); j++) {
            if ( vetor[j] > vetor[j+1] ) {
                std::swap(vetor[j+1], vetor[j]);
                f = true;
            }
        }
        if ( not f ) {
            return vetor;
        }
        f = false;
    }
    return vetor;
}

std::vector<int> quick_sort( std::vector<int> &vetor ) {
    /* Este método de ordenação consiste em utilizar a técnica de
     * dividir e conquistar.
     * Nesta implementação estamos utilizando como pivot inicial o
     * primeiro elemento do vetor, isso simplifica um pouco nosso
     * código e também nos pouca uma operação para descobrir qual
     * o elemento mediano do vetor. Outra opção seria escolher um
     * elemento aleatório como pivot inicial, talvez em algum problema
     * específico essa seja uma boa ideia mas em nosso caso não
     * há essa necessidade.
     *
     * Como queriamos que esta função se comportasse da mesma maneira
     * que a anterior (recebe um vetor e retorna um vetor) resolvemos
     * criar uma variável para guardar o conteúdo do vetor enquanto
     * estamos ordenando ele, de outra forma seriamos obrigados a
     * criar dois novos vetores cada vez que logica_qs() fosse executada.
     * Para vetores grandes isso implicaria em uma quantidade enorme de
     * memória sendo alocada.
     * A solução que utilizamos foi passar o vetor por referência,
     * assim temos apenas uma cópia do vetor. Se não fosse possível
     * guardar uma cópia do vetor em memória poderiamos fazer as
     * oprações diretamente sobre o vetor original, mas a complexidade
     * do código seria um pouco maior e também perderiamos um pouco
     * de flexibilidade.
     *
     * Por questão de comodidade e performance estamos utilizando a
     * função std::swap() [http://www.cplusplus.com/reference/vector/vector/swap/]
     * ela realiza a troca de dois elementos dentro de um vetor.
     * Ela pode ser substituida pelo seguinte código:
     *      temp = vetor[indice1];
     *      vetor[indice1] = vetor[indice2];
     *      vetor[indice2] = temp; */

    std::vector<int> buffer = vetor;
    logica_qs(buffer, 0, buffer.size());
    return buffer;
}

void logica_qs( std::vector<int> &ref_vetor, int esquerda,int direita )
{
    int separador;
    if(esquerda < direita)
    {
        separador = divide(ref_vetor, esquerda, direita);
        logica_qs(ref_vetor, esquerda, separador);
        logica_qs(ref_vetor, separador+1, direita);
    }
}


int divide( std::vector<int> &ref_vetor, int esquerda, int direita )
{
    int x = ref_vetor[esquerda];
    int pivot = esquerda;
    for( int j = esquerda+1; j < direita; j++)
    {
        if(ref_vetor[j] <= x)
        {
            pivot++;
            std::swap(ref_vetor[pivot], ref_vetor[j]);
        }
    }
    std::swap(ref_vetor[pivot], ref_vetor[esquerda]);
    return pivot;
}

std::vector<int> selection_sort( std::vector<int> vetor ) {
    /* Este método de ordenação consiste em ordenar o vetor um
     * elemento por vez.
     * Ele coloca o menor elemento no inicio do vetor, depois o
     * segundo menor elemento na segunda posição e assim sucessivamente
     * até que o vetor esteja todo ordenado.
     * Uma vantegem dele é que a cada iteração ele precisa realizar um
     * número menor de comparações.
     *
     * Por questão de comodidade e performance estamos utilizando a
     * função std::swap() [http://www.cplusplus.com/reference/vector/vector/swap/]
     * ela realiza a troca de dois elementos dentro de um vetor.
     * Ela pode ser substituida pelo seguinte código:
     *      temp = vetor[indice1];
     *      vetor[indice1] = vetor[indice2];
     *      vetor[indice2] = temp; */
    int indice_menor = 0;
    for (int i = 0; i < (vetor.size() -1); i++) {
        indice_menor = i;
        for ( int j = (i+1); j < vetor.size(); j++ ) {
            if ( vetor[j] < vetor[indice_menor] ) {
                indice_menor = j;
            }
        }
        if ( indice_menor != i ) {
            std::swap(vetor[indice_menor], vetor[i]);
        }
    }
    return vetor;
}

std::vector<int> insertion_sort( std::vector<int> vetor ) {
    /* Este método de ordenação consiste em assumir que a primeira
     * posição está ordenada e depois vai ordenando os demais valores
     * presentes no vetor um a um, colocando cada um em seu devido lugar.
     *
     * Por questão de comodidade e performance estamos utilizando a
     * função std::swap() [http://www.cplusplus.com/reference/vector/vector/swap/]
     * ela realiza a troca de dois elementos dentro de um vetor.
     * Ela pode ser substituida pelo seguinte código:
     *      temp = vetor[indice1];
     *      vetor[indice1] = vetor[indice2];
     *      vetor[indice2] = temp; */
    int valor = vetor[0];
    int j;
    for ( int i = 1; i < vetor.size(); i++) {
        valor = vetor[i];
        j = i -1;
        while ( j >= 0 ) {
            if ( valor < vetor[j] ) {
                std::swap( vetor[j], vetor[j+1] );
            }
            --j;
        }
    }
    return vetor;
}
