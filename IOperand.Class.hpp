/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:17:47 by ydeineha          #+#    #+#             */
/*   Updated: 2019/01/29 11:17:49 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_CLASS_HPP
# define IOPERAND_CLASS_HPP

# include <string>

enum eOperandType
{
	Int8 = 0,
	Int16 = 1,
	Int32 = 2,
	Float = 3,
	Double = 4 	
};

class IOperand
{
public:

	virtual int				getPrecision(void) const = 0;
	virtual eOperandType	getType(void) const = 0;
	
	virtual IOperand const * operator+(IOperand const & rhs) const = 0;
	virtual IOperand const * operator-(IOperand const & rhs) const = 0;
	virtual IOperand const * operator*(IOperand const & rhs) const = 0;
	virtual IOperand const * operator/(IOperand const & rhs) const = 0;
	virtual IOperand const * operator%(IOperand const & rhs) const = 0;

	virtual std::string const & toString(void) const = 0;

	virtual ~IOperand(void) {}
	
};

#endif
