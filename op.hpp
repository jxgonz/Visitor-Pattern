#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <iostream>

using namespace std;

class Op: public Base {
    private:
	double value;
	Base* value1;
    public:
	Op(double value) : Base() {
	    this -> value = value;
	}

	~Op() {
	     delete value1;
	}

	virtual double evaluate() {
	    return this -> value;
	}

	virtual string stringify() {
	    string result = to_string(this -> value);
	    return result;
	}

	virtual Base* get_child(int i) {
	    return nullptr;
	}

	virtual int number_of_children() {
	    return 0;
	}
	//virtual void accept(Visitor* visitor, int index) {
	//	visitor -> visit_op(this);
	//	}
};
#endif //__OP_HP__
	
