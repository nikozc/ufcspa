package ex1;
public class ProfessorHorista extends Professor {
    private int totalHoras;
    private double salarioHora;

    public ProfessorHorista (String no, int ma, int id, int totH, double salH) {
        // super("p2", 12, 60);
        super(no, ma, id);
        this.totalHoras = totH;
        this.salarioHora = salH;
    }

    public void calculaSalario() {
        System.out.println((double) this.totalHoras*this.salarioHora);
        // return ((double) this.totalHoras)*this.salarioHora;
    }
    public void setTotalHoras(int totalHoras) {
        this.totalHoras = totalHoras;
    }

    public int getTotalHoras() {
        return totalHoras;
    }

    public void setSalarioHora(double salarioHora) {
        this.salarioHora = salarioHora;
    }

    public double getSalarioHora() {
        return salarioHora;
    }
}
