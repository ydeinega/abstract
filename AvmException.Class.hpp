/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvmException.Class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:01:42 by ydeineha          #+#    #+#             */
/*   Updated: 2019/01/31 11:01:44 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVMEXCEPTION_CLASS_HPP
# define AVMEXCEPTION_CLASS_HPP
# include <exception>
# include <string>

class AvmException {

public:
	AvmException();
	~AvmException();

	class BasicError : public std::exception {

	public:
		virtual const char *what() const throw();
	};
	
	class EmptyStackError : public std::exception {

	public:
		virtual const char *what() const throw();
	};

	class LessThanTwoError : public std::exception {

	public:
		virtual const char *what() const throw();
	};

	class DivisionByZero : public std::exception {

	public:
		virtual const char *what() const throw();
	};

	class AssertFailure : public std::exception {

	public:
		virtual const char *what() const throw();
	};
};

#endif
