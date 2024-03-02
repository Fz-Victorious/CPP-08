/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:34:43 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/03 01:25:33 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(){}

Span::Span( unsigned int N ): _N(N){}

Span::Span( const Span & src ) { *this = src; }

Span::~Span() {}

Span & Span::operator=( const Span & ob )
{
	if (this == &ob)
		return (*this);
	this->_N = ob._N;
	this->_vec = ob._vec;
	return (*this);
}

const char* Span::NoSpan::what() const throw()
{
	return ("Span Exception: There are NO Numbers Stored, or Only One!");
}

const char* Span::NoSpaceLeft::what() const throw()
{
	return ("Span Exception: No Space Left in Container !");
}

void	Span::addNumber( int Number )
{
	if (this->_N == this->_vec.size())
		throw Span::NoSpaceLeft();
	this->_vec.push_back(Number);
}

int		Span::longestSpan()
{
	if (this->_vec.size() <= 1)
		throw Span::NoSpan();
	return (*std::max_element(this->_vec.begin(), this->_vec.end())
		- *std::min_element(this->_vec.begin(), this->_vec.end()));
}

int		Span::shortestSpan()
{
	if (this->_vec.size() <= 1)
		throw NoSpan();
	std::vector<int> sorted = this->_vec;
	std::sort(sorted.begin(), sorted.end());
	int ret = sorted[1] - sorted[0];
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		if (ret > sorted[i + 1] - sorted[i])
			ret = sorted[i + 1] - sorted[i];
	}
	return (ret);
}
