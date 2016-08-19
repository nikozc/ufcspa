import java.util.Scanner;

public class Aplicacao {
    public static void main ( String[] args) {
        ClasseA a1 = new ClasseA();
        ClasseA a2 = new ClasseA( 10 );
        ClasseA a3 = new ClasseA( 10, 20 );
        System.out.println("ClasseA objeto1");
        a1.imprimir();
        System.out.println("ClasseA objeto2");
        a2.imprimir();
        System.out.println("ClasseA objeto3");
        a3.imprimir();

        ClasseB b1 = new ClasseB();
        ClasseB b2 = new ClasseB( 10 );
        ClasseB b3 = new ClasseB( 10, 20 );
        System.out.println("ClasseB objeto1");
        b1.imprimir();
        System.out.println("ClasseB objeto2");
        b2.imprimir();
        System.out.println("ClasseB objeto3");
        b3.imprimir();

        ClasseC c1 = new ClasseC();
        ClasseC c2 = new ClasseC( 10 );
        ClasseC c3 = new ClasseC( 10, 20 );
        System.out.println("ClasseC objeto1");
        c1.imprimir();
        System.out.println("ClasseC objeto2");
        c2.imprimir();
        System.out.println("ClasseC objeto3");
        c3.imprimir();

        ClasseD d1 = new ClasseD();
        ClasseD d2 = new ClasseD( 10 );
        ClasseD d3 = new ClasseD( 10, 20 );
        System.out.println("ClasseD objeto1");
        d1.imprimir();
        System.out.println("ClasseD objeto2");
        d2.imprimir();
        System.out.println("ClasseD objeto3");
        d3.imprimir();

        ClasseE e1 = new ClasseE();
        ClasseE e2 = new ClasseE( 10 );
        ClasseE e3 = new ClasseE( 10, 20 );
        System.out.println("ClasseE objeto1");
        e1.imprimir();
        System.out.println("ClasseE objeto2");
        e2.imprimir();
        System.out.println("ClasseE objeto3");
        e3.imprimir();
    }

}
