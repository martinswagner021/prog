package trabalhopas.model;

public class Trecho {
    private String inicio;
    private String fim;
    private Duracao duracao;
    private float custo;

    public Trecho(String inicio, String fim, Duracao duracao){
        this.setInicio(inicio);
        this.setFim(fim);
        this.setDuracao(duracao);
    }

    public String getInicio() {
        return inicio;
    }
    public String getFim() {
        return fim;
    }
    public Duracao getDuracao() {
        return duracao;
    }
    public float getCusto() {
        return custo;
    }

    public void setInicio(String inicio) {
        this.inicio = inicio;
    }
    public void setFim(String fim) {
        this.fim = fim;
    }
    public void setDuracao(Duracao duracao) {
        this.duracao = duracao;
    }
    public void setCusto(float custo) {
        this.custo = custo;
    }
    
}
