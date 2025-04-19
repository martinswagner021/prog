/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model.exceptions;

/**
 *
 * @author edumo
 */
public class ProdutoJaCadastradoException extends ProdutoException {

    public ProdutoJaCadastradoException(String codigo) {
        super("Produto com codigo "+ codigo+ " já cadastrado",codigo);
    }
    
}
