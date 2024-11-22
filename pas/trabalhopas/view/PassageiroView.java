package trabalhopas.view;

import trabalhopas.controller.PassageiroController;
import trabalhopas.model.Passageiro;
import trabalhopas.model.exceptions.AlreadyExistsException;
import trabalhopas.model.exceptions.NotFoundException;

import java.util.Scanner;

public class PassageiroView {
    private PassageiroController passageiroController;

    public void menu(Scanner scanner, PassageiroController passageiroController) {
        this.passageiroController = passageiroController;
        while (true) {
            System.out.println("\n=== Gerenciar Passageiros ===");
            System.out.println("1. Adicionar Passageiro");
            System.out.println("2. Listar Passageiros");
            System.out.println("3. Atualizar Passageiro");
            System.out.println("4. Remover Passageiro");
            System.out.println("5. Voltar");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    adicionarPassageiro(scanner);
                    break;
                case 2:
                    listarPassageiros();
                    break;
                case 3:
                    atualizarPassageiro(scanner);
                    break;
                case 4:
                    removerPassageiro(scanner);
                    break;
                case 5:
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    private void adicionarPassageiro(Scanner scanner) {
        System.out.print("Informe o CPF: ");
        String cpf = scanner.nextLine();
        System.out.print("Informe o nome: ");
        String nome = scanner.nextLine();
        System.out.print("Informe o e-mail: ");
        String email = scanner.nextLine();

        Passageiro passageiro = new Passageiro(cpf, nome, email);
        try {
            passageiroController.adicionarPassageiro(passageiro);
            System.out.println("Passageiro adicionado com sucesso!");
        } catch (AlreadyExistsException e) {
            System.out.println("CPF " + e.getMessage());
        }
    }

    private void listarPassageiros() {
        if (passageiroController.listarPassageiros().isEmpty()) {
            System.out.println("Nenhum passageiro cadastrado.");
        } else {
            System.out.println("\n=== Lista de Passageiros ===");
            for (Passageiro passageiro : passageiroController.listarPassageiros().values()) {
                System.out.println("- CPF: " + passageiro.getCpf() +
                        ", Nome: " + passageiro.getNome() +
                        ", E-mail: " + passageiro.getEmail());
            }
        }
    }

    private void atualizarPassageiro(Scanner scanner) {
        System.out.print("Informe o CPF do passageiro que deseja atualizar: ");
        String cpf = scanner.nextLine();
        System.out.print("Informe o novo nome: ");
        String nome = scanner.nextLine();
        System.out.print("Informe o novo e-mail: ");
        String email = scanner.nextLine();

        try {
            passageiroController.atualizarPassageiro(cpf, nome, email);
            System.out.println("Passageiro atualizado com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("CPF " + e.getMessage());
        }
    }

    private void removerPassageiro(Scanner scanner) {
        System.out.print("Informe o CPF do passageiro que deseja remover: ");
        String cpf = scanner.nextLine();
        try {
            passageiroController.removerPassageiro(cpf);
            System.out.println("Passageiro removido com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("CPF " + e.getMessage());
        }
    }
}
