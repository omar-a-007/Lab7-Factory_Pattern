#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

// Your main executable should be named calculator and should take the char** argv and the int argc input to main and pass it to the factory. 
// The factory should then convert it to an expression tree, and then you should print the stringify() and evaluate() values of the generated expression tree back to the user.

#include <map>
#include <queue>

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

/*
class abstractFactory {
	public:
		abstractFactory() { }
		virtual ~abstractFactory() { }
		virtual Base* create() = 0;
		virtual Base* create(double value) = 0;
		virtual Base* create(const std::string& comp, Base* x, Base* y) = 0;
};
*/
class Factory /*: public abstractFactory */ {
	public:
		Base* create()  			{ return new Rand();}
		Base* create(double value)  { return new Op(value); }
		Base* create(const std::string& comp, Base& x, Base& y) 
		{
			/*
			std::map<std::string, Base*> map_CreateFuncs = {
				{ "+", new Add(x,y) },
				{ "-", new Sub(x,y) },
				{ "*", new Mult(x,y) },
				{ "/", new Div(x,y) },
				{ "**", new Pow(x,y) }
			};
			auto found = map_CreateFuncs.find(comp);
			return found != map_CreateFuncs.end() ? found->second : nullptr;
			*/

			     if (comp == "+")  return new Add(x,y);
			else if (comp == "-")  return new Sub(x,y);
			else if (comp == "*")  return new Mult(x,y);
			else if (comp == "/")  return new Div(x,y);
			else if (comp == "**") return new Pow(x,y);
			else return nullptr;
		}
};


class factory_Calculator
{
	private:
		Base* getPop(std::queue<Base*>& q) {
			Base* r =  q.size() == 0 ? nullptr : q.front();
			q.pop();
			return r;
		};
		std::string getPop(std::queue<std::string>& q) {
			std::string r =  q.size() == 0 ? "" : q.front();
			q.pop();
			return r;
		};

		Factory factory;
		Base* create(char** operation);
		bool isDouble(const std::string& s) {
			try{std::stod(s); return true;  }
			catch (...)		 {return false; }
		}
	public:
		Base* parse(char** operations, int qty);
};

#endif