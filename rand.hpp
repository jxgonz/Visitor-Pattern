#ifndef __RAND_HPP__
#define __RAND_HPP__
#include <iostream>
using namespace std;

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Rand : public Base {
    private:
	double value;

    public:
        Rand() : Base() {
	    srand(time(0));
	    this -> value = rand() % 100;
	}

        virtual double evaluate() {
	    return this -> value;
	}

        virtual string stringify() {
	    return to_string(this -> value);
	}

	virtual int number_of_children() {
	    return 0;
	}

	virtual Base* get_child(int i) {
	    return nullptr;
	}

	virtual void accept(Visitor* visitor, int index) {
            visitor -> visit_rand(this);
        }
};

#endif //__RAND_HPP__
