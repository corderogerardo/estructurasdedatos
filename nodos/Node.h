/*
 * Node.h
 *
 *  Created on: 14 de feb. de 2016
 *      Author: gerardo
 *      http://corderogerardo.me/blog/estructuras-de-datos
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

using namespace std;

template <class T>
class Node {
private:
	//punteros
	Node<T>* siguiente;
	Node<T>* anterior;
	//Datos de los nodos
	T data;
	char prioridad;
public:
	//Metodos
	Node<T>* obtenerSiguiente();
	void asignarSiguiente(Node<T>* apun);

	Node<T>* obtenerAnterior();
	void asignarAnterior(Node<T>* apun);

	void asignarDato(T dat);
	T obtenerDato();

	void asignarPrioridad(char pri);
	char obtenerPrioridad();
	//Constructor
	Node();
	//Sobrecarga de Constructor
	Node(T,char);
	//Destructor
	~Node();

	void detele_all();
	void imprimir();
};


#endif /* NODE_H_ */
