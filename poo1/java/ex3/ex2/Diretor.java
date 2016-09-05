package ex2;
public class Diretor extends Funcionario implements Autenticavel {
    private int numeroFuncGer;
    public Diretor( String nome, int cpf, double salario) {
        super(nome, cpf, salario);
    }
    public double calculaSalario() {
        return this.salario;
    }

    public void administraFilial() {
    }

    public boolean autentica(String senha) {
        return true;
    }
}
