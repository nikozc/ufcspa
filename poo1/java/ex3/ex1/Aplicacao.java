package ex1;
public class Aplicacao {
    public static void main( String[] args ) {
        ProfessorDE p1 = new ProfessorDE("professor1", 1, 60, 10000.0);
        ProfessorHorista p2 = new ProfessorHorista("professor2", 1, 60, 40, 10000.0/40);
        p1.calculaSalario();
        p2.calculaSalario();
    }
}
