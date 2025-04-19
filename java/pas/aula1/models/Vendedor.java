package models;

public class Vendedor extends Pessoa{
    private final String matricula;
    private float salario;
    private static float SALARIO_BASE = 1400.00f;

    public Vendedor(String cpf, String nome, String matricula, float salario){
        super(cpf, nome);
        this.matricula = matricula;
        setSalario(salario);
    }
    public Vendedor(String cpf, String nome, String matricula){
        super(cpf, nome);
        this.matricula = matricula;
        setSalario(SALARIO_BASE);
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }
    public String getMatricula() {
        return matricula;
    }
    public float getSalario() {
        return salario;
    }
}
