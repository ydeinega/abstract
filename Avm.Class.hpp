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
# include <regex>
//# include "IOperand.Class.hpp"
//# include "Operand.Class.hpp"

class Avm {

public:
	/*canonical form class*/
	Avm(void);
	Avm(Avm const & src);
	~Avm(void);
	
	Avm &	operator=(Avm const & src);

/*
	void	push(std::string value);//here maybe i will need other things to accept
	void	pop(void);
	void	dump(void) const;
	void	assert(std::string value) const;
	void	add(void);
	void	sub(void);
	void	mul(void);
	void	div(void);
	void	mod(void);
	void	print(void) const;
	void	exit(void) const;

	// Bonuses 5 additional commands
	void	min(void) const;
	void	max(void) const;
	void	average(void) const;
	void	sort_asc(void);
	void	sort_desc(void);

	
*/
	void	parse(std::string str);

	std::vector<std::string> str;
	//std::vector<IOperand> stack;
private:
	int	_stack_size;//when i push an element on stack i'll add one to it
	
	//vector in which i'll store all the strings
	//vector in which i'll store ioperands (when i start pushing on stack)
	
};

#endif
