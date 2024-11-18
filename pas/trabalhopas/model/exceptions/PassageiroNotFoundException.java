package trabalhopas.model.exceptions;

public class PassageiroNotFoundException extends Exception {
    public PassageiroNotFoundException(String cpf) {
        super("Passageiro com CPF " + cpf + " não encontrado.");
    }
}
