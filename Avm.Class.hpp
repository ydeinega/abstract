/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Avm.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:31:26 by ydeineha          #+#    #+#             */
/*   Updated: 2019/01/29 13:31:28 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_CLASS_HPP
# define AVM_CLASS_HPP

# include <vector>
# include <string>
# include <fstream>
# include <iostream>

class Avm {

public:
	//canonical form class
	Avm();
	Avm(Avm const & src);
	~Avm();
	Avm & operator=(Avm const & src);

	std::vector<std::string> str;
private:
	int	_stack_size;//when i push an element on stack i'll add one to it
	
	//vector in which i'll store all the strings
	//vector in which i'll store ioperands (when i start pushing on stack)
	
};

#endif
