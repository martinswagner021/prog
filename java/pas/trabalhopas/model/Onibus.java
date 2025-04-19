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
        return this.classe;
    }
    public int getLugares() {
        return this.lugares;
    }
    public String getPlaca() {
        return this.placa;
    }
    public float getCusto() {
        return this.custo;
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
