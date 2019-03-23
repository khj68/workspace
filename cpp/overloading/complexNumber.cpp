#include <iostream>

using namespace std;

class Complex{
  private:
  double real;
  double imaginary;
  
  public:
  Complex() : real(0), imaginary(0){

  }

  Complex(double real, double imaginary) : real(real), imaginary(imaginary){

  }

  Complex(const Complex &other){
    *this = other;
  }

  double getReal() const{
    return real;
  }

  double getImaginary() const {
    return imaginary;
  }

  friend ostream& operator<<(ostream& out, const Complex& c){
    out << "real : " << c.getReal() << "  imaginary : " << c.getImaginary();
  }

  const Complex& operator=(const Complex& other){
    real = other.real;
    imaginary = other.imaginary;
    cout << "copy working!\n";
  }

  
};



int main(){

  Complex c1(2,3);
  Complex c2(c1);

  Complex c3;

  c3 = c2;

  cout << c1 << ": " << c3<< endl;


  return 0;
}