/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Avm.Class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:31:39 by ydeineha          #+#    #+#             */
/*   Updated: 2019/01/29 13:31:41 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Avm.Class.hpp"

/* Canonical Form */

Avm::Avm(void) : _line(0) {}

Avm::~Avm(void) {}

Avm::Avm(Avm const & src) {

	*this = src;
}

//don't forget to realize equals operator
Avm & Avm::operator=(Avm const & src) {

	return *this;
}

void	Avm::parse(std::string str) {

	std::cmatch result;

	_line += 1;

	std::regex	regex_1("[ \t]*(push|assert)[ \t]+(int8|int16|int32)\\(([-]?[0-9]+)\\)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_2("[ \t]*(push|assert)[ \t]+(float|double)\\(([-]?[0-9]+\\.[0-9]+)\\)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_3("[ \t]*(pop|dump|add|sub|mul|div|mod|print|exit|min|max|average|sort_asc|sort_desc)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_4("[ \t]*;[\\w\\W]*");

	try
	{
		if (!std::regex_match(str.c_str(), result, regex_1) &&
			!std::regex_match(str.c_str(), result, regex_2) &&
			!std::regex_match(str.c_str(), result, regex_3) &&
			!std::regex_match(str.c_str(), result, regex_4))
			throw AvmException::BasicError();
	}
	catch(std::exception & e)
	{
		std::cout << "Line " << _line << " : " << e.what() << std::endl;
	}
	_str.push_back(str);

	//iterating through result
	// for(int i = 0; i < result.size(); i++)
	// {
	// 	std::cout << i << " = " << result[i] << std::endl;
	// }
}

void	Avm::execute(void) {

	std::cmatch result;
	
	std::regex	regex_1("[ \t]*(push|assert)[ \t]+(int8|int16|int32)\\(([-]?[0-9]+)\\)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_2("[ \t]*(push|assert)[ \t]+(float|double)\\(([-]?[0-9]+\\.[0-9]+)\\)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_3("[ \t]*(pop|dump|add|sub|mul|div|mod|print|exit|min|max|average|sort_asc|sort_desc)[ \t]*(;[\\w\\W]*)?");

	typedef void (Avm::*funcptr_1)(std::string, eOperandType);
	typedef void (Avm::*funcptr_2)(void);
	//std::map<std::string, void (Avm::*)(void)> my_map = {
	std::map<std::string, funcptr_1> map_1 = {
		
		{ "push",		&Avm::push		},
		{ "assert",		&Avm::avm_assert	}
	};

	std::map<std::string, funcptr_2> map_2 = {

		{ "pop",		&Avm::pop		},
		{ "add",		&Avm::add		},
		{ "sub",		&Avm::sub		},
		{ "mul",		&Avm::mul		},
		{ "div",		&Avm::div		},
		{ "mod",		&Avm::mod		},
        { "dump",		&Avm::dump		},
		{ "print",		&Avm::print		},
        { "exit",		&Avm::exit		},
		{ "min",		&Avm::min		},
		{ "max",		&Avm::max		},
		{ "average",	&Avm::average	},
		{ "sort_asc",	&Avm::sort_asc	},
		{ "sort_desc",	&Avm::sort_desc	}
	};

	for(std::vector<std::string>::iterator it = _str.begin(); 
		it != _str.end(); ++it)
	{
		if (std::regex_match(it->c_str(), result, regex_1) ||
			std::regex_match(it->c_str(), result, regex_2) ||
			std::regex_match(it->c_str(), result, regex_3))
		{
			//(this->*my_map[result[1]])();
			std::map<std::string, funcptr_1>::iterator it_map_1 = map_1.find(result[1]);
			std::map<std::string, funcptr_2>::iterator it_map_2 = map_2.find(result[1]);
			if (it_map_1 != map_1.end())
				(this->*(it_map_1->second))(result[3], getType(result[2]));
			else if (it_map_2 != map_2.end())
				(this->*(it_map_2->second))();
		}
	}
}

void	Avm::print_str(void) {
	for(std::vector<std::string>::iterator it = _str.begin(); 
		it != _str.end(); ++it)
		std::cout << *it << std:: endl;
}


eOperandType	Avm::getType(std::string type) const {

	std::map<std::string, eOperandType> map = {

		{"int8", Int8},
		{"int16", Int16},
		{"int32", Int32},
		{"float", Float},
		{"double", Double}
	};
	std::map<std::string, eOperandType>::iterator it = map.find(type);
	return (it->second);
}

void	Avm::push(std::string value, eOperandType type) {

	Factory factory;

    try {
    	_stack.push_back(factory.createOperand(type, value));
    }
    catch(std::invalid_argument & e) {
    	std::cout << e.what() << std::endl;
    }
    catch(std::out_of_range & e) {
    	std::cout << e.what() << std::endl;
    }
    catch(std::exception & e) {
    	std::cout << e.what() << std::endl;
    }
}

void	Avm::avm_assert(std::string value, eOperandType type) {std::cout << "assert is called" << std::endl; }

void	Avm::pop(void) {std::cout << "pop is called" << std::endl; }

void	Avm::add(void) {

	std::cout << "add is called" << std::endl;
	int size;

	size = _stack.size();
	if (size < 2) {
		std::cout << "Error. Need to throw exception" << std::endl;
	}
	const IOperand * operand = *(_stack[size - 1]) + *(_stack[size - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(operand);

}

void	Avm::sub(void) {std::cout << "sub is called" << std::endl; }
void	Avm::mul(void) {std::cout << "mul is called" << std::endl; }
void	Avm::div(void) {std::cout << "div is called" << std::endl; }
void	Avm::mod(void) {std::cout << "mod is called" << std::endl; }

void	Avm::dump(void) {
	
	std::cout << "dump is called" << std::endl;
	if (_stack.size() == 0)
		std::cout << "Nothing to dump. The stack is empty" << std::endl;
	else
		print_vector();
}

void	Avm::print(void) {std::cout << "print is called" << std::endl; }
void	Avm::exit(void) {std::cout << "exit is called" << std::endl; }

void	Avm::min(void) {std::cout << "min is called" << std::endl; }
void	Avm::max(void) {std::cout << "max is called" << std::endl; }
void	Avm::average(void) {std::cout << "average is called" << std::endl; }
void	Avm::sort_asc(void) {std::cout << "sort_asc is called" << std::endl; }
void	Avm::sort_desc(void) {std::cout << "sort_desc is called" << std::endl; }

void    Avm::print_vector(void) {
     for (int i = _stack.size() - 1; i >= 0 ; i--)
     {
     	std::cout << _stack[i]->toString() << std::endl;
     	//std::cout << std::stoi(_stack[i]->toString()) << std::endl;
     }
}

