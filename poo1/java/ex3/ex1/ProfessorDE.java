package ex1;
public class ProfessorDE extends Professor {
    private double salario;

    public ProfessorDE(String no, int ma, int id, double sal) {
        // super("p1", 12, 60);
        super(no, ma, id);

        this.salario = sal;
    }

    public void calculaSalario() {
        System.out.println(2.0*this.salario);
        // return 2.0*this.salario;
    }
    public void setSalario(double salario) {
        this.salario = salario;
    }

    public double getSalario() {
        return salario;
    }
}
