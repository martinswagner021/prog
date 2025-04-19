/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pas.lojamaterialesportivo.model;

/**
 *
 * @author edumo
 */
public class Raquete extends Produto{
    private final String material;

    public Raquete(String codigo, Tamanho tam,String material) {
        super(codigo, tam);
        this.material = material;
    }

    public String getMaterial() {
        return material;
    }
    
}
