/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public abstract class ProdutoComTime extends Produto {
    public abstract String getTime();

    public ProdutoComTime(String codigo, Tamanho tam) {
        super(codigo, tam);
    }
    
}
