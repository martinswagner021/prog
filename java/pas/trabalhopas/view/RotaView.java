package trabalhopas.view;

import trabalhopas.controller.RotaController;
import trabalhopas.controller.TrechoController;
import trabalhopas.model.Rota;
import trabalhopas.model.Trecho;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.ArrayList;
import java.util.Scanner;

public class RotaView {
    private RotaController rotaController;
    private TrechoController trechoController;
    private TrechoView trechoView;

    public void menu(Scanner scanner, RotaController rotaController, TrechoController trechoController, TrechoView trechoView) {
        this.trechoController = trechoController;
        this.trechoView = trechoView;
        this.rotaController = rotaController;
        while (true) {
            System.out.println("\n=== Gerenciar Rotas ===");
            System.out.println("1. Adicionar Rota");
            System.out.println("2. Listar Rotas");
            System.out.println("3. Remover Rota");
            System.out.println("4. Voltar");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    adicionarRota(scanner);
                    break;
                case 2:
                    listarRotas();
                    break;
                case 3:
                    removerRota(scanner);
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    private void adicionarRota(Scanner scanner) {
        System.out.print("Informe a origem: ");
        String origem = scanner.nextLine();
        System.out.print("Informe o destino: ");
        String destino = scanner.nextLine();

        ArrayList<Trecho> trechos = new ArrayList<>();
        System.out.println("Adicione os trechos para a rota:");
        this.trechoView.listarTrechos();

        System.out.println("Digite o índice dos trechos (finalize com -1): ");
        while (true) {
            int index = scanner.nextInt();
            scanner.nextLine();
            if (index == -1) break;
            try {
                trechos.add(trechoController.listarTrechos().get(index));
            } catch (IndexOutOfBoundsException e) {
                System.out.println("Índice inválido. Tente novamente.");
            }
        }

        try {
            Rota rota = new Rota(origem, destino, trechos);
            rotaController.adicionarRota(rota);
            System.out.println("Rota adicionada com sucesso!");
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }

    private void listarRotas() {
        if (rotaController.listarRotas().isEmpty()) {
            System.out.println("Nenhuma rota cadastrada.");
        } else {
            System.out.println("\n=== Lista de Rotas ===");
            for (Rota rota : rotaController.listarRotas().values()) {
                System.out.println("- Origem: " + rota.getOrigem() +
                        ", Destino: " + rota.getDestino() +
                        ", Trechos: " + rota.getTrechos().size() +
                        ", Custo Total: R$ " + rota.getCustoTotal());
            }
        }
    }

    private void removerRota(Scanner scanner) {
        System.out.println("Informe o índice da rota que deseja remover (veja pela listagem): ");
        listarRotas();
        System.out.print("Índice: ");
        int index = scanner.nextInt();
        scanner.nextLine();

        try {
            rotaController.removerRota(index);
            System.out.println("Rota removida com sucesso!");
        } catch (NotFoundException e) {
            System.out.println(Integer.toString(index));
        }
    }
}
