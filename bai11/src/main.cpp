#include <iostream>
#include <memory> // Include the smart pointer library

class ComplexNumber {
private:
    double RealPart;
    double ImaginaryPart;

public:
    // Default constructor
    ComplexNumber() : RealPart(0.0), ImaginaryPart(0.0) {}

    // Parameterized constructor
    ComplexNumber(double real, double imag) : RealPart(real), ImaginaryPart(imag) {}

    // Display complex number
    void Display() {
        std::cout << "Complex number: " << RealPart << " + " << ImaginaryPart << "i" << std::endl;
    }

    // Add two complex numbers
    std::shared_ptr<ComplexNumber> Add(const std::shared_ptr<ComplexNumber>& other) {
        auto result = std::make_shared<ComplexNumber>();
        result->RealPart = RealPart + other->RealPart;
        result->ImaginaryPart = ImaginaryPart + other->ImaginaryPart;
        return result;
    }

    // Multiply two complex numbers
    std::shared_ptr<ComplexNumber> Multiply(const std::shared_ptr<ComplexNumber>& other) {
        auto result = std::make_shared<ComplexNumber>();
        result->RealPart = RealPart * other->RealPart - ImaginaryPart * other->ImaginaryPart;
        result->ImaginaryPart = RealPart * other->ImaginaryPart + ImaginaryPart * other->RealPart;
        return result;
    }
};

int main() {
    // Example usage
    auto num1 = std::make_shared<ComplexNumber>(2.5, 3.0);
    auto num2 = std::make_shared<ComplexNumber>(1.0, -2.0);

    auto sum = num1->Add(num2);
    auto product = num1->Multiply(num2);

    std::cout << "Sum of two complex numbers: ";
    sum->Display();

    std::cout << "Product of two complex numbers: ";
    product->Display();

    return 0;
}
