#ifndef __DIV_HPP__
#define __DIV_HPP__
#include <iostream>
using namespace std;

#include "base.hpp"
#include "op.hpp"

class Div : public Base {
    private:
        Base* left;
        Base* right;

    public:
        Div(Base* left, Base* right) : Base() {
	    this -> left = left;
	    this -> right = right;
	}

        double evaluate() override{
            return this -> left -> evaluate() / this -> right -> evaluate();
        }

        string stringify() override{
            return ("(" +  this -> left -> stringify() + " / " + this -> right -> stringify() + ")" );
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
		visitor->visit_div_begin(this);	
	    }
	    else if (index == 1){
                visitor->visit_div_middle(this);
            }
            else if (index == 2){
                visitor->visit_div_end(this);
            }
        }
};

#endif //__DIV_HPP__
