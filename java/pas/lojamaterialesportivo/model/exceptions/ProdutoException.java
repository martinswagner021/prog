/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model.exceptions;

/**
 *
 * @author edumo
 */
public class ProdutoException extends Exception{
    private final String codigo;
    protected ProdutoException(String msg,String codigo){
        super(msg);
        this.codigo = codigo;
    }
    public ProdutoException(String codigo){
        super("Exception com Produto de codigo: "+codigo);
        this.codigo = codigo;
    }

    public String getCodigo() {
        return codigo;
    }
    
}
