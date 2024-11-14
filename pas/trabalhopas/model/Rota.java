package trabalhopas.model;

import java.util.ArrayList;

public class Rota {
    private String origem;
    private String destino;
    private final ArrayList<Trecho> trechos;

    public Rota(String origem, String destino, ArrayList<Trecho> trechos){
        this.setDestino(destino);
        this.setOrigem(origem);
        this.trechos = trechos;
    }

    public String getDestino() {
        return destino;
    }
    public String getOrigem() {
        return origem;
    }
    public ArrayList<Trecho> getTrechos() {
        return trechos;
    }
    public float getCustoTotal(){
        float soma = 0;
        for(Trecho t: this.trechos){
            soma += t.getCusto();
        }
        return soma;
    }
    public float getDuracaoTotalHoras(){
        float soma = 0;
        for(Trecho t: this.trechos){
            soma += t.getDuracao().getTempoHoras();
        }
        return soma;
    }
    public float getDuracaoTotalMinutos(){
        float soma = 0;
        for(Trecho t: this.trechos){
            soma += t.getDuracao().getTempoMinutos();
        }
        return soma;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }
    public void setOrigem(String origem) {
        this.origem = origem;
    }
}
