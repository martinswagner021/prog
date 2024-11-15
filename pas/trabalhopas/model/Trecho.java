package trabalhopas.model;

public class Trecho {
    private String inicio;
    private String fim;
    private Duracao duracao;
    private float custo;

    public Trecho(String inicio, String fim, Duracao duracao, float custo){
        this.setInicio(inicio);
        this.setFim(fim);
        this.setDuracao(duracao);
        this.setCusto(custo);
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
