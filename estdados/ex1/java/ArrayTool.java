public class ArrayTool {
    public static void main(String[] args) {
    }
    public int contaElementosNegativos(int[] vetor) {
        int contador = 0;
        for (int valor: vetor) {
            if (valor < 0) {
                contador++;
            }
        }
        return contador;
    }
    public int contaOcorrenciasValor(int[] vetor, int valor) {
        int contador = 0;
        for (int valorAtual: vetor) {
            if (valorAtual == valor) {
                contador++;
            }
        }
        return contador;
    }
    public boolean temElementosDistintos(int[] vetor) {
        for (int valorAtual: vetor) {
            if (valorAtual != vetor[0]) {
                return true;
            }
        }
        return false;
    }
    public int retornaPosicaoMaiorElemento(int[] vetor) {
        int maior = vetor[0];
        int posicao = 0;
        int contador = 0;
        for ( int valor: vetor){
            if (valor > maior) {
                maior = valor;
                posicao = contador;
            }
                    contador++;
        }
        return posicao;
    }
}
