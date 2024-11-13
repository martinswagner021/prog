/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public class Roupa extends ProdutoComTime{
    public enum Tipo { Camisa, shorts, saia, agasalho }
    private final Tipo tipo;
    private final String estilo;
    private final String time;

    public Roupa(String codigo, Tamanho tam,String estilo, String time,Tipo tipo) {
        super(codigo,tam);
        this.tipo = tipo;
        this.estilo = estilo;
        this.time = time;
    }

    public Tipo getTipo() {
        return tipo;
    }

    public String getEstilo() {
        return estilo;
    }

    @Override
    public String getTime() {
        return time;
    }

}
