package testes;

public class Vetor<T> {
    private T[] elementos;
    private int tamanho;

    @SuppressWarnings("unchecked")
    public Vetor(int capacidade) {
        elementos = (T[]) new Object[capacidade]; // Java doesn't support generic array creation directly
        tamanho = 0;
    }

    // Method to add an element to the vector
    public boolean adiciona(T elemento) {
        if (tamanho < elementos.length) {
            elementos[tamanho] = elemento;
            tamanho++;
            return true;
        } else {
            // Vector is full, could expand the array or throw an exception
            return false;
        }
    }

    // Method to get an element at a specific index
    public T get(int indice) {
        if (indice >= 0 && indice < tamanho) {
            return elementos[indice];
        } else {
            throw new IndexOutOfBoundsException("Index out of bounds: " + indice);
        }
    }

    // Method to get the current size of the vector
    public int tamanho() {
        return tamanho;
    }
}