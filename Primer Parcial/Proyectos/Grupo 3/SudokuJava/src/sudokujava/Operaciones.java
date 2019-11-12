package sudokujava;
public interface Operaciones {
    public  boolean seguro(int[][] tablero,  int fila, int col, int num);
    boolean solucionSudoku(int[][] tablero, int n);
    public void mostrar(int[][] tablero, int N);
}
