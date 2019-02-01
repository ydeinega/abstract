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

const char * AvmException::BasicError::what(int line) const throw() { return(("Lexical/syntactic error or unknown instruction" + std::to_string(line)).c_str()); }
