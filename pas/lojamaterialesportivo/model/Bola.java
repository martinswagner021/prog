/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public class Bola extends ProdutoComTime{
    private final float peso;
    private final String time;

    public Bola(String codigo, Tamanho tam,float peso, String time ) {
        super(codigo, tam);
        this.peso = peso;
        this.time = time;
    }

    public float getPeso() {
        return peso;
    }

    @Override
    public String getTime() {
        return time;
    }
    
}
