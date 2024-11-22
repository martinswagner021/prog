package trabalhopas.view;

import trabalhopas.controller.*;
import trabalhopas.model.*;
import trabalhopas.model.exceptions.*;

import java.util.Map;
import java.util.Scanner;

public class ViagemView {
    private ViagemController viagemController;
    private PassageiroController passageiroController;
    private OnibusController onibusController;
    private MotoristaController motoristaController;
    private RotaController rotaController;

    public ViagemView(OnibusController onibusController, MotoristaController motoristaController, 
                      RotaController rotaController, PassageiroController passageiroController, 
                      ViagemController viagemController) {
        this.onibusController = onibusController;
        this.motoristaController = motoristaController;
        this.rotaController = rotaController;
        this.passageiroController = passageiroController;
        this.viagemController = viagemController;
    }

    public void menu(Scanner scanner) {
        while (true) {
            System.out.println("\n=== Gerenciar Viagens ===");
            System.out.println("1. Adicionar Viagem");
            System.out.println("2. Listar Viagens");
            System.out.println("3. Remover Viagem");
            System.out.println("4. Gerenciar Passageiros de uma Viagem");
            System.out.println("5. Voltar");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    adicionarViagem(scanner);
                    break;
                case 2:
                    listarViagens();
                    break;
                case 3:
                    removerViagem(scanner);
                    break;
                case 4:
                    gerenciarPassageiros(scanner);
                    break;
                case 5:
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    private void adicionarViagem(Scanner scanner) {
        // escolher onibus
        System.out.println("Escolha o ônibus:");
        onibusController.listarOnibus().forEach((placa, onibus) -> 
                System.out.println("- Placa: " + placa + ", Classe: " + onibus.getClasse() + ", Lugares: " + onibus.getLugares()));
        System.out.print("Informe a placa do ônibus: ");
        String placa = scanner.nextLine();
        Onibus onibus = null;
        
        try {
            onibus = onibusController.getOnibusPorPlaca(placa);
        } catch (NotFoundException e) {
            System.out.println("Onibus " + e.getMessage());
            return;
        }

        // escolher motorista
        System.out.println("Escolha o motorista:");
        motoristaController.listarMotoristas().forEach((cpf, motorista) -> 
                System.out.println("- CPF: " + cpf + ", Nome: " + motorista.getNome()));
        System.out.print("Informe o CPF do motorista: ");
        String cpfMotorista = scanner.nextLine();
        Motorista motorista = null;

        try {
            motorista = motoristaController.getMotoristaPorCpf(cpfMotorista);
        } catch (NotFoundException e) {
            System.out.println("Motorista " + e.getMessage());
            return;
        }

        // escolher rota
        System.out.println("Escolha a rota:");
        rotaController.listarRotas().forEach((id, rota) -> 
                System.out.println("- ID: " + id + ", Origem: " + rota.getOrigem() + ", Destino: " + rota.getDestino()));
        System.out.print("Informe o ID da rota: ");
        int idRota = scanner.nextInt();
        scanner.nextLine();
        Rota rota = null;

        try {
            rota = rotaController.getRotaPorId(idRota);
        } catch (NotFoundException e) {
            System.out.println("Rota " + e.getMessage());
            return;
        }

        // inserir data
        System.out.print("Informe a data da viagem (DD/MM/AAAA HH:MM): ");
        String dataString = scanner.nextLine();
        String[] dataSplit = dataString.split("[ /:]");
        Data data = new Data(
                Integer.parseInt(dataSplit[0]), Integer.parseInt(dataSplit[1]), Integer.parseInt(dataSplit[2]),
                Integer.parseInt(dataSplit[3]), Integer.parseInt(dataSplit[4]));

        // criar viagem
        Viagem viagem = new Viagem(onibus, motorista, rota, data);
        viagemController.adicionarViagem(viagem);
        System.out.println("Viagem adicionada com sucesso!");
    }


    private void listarViagens() {
        if (viagemController.listarViagens().isEmpty()) {
            System.out.println("Nenhuma viagem cadastrada.");
        } else {
            System.out.println("\n=== Lista de Viagens ===");
            viagemController.listarViagens().forEach((id, viagem) -> {
                System.out.println("- ID: " + id);
                System.out.println("  Ônibus: " + viagem.getOnibus().getPlaca());
                System.out.println("  Motorista: " + viagem.getMotorista().getNome());
                System.out.println("  Rota: " + viagem.getRota().getOrigem() + " -> " + viagem.getRota().getDestino());
                System.out.printf("  Custo Total: R$ %.2f\n", viagem.getCusto());
            });
        }
    }

    private void removerViagem(Scanner scanner) {
        System.out.println("\n=== Remover Viagem ===");
        listarViagens();
        System.out.print("Informe o ID da viagem que deseja remover: ");
        int id = scanner.nextInt();
        scanner.nextLine();

        try {
            viagemController.removerViagem(id);
            System.out.println("Viagem removida com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("Viagem " + e.getMessage());
        }
    }

    private void gerenciarPassageiros(Scanner scanner) {
        System.out.println("\n=== Gerenciar Passageiros ===");
        listarViagens();
        System.out.print("Informe o ID da viagem: ");
        int viagemId = scanner.nextInt();
        scanner.nextLine();

        System.out.println("\n=== Passageiros ===");
        System.out.println("1. Adicionar Passageiro");
        System.out.println("2. Remover Passageiro");
        System.out.println("3. Listar Passageiros");
        System.out.print("Escolha uma opção: ");
        int opcao = scanner.nextInt();
        scanner.nextLine();

        switch (opcao) {
            case 1:
                adicionarPassageiro(scanner, viagemId);
                break;
            case 2:
                removerPassageiro(scanner, viagemId);
                break;
            case 3:
                listarPassageiros(viagemId);
                break;
            default:
                System.out.println("Opção inválida. Tente novamente.");
        }
    }

    private void adicionarPassageiro(Scanner scanner, int viagemId) {
        System.out.print("Informe o número do lugar: ");
        int lugar = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Informe o CPF do passageiro: ");
        String cpf = scanner.nextLine();

        Passageiro passageiro = passageiroController.listarPassageiros().get(cpf);
        if (passageiro == null) {
            System.out.println("Passageiro não encontrado.");
            return;
        }

        try {
            viagemController.adicionarPassageiro(viagemId, lugar, passageiro);
            System.out.println("Passageiro adicionado com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("Viagem id " + e.getMessage());
        } catch (AlreadyExistsException e){
            System.out.println("Lugar " + e.getMessage());
        }
    }

    private void removerPassageiro(Scanner scanner, int viagemId) {
        System.out.print("Informe o número do lugar para remover o passageiro: ");
        int lugar = scanner.nextInt();
        scanner.nextLine();

        try {
            viagemController.removerPassageiro(viagemId, lugar);
            System.out.println("Passageiro removido com sucesso!");
        } catch (NotFoundException e) {
            System.out.println("Viagem id " + e.getMessage());
        } catch (LugarVazioException e){
            System.out.println(e.getMessage());
        }
    }

    private void listarPassageiros(int viagemId) {
        try {
            Map<Integer, Passageiro> passageiros = viagemController.listarPassageiros(viagemId);
            if (passageiros.isEmpty()) {
                System.out.println("Nenhum passageiro nesta viagem.");
            } else {
                System.out.println("\n=== Passageiros ===");
                passageiros.forEach((lugar, passageiro) -> 
                    System.out.println("- Lugar: " + lugar + ", Nome: " + passageiro.getNome() + ", CPF: " + passageiro.getCpf()));
            }
        } catch (NotFoundException e) {
            System.out.println("Viagem id " + e.getMessage());
        }
    }
}
