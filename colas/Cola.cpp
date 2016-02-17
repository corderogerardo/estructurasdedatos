/*
 * Cola.cpp

 *
 *  Created on: 25/5/2015
 *      Author: Gerardo Cordero_2
 */

#include "Cola.h"

using namespace std;

template<typename T>
Cola<T>::Cola() {
	// TODO Auto-generated constructor stub
	 m_inicio = NULL;
	 m_fin = NULL;
}

// Insertar al inicio
template<typename T>
void Cola<T>::agregar(T data_)
{
	//creo los nodos que voy a usar y asignar
	Node<T>* puntero=m_inicio;
	Node<T>* nuevoNodo= new Node<T>;

	//al Nuevo nodo le asigno el nuevo valor, y al siguiente de este nodo lo apunto a NULL
	nuevoNodo->asignarDato(data_);
	nuevoNodo->asignarSiguiente(NULL);

	//Ahora verifico si la cola esta vacia, sino esta vacia agrego al final.
	if(!colaVacia())
	{
		while(puntero->obtenerSiguiente()!=NULL)
		{
			puntero=puntero->obtenerSiguiente();
		}
		nuevoNodo->asignarAnterior(puntero);
		puntero->asignarSiguiente(nuevoNodo);

	}
	else
	{
		m_inicio=nuevoNodo;
	}

}

// Insertar al inicio
template<typename T>
void Cola<T>::agregarConPrioridad(T data_,char pri)
{
	Node<T>* puntero=m_inicio;
	Node<T>* nuevoNodo = new Node<T>;

	//metodo los valores que me pasan por parametro al nuevoNodo
	nuevoNodo->asignarDato(data_);
	nuevoNodo->asignarPrioridad(pri);

	if(colaVacia())
	{
		m_inicio=nuevoNodo;
		nuevoNodo->asignarSiguiente(NULL);
	}
	else
	{
		if(pri < m_inicio->obtenerPrioridad())
		{
			nuevoNodo->asignarSiguiente(m_inicio);
			m_inicio=nuevoNodo;
		}
		else
		{
		while(puntero!=NULL)
			{
				if(pri > puntero->obtenerPrioridad()){
				puntero= puntero->obtenerSiguiente();
				}
				else
				{
					nuevoNodo->asignarSiguiente(puntero->obtenerSiguiente());
					puntero->asignarSiguiente(nuevoNodo);

				}
			}
		nuevoNodo->asignarSiguiente(puntero->obtenerSiguiente());
		puntero->asignarSiguiente(nuevoNodo);
		}

		}
}

template<typename T>
int Cola<T>::retirar()
{
	//creo mi nodo a eliminar y lo hago igual a mi nodo inicial
	Node<T> *a_eliminar = m_inicio;
	int valorAlInicio=0;
	//Verifico que hayan elementos en la cola
	if(cuantos_hay()>0){
		valorAlInicio=m_inicio->obtenerDato();
		m_inicio=a_eliminar->obtenerSiguiente();
		delete a_eliminar;

		//retorno el valor que elimine
	return valorAlInicio;
	}
}

template<typename T>
bool Cola<T>::retirarConPrioridad(T &data, char &pri)
{
	Node<T> *aeliminar = m_inicio;
	if(!colaVacia())
	{
		pri=aeliminar->obtenerPrioridad();
		data=aeliminar->obtenerDato();
		m_inicio=aeliminar->obtenerSiguiente();
		delete aeliminar;
	}
	return true;


}

template<typename T>
void Cola<T>::eliminarImpares()
{
Node<T>* anterior;
Node<T>* actual=m_inicio;

while(actual!=NULL)
{
	//si el modulo del dato entre 2 es cero es par,
	//como busco los impares, mientras el dato sea diferente de cero, el valor es impar.
	if(actual->obtenerDato()%2!=0)
	{
		//si el valor es impar y esta al inicio
		if(actual==m_inicio)
		{
			m_inicio=actual->obtenerSiguiente();
			delete actual;
			actual=m_inicio;
		}
		//si el valor es impar pero no esta al inicio
		else
		{
			anterior->asignarSiguiente(actual->obtenerSiguiente());
			delete actual;
			actual=anterior;

			anterior=actual;
			actual=actual->obtenerSiguiente();
		}

	}
	else
	{
		anterior=actual;
		actual=actual->obtenerSiguiente();
	}
}
}

