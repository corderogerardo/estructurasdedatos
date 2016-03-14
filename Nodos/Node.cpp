/*
 * Node.cpp
 *
 *  Created on: 14 de feb. de 2016
 *      Author: gerardo
 *      http://corderogerardo.me/blog/estructuras-de-datos
 */

#include "Node.h"

//Constructor por defecto
template<class T>
Node<T>::Node() {
	// TODO Auto-generated constructor stub
	data = NULL;
	prioridad = NULL;
	siguiente = NULL;
	anterior = NULL;
}
//Constructor por parametros, sobrecarga de constructor
template<class T>
Node<T>::Node(T data_, char _prioridad){
	data = data_;
	prioridad = _prioridad;
	siguiente = NULL;
	anterior = NULL;
}

//Metodos para apuntador siguiente
template<class T>
Node<T>* Node<T>::obtenerSiguiente(){
	return siguiente;
}
template<class T>
void Node<T>::asignarSiguiente(Node<T>* apun){
	siguiente = apun;
}
//Metodos para apuntador anterior
template<class T>
Node<T>* Node<T>::obtenerAnterior(){
	return anterior;
}
template<class T>
void Node<T>::asignarAnterior(Node<T>* apun){
	anterior = apun;
}
//Metodos para manipular el dato del nodo
template<class T>
void Node<T>::asignarDato(T dat){
	data = dat;
}
template<class T>
T Node<T>::obtenerDato(){
	return data;
}
// Eliminar todos los nodos
template<typename T>
void Node<T>::detele_all(){
	if(siguiente)
		siguiente->delete_all();
	delete this;
}
//Imprimir un nodo
template<typename T>
void Node<T>::imprimir(){
	cout << obtenerDato() << "->" <<endl;
}
//Destructor
template<typename T>
Node<T>::~Node() {

}
