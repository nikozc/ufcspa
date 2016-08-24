public class Carro {
    private String motor;
    private int anofab;
    private String fabricante;

    public Carro( String motor, int ano, String fab) {
        super();
        this.motor = motor;
        this.anofab = ano;
        this.fabricante = fab;
    }
    public String getMotor() {
        return this.motor;
    }
    public int getAno() {
        return this.anofab;
    }
    public String getFabricante() {
        return this.fabricante;
    }
    public void setMotor( String motor ) {
        this.motor = motor;
    }
    public void setAnoFab( int anofab ) {
        this.anofab = anofab;
    }
    public void setFabricante( String fabricante ) {
        this.fabricante = fabricante;
        
    }

}
