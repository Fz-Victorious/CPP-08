/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:19:17 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/03 02:01:27 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
int main()
{
    std::vector<int> vect;

	srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        const int value = rand() % 10;
        vect.push_back(value);
    }
    for (int index = 0; index < 10; ++index)
	{
		std::cout << vect[index];
		if (index != 9)
			std::cout << ',';
	}
    std::cout << std::endl;
    easyfind(vect,8);
    return 0;
}
