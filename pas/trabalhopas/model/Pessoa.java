package trabalhopas.model;

public class Pessoa {
    private final String cpf;
    private String nome;

    public Pessoa(String cpf, String nome, int idade){
        this.cpf = cpf;
        this.setNome(nome);
    }

    public String getCpf() {
        return cpf;
    }
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

}
