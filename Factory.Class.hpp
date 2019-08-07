/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:05:59 by ydeineha          #+#    #+#             */
/*   Updated: 2019/05/01 19:06:05 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

# include "IOperand.Class.hpp"
// # include "Operand.Class.hpp"
# include <stdexcept>

class Factory {

public:
    ~Factory();
    Factory();
    IOperand const * createOperand(eOperandType type, std::string const & value) const;


private:
    Factory(Factory const & src);
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

};

#endif
