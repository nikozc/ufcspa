public class Cliente {
    private String nome;
    private long cpf;

    public Cliente( String nome, long cpf) {
        super();
        this.nome = nome;
        this.cpf = cpf;
    }
    public Cliente() {
    }
    
    public String getNome() {
        return this.nome;
    }
    public long getCpf() {
        return this.cpf;
    }
    public void setNome( String nome ) {
        this.nome = nome;
    }
    public void setCpf( long cpf ) {
        this.cpf = cpf;
    }
    @Override
    public String toString(){
        return "Cliente[nome="+this.nome+", cpf="+this.cpf+"]";
    }
}
