#include <iostream>

#include "../headers/factory_calculator.hpp"

int main(int argc, char** argv)
{
    factory_Calculator calc;

// Example usage of the factory creator
//    Factory f;
//    Base* expr = f.create ("+", f.create(2), f.create(3));
//    std::cout << expr->stringify() << "\n";

    Base* expr2 = calc.parse(argv, argc);
    std::cout << ((expr2 != nullptr) 
        ? expr2->stringify() + " = " + std::to_string(expr2->evaluate()) 
        : "ERROR! Invalid Input.") 
        << "\n";
  

    delete expr2;
    return 0; 
} 