/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:05:46 by ydeineha          #+#    #+#             */
/*   Updated: 2019/05/01 19:05:53 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.Class.hpp"
#include "Operand.Class.hpp"

Factory::Factory() {}
Factory::~Factory() {}

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const {
    
    typedef IOperand const * (Factory::*funcptr)(std::string const &) const;
    
    funcptr array[] = {
    	&Factory::createInt8,
    	&Factory::createInt16,
    	&Factory::createInt32,
    	&Factory::createFloat,
    	&Factory::createDouble
    };

    return ((this->*array[type])(value));
}

IOperand const * Factory::createInt8( std::string const & value ) const {
    
    int num;

    num = std::stoi(value);
    if (num > 127 || num < -128)
        throw std::out_of_range("The value is out of range");
	return new Operand<char>(static_cast<char>(num), Int8, value);
}

IOperand const * Factory::createInt16( std::string const & value ) const {

    int num;

    num = std::stoi(value);
    if (num > 32767 || num < -32768)
        throw std::out_of_range("The value is out of range");
	return new Operand<short>(static_cast<short>(num), Int16, value);
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	return new Operand<int>(std::stoi(value), Int32, value);
}

IOperand const * Factory::createFloat( std::string const & value ) const {
    return new Operand<float>(std::stof(value), Float, value);
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	return new Operand<double>(std::stod(value), Double, value);
}
