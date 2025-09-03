
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

template<class DATO>
void Incrementar(DATO &d) {
   d++;
}

template<class DATO>
void Mostrar(DATO &d) {
   cout << d << ", ";
}

int main() {
   list<int> ListaInt;

   ListaInt.push_back(43);
   ListaInt.push_back(65);
   ListaInt.push_back(33);
   ListaInt.push_back(64);
   ListaInt.push_back(22);
   ListaInt.push_back(11);

   cout << "---listado---" << endl;
   for_each(ListaInt.begin(), ListaInt.end(), Mostrar<int>);
   cout << endl << "-------------" << endl;

   cout << "---Incrementar todos---" << endl;
   for (auto &elemento : ListaInt) {
      Incrementar(elemento);
   }

   cout << "---listado---" << endl;
   for (auto &elemento : ListaInt) {
      Mostrar(elemento);
   }
   cout << endl << "-------------" << endl;
   cin.get();

   cout << "borrar 34" << endl;
   ListaInt.remove(34);

   cout << "---listado---" << endl;
   for (auto &elemento : ListaInt) {
      Mostrar(elemento);
   }
   cout << endl << "-------------" << endl;

   list<float> ListaFloat;

   ListaFloat.push_back(43.2);
   ListaFloat.push_back(65.3);
   ListaFloat.push_back(33.1);
   ListaFloat.push_back(64.8);
   ListaFloat.push_back(22.32);
   ListaFloat.push_back(11.003);

   cout << "---listado---" << endl;
   for (auto &elemento : ListaFloat) {
      Mostrar(elemento);
   }
   cout << endl << "-------------" << endl;

   cout << "---Incrementar todos---" << endl;
   for (auto &elemento : ListaFloat) {
      Incrementar(elemento);
   }

   cout << "---listado---" << endl;
   for (auto &elemento : ListaFloat) {
      Mostrar(elemento);
   }
   cout << endl << "-------------" << endl;

   cin.get();

   list<string> ListaCad;

   ListaCad.push_back("alfa");
   ListaCad.push_back("delta");
   ListaCad.push_back("beta");
   ListaCad.push_back("gamma");
   ListaCad.push_back("delta");
   ListaCad.push_back("epsilon");
   ListaCad.push_back("sigma");
   ListaCad.push_back("delta");

   cout << "---listado---" << endl;
   for (auto &elemento : ListaCad) {
      Mostrar(elemento);
   }
   cout << endl << "-------------" << endl;
   cin.get();

   int count = ListaCad.size();
   ListaCad.remove("delta");
   cout << "Se borraron " << (count - ListaCad.size()) << " ocurrencias de 'delta'" << endl;

   cout << "---listado---" << endl;
   for (auto &elemento : ListaCad) {
      Mostrar(elemento);
   }
   cout << endl << "-------------" << endl;
   cin.get();

   cout << "buscar 'gamma'" << endl;
   auto it = find(ListaCad.begin(), ListaCad.end(), "gamma");
   if(it != ListaCad.end())
      cout << *it << endl;
   else
      cout << "No encontrado" << endl;

   list<int> ListaOrden;

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

   ListaOrden.sort();

   cout << "---listado ordenado---" << endl;
   for (auto &elemento : ListaOrden) {
      Mostrar(elemento);
   }
   cout << endl << "-------------" << endl;

   cin.get();
   return 0;
}
