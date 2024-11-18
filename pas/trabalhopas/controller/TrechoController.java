package trabalhopas.controller;

import trabalhopas.model.Trecho;
import trabalhopas.model.Duracao;

public class TrechoController {
    private Trecho trecho;

    public TrechoController(String inicio, String fim, Duracao duracao, float custo) {
        this.trecho = new Trecho(inicio, fim, duracao, custo);
    }

    public void exibirInformacoes() {
        System.out.println("Informações do Trecho:");
        System.out.println("Início: " + trecho.getInicio());
        System.out.println("Fim: " + trecho.getFim());
        System.out.printf("Duração: %.2f horas\n", trecho.getDuracao().getTempoHoras());
        System.out.printf("Custo: R$ %.2f\n", trecho.getCusto());
    }

    public void atualizarDuracao(float horas, float minutos) {
        Duracao novaDuracao = new Duracao(horas, minutos);
        trecho.setDuracao(novaDuracao);
        System.out.printf("Duração do trecho atualizada para: %.2f horas\n", novaDuracao.getTempoHoras());
    }

    public void atualizarCusto(float novoCusto) {
        trecho.setCusto(novoCusto);
        System.out.printf("Custo do trecho atualizado para: R$ %.2f\n", novoCusto);
    }

    public Trecho getTrecho() {
        return trecho;
    }
}
