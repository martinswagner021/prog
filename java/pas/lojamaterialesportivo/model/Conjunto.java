/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

import java.util.HashMap;

/**
 *
 * @author edumo
 */
public class Conjunto {
    private HashMap<String,Produto>  produtos = new HashMap();

//    public Produto getProduto(int posicao) {
//        if (posicao > produtos.size()) return null;
//        return produtos.get(posicao);
//    }
//    public Produto getProduto(String codigo) {
//        for(Produto p : produtos)
//            if(codigo.equals(p.getCodigo()))
//                return p;
//        return null;
//    }
    public Produto getProduto(String codigo) {
          return produtos.get(codigo);
    }
//    public void setProduto(int posicao,Produto produto) {
//        this.produtos.set(posicao, produto);
//    }
    
    public void addProduto(Produto produto){
        this.produtos.put(produto.getCodigo(),produto);
    }
    
    public int tamanho(){
        return this.produtos.size();
    }
}
