import models.*;

public class Main{
    public static void main(String[] args){
        Vendedor test = new Vendedor("17902379719", "Wagner", "123");
        test.setEndereco("rua a");
        System.out.println(test.getCpf() + " : " + test.getEndereco() + ", " + test.getSalario());

    }
}