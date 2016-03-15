#include "ArbolBB.h"


template <class Tipo>
Nodo<Tipo>* ArbolBB<Tipo>::Buscar(Nodo<Tipo>* p,Tipo valor)
{
  Tipo auxiliar;      
   
  while (p!=NULL)
     {
        auxiliar=p->ObtInfo();
        if (valor==auxiliar)
             return p;
       else 
           if (valor<auxiliar) 
              p=p->ObtIzq();
           else  
              p=p->ObtDer();
      };
  return NULL;      
};

//Buscar que sea recursivo:
template <class Tipo>
Nodo<Tipo>* ArbolBB<Tipo> :: BuscarRecursivo(Nodo<Tipo>* p, Tipo valor) {

      if (p!=NULL){
          if (valor==p->ObtInfo()){
                return p;
                }        
          else if (valor<p->ObtInfo()){
               return BuscarRecursivo(p->ObtIzq(),valor);
               }           
          else return BuscarRecursivo(p->ObtDer(),valor);
          }
      else return NULL;
    };

template <class Tipo>
bool ArbolBB<Tipo>::Insertar(Tipo valor)
{
  Apuntador p,nuevo,ant;
  Tipo auxiliar;
  
  nuevo=this->CrearNodo(valor);
  if (Arbol<Tipo>::ObtRaiz()==NULL)        
	    this->AsigRaiz(nuevo);
  else
  {
  p=Arbol<Tipo>::ObtRaiz();     	    
  while (p!=NULL)
    {     
      auxiliar=p->ObtInfo();      
      if  (valor==auxiliar)
           return false;  
else
    if  (valor<auxiliar)
           {    	 
             ant=p;     
             p=p->ObtIzq();
             if (p==NULL)
               this->InsIzquierdo(ant,valor);
           }    
        else
          {
             ant=p;
             p=p->ObtDer();
             if (p==NULL) 
               this->InsDerecho(ant,valor);
           };
     };
  };	
  return true;	
};


//InsertarRecursivo, este metodo no permite actualizar la raiz!:
template <class Tipo>
bool ArbolBB<Tipo>::InsertarRecursivo(Nodo<Tipo>* p, Tipo valor){
     
     Tipo auxiliar;

     Nodo<Tipo>* nuevo;
     if (Arbol<Tipo>::ObtRaiz()==NULL)  
      {     
        nuevo=this->CrearNodo(valor);
	    this->AsigRaiz(nuevo);
	    return true;
      }
     else {
          auxiliar = p->ObtInfo();
          if (valor==auxiliar) return false;
          else if (valor < auxiliar) {
               if (p->ObtIzq()==NULL) {
                   this->InsIzquierdo(p,valor);
                   return true;
                   }
               else InsertarRecursivo(p->ObtIzq(),valor);
               }
          else
              if (p->ObtDer()==NULL) {
                 this->InsDerecho(p,valor);
                 return true;
                 }
              else InsertarRecursivo(p->ObtDer(),valor);
          }
     };

//InsertarRecursivo, este metodo no permite actualizar la raiz!:
template <class Tipo>
bool ArbolBB<Tipo>::InsertarRecursivoR(Nodo<Tipo>* p, Tipo valor){

     Tipo auxiliar;

     Nodo<Tipo>* nuevo;
     if (Arbol<Tipo>::ObtRaiz()==NULL)
      {
        nuevo=this->CrearNodo(valor);
	    this->AsigRaiz(nuevo);
	    return true;
      }
     else {
          auxiliar = p->ObtInfo();
          if (valor < auxiliar) {
               if (p->ObtIzq()==NULL) {
                   this->InsIzquierdo(p,valor);
                   return true;
                   }
               else InsertarRecursivoR(p->ObtIzq(),valor);
               }
          else
              if (p->ObtDer()==NULL) {
                 this->InsDerecho(p,valor);
                 return true;
                 }
              else InsertarRecursivoR(p->ObtDer(),valor);
          }
     };


