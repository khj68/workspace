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

bool operator==(const Complex& c1, const Complex& c2){
  if(c1.getReal() == c2.getReal() && c1.getImaginary() == c2.getImaginary()){
    return true;
  }else{
    return false;
  }
}

bool operator!=(const Complex& c1, const Complex& c2){
  if(c1.getReal() == c2.getReal() && c1.getImaginary() == c2.getImaginary()){
    return false;
  }else{
    return true;
  }
}


int main(){

  Complex c1(3,2);
  Complex c2(3,2);

  if(c1 != c2){
    cout << "not equal" <<endl;
  }else{
    cout << " equal" << endl;
  }
  

  return 0;
}