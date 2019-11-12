package sudokujava;
public class SudokuJava {
    public static void main(String[] args) {
       Tabla table= new Tabla();
       table.solucionSudoku(table.getTablero(), table.getTablero().length);
       table.mostrar(table.getTablero(), table.getTablero().length);
    }
}
