/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

import java.util.ArrayList;

/**
 *
 * @author edumo
 */
public class Conjunto {
    private ArrayList<Produto>  produtos;

    public Produto getProduto(int posicao) {
        return produtos.get(posicao);
    }

    public void setProduto(int posicao,Produto produto) {
        this.produtos.set(posicao, produto);
    }
    
    public void addProduto(Produto produto){
        this.produtos.add(produto);
    }
    
    
}
