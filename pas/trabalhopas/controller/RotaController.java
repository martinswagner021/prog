package trabalhopas.controller;

import trabalhopas.model.Rota;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.HashMap;
import java.util.Map;

public class RotaController {
    private Map<Integer, Rota> rotaMap = new HashMap<>();
    private int idCounter = 1;

    public void adicionarRota(Rota rota) {
        rotaMap.put(idCounter++, rota);
    }

    public Map<Integer, Rota> listarRotas() {
        return rotaMap;
    }

    public Rota getRotaPorId(int id) throws NotFoundException {
        Rota rota = rotaMap.get(id);
        if (rota == null) {
            throw new NotFoundException(Integer.toString(id));
        }
        return rota;
    }

    public void removerRota(int id) throws NotFoundException {
        if (!rotaMap.containsKey(id)) {
            throw new NotFoundException(Integer.toString(id));
        }
        rotaMap.remove(id);
    }
}