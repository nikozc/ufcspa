public class ContaBancaria {

    private String nomeCorrentista;
    private float saldo;
    private boolean contaEspecial;

    public ContaBancaria(String nome, float deposito, boolean eEspecial) {
        this.nomeCorrentista = nome;
        this.saldo = deposito;
        this.contaEspecial = eEspecial;
    }

    public void deposita( float valor ) {
        if ( valor > 0 ) {
            this.saldo = this.saldo + valor;
        }
    }

    public void retira( float valor ) {
        if ( valor > 0 ) {
            float total = this.saldo - valor;
            if ( total >= 0 ) {
                this.saldo = this.saldo - valor;
            }
        }
    }

    public void mostraDados() {
        System.out.println("Nome: "+this.nomeCorrentista);
        System.out.println("Saldo: "+this.saldo);
        System.out.println("Conta especial : "+this.contaEspecial);
    }




    //Isso não é uma boa ideia
    public float getSaldo() {
        return this.saldo;
    }
    public String getNomeCorrentista() {
        return this.nomeCorrentista;
    }
    public bool getContaEspecial() {
        return this.contaEspecial;
    }
    public void setSaldo( float saldo ) {
        this.saldo = saldo;
    }
    public void setNomeCorrentista( String nome ) {
        this.nomeCorrentista = nome;
    }
    public void setContaEspecial( bool conta ) {
        this.contaEspecial = conta;
    }
}
