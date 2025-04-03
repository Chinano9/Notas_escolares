#include <iostream>

using namespace std;
class Complejo {
  private: double real;
  double imaginario;
  public: Complejo(double = 1.0, double = 1.0);
  Complejo operator + (const Complejo & ) const;
  Complejo operator - (const Complejo & ) const;
  Complejo operator * (const Complejo & ) const;
  const Complejo & operator = (const Complejo & );
  int operator == (const Complejo & ) const;
  void mostrarComplejo() const;
};
Complejo::Complejo(double r, double ima) {
  real = r;
  imaginario = ima;
}
Complejo Complejo::operator + (const Complejo & c1) const {
  double cr, ci;
  cr = real + c1.real;
  ci = imaginario + c1.imaginario;
  return Complejo(cr, ci);
}
Complejo Complejo::operator - (const Complejo & c1) const {
  double cr, ci;
  cr = real - c1.real;
  ci = imaginario - c1.imaginario;
  return Complejo(cr, ci);
}
Complejo Complejo::operator * (const Complejo & c1) const {
  double cr, ci;
  cr = (real * c1.real) - (imaginario * c1.imaginario);
  ci = (real * c1.imaginario) + (c1.real * imaginario);
  return Complejo(cr, ci);
}
const Complejo & Complejo::operator = (const Complejo & c1) {
  real = c1.real;
  imaginario = c1.imaginario;
  return * this;
}
int Complejo::operator == (const Complejo & c1) const {
  if (real == c1.real && imaginario == c1.imaginario)
    return 1;
  else return 0;
}
void Complejo::mostrarComplejo() const {
  cout << "( " << real << " , " << imaginario << " ) " << endl;
}
int main() {
  int b;
  Complejo x, y(2.0, 8.0), z(5.0, 3.0);
  cout << "\nComplejo Y : ";
  y.mostrarComplejo();
  cout << "\nComplejo Z : ";
  z.mostrarComplejo();
  x = y + z;
  cout << "\nLa suma de los complejos Y + Z : ";
  x.mostrarComplejo();
  x = y - z;
  cout << "\nLa resta de los complejos Y - Z : ";
  x.mostrarComplejo();
  x = y * z;
  cout << "\nLa multiplicacion de los complejos Y * Z: ";
  x.mostrarComplejo();
  b = y == z;
  if (b == 1)
    cout << "\nEl numero Complejo Y es igual numero Complejo Z\n";
  else
    cout << "\nEl numero Complejo Y es diferente al numero Complejo Z\n";

  return 0;
}
