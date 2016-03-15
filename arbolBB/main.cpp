#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "ArbolBB.cpp"
#include "Arbol.cpp"
#include "Nodo.cpp"

using namespace std;

typedef Nodo<int>* Apuntador;
Apuntador p;
ArbolBB<int> arboluno;
ArbolBB<int> arbola;
ArbolBB<int> arbolb;
ArbolBB<int> arbolab;
ArbolBB<int> arbolba;
ArbolBB<int> arbolc;


void cargarADesdeTxt(ArbolBB<int>& arbol);
void cargarBDesdeTxt(ArbolBB<int>& arbol);
void cargarADesdeTxtR(ArbolBB<int>& arbol);
void cargarBDesdeTxtR(ArbolBB<int>& arbol);
void inOrden(ArbolBB<int> &arbol, Apuntador raiz);
void preOrden(ArbolBB<int> &arbol, Apuntador raiz);
void postOrden(ArbolBB<int> &arbol, Apuntador raiz);
void CombinarpreOrden(ArbolBB<int> &arbol,ArbolBB<int> &arboldos, Apuntador raiz);
void CombinarRepetido(ArbolBB<int> &arbol,ArbolBB<int> &arboldos, Apuntador raiz);


int main(int argc, char *argv[])
{
    int opc;
    int ele;
    int pos;

    do{
    	 system("cls");
    	        cin.clear();
    	        cout << "Arbol Binario Primera Entrega " << endl;
    	        cout << "-----------" << endl << endl;
    	         cout << "\t1 .- Insertar en Arbol Binario" << endl;
    	        cout << "\t2 .- Eliminar en Arbol Binario" << endl;
    	        cout << "\t3 .- Imprimir InOrden" << endl;
    	        cout << "Arbol Binario Segunda Entrega " << endl;
    	        cout << "-----------" << endl << endl;
    	        cout << "\t4 .- Cargar en Arbol A desde a.txt" << endl;
    	        cout << "\t5 .- Cargar en Arbol B desde b.txt" << endl;
				cout << "\t6 .- Combinar Arbol A + B, Imprimir" << endl;
				cout << "\t7 .- Combinar Arbol B + A, Imprimir" << endl;
				cout << "\t8 .- Combinar Arbol A + B con Repetidos, Imprimir" << endl;
				cout << "\t0 .- Salir" << endl << endl;
    	        cout << "Elije una opcion: ";

    	        cin >> opc;

    	switch(opc){

    	case 1:
    cout << "Insertar en Arbol Binario: " << endl;
    cin >> ele;
    arboluno.Insertar(ele);
    break;
	case 2:
		cout << "Eliminar en Arbol Binario: " << endl;
		cin >> ele;
		//cout << "Dato retirado: " << numeros.Eliminar() <<endl;
		break;
	case 3:
		cout << "Imprimir InOrden: " << endl;
			 inOrden(arboluno,arboluno.ObtRaiz());
				break;
	case 4:
			cout << "Cargar Arbol A: " << endl;
					arbola.~Arbol();
					cargarADesdeTxt(arbola);
					inOrden(arbola,arbola.ObtRaiz());
					break;
	case 5:
			cout << "Cargar Arbol B: " << endl;
					arbolb.~Arbol();
					cargarBDesdeTxt(arbolb);
					inOrden(arbolb,arbolb.ObtRaiz());
					break;
	case 6:
			cout << "Combinar Arbol A + B, Imprimir: " << endl;
			arbolab = arbola;
			CombinarpreOrden(arbolb,arbolab,arbolb.ObtRaiz());
					inOrden(arbolab,arbolab.ObtRaiz());
					break;
	case 7:
			cout << "Combinar Arbol B + A, Imprimir: " << endl;
			arbolba = arbolb;
				CombinarpreOrden(arbola,arbolba,arbola.ObtRaiz());
				inOrden(arbolba,arbolba.ObtRaiz());
					break;
	case 8:
			cout << "Combinar Arbol A + B con Repetidos, Imprimir: " << endl;
					arbola.~Arbol();
					arbolb.~Arbol();
					cargarADesdeTxtR(arbola);
					cargarBDesdeTxtR(arbolb);
					CombinarRepetido(arbola,arbolc,arbola.ObtRaiz());
					CombinarRepetido(arbolb,arbolc,arbolb.ObtRaiz());
					inOrden(arbolc,arbolc.ObtRaiz());
					break;
	}
    }while(opc!=0);

   
    system("PAUSE");
    return EXIT_SUCCESS;
}

