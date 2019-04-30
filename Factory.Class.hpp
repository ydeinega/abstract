//
// Created by Yuliia Deineha on 4/25/19.
//

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
