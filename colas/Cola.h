/*
 * Cola.h
 *
 *  Created on: 25/5/2015
 *      Author: Gerardo Cordero_2
 */

#ifndef COLA_H_
#define COLA_H_
#include <iostream>
#include <string>
#include <stdlib.h>

#include "../nodos/Node.cpp"

using namespace std;

template <class T>

class Cola {
private:
	Node<T> *m_inicio, *m_fin;
public:
	Cola();
	~Cola();

	 void agregar(T);
	 void agregarConPrioridad(T,char);
	 int retirar();
	 bool retirarConPrioridad(T &data, char &pri);
	  int frecuencia(int valor);
	  int cuantos_hay();
	  bool colaVacia();
	  void imprimir();
	  void eliminarImpares();
	  void suprimir_mayores_a(int limite);
	  void eliminar_mayores_a(T data_);
	  void eliminar_menores_a();
	  void EliminarMitadInferior();
	  void eliminarMitadSuperiorAlPromedio();


	 int mayor();
	 int menor();

};

#endif /* COLA_H_ */
