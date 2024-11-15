package trabalhopas.model;

public class Onibus {
    public enum classeOnibus {ECONOMICA, EXECUTIVA, LUXO};
    private final String placa;
    private int lugares;
    private classeOnibus classe;
    private float custo;

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

    public void setCusto(float custo) {
        this.custo = custo;
    }
    public void setClasse(classeOnibus classe) {
        this.classe = classe;
    }
    public void setLugares(int lugares) {
        this.lugares = lugares;
    }

}
