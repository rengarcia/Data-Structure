/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#if !defined(__UML_Class_Diagram_4_Matriz_h)
#define __UML_Class_Diagram_4_Matriz_h

/**
 * @brief Clase para la creacion de una matriz
 */
class Matriz
{
public:
   int** getmatriz(void);
   void setmatriz(int** newMatriz);
   int getfilas(void);
   void setfilas(int newFilas);
   int getexp(void);
   void setexp(int newExp);
   int getcolumnas(void);
   void setcolumnas(int newColumnas);
   /**
 		 * @brief Constructor matriz vacio
 		 */
   Matriz();
   
   	/**
		  * @brief crear crea la matriz
		  * @return void
		*/
   void crear(void);
   
   /**
		  * @brief crear llena la matriz
		  * @return void
		*/
   void llenar(void);
   
   /**
		  * @brief imprime la matriz
		  * @return void
		*/
   void imprimir(void);
   
   /**
		  * @brief multiplica la matriz
		  * @param int
		  * @return void
		*/
   void multiplicar(int exponente);
   
  
   
protected:
private:
   int filas;
   int columnas;
   int exp;
   int** matriz;


};

#endif
