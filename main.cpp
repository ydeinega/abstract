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

    //argc == 1 when we read from stdin
	if (argc == 1)
	{
		while (std::getline(std::cin, str))
		{
			if (str == ";;")
				break ;
			vm.parse(str);
			// std::cout << str << std::endl;
		}
	} //argc == 2 when we read from a file
	else if (argc == 2)
	{
        //what happens when the file doesn't exist?
		std::ifstream ifs(argv[1]);
		while (std::getline(ifs, str))
		{
			vm.parse(str);
		}
        // std::cout << str << std::endl;
	}
	else
		std::cout	<< "Too many arguments. "
					<< "Abstract VM may read from standard str or from a file "
					<< "(in this case you should pass only one argument - name of the file"
					<< std::endl;

	// std::cout << "The vector elememnts are: " << std::endl;
	// for (size_t i = 0; i < vm.str.size(); i++)
	// {
	// 	std::cout << vm.str[i] << std::endl;
	// }
	//vm.print_str();
	vm.execute();
	//vm.print_vector();
}
