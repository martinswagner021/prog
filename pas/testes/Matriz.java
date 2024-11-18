package testes;

public class Matriz<T>{
    private Vetor<Vetor<T>> matriz;
	private int linhas;
	private int colunas;
	public Matriz (int linhas, int colunas) {
		this.linhas = linhas;
		this.colunas = colunas;
		this.matriz = new Vetor<>(linhas);

		for(int i=0; i<linhas; i++){
			this.matriz.adiciona(new Vetor<>(colunas));
        }
    }

    public void set(int linha, int coluna, T elemento) {
        Vetor<T> row = matriz.get(linha);
        row.adiciona(elemento);
    }

    public T get (int linha, int coluna){
        return this.matriz.get(linha).get(coluna);
    }
}

