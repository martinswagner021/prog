package trabalhopas.view;

import trabalhopas.controller.MotoristaController;
import trabalhopas.model.Motorista;
import trabalhopas.model.exceptions.AlreadyExistsException;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.Scanner;

public class MotoristaView {
    private MotoristaController motoristaController;

    public void menu(Scanner scanner, MotoristaController motoristaController) {
        this.motoristaController = motoristaController;
        while (true) {
            System.out.println("\n=== Gerenciar Motoristas ===");
            System.out.println("1. Adicionar Motorista");
            System.out.println("2. Listar Motoristas");
            System.out.println("3. Atualizar Motorista");
            System.out.println("4. Remover Motorista");
            System.out.println("5. Voltar");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    adicionarMotorista(scanner);
                    break;
                case 2:
                    listarMotoristas();
                    break;
                case 3:
                    atualizarMotorista(scanner);
                    break;
                case 4:
                    removerMotorista(scanner);
                    break;
                case 5:
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    private void adicionarMotorista(Scanner scanner) {
        System.out.print("Informe o CPF: ");
        String cpf = scanner.nextLine();
        System.out.print("Informe o nome: ");
        String nome = scanner.nextLine();
        System.out.print("Informe a idade: ");
        int idade = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Informe o valor da diária: ");
        float diaria = scanner.nextFloat();
        scanner.nextLine();

        Motorista motorista = new Motorista(cpf, nome, idade, diaria);
        try {
            motoristaController.adicionarMotorista(motorista);
            System.out.println("Motorista adicionado com sucesso!");
        } catch (AlreadyExistsException e) {
            System.out.println("CPF " + e.getMessage());
        }
    }

    private void listarMotoristas() {
        if (motoristaController.listarMotoristas().isEmpty()) {
            System.out.println("Nenhum motorista cadastrado.");
        } else {
            System.out.println("\n=== Lista de Motoristas ===");
            for (Motorista motorista : motoristaController.listarMotoristas().values()) {
                System.out.println("- CPF: " + motorista.getCpf() +
                        ", Nome: " + motorista.getNome() +
                        ", Idade: " + motorista.getIdade() +
                        ", Valor da Diária: R$ " + motorista.getValorDiaria());
            }
        }
    }

    private void atualizarMotorista(Scanner scanner) {
        System.out.print("Informe o CPF do motorista que deseja atualizar: ");
        String cpf = scanner.nextLine();
        System.out.print("Informe o novo nome: ");
        String nome = scanner.nextLine();
        System.out.print("Informe a nova idade: ");
        int idade = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Informe o novo valor da diária: ");
        float diaria = scanner.nextFloat();
        scanner.nextLine();

        try {
            motoristaController.atualizarMotorista(cpf, nome, idade, diaria);
            System.out.println("Motorista atualizado com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("CPF " + e.getMessage());
        }
    }

    private void removerMotorista(Scanner scanner) {
        System.out.print("Informe o CPF do motorista que deseja remover: ");
        String cpf = scanner.nextLine();
        try {
            motoristaController.removerMotorista(cpf);
            System.out.println("Motorista removido com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("CPF " + e.getMessage());
        }
    }
}
