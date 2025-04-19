package models;

public class Produto{
    public enum Tamanho {P, M, G};
    private final Tamanho tamanho;
    private final String cor;
    private final String esporte;
    private final String codigo;
    private float preco;

    public Produto(Tamanho tamanho, String cor, String esporte, String codigo, float preco){
        this.tamanho = tamanho;
        this.cor = cor;
        this.esporte = esporte;
        this.codigo = codigo;
        this.preco = preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public String getCodigo() {
        return codigo;
    }
    public String getCor() {
        return cor;
    }
    public String getEsporte() {
        return esporte;
    }
    public float getPreco() {
        return preco;
    }
    public Tamanho getTamanho() {
        return tamanho;
    }
}