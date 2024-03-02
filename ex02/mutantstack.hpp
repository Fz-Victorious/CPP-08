/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:16:10 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/03 02:03:45 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <deque>
#include <stack>
#include <iostream>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:
    MutantStack(){}
    MutantStack(MutantStack const &ob){*this = ob;}
    MutantStack &operator=(MutantStack const &ob)
    {
        *(dynamic_cast< std::stack<T, Container> * >(this)) = ob;
    }
    ~MutantStack(){}

public:
    typedef typename Container::iterator iter_type;

public:
    class iterator
    {
    private:
        iter_type _iter;
        iterator(){};
    public:
        iterator(iter_type const &iter) : _iter(iter) {}
        iterator(iterator const &ob) {*this = ob;}
        iterator &operator=(iterator const &ob)
        {
            if (this != &ob)
            {
                this->_iter = ob._iter;
            }
            return (*this);
        }
        ~iterator() {}

    public:
        iterator &operator++()
        {
            this->_iter++;
            return (*this);
        }
        iterator &operator--()
        {
            this->_iter--;
            return (*this);
        }

        iterator &operator++(int)
        {
            iterator tmp = *this;
            this->_iter++;
            return (tmp);
        }

        iterator &operator--(int)
        {
            iterator tmp = *this;
            this->_iter--;
            return (tmp);
        }

        T &operator*()
        {
            return (*this->_iter);
        }

        bool operator==(const iterator &ob) const
        {
            return (this->_iter == ob._iter);
        }

        bool operator!=(const iterator &ob) const
        {
            return (this->_iter != ob._iter);
        }
    };
    iterator begin()
    {
        return (MutantStack<T, Container>::iterator(this->c.begin()));
    }
    iterator end()
    {
        return (MutantStack<T, Container>::iterator(this->c.end()));
    }
};

#endif
