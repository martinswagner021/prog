package trabalhopas.view;

import trabalhopas.controller.*;
import java.util.Scanner;

public class MainMenuView {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        OnibusController onibusController = new OnibusController();
        MotoristaController motoristaController = new MotoristaController();
        PassageiroController passageiroController = new PassageiroController();
        TrechoController trechoController = new TrechoController();
        RotaController rotaController = new RotaController();
        ViagemController viagemController = new ViagemController();

        OnibusView onibusView = new OnibusView();
        MotoristaView motoristaView = new MotoristaView();
        PassageiroView passageiroView = new PassageiroView();
        TrechoView trechoView = new TrechoView();
        RotaView rotaView = new RotaView();
        ViagemView viagemView = new ViagemView(onibusController, motoristaController, rotaController, passageiroController, viagemController);

        while (true) {
            System.out.println("\n=== Menu Principal ===");
            System.out.println("1. Gerenciar Ônibus");
            System.out.println("2. Gerenciar Motoristas");
            System.out.println("3. Gerenciar Passageiros");
            System.out.println("4. Gerenciar Trechos");
            System.out.println("5. Gerenciar Rotas");
            System.out.println("6. Gerenciar Viagens");
            System.out.println("7. Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    onibusView.menu(scanner, onibusController);
                    break;
                case 2:
                    motoristaView.menu(scanner, motoristaController);
                    break;
                case 3:
                    passageiroView.menu(scanner, passageiroController);
                    break;
                case 4:
                    trechoView.menu(scanner, trechoController);
                    break;
                case 5:
                    rotaView.menu(scanner, rotaController, trechoController, trechoView);
                    break;
                case 6:
                    viagemView.menu(scanner);
                    break;
                case 7:
                    scanner.close();
                    return;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }
}
