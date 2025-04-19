/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model.exceptions;

/**
 *
 * @author edumo
 */
public class FormatoTamanhoException extends ProdutoException{
    private final String tamanho;
    public FormatoTamanhoException(String codigo,String tamanho) {
        super("Formato '"+tamanho+"' do tamanho está incorreto",codigo);
        this.tamanho = tamanho;
    }

    public String getTamanho() {
        return tamanho;
    }
    
}
