package trabalhopas.controller;

import trabalhopas.model.Onibus;

public class OnibusController {
    private Onibus onibus;

    public OnibusController(String placa, int lugares, Onibus.classeOnibus classe, float custo) {
        this.onibus = new Onibus(placa, lugares, classe, custo);
    }

    public void exibirInformacoes() {
        System.out.println("Informações do Ônibus:");
        System.out.println("Placa: " + onibus.getPlaca());
        System.out.println("Lugares: " + onibus.getLugares());
        System.out.println("Classe: " + onibus.getClasse());
        System.out.printf("Custo: R$ %.2f\n", onibus.getCusto());
    }

    public void atualizarClasse(Onibus.classeOnibus novaClasse) {
        onibus.setClasse(novaClasse);
        System.out.println("Classe do ônibus atualizada para: " + novaClasse);
    }

    public void atualizarLugares(int novosLugares) {
        onibus.setLugares(novosLugares);
        System.out.println("Número de lugares atualizado para: " + novosLugares);
    }

    public void atualizarCusto(float novoCusto) {
        onibus.setCusto(novoCusto);
        System.out.printf("Custo do ônibus atualizado para: R$ %.2f\n", novoCusto);
    }

    public Onibus getOnibus() {
        return onibus;
    }
}
