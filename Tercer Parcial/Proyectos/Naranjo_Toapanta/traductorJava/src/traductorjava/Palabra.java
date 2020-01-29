/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package traductorjava;

/**
 *
 * @author Jhony
 */
public class Palabra {
    private String espanol;
    private String ingles;

    public Palabra() {
    }

    public Palabra(String espanol, String ingles) {
        this.espanol = espanol;
        this.ingles = ingles;
    }
    

    public String getEspanol() {
        return espanol;
    }

    public void setEspanol(String espanol) {
        this.espanol = espanol;
    }

    public String getIngles() {
        return ingles;
    }

    public void setIngles(String ingles) {
        this.ingles = ingles;
    }
}
