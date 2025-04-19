/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public class Vendedor extends Pessoa{
    private final String matricula;
    private float salario;
    private static float salarioBase = 2000f;

    public Vendedor(String matricula, String cpf, String nome) {
        super(cpf, nome);
        this.matricula = matricula;
        this.salario = salarioBase;
    }

    public String getMatricula() {
        return matricula;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public static float getSalarioBase() {
        return salarioBase;
    }

    public static void setSalarioBase(float salarioBase) {
        Vendedor.salarioBase = salarioBase;
    }   
}
