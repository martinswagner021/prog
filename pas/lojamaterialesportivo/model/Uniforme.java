/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public class Uniforme extends Conjunto{
    private final String time;

    public Uniforme(String time) {
        this.time = time;
    }

    public String getTime() {
        return time;
    }
    
    @Override
    public void addProduto(Produto produto){

    }
    public void addProduto(ProdutoComTime produto){
        if(this.time.equals(produto.getTime()))
            super.addProduto(produto);
    }
}
