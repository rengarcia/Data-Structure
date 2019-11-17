/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyectoapp;

/**
 *
 * @author Elian Llorente, Luis Carvajal
 */
public class Convinaciones {
    
    public void  back(int st[], int k)   {
       int ev,n=0;
	if(k==n+1)
	{
		for(int i = 1; i < k; i++)
		              System.out.println(st[i]+"\n");
		
	}
	else
		for(int i = 1; i <= k; i++)
		{
			st[k] = i;
			ev=1;
			for(int j = 1; j < k; j++){
                            	if(st[j] == st[k]){ev=0;}
        			if(ev==1){back(st, k+1);}
                        }
			
				
		}
     
 }
    public void mostrar(int st[], int k){
        System.out.println("NUMEROS QUE SE VAN A CONVINAR: "); 

   	for(int i = 1; i <= k; i++)
		{
			st[k] = i;
			System.out.println(st[k]); 
		}
	
}
    }
    

