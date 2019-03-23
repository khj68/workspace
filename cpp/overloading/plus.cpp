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

Complex operator+(const Complex& c1, const Complex& c2){
    return Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
}

Complex operator+(const Complex& c1, double d){
    return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex operator+(double d, const Complex& c1){
    return Complex(c1.getReal()+d, c1.getImaginary());
}



int main(){

  Complex c1(3,4);
  Complex c2(2,3);

  Complex c3 = c1+c2;

  cout << c1 <<endl;

  cout << c1+c2+c3 <<endl;

  Complex c4(4,2);
  Complex c5(c4+7);

  cout << c5<<endl;

  Complex c6(1,7);

  cout << 3.2+c6 << endl;

  cout << 7+c1+c2+8+9+c6 <<endl;

  return 0;
}