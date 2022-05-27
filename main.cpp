#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"

#include "visitor.hpp"
#include "iterator.hpp"

int main() {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(seven, two);

    std::cout << add->stringify() << " = " << add->evaluate() << std::endl;
    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    std::cout << mult->stringify() << " = " << mult->evaluate() << std::endl;

    delete three;
    delete seven;
    delete four;
    delete two;
    
    delete mult;
    delete add;
    delete minus;

    return 0;
}
