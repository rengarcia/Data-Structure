#include "Nodo.h"
#include "OperacionesSet.h"

set <int> ::iterator itr;
set <int> ::iterator itrAux;

void OperacionesSet::imprimir(set<int> setTemp)
{
	cout << "\nLos elementos del set son : {";
	for (itr = setTemp.begin(); itr != setTemp.end(); ++itr)
	{
		cout << " " << *itr;
	}
	cout << " }" << endl;

}

set<int> OperacionesSet::InsertarDatosSet(string cadena)
{
	int aux;
	set <int> setNuevo;

	char* temp = (char*)cadena.c_str();
	char* token = strtok(temp, " ");

	while (token != NULL)
	{
		aux = stoi(token);
		setNuevo.insert(aux);
		token = strtok(NULL, " ");
	}

	return setNuevo;
}

set<int> OperacionesSet::Lista_a_Conjunto(Nodo* referencia)
{
	set <int> setNuevo;

	while (referencia != NULL) {
		setNuevo.insert(referencia->getNumero());
		referencia = referencia->getSiguiente();
	}

	return setNuevo;
}

set<int> OperacionesSet::Union(set<int> setAux1, set<int> setAux2)
{
	set <int> setUnion;

	for (itr = setAux1.begin(); itr != setAux1.end(); ++itr)
	{
		setUnion.insert(*itr);
	}

	for (itr = setAux2.begin(); itr != setAux2.end(); ++itr)
	{
		setUnion.insert(*itr);
	}

	return setUnion;
}

set<int> OperacionesSet::Interseccion(set<int> setAux1, set<int> setAux2)
{
	set <int> setInterseccion;
	int temp;
	bool bandera = false;

	for (itr = setAux1.begin(); itr != setAux1.end(); ++itr)
	{
		temp = *itr;

		bandera = esComun(temp, setAux2);
		if (bandera) {
			setInterseccion.insert(*itr);
		}
	}

	return setInterseccion;
}

set<int> OperacionesSet::Diferencia(set<int> setAux1, set<int> setAux2)
{
	set <int> setDiferencia;
	int temp;
	bool bandera = false;

	for (itr = setAux1.begin(); itr != setAux1.end(); ++itr)
	{
		temp = *itr;
		bandera = esComun(temp, setAux2);
		if (!bandera) {
			setDiferencia.insert(*itr);
		}
	}

	return setDiferencia;

}

bool OperacionesSet::sonIguales(set<int> setAux1, set<int> setAux2)
{
	bool bandera;
	int temp;

	for (itr = setAux1.begin(); itr != setAux1.end(); ++itr)
	{
		temp = *itr;
		bandera = esComun(temp, setAux2);
		if (!bandera) {
			break;
		}
	}

	return bandera;
}

bool OperacionesSet::esComun(int valor, set<int> setAux2)
{

	for (itrAux = setAux2.begin(); itrAux != setAux2.end(); ++itrAux)
	{
		if (valor == *itrAux)
			return true;
	}

	return false;
}
