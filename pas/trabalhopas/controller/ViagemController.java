package trabalhopas.controller;

import trabalhopas.model.*;

import java.util.HashMap;

public class ViagemController {
    private Viagem viagem;

    public ViagemController(Onibus onibus, Motorista motorista, Rota rota, Data dataInicio) {
        this.viagem = new Viagem(onibus, motorista, rota, dataInicio);
    }

    public void adicionarPassageiro(int numeroAssento, Passageiro passageiro) {
        HashMap<Passageiro, Integer> lugaresOcupados = viagem.getLugares_ocupados();
        if (lugaresOcupados.containsValue(numeroAssento)) {
            System.out.println("Assento " + numeroAssento + " já está ocupado.");
        } else if (numeroAssento > viagem.getOnibus().getLugares() || numeroAssento < 1) {
            System.out.println("Número de assento inválido.");
        } else {
            lugaresOcupados.put(passageiro, numeroAssento);
            System.out.println("Passageiro adicionado ao assento " + numeroAssento);
        }
    }

    public void removerPassageiro(Passageiro passageiro) {
        HashMap<Passageiro, Integer> lugaresOcupados = viagem.getLugares_ocupados();
        if (lugaresOcupados.remove(passageiro) != null) {
            System.out.println("Passageiro " + passageiro.getNome() + " removido.");
        } else {
            System.out.println("Passageiro não encontrado.");
        }
    }

    public float calcularCusto() {
        return viagem.getCusto();
    }

    public Viagem getViagem() {
        return viagem;
    }
}
