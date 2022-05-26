#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Add: public Base {
    private:
	Base* left;
	Base* right;
    public: 
	Add(Base* val1, Base* val2): Base(){
	left = val1;
	right = val2;
	}
	~Add() {
	    delete left;
            delete right;
	}
	double evaluate() override {
	return (this -> left -> evaluate() + this -> right -> evaluate());
	}

	string stringify() {
	return ( "(" + this -> left -> stringify() + " + " + this -> right -> stringify() + ")");
	}
	
	int number_of_children() {
	return 2;
	}

	Base* get_child(int i) {
	if (i == 0) {
	   return left;
	}
	else if (i == 1) {
	   return right;	
	}
	else if (i == 2) {
	   return nullptr;
	}
	
	// virtual void accept()
};
#endif //__ADD_HPP__

