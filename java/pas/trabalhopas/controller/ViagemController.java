package trabalhopas.controller;

import trabalhopas.model.Viagem;
import trabalhopas.model.exceptions.NotFoundException;
import trabalhopas.model.exceptions.AlreadyExistsException;
import trabalhopas.model.exceptions.LugarVazioException;
import trabalhopas.model.Passageiro;

import java.util.HashMap;
import java.util.Map;

public class ViagemController {
    private Map<Integer, Viagem> viagemMap = new HashMap<>();
    private int idCounter = 1;

    public void adicionarViagem(Viagem viagem) {
        viagemMap.put(idCounter++, viagem);
    }

    public Map<Integer, Viagem> listarViagens() {
        return viagemMap;
    }

    public void removerViagem(int id) throws NotFoundException {
        if (!viagemMap.containsKey(id)) {
            throw new NotFoundException(Integer.toString(id));
        }
        viagemMap.remove(id);
    }

    public void adicionarPassageiro(int viagemId, int lugar, Passageiro passageiro) throws NotFoundException, AlreadyExistsException {
        Viagem viagem = viagemMap.get(viagemId);
        if (viagem == null) {
            throw new NotFoundException(Integer.toString(viagemId));
        }

        if (viagem.getLugares_ocupados().containsKey(lugar)) {
            throw new AlreadyExistsException(Integer.toString(lugar));
        }

        viagem.addPassageiro(lugar, passageiro);
    }

    public void removerPassageiro(int viagemId, int lugar) throws NotFoundException, LugarVazioException {
        Viagem viagem = viagemMap.get(viagemId);
        if (viagem == null) {
            throw new NotFoundException(Integer.toString(viagemId));
        }
        if (!viagem.getLugares_ocupados().containsKey(lugar)) {
            throw new LugarVazioException(lugar);
        }
        viagem.getLugares_ocupados().remove(lugar);
    }

    public Map<Integer, Passageiro> listarPassageiros(int viagemId) throws NotFoundException {
        Viagem viagem = viagemMap.get(viagemId);
        if (viagem == null) {
            throw new NotFoundException(Integer.toString(viagemId));
        }
        return viagem.getLugares_ocupados();
    }
}
