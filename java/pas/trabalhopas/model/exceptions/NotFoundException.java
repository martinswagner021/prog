package trabalhopas.model.exceptions;

public class NotFoundException extends Exception {
    public NotFoundException(String id) {
        super(id + " não encontrado.");
    }
}
