/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:01:50 by ychibani          #+#    #+#             */
/*   Updated: 2023/02/21 18:22:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Vector.hpp"
#include "iterator_traits.hpp"

int	main(void)
{

	/*---------------------------------------------------*/
	/*													 */
	/*					Int	Tests						 */
	/*													 */
	/*---------------------------------------------------*/

	{
		ft::vector<int> test;
		std::vector<int> test2;

		std::vector<int> tmp(5, 12);
		// ft::vector<int> tmp2(5, 12);

		std::cout << "size ft::vector = " << test.size() << std::endl;
		std::cout << "size std::vector = " << test2.size() << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "size std::vector = " << tmp.size() << std::endl;
		// std::cout << "size ft::vector = " << tmp2.size() << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "capacity std::vector = " << tmp.capacity() << std::endl;
		std::cout << "capacity std::vector = " << tmp.capacity() << std::endl;
	
		std::cout << "capacity std::vector = " << tmp.capacity() << std::endl;
		std::cout << "max_size of std::vector = " << tmp.max_size() << std::endl;
		std::cout << "max_size of ft::vector = " << tmp.max_size() << std::endl;
		try 
		{
			// tmp2.reserve(tmp.max_size() + 1);
		}
		catch (const std::length_error &le)
		{
			std::cout << "can't reserve that much space because : " << le.what() << std::endl;
		}
		try 
		{
			tmp.reserve(tmp.max_size() + 1);
		}
		catch (const std::length_error &le)
		{
			std::cout << "can't reserve that much space because : " << le.what() << std::endl;
		}
		tmp.assign(2, 4);

		// for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
			// std::cout << *it << std::endl;
		std::cout << *tmp.begin() << std::endl;
		std::cout << tmp.capacity() << std::endl;
		tmp.reserve(100);
		std::cout << *tmp.begin() << std::endl;
		std::cout << tmp.capacity() << std::endl;
		// for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
			// std::cout << *it << std::endl;

		// tmp2.assign(12, 4);
		// for (ft::vector<int>::iterator it = tmp2.begin(); it != tmp2.end(); it++)
			// std::cout << *it << std::endl;
		// std::cout << "---------------------------------------" << std::endl;
		// for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
			// std::cout << *it << std::endl;
	}	
  	// typedef ft::iterator_traits<int*> traits;
  	// if (typeid(traits::iterator_category)==typeid(ft::random_access_iterator_tag))
   	//  std::cout << "int* is a random-access iterator";
//   return 0;
}
