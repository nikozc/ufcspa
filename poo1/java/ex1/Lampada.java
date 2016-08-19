public class Lampada {
    private String estadoDaLampada;
    public Lampada() {
        this.estadoDaLampada = "Apagada";
    }
    public void acende() {
        this.estadoDaLampada = "Acesa";
    }

    public void apaga() {
        this.estadoDaLampada = "Apagada";
    }

    public void mostraEstado() {
        System.out.println("A lampada está "+this.estadoDaLampada);
    }



    //Isso não é uma boa ideia
    public String getEstado() {
        return this.estadoDaLampada;
    }
    public void setEstado( String estado ) {
        this.estadoDaLampada = estado;
    }
}
