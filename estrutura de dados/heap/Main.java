import java.util.Scanner;

public class Main{
    public static void main(String[] argv){
            Scanner input = new Scanner(System.in);

            System.out.print("Digite o tamanho do vetor heap alocado: ");
            int heap_size = input.nextInt();
            int opt;

            Heap h = new Heap(heap_size);

            while(true){
                print_menu();
                opt = input.nextInt();
                switch(opt){
                    case 1:{
                        System.out.print("Digite o valor do elemento: ");
                        int obj = input.nextInt();
                        h.inserir_elem(obj);
                        break;
                    }
                    case 2:{
                        System.out.println(h.remover_elem());
                        break;
                    }
                    case 3:{
                        h.print_heap();
                        break;
                    }
                    case 4:{
                        System.exit(0);
                        input.close();
                        break;
                    }
                }
            }
            
        }

        public static void print_menu(){
            System.out.println("1. Inserir um elemento x na heap.");
            System.out.println("2. Remover um elemento - o elemento removido deve ser impresso na tela.");
            System.out.println("3. Imprimir a heap.");
            System.out.println("4. Sair");
        }
}