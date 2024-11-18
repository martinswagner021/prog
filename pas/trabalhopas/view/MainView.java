package trabalhopas.view;

import trabalhopas.controller.*;
import trabalhopas.model.*;

import java.util.ArrayList;
import java.util.Scanner;

public class MainView {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        OnibusController onibusController = new OnibusController("ABC-1234", 40, Onibus.classeOnibus.EXECUTIVA, 2000.0f);
        MotoristaController motoristaController = new MotoristaController("12345678900", "João", 40, 200.0f);
        ArrayList<Trecho> trechos = new ArrayList<>();
        TrechoController trechoController = new TrechoController("Cidade A", "Cidade B", new Duracao(2, 30), 300.0f);
        trechos.add(trechoController.getTrecho());
        RotaController rotaController = new RotaController("Cidade A", "Cidade B", trechos);
        ViagemController viagemController = new ViagemController(onibusController.getOnibus(), motoristaController.getMotorista(), rotaController.getRota(), new Data(1, 1, 2023, 8, 0));

        while (true) {
            System.out.println("\n=== Menu Principal ===");
            System.out.println("1. Gerenciar Ônibus");
            System.out.println("2. Gerenciar Motorista");
            System.out.println("3. Gerenciar Rota");
            System.out.println("4. Gerenciar Trecho");
            System.out.println("5. Gerenciar Passageiros");
            System.out.println("6. Exibir Custo Total da Viagem");
            System.out.println("7. Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    gerenciarOnibus(onibusController, scanner);
                    break;
                case 2:
                    gerenciarMotorista(motoristaController, scanner);
                    break;
                case 3:
                    gerenciarRota(rotaController, scanner);
                    break;
                case 4:
                    gerenciarTrecho(trechoController, rotaController, scanner);
                    break;
                case 5:
                    new PassageiroView(viagemController, scanner);
                    break;
                case 6:
                    System.out.printf("Custo Total da Viagem: R$ %.2f\n", viagemController.calcularCusto());
                    break;
                case 7:
                    System.out.println("Saindo do sistema...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
                    break;
            }
        }
    }

    private static void gerenciarOnibus(OnibusController onibusController, Scanner scanner) {
        System.out.println("\n=== Gerenciar Ônibus ===");
        onibusController.exibirInformacoes();
        System.out.print("Deseja atualizar o custo do ônibus? (s/n): ");
        String resposta = scanner.nextLine();
        if (resposta.equalsIgnoreCase("s")) {
            System.out.print("Informe o novo custo: ");
            float novoCusto = scanner.nextFloat();
            scanner.nextLine();
            onibusController.atualizarCusto(novoCusto);
        }
    }

    private static void gerenciarMotorista(MotoristaController motoristaController, Scanner scanner) {
        System.out.println("\n=== Gerenciar Motorista ===");
        motoristaController.exibirInformacoes();
        System.out.print("Deseja atualizar o valor da diária? (s/n): ");
        String resposta = scanner.nextLine();
        if (resposta.equalsIgnoreCase("s")) {
            System.out.print("Informe o novo valor da diária: ");
            float novoValorDiaria = scanner.nextFloat();
            scanner.nextLine();
            motoristaController.atualizarValorDiaria(novoValorDiaria);
        }
    }

    private static void gerenciarRota(RotaController rotaController, Scanner scanner) {
        System.out.println("\n=== Gerenciar Rota ===");
        rotaController.exibirInformacoes();
    }

    private static void gerenciarTrecho(TrechoController trechoController, RotaController rotaController, Scanner scanner) {
        System.out.println("\n=== Gerenciar Trecho ===");
        trechoController.exibirInformacoes();
        
        System.out.print("Deseja atualizar a duração do trecho? (s/n): ");
        String respostaDuracao = scanner.nextLine();
        if (respostaDuracao.equalsIgnoreCase("s")) {
            System.out.print("Informe a nova duração em horas: ");
            float horas = scanner.nextFloat();
            System.out.print("Informe a nova duração em minutos: ");
            float minutos = scanner.nextFloat();
            scanner.nextLine();
            trechoController.atualizarDuracao(horas, minutos);
        }

        System.out.print("Deseja atualizar o custo do trecho? (s/n): ");
        String respostaCusto = scanner.nextLine();
        if (respostaCusto.equalsIgnoreCase("s")) {
            System.out.print("Informe o novo custo: ");
            float novoCusto = scanner.nextFloat();
            scanner.nextLine();
            trechoController.atualizarCusto(novoCusto);
        }

        rotaController.adicionarTrecho(trechoController.getTrecho());
    }
}
