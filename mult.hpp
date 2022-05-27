fndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "visitor.hpp"

using namespace std;

class Mult: public Base {
    private:
	Base* left;
        Base* right;
    public:
	Mult(Base* val1, Base* val2): Base(){
	left = val1;
	right = val2;
	}
	
	~Mult() {
	   delete left;
	   delete right;
        }

        virtual double evaluate() override {
	return (this -> left -> evaluate() * this -> right -> evaluate());
	}

	virtual string stringify() override {
	return ( "(" + this -> left -> stringify() + " * " + this -> right -> stringify() + ")");
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

	virtual void accept(Visitor* visitor, int index) {
	   if (index == 0) {
	      visitor -> visit_mult_begin(this);
	   }
	   else if (index == 1) {
	      visitor -> visit_mult_middle(this);
	   }
	   else if (index == 2) {
	      visitor -> visit_mult_end(this);
	   }
};
	
#endif //__MULT_HPP__
