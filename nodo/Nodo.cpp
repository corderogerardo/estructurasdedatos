/*
 * Nodo.cpp
 *
 *  Created on: 27 de feb. de 2016
 *      Author: gerardo
 */



template <class Tipo>
Tipo Nodo<Tipo>::ObtInfo(){
     return info;
     };

template <class Tipo>
void Nodo<Tipo>::AsigIzq(Nodo<Tipo>* p){
     izq=p;
     };

template <class Tipo>
Nodo<Tipo>* Nodo<Tipo>::ObtIzq(){
    return izq;
    };

template <class Tipo>
void Nodo<Tipo>::AsigDer(Nodo<Tipo>* p){
     der=p;
     };

template <class Tipo>
Nodo<Tipo>* Nodo<Tipo>::ObtDer(){
     return der;
     };

//Imprimir un nodo
template<class Tipo>
void Nodo<Tipo>::imprimir(){
	cout << ObtInfo() << "->" <<endl;
}

//Destructor
template<class Tipo>
Nodo<Tipo>::~Nodo() {

}
