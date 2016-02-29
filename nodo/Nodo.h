/*
 * Nodo.h
 *
 *  Created on: 27 de feb. de 2016
 *      Author: gerardo
 */

#ifndef NODO_H_
#define NODO_H_

#include <iostream>

using namespace std;

template<class Tipo>
class Nodo {
private:
	Tipo info;
	Nodo<Tipo>* izq;
	Nodo<Tipo>* der;
public:
	void AsigInfo(Tipo in);
	Tipo ObtInfo();

	void AsigIzq(Nodo<Tipo>*p);
	Nodo<Tipo>* ObtIzq();

	void AsigDer(Nodo<Tipo>*p);
	Nodo<Tipo>*ObtDer();

	//Constructor
	Nodo();
	//Sobrecarga de Constructor
	Nodo(Tipo);
	//Destructor
	~Nodo();

	void imprimir();
};

#include "Nodo.cpp"
#endif /* NODO_H_ */
