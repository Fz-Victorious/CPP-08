/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:19:05 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/03 02:01:21 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

template <typename T>
bool easyfind(T x,int y)
{
    if (std::find(x.begin(), x.end(), y) != x.end())
    {
        std::cout << "the first occurrence founded" << std::endl;
        return (true);
    }
    else
    {
        std::cout << "the first occurrence not found" << std::endl;
        return (false);
    }
}
