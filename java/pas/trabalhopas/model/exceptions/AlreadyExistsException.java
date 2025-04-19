package trabalhopas.model.exceptions;

public class AlreadyExistsException extends Exception{
    public AlreadyExistsException(String id) {
        super(id + " já cadastrado.");
    }
}