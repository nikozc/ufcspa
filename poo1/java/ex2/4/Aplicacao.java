import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Aplicacao {
    public static void main ( String[] args) throws Exception {
    BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
    System.out.println("Digite seu nome:");
    String nome = br.readLine();
    System.out.println("Digite a idade:");
    int idade = Integer.parseInt( br.readLine());
    System.out.println("Digite o endereço:");
    String end = br.readLine();
    System.out.println("Digite a altura:");
    float alt = Float.parseFloat(br.readLine());
    System.out.println("Digite o peso:");
    float peso = Float.parseFloat(br.readLine());
    Paciente p = new Paciente(nome, idade, end, alt, peso);
    System.out.println(p);
    System.out.println("O IMC do paciente é: "+p.obterIMC());
    }

}
