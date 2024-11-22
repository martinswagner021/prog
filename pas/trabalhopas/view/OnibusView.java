package trabalhopas.view;

import trabalhopas.controller.OnibusController;
import trabalhopas.model.Onibus;
import trabalhopas.model.exceptions.AlreadyExistsException;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.Scanner;

public class OnibusView {
    private OnibusController onibusController;

    public void menu(Scanner scanner, OnibusController onibusController) {
        this.onibusController = onibusController;
        while (true) {
            System.out.println("\n=== Gerenciar Ônibus ===");
            System.out.println("1. Adicionar Ônibus");
            System.out.println("2. Listar Ônibus");
            System.out.println("3. Atualizar Ônibus");
            System.out.println("4. Remover Ônibus");
            System.out.println("5. Voltar");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    adicionarOnibus(scanner);
                    break;
                case 2:
                    listarOnibus();
                    break;
                case 3:
                    atualizarOnibus(scanner);
                    break;
                case 4:
                    removerOnibus(scanner);
                    break;
                case 5:
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    private void adicionarOnibus(Scanner scanner) {
        System.out.print("Informe a placa: ");
        String placa = scanner.nextLine();
        System.out.print("Informe o número de lugares: ");
        int lugares = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Informe a classe (ECONOMICA, EXECUTIVA, LUXO): ");
        String classe = scanner.nextLine();
        System.out.print("Informe o custo: ");
        float custo = scanner.nextFloat();
        scanner.nextLine();

        Onibus novoOnibus = new Onibus(placa, lugares, Onibus.classeOnibus.valueOf(classe.toUpperCase()), custo);
        try {
            onibusController.adicionarOnibus(novoOnibus);
            System.out.println("Ônibus adicionado com sucesso!");
        } catch (AlreadyExistsException e) {
            System.out.println("Ônibus com placa: " + e.getMessage());
        }
    }

    private void listarOnibus() {
        if (onibusController.listarOnibus().isEmpty()) {
            System.out.println("Nenhum ônibus cadastrado.");
        } else {
            System.out.println("\n=== Lista de Ônibus ===");
            for (Onibus onibus : onibusController.listarOnibus().values()) {
                System.out.println("- Placa: " + onibus.getPlaca() +
                        ", Lugares: " + onibus.getLugares() +
                        ", Classe: " + onibus.getClasse() +
                        ", Custo: R$ " + onibus.getCusto());
            }
        }
    }

    private void atualizarOnibus(Scanner scanner) {
        System.out.print("Informe a placa do ônibus que deseja atualizar: ");
        String placa = scanner.nextLine();
        System.out.print("Informe o novo número de lugares: ");
        int lugares = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Informe a nova classe (ECONOMICA, EXECUTIVA, LUXO): ");
        String classe = scanner.nextLine();
        System.out.print("Informe o novo custo: ");
        float custo = scanner.nextFloat();
        scanner.nextLine();

        try {
            onibusController.atualizarOnibus(placa, lugares, Onibus.classeOnibus.valueOf(classe.toUpperCase()), custo);
            System.out.println("Ônibus atualizado com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("Ônibus com placa: " + e.getMessage());
        }
    }

    private void removerOnibus(Scanner scanner) {
        System.out.print("Informe a placa do ônibus que deseja remover: ");
        String placa = scanner.nextLine();
        try {
            onibusController.removerOnibus(placa);
            System.out.println("Ônibus removido com sucesso!");
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }
}
