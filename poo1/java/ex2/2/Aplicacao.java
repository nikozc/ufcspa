import java.util.Scanner;

public class Aplicacao {
    public static void main ( String[] args) {
        Scanner leitura = new Scanner(System.in);
        int num1 = 0;
        int num2 = 0;
        System.out.println("Digite um decimal:");
        num1 = leitura.nextInt();
        System.out.println("Digite outro decimal:");
        num2 = leitura.nextInt();
        System.out.println(num1 + " para binário -> " +Integer.toBinaryString(num1));
        System.out.println(num2 + " para binário -> " +Integer.toBinaryString(num2));
    }

}
