package trabalhopas.controller;

import trabalhopas.model.Onibus;
import trabalhopas.model.exceptions.AlreadyExistsException;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.HashMap;
import java.util.Map;

public class OnibusController {
    private Map<String, Onibus> onibusMap = new HashMap<>();

    public void adicionarOnibus(Onibus onibus) throws AlreadyExistsException {
        if (onibusMap.containsKey(onibus.getPlaca())) {
            throw new AlreadyExistsException(onibus.getPlaca().toString());
        }
        onibusMap.put(onibus.getPlaca(), onibus);
    }

    public Map<String, Onibus> listarOnibus() {
        return onibusMap;
    }

    public Onibus getOnibusPorPlaca(String placa) throws NotFoundException {
        Onibus onibus = onibusMap.get(placa);
        if (onibus == null) {
            throw new NotFoundException(placa);
        }
        return onibus;
    }

    public void atualizarOnibus(String placa, int lugares, Onibus.classeOnibus classe, float custo) throws NotFoundException {
        Onibus onibus = onibusMap.get(placa);
        if (onibus == null) {
            throw new NotFoundException(placa);
        }
        onibus.setLugares(lugares);
        onibus.setClasse(classe);
        onibus.setCusto(custo);
    }

    public void removerOnibus(String placa) {
        if (!onibusMap.containsKey(placa)) {
            throw new RuntimeException("Ônibus com a placa " + placa + " não encontrado.");
        }
        onibusMap.remove(placa);
    }
}
