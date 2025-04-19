interface Bem{
    Proprietario dono;
    public double custo;
}

abstract class MeioTransporte implements Bem{
    abstract void dirigir();
}

class Imovel implements Bem{
    void setValor(double x){
        this.valor = x;
    }
}