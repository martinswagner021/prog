/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public class Produto {
    public enum Tamanho { P, M, G }
    private final Tamanho tam;
    private float preco;

    public Produto(Tamanho tam) {
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
    
}
