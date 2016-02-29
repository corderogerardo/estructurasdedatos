#include <cstdlib>
#include <iostream>
#include "ArbolBB.h"
#include "Nodo.h"

using namespace std;

ArbolBB<int> arbolbb;
int ele;
void imprimirArbolInOrden(ArbolBB<int>& arbol, Nodo<int>* nodo);

int main()
{
    int pos;
	int opc;

    do{
    	 system("cls");
    	        cin.clear();
    	        cout << "Arboles " << endl;
    	        cout << "-----------" << endl << endl;
    	        cout << "\t1 .- Insertar en arbol" << endl;
    	        cout << "\t2 .- Eliminar en arbol" << endl;
    	        cout << "\t3 .- Imprimir inOrden" << endl;
    	        cout << "\t0 .- Salir" << endl << endl;
    	        cout << "Elije una opcion: ";

    	        cin >> opc;

    	switch(opc){
    	case 1:
			cout << "Insertar en Arbol: " << endl;
			cin >> ele;
			arbolbb.Insertar(ele);
			break;
		case 2:
			cout << "Eliminar en arbol el siguiente nodo: " << endl;
			cin >> ele;
			//cout << "Dato retirado: " << arbolbb.Eliminar(ele)<<endl;
			break;
		case 3:
			cout << "Imprimir inOrden: " << endl;
			//cout << cola1.cuantos_hay() <<endl;
			break;
	}
    }while(opc!=0);

    return 0;
}
