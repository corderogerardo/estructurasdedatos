/*
 * Arbol.h
 *
 *  Created on: 27 de feb. de 2016
 *      Author: gerardo
 */

#ifndef ARBOL_H_
#define ARBOL_H_
#include <iostream>
#include "Nodo.h"

template<class Tipo>
class Arbol {
typedef Nodo<Tipo>* Apuntador;
private:
	Nodo<Tipo>* raiz;
public:
	Arbol(void);
	Arbol(Arbol<Tipo> &entrada);

	Nodo<Tipo>* ObtRaiz();
	void AsigRaiz(Nodo<Tipo>* p);

	void Liberar(Nodo<Tipo>* p);

	virtual ~Arbol(void);

	bool Vacio(void);
	bool Lleno(void);

	Nodo<Tipo>* CrearNodo(Tipo valor);

	bool InsIzquierdo(Nodo<Tipo> *P, Tipo valor);
	bool InsDerecho(Nodo<Tipo> *P, Tipo valor);

	Nodo<Tipo> *Combinar(Nodo<Tipo> *arbol1, Nodo<Tipo> *arbol2, Tipo valor);

	bool EliDerecho(Nodo<Tipo> *p, Tipo &valor);
	bool EliIzquierdo(Nodo<Tipo> *p, Tipo &valor);

	bool Eliminar(Nodo<Tipo> *ap, Nodo<Tipo>* &p, Tipo &valor);

	Nodo<Tipo> *CopiaArbol(Nodo<Tipo> *p);
	Arbol<Tipo> &operador = (Arbol<Tipo> &entrada);

};

#include "Arbol.cpp"
#endif /* ARBOL_H_ */

