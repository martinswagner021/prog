package models;

public class Pessoa {
    private final String cpf;
    private String nome;
    private String endereco;

    public Pessoa(String cpf, String nome){
        this.cpf = cpf;
        this.setNome(nome);
        this.setEndereco(endereco);
    }
    public Pessoa(String cpf, String nome, String endereco){
        this.cpf = cpf;
        this.setNome(nome);
        this.setEndereco(endereco);
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    public String getCpf() {
        return cpf;
    }
    public String getNome() {
        return nome;
    }
    public String getEndereco() {
        return endereco;
    }
}
