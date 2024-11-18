package trabalhopas.controller;

import trabalhopas.model.Rota;
import trabalhopas.model.Trecho;

import java.util.ArrayList;

public class RotaController {
    private Rota rota;

    public RotaController(String origem, String destino, ArrayList<Trecho> trechos) {
        this.rota = new Rota(origem, destino, trechos);
    }

    public void exibirInformacoes() {
        System.out.println("Informações da Rota:");
        System.out.println("Origem: " + rota.getOrigem());
        System.out.println("Destino: " + rota.getDestino());
        System.out.println("Trechos:");
        for (Trecho trecho : rota.getTrechos()) {
            System.out.println("- De " + trecho.getInicio() + " até " + trecho.getFim());
            System.out.printf("  Duração: %.2f horas\n", trecho.getDuracao().getTempoHoras());
            System.out.printf("  Custo: R$ %.2f\n", trecho.getCusto());
        }
        System.out.printf("Custo Total da Rota: R$ %.2f\n", rota.getCustoTotal());
        System.out.printf("Duração Total da Rota: %.2f horas\n", rota.getDuracaoTotalHoras());
    }

    public void adicionarTrecho(Trecho trecho) {
        rota.getTrechos().add(trecho);
        System.out.println("Trecho adicionado: " + trecho.getInicio() + " até " + trecho.getFim());
    }

    public float calcularCustoTotal() {
        return rota.getCustoTotal();
    }

    public float calcularDuracaoTotalHoras() {
        return rota.getDuracaoTotalHoras();
    }

    public Rota getRota() {
        return rota;
    }
}
