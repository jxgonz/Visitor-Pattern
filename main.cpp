#include <iostream>

#include "visitor.hpp"
#include "VisitorLatex.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "div.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* rand = new Rand();
   
    Base* div = new Div(four, two);
    Base* power = new Pow(four, two);
    Base* rand_test = new Pow(four, rand);
    Base* long_eq = new Div(power, rand_test);

    std::cout << div->stringify() << " = " << div->evaluate() << std::endl;
    std::cout << power->stringify() << " = " << power->evaluate() << std::endl;
    std::cout << rand_test->stringify() << " = " << rand_test->evaluate() << std::endl;
    std::cout << long_eq->stringify() << " = " << long_eq->evaluate() << std::endl << std::endl;


    VisitorLatex* test1  = new VisitorLatex();
    cout << test1->PrintLaTeX(div) << endl;

    VisitorLatex* test2 = new VisitorLatex();
    cout << test2->PrintLaTeX(power) << endl;

    VisitorLatex* test3 = new VisitorLatex();
    cout << test3->PrintLaTeX(rand_test) << endl;

    VisitorLatex* test4 = new VisitorLatex();
    cout << test4->PrintLaTeX(long_eq) << endl;

    delete test1;
    delete test2;
    delete test3;
    delete test4;
    delete three;
    delete seven;
    delete four;
    delete two;
    delete rand;

    delete div;
    delete power;
    delete rand_test;
    delete long_eq;

    return 0;
}
