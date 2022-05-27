#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Sub: public Base {
    private:
       Base* left;
       Base* right;
    public:
	Sub(Base* val1, Base* val2) : Base() {
	left = val1;
	right = val2;
	}
 
        ~Sub() {
	   delete left;
	   delete right;
	}
	
	virtual double evaluate() override {
	return (this -> left -> evaluate() - this -> right -> evaluate());
	}

	virtual string stringify() {
	return ( "(" + this -> left -> stringify() + " - " + this -> right -> stringify() + ")");
	}
	
	virtual int number_of_children() {
	return 2;
	}

	virtual Base* get_child(int i) {
	if (i == 0) {
	   return left;
	}
	else if (i == 1) {
	   return right;	
	}
	   return nullptr;
	}

	// virtual void accept()
};
#endif //__SUB_HPP__
