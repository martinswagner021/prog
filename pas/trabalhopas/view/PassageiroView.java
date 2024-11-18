package trabalhopas.view;

import java.util.Scanner;

import trabalhopas.controller.PassageiroController;
import trabalhopas.controller.ViagemController;

public class PassageiroView {
    public PassageiroView(ViagemController viagemController, Scanner scanner){
        System.out.println("\n=== Gerenciar Passageiros ===");
        System.out.println("1. Adicionar Passageiro");
        System.out.println("2. Remover Passageiro");
        System.out.println("3. Listar Passageiros");
        System.out.print("Escolha uma opção: ");
        int opcao = scanner.nextInt();
        scanner.nextLine();

        if (opcao == 1) {
            System.out.print("Informe o número do assento: ");
            int numeroAssento = scanner.nextInt();
            scanner.nextLine();
            System.out.print("Informe o CPF do passageiro: ");
            String cpf = scanner.nextLine();
            System.out.print("Informe o nome do passageiro: ");
            String nome = scanner.nextLine();
            System.out.print("Informe o e-mail do passageiro: ");
            String email = scanner.nextLine();
            PassageiroController passageiroController = new PassageiroController(cpf, nome, email);
            viagemController.adicionarPassageiro(numeroAssento, passageiroController.getPassageiro());
        } else if (opcao == 2) {
            System.out.print("Informe o CPF do passageiro para remover: ");
            String cpfParaRemover = scanner.nextLine();
            viagemController.removerPassageiro(cpfParaRemover);
        } else if (opcao == 3){
            viagemController.listarPassageiros();
        } else{
            System.out.println("Opção inválida.");
        }
    }
}
