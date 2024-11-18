package trabalhopas.controller;

import trabalhopas.model.Motorista;

public class MotoristaController {
    private Motorista motorista;

    public MotoristaController(String cpf, String nome, int idade, float valorDiaria) {
        this.motorista = new Motorista(cpf, nome, idade, valorDiaria);
    }

    public void exibirInformacoes() {
        System.out.println("Informações do Motorista:");
        System.out.println("Nome: " + motorista.getNome());
        System.out.println("CPF: " + motorista.getCpf());
        System.out.println("Idade: " + motorista.getIdade());
        System.out.printf("Valor da Diária: R$ %.2f\n", motorista.getValorDiaria());
    }

    public void atualizarValorDiaria(float novoValorDiaria) {
        motorista.setValorDiaria(novoValorDiaria);
        System.out.printf("Valor da diária atualizado para: R$ %.2f\n", novoValorDiaria);
    }

    public Motorista getMotorista() {
        return motorista;
    }
}
