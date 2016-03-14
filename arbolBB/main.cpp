#include <iostream>
#include <cstdio>
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
    	        cout << "\t4 .- Insertar en Arbol A" << endl;
    	        cout << "\t4 .- Insertar en Arbol B" << endl;
				cout << "\t5 .- Eliminar en Arbol Binario" << endl;
				cout << "\t6 .- Imprimir InOrden" << endl;
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

	}
    }while(opc!=0);

   
    system("PAUSE");
    return EXIT_SUCCESS;
}

void inOrden(ArbolBB<int>& arbol, Nodo<int>* nodo){
     if(nodo!= NULL){
         inOrden(arbol,nodo->ObtIzq());
         cout << " " <<nodo->ObtInfo() << " ";
         inOrden(arbol,nodo->ObtDer());          
     }
}
