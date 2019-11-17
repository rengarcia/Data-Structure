import os
from operator import itemgetter
import webbrowser as wb
X = [1,2,3,4,5]
PRESO = [0,0,0,0,0]
M = [0,0,0,0,0]

def perm(n,i):
    if(i==n):
        print(M)
    else:
        for j in range(n):
            if(PRESO[j]==0):
                M[i] = X[j]
                PRESO[j] = 1
                perm(n,i+1)
                PRESO[j]=0
def mostrar():
	print(X)


def menu():
	"""
	Función que limpia la pantalla y muestra nuevamente el menu
	"""
	os.system('cls') # NOTA para windows tienes que cambiar clear por cls
	print ("Selecciona una opción")
	print ("\t1 - aplicativo")
	print ("\t2 - ayuda")
	print ("\t3 - soluciones")
	print ("\t4 - salir")
 
 
while True:
	# Mostramos el menu
	menu()
 
	# solicituamos una opción al usuario
	opcionMenu = input("escoga una opcio: ")
 
	if opcionMenu=="1":
		print ("APLICATIVO \n")
		mostrar()
		input("\npulsa una tecla para continuar")
	elif opcionMenu=="2":
		wb.open_new(r'C:\Users\Sashael\Desktop\ProyectoEstructuras\python\help.chm')
		input("pulsa una tecla para continuar")
	elif opcionMenu=="3":
		perm(5,0)
		input("pulsa una tecla para continuar")
	elif opcionMenu=="4":
		break
	else:
		print ("")
		input("No has pulsado ninguna opción correcta...\npulsa una tecla para continuar")
