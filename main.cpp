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

int		main(int argc, char **argv)
{
	std::string str;
	Avm vm;

	if (argc == 1)
	{
		while (std::getline(std::cin, str))
		{
			if (str == ";;")
				break ;
			vm.parse(str);
		}
	}
	else if (argc == 2)
	{
		std::ifstream ifs(argv[1]);
		if (ifs.is_open())
		{
			while (std::getline(ifs, str))
				vm.parse(str);
			ifs.close();
		}
		else
			std::cout << "Failure to open a file " << argv[1] << std::endl; 
	}
	else
		std::cout	<< "Too many arguments. "
					<< "Abstract VM may read from standard str or from a file "
					<< "(in this case you should pass only one argument - name of the file"
					<< std::endl;

	vm.execute();
	if (!vm.getExit())
		std::cout << "No exit instruction" << std::endl;
}
