/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 09:35:17 by ydeineha          #+#    #+#             */
/*   Updated: 2019/01/30 09:35:19 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP
# include "IOperand.Class.hpp"

template<typename T>
class Operand : public IOperand {

public:
	Operand(void);
	//Operand(T value);it is a question what I will accept here as parameters
	Operand(Operand const & src);
	~Operand(void);

	Operand &       operator=(Operand const & src);

	int				getPrecision(void) const;
	eOperandType	getType(void) const;
	
	IOperand const * operator+(IOperand const & rhs) const;
	IOperand const * operator-(IOperand const & rhs) const;
	IOperand const * operator*(IOperand const & rhs) const;
	IOperand const * operator/(IOperand const & rhs) const;
	IOperand const * operator%(IOperand const & rhs) const;

	std::string const & toString(void) const;

	
};

#endif
