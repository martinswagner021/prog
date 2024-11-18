package trabalhopas.controller;

import trabalhopas.model.Passageiro;

public class PassageiroController {
    private Passageiro passageiro;

    public PassageiroController(String cpf, String nome, String email) {
        this.passageiro = new Passageiro(cpf, nome, email);
    }

    public void exibirInformacoes() {
        System.out.println("Informações do Passageiro:");
        System.out.println("Nome: " + passageiro.getNome());
        System.out.println("CPF: " + passageiro.getCpf());
        System.out.println("Email: " + passageiro.getEmail());
    }

    public void atualizarEmail(String novoEmail) {
        passageiro.setEmail(novoEmail);
        System.out.println("E-mail atualizado para: " + novoEmail);
    }

    public Passageiro getPassageiro() {
        return passageiro;
    }
}
