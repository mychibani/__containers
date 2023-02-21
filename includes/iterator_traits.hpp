/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:29:25 by ychibani          #+#    #+#             */
/*   Updated: 2023/02/21 13:41:3 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// namespace ft
// {
// 	template <class Iterator>
// 	struct iterator_traits
// 	{
// 		typedef typename Iterator::difference_type difference_type;
// 		typedef typename Iterator::value_type value_type;
// 		typedef typename Iterator::pointer pointer;
// 		typedef typename Iterator::reference reference;
// 		typedef typename Iterator::iterator_category iterator_category;
// 	};

// 	template <class T>
// 	struct iterator_traits<T *>
// 	{
// 		typedef std::ptrdiff_t difference_type;
// 		typedef T value_type;
// 		typedef T *pointer;
// 		typedef T &reference;
// 		typedef std::random_access_iterator_tag iterator_category;
// 	};

// 	template <class T>
// 	struct iterator_traits<const T *>
// 	{
// 		typedef std::ptrdiff_t difference_type;
// 		typedef T value_type;
// 		typedef const T *pointer;
// 		typedef const T &reference;
// 		typedef std::random_access_iterator_tag iterator_category;
// 	};

// 	template <class T>
// 	struct iterator_traits<T _ _far *>
// 	{
// 		typedef long difference_type;
// 		typedef T value_type;
// 		typedef T __far *pointer;
// 		typedef T __far &reference;
// 		typedef random_access_iterator_tag iterator_category;
// 	};
// }
