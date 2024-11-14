package trabalhopas.view;

import trabalhopas.controller.ViagemController;
import trabalhopas.model.*;

import java.util.Scanner;
import java.util.ArrayList;

public class MainView{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Onibus onibus = new Onibus("ABC-1234", 40, Onibus.classeOnibus.EXECUTIVA, 2000.0f);
        Motorista motorista = new Motorista("12345678900", "João", 40, 200.0f); // Implementar classe Motorista
        ArrayList<Trecho> trechos = new ArrayList<>();
        trechos.add(new Trecho("Cidade A", "Cidade B", new Duracao(2, 30)));
        Rota rota = new Rota("Cidade A", "Cidade B", trechos);
        Data dataInicio = new Data(1, 1, 2023, 8, 0);

        ViagemController viagemController = new ViagemController(onibus, motorista, rota, dataInicio);

        // Menu de opções
        while (true) {
            System.out.println("\n=== Menu de Viagem ===");
            System.out.println("1. Adicionar Passageiro");
            System.out.println("2. Remover Passageiro");
            System.out.println("3. Calcular Custo da Viagem");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    System.out.print("Informe o número do assento: ");
                    int numeroAssento = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Informe o CPF do passageiro: ");
                    String cpf = scanner.nextLine();
                    System.out.print("Informe o nome do passageiro: ");
                    String nome = scanner.nextLine();
                    System.out.print("Informe a idade do passageiro: ");
                    int idade = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Informe o email do passageiro: ");
                    String email = scanner.nextLine();
                    Passageiro passageiro = new Passageiro(cpf, nome, idade, email);
                    viagemController.adicionarPassageiro(numeroAssento, passageiro);
                    break;

                case 2:
                    System.out.printf("Custo total da viagem: R$ %.2f\n", viagemController.calcularCusto());
                    break;

                case 3:
                    System.out.println("Saindo do sistema...");
                    scanner.close();
                    return;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
                    break;
            }
        }
    }
}
