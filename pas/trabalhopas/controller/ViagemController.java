package trabalhopas.controller;

import trabalhopas.model.*;
import trabalhopas.model.exceptions.PassageiroNotFoundException;

import java.util.HashMap;
import java.util.Set;

public class ViagemController{
    private Viagem viagem;

    public ViagemController(Onibus onibus, Motorista motorista, Rota rota, Data dataInicio) {
        this.viagem = new Viagem(onibus, motorista, rota, dataInicio);
    }

    public Passageiro findPassageiro(String cpf) throws PassageiroNotFoundException{
        for(Passageiro p : this.viagem.getLugares_ocupados().keySet()){
            if(p.getCpf().equals(cpf)) return p;
        }
        throw new PassageiroNotFoundException(cpf);
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

    public void removerPassageiro(String cpfParaRemover) {
        try{
            Passageiro passageiroParaRemover = this.findPassageiro(cpfParaRemover);
            this.viagem.removePassageiro(passageiroParaRemover);
            System.out.println("Passageiro removido com sucesso.");
        }
        catch(PassageiroNotFoundException e){
            System.out.println("Não foi possível remover o passageiro, pois:\n\t" + e.getMessage());
        }
    }

    public void listarPassageiros() {
        Set<Passageiro> passageiros = this.viagem.getLugares_ocupados().keySet();

        if (passageiros.isEmpty()) {
            System.out.println("Não há passageiros na viagem.");
        } else {
            System.out.println("Lista de Passageiros:");
            for (Passageiro passageiro : passageiros) {
                new PassageiroController(passageiro.getCpf(), passageiro.getNome(), passageiro.getEmail()).exibirInformacoes();
            }
        }
    }

    public float calcularCusto() {
        return viagem.getCusto();
    }

    public Viagem getViagem() {
        return viagem;
    }
}
