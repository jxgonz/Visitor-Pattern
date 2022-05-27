#ifndef __POW_HPP__
#define __POW_HPP__
#include <iostream>
#include <math.h>
using namespace std;

#include "base.hpp"
#include "op.hpp"

class Pow : public Base {
    private:
        Base* left;
	Base* right;

    public:
        Pow(Base* left, Base* right) : Base() {
            this -> left = left;
	    this -> right = right;
        }

        double evaluate() override {
	    double result = pow(this -> left -> evaluate(), this -> right -> evaluate());
	    return result;
	}

        string stringify() override {
	    string result = ("(" +  this -> left -> stringify() + " ** " + this -> right -> stringify() + ")" );
	    return result;
	}

	int number_of_children() override {
	    return 2;
	}

	Base* get_child(int i) override{
	    if (i == 0) {
		return left;
	    }
	    if (i == 1) {
		return right;
	    }
	    return nullptr;
	}

        virtual void accept(Visitor* visitor, int index) {
            if (index == 0) {
                visitor->visit_pow_begin(this);
            }
            else if (index == 1){
                visitor->visit_pow_middle(this);
            }
            else if (index == 2){
                visitor->visit_pow_end(this);
            }
        }
};

#endif //__POW_HPP__

