/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public class Pessoa {
    private final String cpf;
    private String nome;
    private String endereco;
    
    public Pessoa(String cpf, String nome){
        this.cpf = cpf;
        this.nome = nome;
        this.endereco = "";
    }
    public String getCpf(){
        return this.cpf;
    }

    public String getNome() {
        return this.nome;
    }

    public String getEndereco() {
        return this.endereco;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    
}
