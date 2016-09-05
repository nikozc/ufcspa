public class Gerente extends Funcionario implements Autenticavel {
    private int numeroFuncGer;
    public Gerente( String nome, int cpf, double salario) {
        super(nome, cpf, salario);
    }
    public double calculaSalario() {
        return this.salario;
    }

    public void supervisionaFunc() {
    }

    public boolean autentica(String senha) {
        return true;
    }
}
