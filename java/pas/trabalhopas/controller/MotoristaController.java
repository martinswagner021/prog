package trabalhopas.controller;

import trabalhopas.model.Motorista;
import trabalhopas.model.exceptions.AlreadyExistsException;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.HashMap;
import java.util.Map;

public class MotoristaController {
    private Map<String, Motorista> motoristaMap = new HashMap<>();

    public void adicionarMotorista(Motorista motorista) throws AlreadyExistsException {
        if (motoristaMap.containsKey(motorista.getCpf())) {
            throw new AlreadyExistsException(motorista.getCpf());
        }
        motoristaMap.put(motorista.getCpf(), motorista);
    }

    public Map<String, Motorista> listarMotoristas() {
        return motoristaMap;
    }

    public Motorista getMotoristaPorCpf(String cpf) throws NotFoundException {
        Motorista motorista = motoristaMap.get(cpf);
        if (motorista == null) {
            throw new NotFoundException(cpf);
        }
        return motorista;
    }

    public void atualizarMotorista(String cpf, String nome, int idade, float valorDiaria) throws NotFoundException {
        Motorista motorista = motoristaMap.get(cpf);
        if (motorista == null) {
            throw new NotFoundException(cpf);
        }
        motorista.setNome(nome);
        motorista.setIdade(idade);
        motorista.setValorDiaria(valorDiaria);
    }

    public void removerMotorista(String cpf) throws NotFoundException {
        if (!motoristaMap.containsKey(cpf)) {
            throw new NotFoundException(cpf);
        }
        motoristaMap.remove(cpf);
    }
}
