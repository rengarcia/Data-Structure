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
public class Diccionario {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ArbolBinario treeIngles = new ArbolBinario();
        ArbolBinario treeEspaniol = new ArbolBinario();
        ArbolBinario treePronunciacion = new ArbolBinario();
        
        treeIngles.insertar(1, "shield");
        treeEspaniol.insertar(1, "escudo");
        treePronunciacion.insertar(1, "shild");
        
        System.out.println(treeIngles.traduccion(treeIngles.raiz, treeEspaniol.raiz, "shield"));
        System.out.println(treeIngles.traduccion(treeEspaniol.raiz, treeIngles.raiz, "escudo"));
        System.out.println(treeIngles.traduccion(treeEspaniol.raiz, treePronunciacion.raiz, "escudo"));
    }
    
}
