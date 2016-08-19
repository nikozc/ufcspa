import java.util.Scanner;

public class Aplicacao {
    public static void main ( String[] args){
    Scanner leitura = new Scanner(System.in);
    System.out.println("Digite seu nome:");
    String nome = leitura.nextLine();
    System.out.println("Seu nome contém "+nome.length()+" caracteres");
    String p = " Programando";
    System.out.println(nome.split(" ")[0] + p );
    System.out.println(nome.toUpperCase());
    System.out.println(nome.split(" ")[1]);
    }

}
