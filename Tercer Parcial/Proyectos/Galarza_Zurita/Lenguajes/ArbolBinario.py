class Arbol:

    def __init__(self, arbol, id, palabra):
        self.derecha = None
        self.izquierda = None
        self.id = id
        self.palabra = palabra

    def agregar(self, arbol, id, palabra):
        if arbol.id >= id:
            self.agregarIzquierda(arbol, id, palabra)
        elif arbol.id < id:
            self.agregarDerecha(arbol, id, palabra)

    def agregarIzquierda(self, arbol, id, palabra):
        if arbol.izquierda == None:
            arbol.izquierda = Arbol(arbol, id, palabra)
        else:
            self.agregar(arbol.izquierda, id, palabra)

    def agregarDerecha(self, arbol, id, palabra):
        if arbol.derecha == None:
            arbol.derecha = Arbol(arbol, id, palabra)
        else:
            self.agregar(arbol, id, palabra)

    def busquedaPalabra(self, arbol, id):
        while arbol != None:
            if arbol.id == id:
                return arbol.palabra
            arbol = arbol.derecha
        return "No disponible"

    def busquedaCodigo(self, arbol, palabra):
        while arbol != None:
            if arbol.palabra == palabra:
                return arbol.id
            arbol = arbol.derecha
        return 0

    def traduccion(self, tree, arbol, palabra):
        return self.busquedaPalabra(arbol, self.busquedaCodigo(tree, palabra))


tree = Arbol(None, 1, "shield")
arbol = Arbol(None, 1, "escudo")
pronun = Arbol(None, 1, "shild")
tree.agregar(tree,2,"house")
arbol.agregar(arbol,2,"casa")
pronun.agregar(pronun,2,"jaus")

print(tree.traduccion(tree, arbol, "shield"))
print(tree.traduccion(arbol,tree,"casa"))
print(tree.traduccion(arbol,pronun,"casa"))