/*
 * main.cpp
 *
 *  Created on: 25/5/2015
 *      Author: Gerardo Cordero_2
 *      http://corderogerardo.me/blog/estructuras-de-datos
 *
 */
#include <iostream>
#include <sstream>
#include <string>

#include "Cola.cpp"


using namespace std;

Cola<int> cola1;
Cola<int> cola2;
Cola<double> cola3;
Cola<double> cola4;
Cola<int> aux;
Cola<int> temp;
Cola<int> colaunion;
int ele;
double valor;
double resultado;
char pri;


void eliminarDePrimeraValoresQueNoenSegunda()
       {

    	while(cola1.colaVacia()!=true)
    	    {
    	   		int valorCola1;
    	       	valorCola1=cola1.retirar();
    	       	int frec;
   	       		frec=cola2.frecuencia(valorCola1);
    	       	if(frec!=0)
  	       		{
   	       		aux.agregar(valorCola1);
   	       		}
    	   	}
    	while(aux.colaVacia()!=true)
    	{
    		cola1.agregar(aux.retirar());
    	}
    	cola1.imprimir();
}

void eliminarValoresdeColaUnoMultiplosDeValoresenColaDos()
{
int valorColaUno,valorColaDos;
int cuantoshay=cola1.cuantos_hay();
int cuantosHay2=cola2.cuantos_hay();
bool encontradoDos=false;

for(int i=1;i<cuantoshay;i++)
	{

		valorColaUno=cola1.retirar();
		for(int i=1;i<cuantosHay2;i++)
		{
			valorColaDos=cola2.retirar();

			if(valorColaUno%valorColaDos!=0 && temp.frecuencia(valorColaUno)==0)
			{
				temp.agregar(valorColaUno);
			}
			cola2.agregar(valorColaDos);
		}

		cola1.agregar(valorColaUno);
	}
}

void unionDeColas()
{
	while(cola1.colaVacia()!=true)
	{
		colaunion.agregar(cola1.retirar());
	}
	while(cola2.colaVacia()!=true)
	{
		int valorCola2=cola2.retirar();
			if(colaunion.frecuencia(valorCola2)==0)
			{
				colaunion.agregar(valorCola2);
			}
	}
}
void guardarFactorialIColasRutina(double valor){
	double respaldoValor;

	for(int i=valor;i>0;i--){
		resultado = cola3.factorialIColas(valor);
		cola3.agregar(resultado);
		valor--;
	}
	cola3.imprimir();
}
void guardarFactorialRColasRutina(double valor){
	for(int i=valor;i>0;i--){
		resultado = cola4.factorialRColas(valor);
		cola4.agregar(resultado);
		valor--;
	}
	cola4.imprimir();
}





int main()
{
    int pos;
	int opc;

    do{
    	 system("cls");
    	        cin.clear();
    	        cout << "Cola " << endl;
    	        cout << "-----------" << endl << endl;
    	        cout << "\t1 .- Agregar" << endl;
    	        cout << "\t2 .- Retirar" << endl;
    	        cout << "\t3 .- Cuantos hay" << endl;
    	        cout << "\t4 .- Frecuencia" << endl;
    	        cout << "\t5 .- Mayor" << endl;
    	        cout << "\t6 .- Menor" << endl;
    	        cout << "\t7 .- Imprimir" << endl;
    	        cout << "\t8 .- Eliminar Impares" << endl;
    	        cout << "\t9 .- Suprimir mayores a este limite "<<endl;
    	        cout << "\t10 .- Eliminar mitad inferior "<<endl;
    	        cout << "\t11 .- Agregar en Cola 2" <<endl;
    	        cout << "\t12 .- Imprimir cola 2" << endl;
    	        cout << "\t13 .- Eliminar de la primera cola que no aparezcan en la 2da Cola"<<endl;
    	        cout << "\t14 .- Eliminar la mitad superior a un promedio"<<endl;
    	        cout << "\t15 .- eliminar Valores de Cola Uno Multiplos De Valores en Cola Dos"<<endl;
    	        cout << "\t16 .- Factorial Iterativo"<<endl;
    	        cout << "\t17 .- Factorial Recursivo"<<endl;
    	        cout << "\t0 .- Salir" << endl << endl;
    	        cout << "Elije una opcion: ";

    	        cin >> opc;

    	switch(opc){

    	case 1:
    cout << "Agrega un elemento al inicio: " << endl;
    cin >> ele;
    cola1.agregar(ele);
    cola1.imprimir();
    break;
	case 2:
		cout << "Retirar: " << endl;
		cout << "Dato retirado: " << cola1.retirar() <<endl;
		break;
	case 3:
		cout << "Cuantos hay: " << endl;
				cout << cola1.cuantos_hay() <<endl;
				break;

	case 4:
		cout << "Frecuencia: " << endl;
		cin >> ele;
		cout << cola1.frecuencia(ele)<<endl;
		break;
	case 5:
		cout <<"El mayor es: " <<endl;
		cout << cola1.mayor()<<endl;
			break;
	case 6:
		cout <<"El menor es: eliminarValoresdeColaUnoMultiplosDeValoresenColaDos" <<endl;
				cout << cola1.menor() <<endl;
			break;
	case 7:
		cola1.imprimir();
		break;
	case 8:
		cola1.eliminarImpares();
	break;
	case 9:
		cin >> ele;
			cola1.suprimir_mayores_a(ele);
		break;
	case 10:
			cola1.EliminarMitadInferior();
			cola1.imprimir();
			break;
	case 11:
		cin >> ele;
			cola2.agregar(ele);
		break;
	case 12:
			cola2.imprimir();
		break;
	case 13:
		eliminarDePrimeraValoresQueNoenSegunda();
		break;
	case 14:
		cola1.eliminarMitadSuperiorAlPromedio();
		cola1.imprimir();
		break;
	case 15:
	eliminarValoresdeColaUnoMultiplosDeValoresenColaDos();
	temp.imprimir();
			break;
	case 16:
		cout<<"Introduzca el numero a calcular el factorial Iterativo"<<endl;
		cin >> valor;
		guardarFactorialIColasRutina(valor);
		resultado=cola3.factorialIColas(valor);
		cout<<resultado<<endl<<endl;

		break;
	case 17:
		cout<<"Introduzca el numero a calcular el factorial Recursivo"<<endl;
		cin >> valor;
		guardarFactorialRColasRutina(valor);
		resultado=cola4.factorialRColas(valor);
		cout<<resultado<<endl<<endl;

		break;
	}
    }while(opc!=0);

    return 0;
}




