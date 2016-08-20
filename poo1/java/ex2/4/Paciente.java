import java.lang.Math;
public class Paciente {
    private String nome;
    private int idade;
    private String endereco;
    private float altura;
    private float peso;

    public Paciente( String nome, int idade, String end, float alt, float peso ) {
        this.nome = nome;
        this.idade = idade;
        this.endereco = end;
        this.altura = alt;
        this.peso = peso;
    }

    public float obterIMC( ) {
        return this.peso/((float) Math.pow(this.altura, 2));
    }

    @Override
    public String toString(){
        return "Paciente\n[nome="+this.nome+"\nidade="+this.idade+
            "\nendereço="+this.endereco+"\naltura="+this.altura+"\npeso="+this.peso+"]";
    }
}
