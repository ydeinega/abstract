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

Avm::Avm(void) : _stack_size(0) {}

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
	// std::regex	regular("(?:(push|assert) (int8|int16|int32|float|double)\\(([-]?[0-9]+[\\.]?[0-9]*)\\))|\
	// 	(pop|dump|add|sub|mul|div|mod|print|exit|min|max|average|sort_asc|sort_desc)");

	//In the end comment

	std::regex	regex_1("[ \t]*(push|assert)[ \t]+(int8|int16|int32)\\(([-]?[0-9]+)\\)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_2("[ \t]*(push|assert)[ \t]+(float|double)\\(([-]?[0-9]+\\.[0-9]+)\\)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_3("[ \t]*(pop|dump|add|sub|mul|div|mod|print|exit|min|max|average|sort_asc|sort_desc)[ \t]*(;[\\w\\W]*)?");
	std::regex	regex_4("[ \t]*;[\\w\\W]*");


	//std::regex	regular("(?:(push|assert) (int8|int16|int32|float|double)\\(([-]?[0-9]+[\\.]?[0-9]*)\\))|(pop|dump|add|sub|mul|div|mod|print|exit|min|max|average|sort_asc|sort_desc)");
	
	if (std::regex_match(str.c_str(), result, regex_1) ||
		std::regex_match(str.c_str(), result, regex_2) ||
		std::regex_match(str.c_str(), result, regex_3) ||
		std::regex_match(str.c_str(), result, regex_4))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;


	for(int i = 0; i < result.size(); i++)
	{
		std::cout << i << " = " << result[i] << std::endl;
	}
}
