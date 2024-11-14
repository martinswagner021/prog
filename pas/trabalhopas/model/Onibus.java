package trabalhopas.model;

public class Onibus {
    public enum classeOnibus {ECONOMICA, EXECUTIVA, LUXO};
    private final String placa;
    private final int lugares;
    private final classeOnibus classe;
    private final float custo;

    public Onibus(String placa, int lugares, classeOnibus classe, float custo){
        this.classe = classe;
        this.lugares = lugares;
        this.placa = placa;
        this.custo = custo;
    }

    public classeOnibus getClasse() {
        return classe;
    }
    public int getLugares() {
        return lugares;
    }
    public String getPlaca() {
        return placa;
    }
    public float getCusto() {
        return custo;
    }

}
