/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.controller;

import java.util.HashMap;
import pas.lojamaterialesportivo.model.Bola;
import pas.lojamaterialesportivo.model.Produto;
import pas.lojamaterialesportivo.model.Raquete;
import pas.lojamaterialesportivo.model.Roupa;
import pas.lojamaterialesportivo.model.Uniforme;
import pas.lojamaterialesportivo.model.exceptions.FormatoPesoException;
import pas.lojamaterialesportivo.model.exceptions.FormatoTamanhoException;
import pas.lojamaterialesportivo.model.exceptions.ProdutoJaCadastradoException;

/**
 *
 * @author edumo
 */
public class Controlador {
    private HashMap<String,Produto> produtos = new HashMap();
    public void cadastrarBola(String codigo,String peso,String tamanho,String time) 
            throws ProdutoJaCadastradoException, FormatoPesoException, FormatoTamanhoException{
        if(produtos.get(codigo) != null)
            throw new ProdutoJaCadastradoException(codigo);
        
        Produto.Tamanho t= Produto.Tamanho.DESCONHECIDO;
        switch(tamanho){
            case "P" : t = Produto.Tamanho.P;break;
            case "M" : t = Produto.Tamanho.M;break;
            case "G" : t = Produto.Tamanho.G;break;
        }
        
        if(t == Produto.Tamanho.DESCONHECIDO)
            throw new FormatoTamanhoException(codigo, tamanho);
        
        float p;
        try{
            p=Float.parseFloat(peso);
        }catch(NumberFormatException ex){
            throw new FormatoPesoException(codigo,peso);
        }
        Bola b = new Bola(codigo,t,p,time);
        produtos.put(codigo,b);
    }
    private void teste(){
        Uniforme u = new Uniforme("Botafogo");
        Raquete ra = new Raquete("RA001",Produto.Tamanho.M,"madeira");
        Bola b = new Bola("B001",Produto.Tamanho.M,400,"Botafogo");
        Roupa ro = new Roupa("RO001",Produto.Tamanho.M,"esportivo","Botafogo",Roupa.Tipo.Camisa);
        
        u.addProduto(ro);
        u.addProduto(b);
        u.addProduto(ra);
        
        //System.out.println(u.tamanho());
    }
}
