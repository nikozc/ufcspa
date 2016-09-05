package ex1;

public abstract class Professor {
    private String nome;
    private int matricula;
    private int idade;
    public Professor (String no, int ma, int id) {
        this.nome = no;
        this.matricula = ma;
        this.idade = id;
    }

    public abstract void calculaSalario();

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getIdade() {
        return idade;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public int getMatricula() {
        return matricula;
    }
}
