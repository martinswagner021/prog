package trabalhopas.model;

public class Motorista extends Pessoa {
    private int idade;
    private float valorDiaria;

    public Motorista(String cpf, String nome, int idade, float valorDiaria){
        super(cpf, nome, idade);
        this.setIdade(idade);
        this.setvalorDiaria(valorDiaria);
    }

    public float getvalorDiaria() {
        return valorDiaria;
    }
    public int getIdade() {
        return idade;
    }

    public void setvalorDiaria(float valorDiaria) {
        this.valorDiaria = valorDiaria;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
}
