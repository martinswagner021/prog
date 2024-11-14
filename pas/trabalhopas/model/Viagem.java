package trabalhopas.model;

import java.util.HashMap;

public class Viagem {
    private Onibus onibus;
    private Motorista motorista;
    private Rota rota;
    private Data data_inicio;
    private HashMap<Passageiro, Integer> lugares_ocupados = new HashMap<>();
    
    public Viagem(Onibus onibus, Motorista motorista, Rota rota, Data data_inicio, HashMap<Passageiro, Integer> lugares_ocupados){
        this.setData_inicio(data_inicio);
        this.setMotorista(motorista);
        this.setOnibus(onibus);
        this.setRota(rota);
        this.lugares_ocupados.putAll(lugares_ocupados);
    }
    public Viagem(Onibus onibus, Motorista motorista, Rota rota, Data data_inicio){
        this.setData_inicio(data_inicio);
        this.setMotorista(motorista);
        this.setOnibus(onibus);
        this.setRota(rota);
    }

    public float getCusto(){
        return ((this.rota.getDuracaoTotalHoras()/24)*this.motorista.getvalorDiaria()) + this.onibus.getCusto() + this.rota.getCustoTotal();
    }
    public Motorista getMotorista() {
        return motorista;
    }
    public Onibus getOnibus() {
        return onibus;
    }
    public Rota getRota() {
        return rota;
    }
    public Data getData_inicio() {
        return data_inicio;
    }
    public HashMap<Passageiro, Integer> getLugares_ocupados() {
        return lugares_ocupados;
    }

    public void setOnibus(Onibus onibus) {
       this.onibus = onibus;
    }
    public void setData_inicio(Data data_inicio) {
        this.data_inicio = data_inicio;
    }
    public void setMotorista(Motorista motorista) {
        this.motorista = motorista;
    }
    public void setRota(Rota rota) {
        this.rota = rota;
    }

    public void addPassageiro(Passageiro passageiro, int lugar){
        this.lugares_ocupados.put(passageiro, lugar);
    }
    public void removePassageiro(Passageiro passageiro){
        this.lugares_ocupados.remove(passageiro);
    }
}
