/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:28:22 by ydeineha          #+#    #+#             */
/*   Updated: 2019/01/29 11:28:24 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Avm.Class.hpp"
//I need to write a function getnextline which will read a line and return it

int		main(int argc, char **argv)
{
	std::string str;
	Avm vm;

	if (argc == 1)
	{
		//here it is different i need to check for ;; - it is end of str
		//I will look for it in the string later maybe
		while (std::getline(std::cin, str))
		{
			
			if (str == ";;")
				break ;
			vm.str.push_back(str);
			// std::cout << str << std::endl;
		}
	}
	else if (argc == 2)
	{
		std::ifstream ifs(argv[1]);
		while (std::getline(ifs, str))
			vm.str.push_back(str);
			// std::cout << str << std::endl;
	}
	else
		std::cout	<< "Too many arguments. "
					<< "Abstract VM may read from standard str or from a file "
					<< "(in this case you should pass only one argument - name of the file"
					<< std::endl;

	std::cout << "The vector elememnts are: " << std::endl;
	for (size_t i = 0; i < vm.str.size(); i++)
	{
		std::cout << vm.str[i] << std::endl;
	}
}
