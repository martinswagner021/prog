/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public abstract class Produto {
    public enum Tamanho { DESCONHECIDO, P, M, G }
    private final String codigo;
    private String descricao;
    private final Tamanho tam;
    private float preco;

    public Produto(String codigo,Tamanho tam) {
        this.codigo = codigo;
        this.tam = tam;
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public Tamanho getTam() {
        return tam;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }
    
}
