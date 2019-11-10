/**
  * @file Matriz.h
  * @version 1.0
  * @date 07/11/2019
  * @author Luis Carvajal
  * @title Clase Matriz
  * @code
    int main(){
	main:
	int row,col,exp;
	Matriz p;
	Ingreso lee;
	row= lee.ingresarInt("Ingrese # filas: ");
	p.setfilas(row);
	col= lee.ingresarInt("Ingrese # columnas: ");
	p.setfilas(col);
	cout<<endl;
	
	
	if(row>10&&row>10||row!=col){
		cout<<"la matriz tiene q ser cuadrada y su dimenion menor o igual q 10\n"<<endl;
	}else{
		p.setcolumnas(col);
		p.setfilas(row);
		p.crear();
		p.llenar();
		p.imprimir();
		col= lee.ingresarInt("Ingrese el exponente: ");
		p.setexp(exp);
		cout<<endl;
		p.multiplicar(p.getexp());
		p.imprimir();
		
		
	}
	system("pause");
	system("cls");
	goto main;
	return 0;
  * @endcode
  * @brief Elevar una matriz a un exponente n
  */

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
