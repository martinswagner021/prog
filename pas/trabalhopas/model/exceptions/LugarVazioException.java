package trabalhopas.model.exceptions;

public class LugarVazioException extends Exception{
    public LugarVazioException(int lugar){
        super("Não há passageiro no lugar " + lugar + " para ser removido.");
    }
}