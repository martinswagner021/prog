package trabalhopas.model;

public class Data {
    private int dia, mes, ano, hora, minuto;

    public Data(int dia, int mes, int ano, int hora, int minuto){
        this.setAno(ano);
        this.setDia(dia);
        this.setHora(hora);
        this.setMes(mes);
        this.setMinuto(minuto);
    }

    public int getAno() {
        return ano;
    }
    public int getDia() {
        return dia;
    }
    public int getHora() {
        return hora;
    }
    public int getMes() {
        return mes;
    }
    public int getMinuto() {
        return minuto;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
    public void setDia(int dia) {
        this.dia = dia;
    }
    public void setHora(int hora) {
        this.hora = hora;
    }
    public void setMes(int mes) {
        this.mes = mes;
    }
    public void setMinuto(int minuto) {
        this.minuto = minuto;
    }
}
