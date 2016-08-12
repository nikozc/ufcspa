import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.lang.Math;
public class Aplicacao {
    public static void main ( String[] args) throws Exception {
        Cliente cli = new Cliente("Nicolas", 12345);
         cli = new Cliente("Nicolas2", 812345);
         System.out.println("Imprimindo nome:" + cli.getNome());
         System.out.println("Imprimindo cpf:" + cli.getCpf());
         Scanner leitura = new Scanner(System.in);
         System.out.print("Digite o nome do cliente: " );
         String nome;
         long cpf;
         nome = leitura.nextLine();
         System.out.print(nome);
         System.out.println("!!");
         System.out.print("Digite o cpf do cliente: ");
         cpf = leitura.nextLong();
         System.out.print(cpf);
         System.out.println("!!");
         Cliente outro_cliente = new Cliente(nome, cpf);
         System.out.println(outro_cliente);



    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();
    System.out.println(Math.PI);
    }
}
