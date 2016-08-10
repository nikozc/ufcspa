public class Lampada {
    private String estadoDaLampada;
    public Lampada(String estado) {
        this.estadoDaLampada = estado;
    }
    public void acende() {
        this.estadoDaLampada = "ligada";
    }

    public void apaga() {
        this.estadoDaLampada = "desligada";
    }

    public void mostraEstado() {
        System.out.println("A lampada está "+this.estadoDaLampada);
    }

    public String getEstado() {
        return this.estadoDaLampada;
    }
}
