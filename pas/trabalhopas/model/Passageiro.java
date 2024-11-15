package trabalhopas.model;

public class Passageiro extends Pessoa{
    private String email;

    public Passageiro(String cpf, String nome, String email){
        super(cpf, nome);
        this.setEmail(email);
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
    
}
