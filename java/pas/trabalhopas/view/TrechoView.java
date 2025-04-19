package trabalhopas.view;

import trabalhopas.controller.TrechoController;
import trabalhopas.model.Duracao;
import trabalhopas.model.Trecho;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.Scanner;

public class TrechoView {
    private TrechoController trechoController;

    public void menu(Scanner scanner, TrechoController trechoController) {
        this.trechoController = trechoController;
        while (true) {
            System.out.println("\n=== Gerenciar Trechos ===");
            System.out.println("1. Adicionar Trecho");
            System.out.println("2. Listar Trechos");
            System.out.println("3. Remover Trecho");
            System.out.println("4. Voltar");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    adicionarTrecho(scanner);
                    break;
                case 2:
                    listarTrechos();
                    break;
                case 3:
                    removerTrecho(scanner);
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    private void adicionarTrecho(Scanner scanner) {
        System.out.print("Informe o ponto de início: ");
        String inicio = scanner.nextLine();
        System.out.print("Informe o ponto de fim: ");
        String fim = scanner.nextLine();
        System.out.print("Informe a duração em horas: ");
        float duracaoHoras = scanner.nextFloat();
        System.out.print("Informe o custo do trecho: ");
        float custo = scanner.nextFloat();
        scanner.nextLine();

        Trecho trecho = new Trecho(inicio, fim, new Duracao(duracaoHoras, 0), custo);
        trechoController.adicionarTrecho(trecho);
        System.out.println("Trecho adicionado com sucesso!");
    }

    public void listarTrechos() {
        if (trechoController.listarTrechos().isEmpty()) {
            System.out.println("Nenhum trecho cadastrado.");
        } else {
            System.out.println("\n=== Lista de Trechos ===");
            for (Trecho trecho : trechoController.listarTrechos().values()) {
                System.out.println("- Início: " + trecho.getInicio() +
                        ", Fim: " + trecho.getFim() +
                        ", Duração: " + trecho.getDuracao().getTempoHoras() + " horas" +
                        ", Custo: R$ " + trecho.getCusto());
            }
        }
    }

    private void removerTrecho(Scanner scanner) {
        System.out.println("Informe o índice do trecho que deseja remover (veja pela listagem): ");
        listarTrechos();
        System.out.print("Índice: ");
        int index = scanner.nextInt();
        scanner.nextLine();

        try {
            trechoController.removerTrecho(index);
            System.out.println("Trecho removido com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("Índice " + index);
        }
    }
}
