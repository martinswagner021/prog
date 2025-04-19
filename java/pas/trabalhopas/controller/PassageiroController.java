package trabalhopas.controller;

import trabalhopas.model.Passageiro;
import trabalhopas.model.exceptions.AlreadyExistsException;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.HashMap;
import java.util.Map;

public class PassageiroController {
    private Map<String, Passageiro> passageiroMap = new HashMap<>();

    public void adicionarPassageiro(Passageiro passageiro) throws AlreadyExistsException {
        if (passageiroMap.containsKey(passageiro.getCpf())) {
            throw new AlreadyExistsException(passageiro.getCpf());
        }
        passageiroMap.put(passageiro.getCpf(), passageiro);
    }

    public Map<String, Passageiro> listarPassageiros() {
        return passageiroMap;
    }

    public void atualizarPassageiro(String cpf, String nome, String email) throws NotFoundException {
        Passageiro passageiro = passageiroMap.get(cpf);
        if (passageiro == null) {
            throw new NotFoundException(cpf);
        }
        passageiro.setNome(nome);
        passageiro.setEmail(email);
    }

    public void removerPassageiro(String cpf) throws NotFoundException {
        if (!passageiroMap.containsKey(cpf)) {
            throw new NotFoundException(cpf);
        }
        passageiroMap.remove(cpf);
    }
}
