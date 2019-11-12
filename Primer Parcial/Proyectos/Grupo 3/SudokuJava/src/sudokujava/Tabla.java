package sudokujava;

public class Tabla implements Operaciones{
    private int tablero[][];

    public Tabla(int[][] tablero) {
        this.tablero = tablero;
    }
    public Tabla() {
        int[][] tablero = new int[9][9];
        for (int i = 0; i < tablero.length; i++) {
            for (int j = 0; j < tablero.length; j++) {
                tablero[i][j]=0;
            }
        }
        this.tablero = tablero;
    }
    public int[][] getTablero() {
        return tablero;
    }

    public void setTablero(int[][] tablero) {
        this.tablero = tablero;
    }
    
    @Override
   public  boolean seguro(int[][] tablero,  int fila, int col, int num)  
{  
    for (int d = 0; d < tablero.length; d++)  
    { 
        if (tablero[fila][d] == num)  
        { 
            return false; 
        } 
    } 
    for (int r = 0; r < tablero.length; r++) 
    { 
        if (tablero[r][col] == num) 
        { 
            return false; 
        } 
    } 
    int sqrt = (int) Math.sqrt(tablero.length); 
    int filaInicio = fila - fila % sqrt; 
    int ColumnaInicio = col - col % sqrt; 
    for (int r = filaInicio; r < filaInicio + sqrt; r++)  
    { 
        for (int d = ColumnaInicio;d < ColumnaInicio + sqrt; d++)  
        { 
            if (tablero[r][d] == num)  
            { 
                return false; 
            } 
        } 
    } 
    return true; 
} 
    @Override
    public boolean solucionSudoku(int[][] tablero, int n)  
{ 
    int fila = -1; 
    int col = -1; 
    boolean vacio = true; 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++)  
        { 
            if (tablero[i][j] == 0)  
            { 
                fila = i; 
                col = j;
                vacio = false;  
                break; 
            } 
        } 
        if (!vacio) 
        { 
            break; 
        } 
    } 
    if (vacio)  
    { 
        return true; 
    } 
    for (int num = 1; num <= n; num++) 
    { 
        if (seguro(tablero, fila, col, num)) 
        { 
            tablero[fila][col] = num; 
            mostrar(tablero,n);
            System.out.println("");
            if (solucionSudoku(tablero, n))  
            { 
                return true; 
            }  
            else
            { 
                tablero[fila][col] = 0;
            } 
        } 
    } 
    return false; 
} 
    @Override
   public void mostrar(int[][] tablero, int N) 
{ 
    for (int r = 0; r < N; r++) 
    { 
        for (int d = 0; d < N; d++) 
        { 
            System.out.print(tablero[r][d]); 
            System.out.print(" "); 
        } 
        System.out.print("\n"); 
          
        if ((r + 1) % (int) Math.sqrt(N) == 0)  
        { 
            System.out.print(""); 
        } 
    } 
} 
}
