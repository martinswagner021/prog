/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model.exceptions;

/**
 *
 * @author edumo
 */
public class FormatoPesoException extends ProdutoException{
    private final String peso;
    public FormatoPesoException(String codigo,String peso) {
        super("Formato '"+peso+"' do peso está incorreto",codigo);
        this.peso = peso;
    }

    public String getPeso() {
        return peso;
    }
    
}
