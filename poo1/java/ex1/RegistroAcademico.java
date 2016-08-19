public class RegistroAcademico {

    private String nomeAluno;
    private int numeroMatricula;
    private boolean eBolsista;

    public RegistroAcademico(String nome, int mat, boolean bosista) {
        this.nomeAluno = nome;
        this.numeroMatricula = mat;
        this.eBolsista = bosista;
    }

    public void calculaMensalidade( float valMensalidade ) {
        if ( valMensalidade > 0 ) {
            if ( this.eBolsista ) {
                valMensalidade = valMensalidade * 0.5f;
            }
            System.out.println("Valor mensalidade: "+ valMensalidade);
        }
    }

    public void mostraRegistro() {
        System.out.println("Nome: "+this.nomeAluno);
        System.out.println("Matricula: "+this.numeroMatricula);
        System.out.println("Bosista: "+this.eBolsista);
    }


    public float getMensalidade( float valMensalidade ) {
        if ( valMensalidade > 0 ) {
            if ( this.eBolsista ) {
                valMensalidade = valMensalidade * 0.5f;
            }
            return valMensalidade;
        }
        return 0f;
    }

    //Isso não é uma boa ideia
    public String getNomeAluno() {
        return this.nomeAluno;
    }

    public int getNumeroMatricula() {
        return this.numeroMatricula;
    }
    public boolean getEBolsista() {
        return this.eBolsista;
    }
    public void setNomeAluno( String nome ) {
        this.nomeAluno = nome;
    }
    public void setNumeroMatricula( int numero ) {
        this.numeroMatricula = numero;
    }
    public void setEBolsista( boolean bol ) {
        this.eBolsista = bol;
    }
}
