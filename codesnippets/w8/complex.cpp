#include <iostream>
#include <cmath>
#include <type_traits>



template <typename T>
class ComplexNumber {
private:
    T real;
    T imag;

public:
    // Constructor for types that support zero initialization
    ComplexNumber(T r = 0, T i = 0) : real(r), imag(i) {}

    // Getter functions
    T getReal() const { return real; }
    T getImag() const { return imag; }

    // Setter functions
    void setReal(T r) { real = r; }
    void setImag(T i) { imag = i; }

    // Add two complex numbers
    ComplexNumber<T> operator + (const ComplexNumber<T>& other) {
        return ComplexNumber<T>(real + other.real, imag + other.imag);
    }

    // Subtract two complex numbers
    ComplexNumber<T> operator - (const ComplexNumber<T>& other) {
        return ComplexNumber<T>(real - other.real, imag - other.imag);
    }

    ComplexNumber<T> operator- () const /* const is important*/{
        return ComplexNumber<T>( - real, - imag );
    }

    // Multiply two complex numbers
    ComplexNumber<T> operator * (const ComplexNumber<T>& other) {
        T realPart = real * other.real - imag * other.imag;
        T imagPart = real * other.imag + imag * other.real;
        return ComplexNumber<T>(realPart, imagPart);
    }

    // Divide two complex numbers
    ComplexNumber<T> operator / (const ComplexNumber<T>& other) {
        T denom = other.real * other.real + other.imag * other.imag;
        T realPart = (real * other.real + imag * other.imag) / denom;
        T imagPart = (imag * other.real - real * other.imag) / denom;
        return ComplexNumber<T>(realPart, imagPart);
    }

    // Calculate the magnitude of the complex number
    T magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Friend function to overload the << operator
    friend std::ostream& operator<< (std::ostream& os, const ComplexNumber<T>& c) {
        os << "(";
        os << c.real;
         os << " + " << c.imag << "i";
        os<<")";
        return os;
    }
};

int main() {
    // For types that support zero initialization (e.g., int, float, etc.)
    ComplexNumber<int> c1(3, 4);
    ComplexNumber<int> c2(1, 2);

    std::cout << "Complex Number 1: " << c1 << std::endl;
    std::cout << "Complex Number 2: " << c2 << std::endl;

    // Addition of complex numbers
    ComplexNumber<int> sum = c1 + 3;
    std::cout << "Sum: " << sum << std::endl;

    ComplexNumber<ComplexNumber<int>> c;

    std::cout << c;

    return 0;
}
