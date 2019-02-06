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
# include <exception>
# include <map>
//# include "IOperand.Class.hpp"
//# include "Operand.Class.hpp"
# include "AvmException.Class.hpp"

enum eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double 	
};

class Avm {

public:
	/*canonical form class*/
	Avm(void);
	Avm(Avm const & src);
	~Avm(void);
	
	Avm &	operator=(Avm const & src);


	void	push(std::string value, eOperandType type);
	void	avm_assert(std::string value, eOperandType type);
	void	pop(void);
	void	add(void);
	void	sub(void);
	void	mul(void);
	void	div(void);
	void	mod(void);
	void	dump(void);
	void	print(void);
	void	exit(void);

	/* Bonuses 5 additional commands */
	void	min(void);
	void	max(void);
	void	average(void);
	void	sort_asc(void);
	void	sort_desc(void);

	
	void	parse(std::string str);
	void	execute(void);
	void	print_str(void);
	
	eOperandType getType(std::string type) const;

private:
	int							_stack_size;//when i push an element on stack i'll add one to it
	//std::vector<IOperand> 		_stack;
	int							_line;
	std::vector<std::string>	_str;
	//vector in which i'll store all the strings
	//vector in which i'll store ioperands (when i start pushing on stack)
	
};

#endif
