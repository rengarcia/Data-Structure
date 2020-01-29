/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package traductorjava;

import com.google.gson.Gson;
import  filemanager.FileManager;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Jhony
 */
public class TraductorJava {

    static ArrayList<Palabra> arrayPalabras = new ArrayList<Palabra>();
    /**
     * @throws java.io.IOException
     */
    
    public static void readLastLine(String filePath) throws IOException{
    
    BufferedReader input = null;
        try {
            input = new BufferedReader(new FileReader(filePath));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(FileManager.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        String line;

        while ((line = input.readLine()) != null) {
             Gson gson = new Gson();
            Palabra word;
           word = gson.fromJson(line,Palabra.class);
           arrayPalabras.add(word);
        }
    }
    
    public static void main(String[] args) throws IOException {
        int opc = 0;
        Scanner reader = new Scanner(System.in);
        Gson gson = new Gson(); 
        String word;
        do{
            readLastLine("Dic.txt");
            System.out.println("1. Traducir Espanol-Ingles");
            System.out.println("2. Traducir Ingles-Espanol");
            System.out.println("3. Agregar Palabras");
            System.out.println("4. Salir");
            opc = reader.nextInt();
            switch(opc){
                case 1:
                        System.out.println("Ingrese una palabra en espanol para traducir: ");
                        word = reader.nextLine();
                        word = reader.nextLine();
                        if(FileManager.searchFile("Dic.txt", word)){
                            for(int i = 0; i<arrayPalabras.size(); i++){
                                if(arrayPalabras.get(i).getEspanol().equals(word)){
                                    System.out.println(arrayPalabras.get(i).getEspanol()+" - "+arrayPalabras.get(i).getIngles());
                                    break;
                                }
                            }
                        }else{
                            System.out.println("No existe en el diccionario");
                        }
                        break;
                case 2:
                        System.out.println("Ingrese una palabra en ingles para traducir: ");
                        word = reader.nextLine();
                        word = reader.nextLine();
                        if(FileManager.searchFile("Dic.txt", word)){
                            for(int i = 0; i<arrayPalabras.size(); i++){
                                if(arrayPalabras.get(i).getIngles().equals(word)){
                                    System.out.println(arrayPalabras.get(i).getIngles()+" - "+arrayPalabras.get(i).getEspanol());
                                    break;
                                }
                            }
                        }else{
                            System.out.println("No existe en el diccionario");
                        }
                        break;
                case 3:
                        String espanol,ingles;
                        System.out.println("Ingrese espanol: ");
                        reader.nextLine();
                        espanol = reader.nextLine();
                        System.out.println("Ingrese ingles: ");
                        ingles = reader.nextLine();
                        Palabra palabra = new Palabra(espanol,ingles);
                        FileManager.appendStrToFile("Dic.txt", gson.toJson(palabra));
                        System.out.println("Ingresado con exito!!!");
                        break;
            }
        }while(opc!=4);
    }   
}
