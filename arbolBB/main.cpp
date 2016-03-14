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

void cargarADesdeTxt(ArbolBB<int>& arbol);
void cargarBDesdeTxt(ArbolBB<int>& arbol);
void inOrden(ArbolBB<int> &arbol, Apuntador raiz);


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

					cargarADesdeTxt(arbola);
					inOrden(arbola,arbola.ObtRaiz());
					break;
	case 5:
			cout << "Cargar Arbol B: " << endl;

					cargarBDesdeTxt(arbolb);
					inOrden(arbolb,arbolb.ObtRaiz());
					break;
	case 6:
			cout << "Combinar Arbol A + B, Imprimir: " << endl;

					break;
	case 7:
			cout << "Combinar Arbol B + A, Imprimir: " << endl;

					break;
	case 8:
			cout << "Combinar Arbol A + B con Repetidos, Imprimir: " << endl;

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
			 arbol.Insertar(ele);
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
			 arbol.Insertar(ele);
		}
		myfile.close();
	}else{
		cout << "No puedo abrir txt";
	}

}

void inOrden(ArbolBB<int>& arbol, Nodo<int>* nodo){
     if(nodo!= NULL){
         inOrden(arbol,nodo->ObtIzq());
         cout << " " <<nodo->ObtInfo() << " ";
         inOrden(arbol,nodo->ObtDer());          
     }
}