void cargarADesdeTxt(ArbolBB<int>& arbol){

	string line;
	int ele;
	ifstream myfile ("arbolBB/a.txt");
	if(myfile.is_open()){
		while(getline (myfile,line)){
			ele = atoi(line.c_str());
			 arbol.InsertarRecursivo(arbol.ObtRaiz(),ele);
		}
		myfile.close();
	}else{
		cout << "No puedo abrir txt";
	}
}
void cargarBDesdeTxt(ArbolBB<int>& arbol){
	string line;
	int ele;
	ifstream myfile ("arbolBB/b.txt");
	if(myfile.is_open()){
		while(getline (myfile,line)){
			ele = atoi(line.c_str());
			arbol.InsertarRecursivo(arbol.ObtRaiz(),ele);}
		myfile.close();
	}else{
		cout << "No puedo abrir txt";
	}}//else/while
void cargarADesdeTxtR(ArbolBB<int>& arbol){

	string line;
	int ele;
	ifstream myfile ("arbolBB/a.txt");
	if(myfile.is_open()){
		while(getline (myfile,line)){
			ele = atoi(line.c_str());
			 arbol.InsertarRecursivoR(arbol.ObtRaiz(),ele);
		}
		myfile.close();
	}else{
		cout << "No puedo abrir txt";
	}
}
void cargarBDesdeTxtR(ArbolBB<int>& arbol){
	string line;
	int ele;
	ifstream myfile ("arbolBB/b.txt");
	if(myfile.is_open()){
		while(getline (myfile,line)){
			ele = atoi(line.c_str());
			arbol.InsertarRecursivoR(arbol.ObtRaiz(),ele);}
		myfile.close();
	}else{
		cout << "No puedo abrir txt";
	}}//else/while
void inOrden(ArbolBB<int>& arbol, Nodo<int>* raiz){
	int simbolo;
     if(raiz!= NULL){
         inOrden(arbol,raiz->ObtIzq());
         simbolo=raiz->ObtInfo();
         cout <<simbolo << "-";
         inOrden(arbol,raiz->ObtDer());
     }
}
void postOrden(ArbolBB<int> &arbol, Apuntador raiz){
	int simbolo;
	if(raiz!= NULL){
		postOrden(arbol,raiz->ObtIzq());
		postOrden(arbol,raiz->ObtDer());
		simbolo=raiz->ObtInfo();
	    cout <<simbolo << "-";

	     }
}
void preOrden(ArbolBB<int> &arbol, Apuntador raiz){
	int simbolo;
	if(raiz!= NULL){
			simbolo=raiz->ObtInfo();
		    cout <<simbolo << "-";
		    preOrden(arbol,raiz->ObtIzq());
		    preOrden(arbol,raiz->ObtDer());

		     }
}
void CombinarpreOrden(ArbolBB<int> &arbol,ArbolBB<int> &arboldos, Apuntador raiz){
	int simbolo;
	if(raiz!= NULL){
			simbolo=raiz->ObtInfo();
		    arboldos.InsertarRecursivo(arboldos.ObtRaiz(),simbolo);
		    CombinarpreOrden(arbol,arboldos,raiz->ObtIzq());
		    CombinarpreOrden(arbol,arboldos,raiz->ObtDer());
		     }
}
void CombinarRepetido(ArbolBB<int> &arbol,ArbolBB<int> &arboldos, Apuntador raiz){
	int simbolo;
	if(raiz!= NULL){
			simbolo=raiz->ObtInfo();
		    arboldos.InsertarRecursivoR(arboldos.ObtRaiz(),simbolo);
		    CombinarRepetido(arbol,arboldos,raiz->ObtIzq());
		    CombinarRepetido(arbol,arboldos,raiz->ObtDer());
		     }
}
