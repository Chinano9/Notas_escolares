#include<iostream>

using namespace std;
class ClFecha {
  int dd;
  int mm;
  int aa;
  public:
    ClFecha(int D = 1, int M = 1, int A = 1999);
  /*Es en este lugar donde se colocan los argumentos con sus
  respectivos valores por defecto*/
  void DefineD(int);
  void DefineM(int);
  void DefineA(int);
  char * Dame(void);
};
ClFecha::ClFecha(int D, int M, int A) {
  dd = D;
  mm = M;
  aa = A;
}
void ClFecha::DefineD(int D) {
  dd = D;
}
void ClFecha::DefineM(int M) {
  mm = M;
}
void ClFecha::DefineA(int A) {
  aa = A;
}
char * ClFecha::Dame(void) {
  char * F;
  int aux;
  F = new char[11];
  F[0] = '0' + dd / 10;
  F[1] = '0' + dd % 10;
  F[2] = '/';
  F[3] = '0' + mm / 10;
  F[4] = '0' + mm % 10;
  F[5] = '/';
  F[6] = '0' + aa / 1000;
  aux = aa % 1000;
  F[7] = '0' + aux / 100;
  aux %= 100;
  F[8] = '0' + aux / 10;
  F[9] = '0' + aux % 10;
  F[10] = 0;
  return F;
}
int main() {
  ClFecha Fecha1;
  ClFecha Fecha2(13);
  ClFecha Fecha3(13, 5);
  ClFecha Fecha4(13, 5, 2000);
  cout << "Sin argumentos :" << Fecha1.Dame() << endl;
  cout << "Con 1 argumento : " << Fecha2.Dame() << endl;
  cout << "Con 2 argumentos : " << Fecha3.Dame() << endl;
  cout << "Con 3 argumentos : " << Fecha4.Dame() << endl;
  return 0;
}