template <class Tipo>
bool ArbolBB<Tipo>::Eliminar(Tipo &valor)
{
  Apuntador p,ant,temp;
  bool encontrado;
  Tipo auxiliar;
  p=Arbol<Tipo>::ObtRaiz(); 
  encontrado=false;
  while ((p!=NULL) && !(encontrado)) {
     auxiliar=p->ObtInfo();
   if  (valor==auxiliar)
	    encontrado=true;
     else {
           ant=p; //El padre de p
           if (valor< auxiliar)
                 p=p->ObtIzq();
          else 
                 p=p->ObtDer();
       };
   };
if (encontrado)   {   //la Clave esta en el arbol
        temp=p;   //Apuntador cuyo nodo va a ser eliminado       	            
        valor=auxiliar;     
         if (p->ObtDer()==NULL) {  //Tiene un posible Hijo Izquierdo:   
              if (p==Arbol<Tipo>::ObtRaiz())  //Caso Raiz
                AsigRaiz(p->ObtIzq());	         //Asigna el hijo izquierdo como Raiz	
              else    //Se actualiza el Der o Izq del padre seg�n sea el caso
                if (ant->ObtIzq()==p)  ant->AsigIzq(p->ObtIzq());
                else                    ant->AsigDer(p->ObtIzq());
        }
        else if (p->ObtIzq()==NULL) { 	 //Tiene un posible Hijo Derecho:
              if (p==Arbol<Tipo>::ObtRaiz()) //Caso Raiz
                 AsigRaiz(p->ObtDer()); //Asigna el hijo derecho como Raiz	
              else //Se actualiza el Der o Izq del padre seg�n sea el caso
            	  if (ant->ObtIzq()==p) ant->AsigIzq(p->ObtDer());
                  else  ant->AsigDer(p->ObtDer());

}
else  {	              // Caso dos hijos:				
                ant=p;
              //El nodo a eliminar ser� el mas a la derecha del subarbol izquierdo
                temp=p->ObtIzq(); 
                while (temp->ObtDer()!=NULL) {
                	    ant=temp;
                	    temp=temp->ObtDer();       
                   };
                 auxiliar=temp->ObtInfo();
                 p->AsigInfo(auxiliar);
                 if (ant==p)       ant-> AsigIzq(temp->ObtIzq());
                 else              ant-> AsigDer(temp->ObtIzq());
              };
           //Sucede para cualquiera de los tres casos
           delete temp;
           return true;    
           }
   else return false;    //En caso de que la clave no se encuentre!
};
     
/*
template <class Tipo>
bool ArbolBB<Tipo>::Eliminar(Tipo &valor)
{
  Apuntador p,ant,temp;
  bool encontrado;
  Tipo auxiliar;
  p=Arbol<Tipo>::ObtRaiz(); 
  encontrado=false;
  while ((p!=NULL) && !(encontrado)) {
     auxiliar=p->ObtInfo();
     if  (valor==auxiliar)
	    encontrado=true;
     else {
           ant=p; //El padre de p
           if (valor< auxiliar) 
                 p=p->ObtIzq();
          else 
                 p=p->ObtDer();
       };
   };
if (encontrado)   {   //la Clave esta en el arbol
        temp=p;   //Apuntador cuyo nodo va a ser eliminado       	            
        valor=auxiliar;     
         if (p->ObtDer()==NULL) {  //Tiene un posible Hijo Izquierdo:   
              if (p==Arbol<Tipo>::ObtRaiz())  //Caso Raiz
                AsigRaiz(p->ObtIzq());	         //Asigna el hijo izquierdo como Raiz	
              else    //Se actualiza el Der o Izq del padre seg�n sea el caso
                if (ant->ObtIzq()==p)  ant->AsigIzq(p->ObtIzq());
                else                    ant->AsigDer(p->ObtIzq());
        }
        else if (p->ObtIzq()==NULL) { 	 //Tiene un posible Hijo Derecho:
              if (p==Arbol<Tipo>::ObtRaiz()) //Caso Raiz
                 AsigRaiz(p->ObtDer()); //Asigna el hijo derecho como Raiz	
              else //Se actualiza el Der o Izq del padre seg�n sea el caso
            	  if (ant->ObtIzq()==p) ant->AsigIzq(p->ObtDer());
                  else  ant->AsigDer(p->ObtDer());

}
else  {	              // Caso dos hijos:				
                ant=p;
              //El nodo a eliminar ser� el mas a la derecha del subarbol izquierdo
                temp=p->ObtIzq(); 
                while (temp->ObtDer()!=NULL) {
                	    ant=temp;
                	    temp=temp->ObtDer();       
                   };
                 auxiliar=temp->ObtInfo();
                 p->AsigInfo(auxiliar);
                 if (ant==p)       ant->AsigIzq(temp->ObtIzq());
                 else              ant->AsigDer(temp->ObtIzq());
              };
           //Sucede para cualquiera de los tres casos
           delete temp;
           return true;    
           }
   else return false;    //En caso de que la clave no se encuentre!
};
*/
