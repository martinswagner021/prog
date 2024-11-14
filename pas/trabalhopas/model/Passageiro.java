package trabalhopas.model;

public class Passageiro extends Pessoa{
    private String email;

    public Passageiro(String cpf, String nome, int idade, String email){
        super(cpf, nome, idade);
        this.setEmail(email);
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
    
}