template<typename T>
int Cola<T>::frecuencia(int valor)
{
	Node<T> *auxNode = m_inicio;
	Node<T> *tempo = m_inicio;
	int frecuencia=0;

	frecuencia=0;
		while(auxNode!=NULL)
		{
			if(auxNode->obtenerDato()==valor)
		{
			frecuencia++;
		}
		auxNode=auxNode->obtenerSiguiente();
		}
		return frecuencia;
}




template<typename T>
bool Cola<T>::colaVacia(){
	 Node<T> *aux_node = m_inicio;
		int cantidad=0;
			if(m_inicio == NULL)
			{
		      return true;
			}
			else{
				return false;
			}

}

template<typename T>
int Cola<T>::cuantos_hay()
{
	 Node<T> *aux_node = m_inicio;

	int cantidad=0;

		if(m_inicio == NULL){
	   	cout << "No hay elementos en la lista"<<endl;
	      return 0;
	   }
	   else{
	   	while(m_inicio!=NULL){
	      	cantidad ++;
	      	m_inicio = m_inicio->obtenerSiguiente();
	      }
	   	m_inicio=aux_node;
	      return(cantidad);
	   }
}

// Imprimir la cola
template<typename T>
void Cola<T>::imprimir()
{
	int val= cuantos_hay();
    Node<T> *temp = m_inicio;
    if (!m_inicio) {
        cout << "La cola esta vacia " << endl;
    } else {
        while (temp!=NULL) {
         		cout<<"Factorial de ";
        		cout<<val;
        		cout<<" es: ";
        		cout<<val;
        		cout<<" x ";
        		cout<<val-1;
        		cout<<"!= ";
        		temp->imprimir();
        		val--;

            if (temp->obtenerSiguiente()==NULL)
            	{cout << "NULL";}
            temp = temp->obtenerSiguiente();
        }
  }
    cout << endl<<endl;
}

// Mayor
template<typename T>
int Cola<T>::mayor()
{
	int el_mayor;
	Node<T> *lugar = m_inicio;

	el_mayor = lugar->obtenerDato();
	while(lugar!=NULL)
	{
		if(lugar->obtenerDato()>el_mayor)
		{
			el_mayor=lugar->obtenerDato();

		}
		lugar=lugar->obtenerSiguiente();
	}
	return el_mayor;
}
// Menor
template<typename T>
int Cola<T>::menor()
{
	int el_menor;
		Node<T> *lugar = m_inicio;
		el_menor = lugar->obtenerDato();
		while(lugar!=NULL)
		{
			if(lugar->obtenerDato()<el_menor)
			{
				el_menor=lugar->obtenerDato();

			}
			lugar=lugar->obtenerSiguiente();
		}
		return el_menor;

}

//suprimir valores mayores a un limite dado
template<typename T>
void Cola<T>::suprimir_mayores_a(int limite)
{
	Node<T> *anterior;
	Node<T> *actual = m_inicio;

	while(actual!=NULL)
	{
		if(actual->obtenerDato() > limite)
		{
			if(actual==m_inicio)
			{
			m_inicio=actual->obtenerSiguiente();
			delete actual;
			actual = m_inicio;
			}
			else
			{
				anterior->asignarSiguiente(actual->obtenerSiguiente());
				delete actual;
				actual=anterior;


				anterior=actual;
				actual=actual->obtenerSiguiente();
			}

		}else
		{
			anterior=actual;
			actual=actual->obtenerSiguiente();
		}

	}

}

template<typename T>
void Cola<T>::eliminar_menores_a()
{
	Node<T> *anterior;
		Node<T> *actual = m_inicio;
		Node<T>* aux=m_inicio;
		int acum=0;
		int mitadMenores;

		while(aux!=NULL)
		{
			acum=acum+aux->obtenerDato();
			aux=aux->obtenerSiguiente();

		}
		mitadMenores=acum/cuantos_hay();

		while(actual!=NULL)
		{
			if(actual->obtenerDato() < mitadMenores)
			{
				if(actual==m_inicio)
				{
				m_inicio=actual->obtenerSiguiente();
				delete actual;
				actual = m_inicio;
				}
				else
				{
					anterior->asignarSiguiente(actual->obtenerSiguiente());
					delete actual;
					actual=anterior;


					anterior=actual;
					actual=actual->obtenerSiguiente();
				}

			}else
			{
				anterior=actual;
				actual=actual->obtenerSiguiente();
			}

		}
}

