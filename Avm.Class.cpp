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

Avm::Avm(void) : _stack_size(0), _line(0) {}

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

	typedef void (Avm::*funcptr)(void);
	//std::map<std::string, void (Avm::*)(void)> my_map = {
	std::map<std::string, funcptr> my_map = {
	{ "push",		&Avm::push		},
	{ "pop",		&Avm::pop		},
	{ "dump", 		&Avm::dump		}
	// { "assert",		&Avm::assert	}
	// { "add",		4 },
	// { "sub",		5 },
	// { "mul",		6 },
	// { "div",		7 },
	// { "mod",		8 },
	// { "print",		9 },
	// { "min",		10 },
	// { "max",		11 },
	// { "average",	12 },
	// { "sort_asc",	13 },
	// { "sort_desc",	14 },
	};

	for(std::vector<std::string>::iterator it = _str.begin(); 
		it != _str.end(); ++it)
	{
		if (std::regex_match(it->c_str(), result, regex_1) ||
			std::regex_match(it->c_str(), result, regex_2) ||
			std::regex_match(it->c_str(), result, regex_3))
		{
			
			//(this->*my_map[result[1]])();

			// std::map<std::string, void (Avm::*)(void)>::iterator it_map = my_map.find(result[1]);
			std::map<std::string, funcptr>::iterator it_map = my_map.find(result[1]);
			//auto func = my_map.find(result[1]);
			if (it_map != my_map.end())
			{
			//	std::cout << it_map->first << " is command" << std::endl;
				// auto func = it_map->second;
				// ::*func();
				(this->*(it_map->second))();
			}
			//iterating through result
		}
	}
}

void	Avm::print_str(void) {
	for(std::vector<std::string>::iterator it = _str.begin(); 
		it != _str.end(); ++it)
		std::cout << *it << std:: endl;
}

void	Avm::pop(void) {std::cout << "pop is called" << std::endl; }
void	Avm::dump(void) {std::cout << "dump is called" << std::endl; }
void	Avm::push(void) {std::cout << "push is called" << std::endl; }
//void	Avm::assert(void) {std::cout << "assert is called" << std::endl; }
