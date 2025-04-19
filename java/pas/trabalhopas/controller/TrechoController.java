package trabalhopas.controller;

import trabalhopas.model.Trecho;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.HashMap;
import java.util.Map;

public class TrechoController {
    private Map<Integer, Trecho> trechoMap = new HashMap<>();
    private int idCounter = 1;

    public void adicionarTrecho(Trecho trecho) {
        trechoMap.put(idCounter++, trecho);
    }

    public Map<Integer, Trecho> listarTrechos() {
        return trechoMap;
    }

    public void removerTrecho(int id) throws NotFoundException {
        if (!trechoMap.containsKey(id)) {
            throw new NotFoundException(Integer.toString(id));
        }
        trechoMap.remove(id);
    }
}