template<class T>
void Cola<T>::EliminarMitadInferior()
{ 	Node<T> *anterior;
	Node<T> *actual=m_inicio;
	int mitad;
	mitad=cuantos_hay()/2;
	for(int i=0; i<mitad;i++)
	{
		int menorValor=menor();
		actual=m_inicio;
		bool encontrado;
		encontrado=false;
		while(encontrado==false)
		{
				if(actual->obtenerDato()==menorValor)
				{
					encontrado=true;
					if (actual==m_inicio)
					{
						m_inicio=actual->obtenerSiguiente();
						delete actual;
						actual=m_inicio;
					}else
					{
						anterior->asignarSiguiente(actual->obtenerSiguiente());
						delete actual;
						actual=anterior;

						anterior=actual;
						actual=actual->obtenerSiguiente();
					}
				}
				else
				{
				anterior=actual;
				actual=actual->obtenerSiguiente();
				}
		}//end While
	}//end For
}

template<typename T>
void Cola<T>::eliminarMitadSuperiorAlPromedio()
{
	Node<T>* anterior;
	Node<T>* aux=m_inicio;
	Node<T>* actual=m_inicio;

	int mitad;
	float acum,prom;
	bool encontrado;
	mitad=0;
	acum=0;
	prom=0;

	while(aux!=NULL)
	{
		acum+=aux->obtenerDato();
		aux=aux->obtenerSiguiente();
	}
	aux=m_inicio;


	mitad=cuantos_hay()/2;

	prom=acum/cuantos_hay();

	for(int i=0;i<mitad;i++)
	{
		actual=m_inicio;
		encontrado=false;

		while(encontrado==false)
		{
			if(actual->obtenerDato()>prom)
			{
				encontrado=true;
				if(actual==m_inicio)
				{
					m_inicio=actual->obtenerSiguiente();
					delete actual;
					actual=m_inicio;
				}
				else
				{
					anterior->asignarSiguiente(actual->obtenerSiguiente());
					delete actual;
					actual=anterior;

					anterior=actual;
					actual=actual->obtenerSiguiente();
				}
			}
			else
			{
				anterior=actual;
				actual=actual->obtenerSiguiente();
			}
		}//end while
	}//end for

}//end del metodo

// Eliminar por data del nodo
template<typename T>
void Cola<T>::eliminar_mayores_a(T data_)
{
    Node<T> *temp = m_inicio;
    Node<T> *temp1 = m_inicio->siguiente;


    if (m_inicio->data > data_) {
    	m_inicio = temp->siguiente;
    } else {
    	    while (temp1) {
                Node<T> *aux_node = temp1;
            if (temp1->data > data_) {
            	if(temp1!=NULL)
            	{
                temp->siguiente = temp1->siguiente;
                delete aux_node;
            	}
            	else
            	{
                temp1=temp1->anterior;
                m_fin = temp1;
                delete aux_node;
            	}

            }
                temp = temp->siguiente;
                temp1 = temp1->siguiente;
        }
    }
}

template<typename T>
double Cola<T>::factorialIColas(double valor){
	double resultado=1;
	while(valor>1){
		resultado=resultado*valor;
		valor= valor -1;
	}

	return (resultado);
}
template<typename T>
void Cola<T>::guardarFactorialIColas(double valor){
	double result;
	while(valor<1){
		result = factorialIColas(valor);
		agregar(result);
		valor--;
	}
	imprimir();
}
template<typename T>
double Cola<T>::factorialRColas(double n){
	if(n < 1){
		return 0;
	}
	else if(n==1){
		return 1;
	}else{
		return (n*factorialRColas(n-1));
	}
}//Graciano
template<typename T>
void Cola<T>::guardarFactorialRColas(double valor){
	for(int i=valor;i>0;i--){
		double result = factorialRColas(valor);
		agregar(result);
		valor--;
	}
	imprimir();
}



template<typename T>
Cola<T>::~Cola() {

}

