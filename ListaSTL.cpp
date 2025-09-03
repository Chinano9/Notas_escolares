// ListaSTL.cpp: Versión usando las listas de STL
// Basado en ejemplo de listas abiertas personalizadas

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

// Plantilla de función que incrementa el valor del objeto
// dado como parámetro aplicando el operador ++
template<class DATO>
void Incrementar(DATO &d) {
   d++;
}

// Plantilla de función que mustra el valor del objeto
// dado como parámetro formando una lista separada con comas
template<class DATO>
void Mostrar(DATO &d) {
   cout << d << ", ";
}

int main() {
   // Declaración de una lista de enteros usando STL:
   list<int> ListaInt;

   // Inserción de algunos valores:
   ListaInt.push_back(43);
   ListaInt.push_back(65);
   ListaInt.push_back(33);
   ListaInt.push_back(64);
   ListaInt.push_back(22);
   ListaInt.push_back(11);

   // Mostrar lista:
   cout << "---listado---" << endl;
   for_each(ListaInt.begin(), ListaInt.end(), Mostrar<int>); // Aplicamos la función Mostrar a cada elemento
   cout << endl << "-------------" << endl;

   // Incrementamos los valores de todos los elementos de la lista
   // aplicando a cada uno la función "Incrementar":
   cout << "---Incrementar todos---" << endl;
   for_each(ListaInt.begin(), ListaInt.end(), Incrementar<int>);

   // Mostrar lista:
   cout << "---listado---" << endl;
   for_each(ListaInt.begin(), ListaInt.end(), Mostrar<int>);
   cout << endl << "-------------" << endl;
   cin.get();

   // Borrar el primer elemento de valor 34:
   cout << "borrar 34" << endl;
   ListaInt.remove(34);

   // Mostrar lista:
   cout << "---listado---" << endl;
   for_each(ListaInt.begin(), ListaInt.end(), Mostrar<int>);
   cout << endl << "-------------" << endl;

   // Declaración de una lista de floats:
   list<float> ListaFloat;

   // Inserción de algunos valores:
   ListaFloat.push_back(43.2);
   ListaFloat.push_back(65.3);
   ListaFloat.push_back(33.1);
   ListaFloat.push_back(64.8);
   ListaFloat.push_back(22.32);
   ListaFloat.push_back(11.003);

   // Mostrar lista:
   cout << "---listado---" << endl;
   for_each(ListaFloat.begin(), ListaFloat.end(), Mostrar<float>);
   cout << endl << "-------------" << endl;

   // Incrementamos todos:
   cout << "---Incrementar todos---" << endl;
   for_each(ListaFloat.begin(), ListaFloat.end(), Incrementar<float>);

   // Mostrar lista:
   cout << "---listado---" << endl;
   for_each(ListaFloat.begin(), ListaFloat.end(), Mostrar<float>);
   cout << endl << "-------------" << endl;

   cin.get();

   // Declaración de una lista de cadenas:
   list<string> ListaCad;

   // Inserción de algunos valores:
   ListaCad.push_back("alfa");
   ListaCad.push_back("delta");
   ListaCad.push_back("beta");
   ListaCad.push_back("gamma");
   ListaCad.push_back("delta");
   ListaCad.push_back("epsilon");
   ListaCad.push_back("sigma");
   ListaCad.push_back("delta");

   // Mostrar lista:
   cout << "---listado---" << endl;
   for_each(ListaCad.begin(), ListaCad.end(), Mostrar<string>);
   cout << endl << "-------------" << endl;
   cin.get();

   // Borramos todos los elementos de valor "delta":
   int count = ListaCad.size();
   ListaCad.remove("delta");
   cout << "Se borraron " << (count - ListaCad.size()) << " ocurrencias de 'delta'" << endl;

   // Mostrar lista:
   cout << "---listado---" << endl;
   for_each(ListaCad.begin(), ListaCad.end(), Mostrar<string>);
   cout << endl << "-------------" << endl;
   cin.get();

   // Buscar el primer elemento de valor "gamma":
   cout << "buscar 'gamma'" << endl;
   auto it = find(ListaCad.begin(), ListaCad.end(), "gamma");
   if(it != ListaCad.end())
      cout << *it << endl;
   else
      cout << "No encontrado" << endl;

   // Declaración de una lista de enteros:
   list<int> ListaOrden;

   // Inserción de algunos valores:
   cout << "Lista ordenada de enteros" << endl;
   ListaOrden.push_back(43);
   ListaOrden.push_back(65);
   ListaOrden.push_back(33);
   ListaOrden.push_back(64);
   ListaOrden.push_back(4);
   ListaOrden.push_back(22);
   ListaOrden.push_back(1);
   ListaOrden.push_back(11);
   ListaOrden.push_back(164);

   // Ordenamos la lista
   ListaOrden.sort();

   // Mostrar lista ordenada:
   cout << "---listado ordenado---" << endl;
   for_each(ListaOrden.begin(), ListaOrden.end(), Mostrar<int>);
   cout << endl << "-------------" << endl;

   cin.get();
   return 0;
}
