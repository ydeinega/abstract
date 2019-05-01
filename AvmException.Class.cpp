/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvmException.Class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:48:44 by ydeineha          #+#    #+#             */
/*   Updated: 2019/01/31 15:48:46 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AvmException.Class.hpp"

AvmException::AvmException(void) {}
AvmException::~AvmException(void) {}

const char * AvmException::BasicError::what() const throw() { 

	return("Lexical/syntactic error or unknown instruction");
}

const char * AvmException::EmptyStackError::what() const throw() { 

	return("Empty stack");
}

const char * AvmException::LessThanTwoError::what() const throw() { 

	return("Less than two members in a stack");
}

const char * AvmException::DivisionByZero::what() const throw() { 

	return("Division by zero");
}

const char * AvmException::AssertFailure::what() const throw() { 

	return("Assert failed");
}

