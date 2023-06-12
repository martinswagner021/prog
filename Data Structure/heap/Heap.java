public class Heap{
    private int[] h;
    private int last_elem;
    
    public Heap(int heap_size){
        this.h = new int[heap_size];
        this.last_elem = 0;
    }
    
    public void inserir_elem(int obj){
        this.h[last_elem] = obj;
        this.last_elem++;
        
        ajustarSubindo(this.last_elem - 1);
    }

    private void ajustarSubindo(int pos){
        if (pos != -1 && indicePai(pos) != -1){
            if (this.h[pos] < this.h[indicePai(pos)]){
                int aux = this.h[pos];
                this.h[pos] = this.h[indicePai(pos)];
                this.h[indicePai(pos)] = aux;
                ajustarSubindo(indicePai(pos));
            }
        }
    }
    
    public int remover_elem(){
        if (this.last_elem == 0){
            return -1;
        }
        else{
            int ret = this.h[0];
            this.last_elem--;
            this.h[0] = this.h[last_elem];
            ajustarDescendo(0);
            return ret;
        }
    }

    private void ajustarDescendo(int pos){
        if (pos != -1 && indiceFilhoEsq(pos) != -1){
            int indiceMenor = indiceFilhoEsq(pos);
            if (indiceFilhoDir(pos) != -1 && this.h[indiceFilhoDir(pos)] < this.h[indiceMenor]){
                indiceMenor = indiceFilhoDir(pos);
            }

            if (this.h[indiceMenor] < this.h[pos]){
                int aux = this.h[pos];
                this.h[pos] = this.h[indiceMenor];
                this.h[indiceMenor] = aux;
                ajustarDescendo(indiceMenor);
            }
        }
    }
    
    public void print_heap(){
        System.out.print("[");
        for (int i=0; i<this.last_elem; i++){
            System.out.print((i == this.last_elem - 1) ? h[i] + "" : h[i] + ", ");
        }
        System.out.println("]");
    }

    private int indicePai(int ind){
        int indice = (int) (ind-1)/2;
        if (ind <= 0 || ind >= this.last_elem){
            return -1;
        }
        return indice;
    }
    private int indiceFilhoEsq(int ind){
        int indice = (ind*2)+1;
        if (indice <= 0 || indice >= this.last_elem){
            return -1;
        }
        return indice;
    }
    private int indiceFilhoDir(int ind){
        int indice = (ind*2)+2;
        if (indice <= 0 || indice >= this.last_elem){
            return -1;
        }
        return indice;
    }
}