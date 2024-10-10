package models;

public class Roupa extends Produto{
    public enum Tipo {CAMISA, SHORT};
    private final String estilo;
    private final String time;
    private final Tipo tipo;

    public Roupa(Tamanho tamanho, String cor, String esporte, String codigo, float preco, String estilo, String time, Tipo tipo){
        super(tamanho, cor, esporte, codigo, preco);
        this.estilo = estilo;
        this.time = time;
        this.tipo = tipo;
    }

    public String getEstilo() {
        return estilo;
    }
    public String getTime() {
        return time;
    }
    public Tipo getTipo() {
        return tipo;
    }
}
