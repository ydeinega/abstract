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
# include "Factory.Class.hpp"
# include "AvmException.Class.hpp"
# include <cmath> 

template<typename T>
class Operand : public IOperand {

public:
	Operand(T value, eOperandType type, std::string str_value) : value(value), type(type), str_value(str_value) {}
	
	~Operand(void) {}
    
    Operand(Operand const & src) {
    	*this = src;
    }
	
	Operand &       operator=(Operand const & src) {
		this->type = src.getType();
		this->str_value = src.toString();
		return *this;
	}

	int				getPrecision(void) const { return type; }

	eOperandType	getType(void) const { return type; }
	
	IOperand const * operator+(IOperand const & rhs) const {

		Factory			factory;
		int				precision;
		eOperandType	type;

		precision = getPrecision() > rhs.getPrecision() ? getPrecision() : rhs.getPrecision();
		type = getPrecision() > rhs.getPrecision() ? getType() : rhs.getType();
		if (precision <= 2) {
			int calc = std::stoi(toString()) + std::stoi(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
		else {
			double calc = std::stod(toString()) + std::stod(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
	}

	IOperand const * operator-(IOperand const & rhs) const {
		
		Factory			factory;
		int				precision;
		eOperandType	type;

		precision = getPrecision() > rhs.getPrecision() ? getPrecision() : rhs.getPrecision();
		type = getPrecision() > rhs.getPrecision() ? getType() : rhs.getType();
		if (precision <= 2) {
			int calc = std::stoi(toString()) - std::stoi(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
		else {
			double calc = std::stod(toString()) - std::stod(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
	}

	IOperand const * operator*(IOperand const & rhs) const {
		
		Factory			factory;
		int				precision;
		eOperandType	type;

		precision = getPrecision() > rhs.getPrecision() ? getPrecision() : rhs.getPrecision();
		type = getPrecision() > rhs.getPrecision() ? getType() : rhs.getType();
		if (precision <= 2) {
			int calc = std::stoi(toString()) * std::stoi(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
		else {
			double calc = std::stod(toString()) * std::stod(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
	}

	IOperand const * operator/(IOperand const & rhs) const {
		
		Factory			factory;
		int				precision;
		eOperandType	type;

		precision = getPrecision() > rhs.getPrecision() ? getPrecision() : rhs.getPrecision();
		type = getPrecision() > rhs.getPrecision() ? getType() : rhs.getType();
		if (precision <= 2) {
			if (std::stoi(rhs.toString()) == 0)
				throw AvmException::DivisionByZero();
			int calc = std::stoi(toString()) / std::stoi(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
		else {
			double calc = std::stod(toString()) / std::stod(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
	}

	IOperand const * operator%(IOperand const & rhs) const {
		Factory			factory;
		int				precision;
		eOperandType	type;

		precision = getPrecision() > rhs.getPrecision() ? getPrecision() : rhs.getPrecision();
		type = getPrecision() > rhs.getPrecision() ? getType() : rhs.getType();
		if (precision <= 2) {
			if (std::stoi(rhs.toString()) == 0)
				throw AvmException::DivisionByZero();
			int calc = std::stoi(toString()) % std::stoi(rhs.toString());
			return factory.createOperand(type, std::to_string(calc));
		}
		else {
			double calc = std::fmod(std::stod(toString()), std::stod(rhs.toString()));
			return factory.createOperand(type, std::to_string(calc));
		}
		return this;
	}

	std::string const & toString(void) const {
        return str_value;
    }

    T getValue(void) const {
    	return value;
    }

private:
    Operand(void) {}
	T value;
	eOperandType type;
	std::string	str_value;
};

#endif
