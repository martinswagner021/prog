package trabalhopas.model;

public class Duracao {
    private float tempo;

    public Duracao(float minutos){
        this.setTempoMinutos(minutos);
    }
    public Duracao(float horas, float minutos){
        this.setTempoMinutos((horas*60)+minutos);
    }

    public float getTempoHoras() {
        return tempo/60;
    }
    public float getTempoMinutos() {
        return tempo;
    }

    public void setTempoHoras(float tempo) {
        this.tempo = tempo*60;
    }
    public void setTempoMinutos(float tempo) {
        this.tempo = tempo;
    }
}
