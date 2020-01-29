/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package diccionario;

/**
 *
 * @author Kevin Zurita
 */
public class ArbolBinario {
    
    Nodo raiz;
    public ArbolBinario(){
        raiz=null;
    }
    
    public void insertar(int id, String palabra){
        Nodo n = new Nodo(id,palabra);
        
        if(raiz==null){
            raiz=n;
        }else{
            Nodo aux=raiz;
            while(aux!=null){
                n.padre=aux;
                if(n.id>=aux.id){
                    aux=aux.derecha;
                }else{
                    aux=aux.izquierda;
                }
            }
            
            if(n.id<n.padre.id){
                n.padre.izquierda=n;
            }else{
                n.padre.derecha=n;
            }
        }
    }
    
    public String busquedaPalabra(Nodo n, int x){
        while (n != null)
	{
		if (n.id == x)
		{
			return n.palabra;
		}
		n = n.derecha;
	}
	return "No disponible.";
    }
    
    public int busquedaCodigo(Nodo n, String word){
        while (n != null)
	{
		if (n.palabra.equals(word))
		{
			return n.id;
		}
		n = n.derecha;
	}
        return 0;
    }
    
    public String traduccion(Nodo a, Nodo b, String word){
        return busquedaPalabra(b,busquedaCodigo(a,word));
    }
    
    private class Nodo{
        public Nodo padre;
        public Nodo izquierda;
        public Nodo derecha;
        public int id;
        public String palabra; 
        
        public Nodo(int key,String word){
            id=key;
            palabra=word;
            padre=null;
            izquierda=null;
            derecha=null;
        }
    }
}
