#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include <iostream>
#include <string>

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "pow.hpp"

class VisitorLatex : public Visitor{
 private:
    string latex = "";
 public:
    VisitorLatex(){}

    string PrintLaTeX(Base* node){
        VisitorLatex* visit = new VisitorLatex();
	Iterator iter(node);

    	for (iter; !iter.is_done(); iter.next()){
            iter.current_node()->accept(visit, iter.current_index());
    	}

	return "$" + visit->getLatex() + "$";
    }

    string getLatex(){
        return latex;
    }

    void visit_op(Op* node) override  {
        latex = latex + "{"  + node->stringify() + "}";
    }
    void visit_rand(Rand* node) override {
        latex = latex + "{" +  node->stringify() + "}";
    }
    virtual void visit_add_begin(Add* node){
        latex = latex + "{(";
    }
    virtual void visit_add_middle(Add* node){
        latex = latex + "(+)";
    }
    virtual void visit_add_end(Add* node){
        latex = latex + ")}";
    }
    virtual void visit_sub_begin(Sub* node){
        latex = latex + "{(";
    }
    virtual void visit_sub_middle(Sub* node){
        latex = latex + "(-)";
    }
    virtual void visit_sub_end(Sub* node){
        latex = latex + ")}";
    }
    virtual void visit_mult_begin(Mult* node){
        latex = latex + "{(";
    }
    virtual void visit_mult_middle(Mult* node){
        latex = latex + "(\\cdot)";
    }
    virtual void visit_mult_end(Mult* node){
        latex = latex + ")}";
    }
    virtual void visit_div_begin(Div* node){
        latex = latex + "{\\frac"; 
    }
    virtual void visit_div_middle(Div* node){
	return;		
    }
    virtual void visit_div_end(Div* node){
        latex = latex + "}";
    }
    virtual void visit_pow_begin(Pow* node){
        latex = latex + "{(";
    }
    virtual void visit_pow_middle(Pow* node){
        latex = latex + "(^)";
    }
    virtual void visit_pow_end(Pow* node){
        latex = latex + ")}";
    }

};

#endif //__VISITORLATEX_HPP__
