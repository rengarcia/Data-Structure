package proyectoapp;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 *
 * @author Luis Carvajal, Elian Llorente
 */
public class GestorProyecto {
public static void main(String[] args) 
    {
        Convinaciones st= new Convinaciones();
        int[ ] a= new int[50];
        int b;
        Scanner sc= new Scanner(System.in);
        b=sc.nextInt();
        st.mostrar(a, b);
        st.back(a, 1);
        
    }
}
    
  
    

