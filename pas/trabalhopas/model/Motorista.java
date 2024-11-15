package trabalhopas.model;

public class Motorista extends Pessoa {
    private int idade;
    private float valorDiaria;

    public Motorista(String cpf, String nome, int idade, float valorDiaria){
        super(cpf, nome);
        this.setIdade(idade);
        this.setValorDiaria(valorDiaria);
    }

    public float getValorDiaria() {
        return valorDiaria;
    }
    public int getIdade() {
        return idade;
    }

    public void setValorDiaria(float valorDiaria) {
        this.valorDiaria = valorDiaria;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
}
