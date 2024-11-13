/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.view;

import java.util.Scanner;
import pas.lojamaterialesportivo.controller.Controlador;
import pas.lojamaterialesportivo.model.exceptions.FormatoPesoException;
import pas.lojamaterialesportivo.model.exceptions.FormatoTamanhoException;
import pas.lojamaterialesportivo.model.exceptions.ProdutoJaCadastradoException;

/**
 *
 * @author edumo
 */
class Menu {
    private final Controlador ctrl = new Controlador();
    private final Scanner sc = new Scanner(System.in);
    public void menu() {
        int opcao;
       
        System.out.println("Loja de material esportivo");
        System.out.println("1 - Cadastrar Produto");
        System.out.println("2 - Sair");
        do{
            opcao = sc.nextInt();
            switch(opcao){
                case 1 : CadastrarProduto(); break;
            }
        }while(opcao != 2);
    }
    
    private void CadastrarProduto(){
        int opcao;
        do{
            System.out.println("1- Bola");
            System.out.println("2- Raquete");
            System.out.println("3- Roupa");
            System.out.println("4- Voltar");
            opcao = sc.nextInt();
            switch(opcao){
                case 1 : 
                    try {
                        CadastrarBola();
                    } catch(ProdutoJaCadastradoException ex) {
                        System.out.println(ex.getMessage());
                        ex.getCodigo();
                    }break;
                case 2 : CadastrarRaquete(); break;
                case 3 : CadastrarRoupa(); break;
            }
        }while(opcao != 4);    
    }
    private void CadastrarRaquete(){
        
    }
    private void CadastrarRoupa(){
        
    }
    private void CadastrarBola() throws ProdutoJaCadastradoException{
        String codigo, peso, tamanho, time;
        System.out.println("Codigo: ");
        codigo = sc.next();
        System.out.println("Peso: ");
        peso = sc.next();
        System.out.println("Time: ");
        time = sc.next();
        boolean sucesso = true;
        do{
            System.out.println("Tamanho: ");
            tamanho = sc.next();
      
            try{
                ctrl.cadastrarBola(codigo,peso,tamanho,time);
                System.out.println("Produto cadastrado com sucesso");
                sucesso = true;
            }catch(FormatoTamanhoException ex){
                System.out.println(ex.getMessage());
                sucesso = false;
            }catch(FormatoPesoException ex){
                System.out.println(ex.getMessage());
                sucesso = true;
            }
        }while(!sucesso);
    }
}
