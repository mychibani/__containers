#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstdlib>

/*
**						As a reminder, you have to comply with the C++98 standard, so any later feature of
**						the containers MUST NOT be implemented, but every C++98 feature (even deprecated
**						ones) is expected.
*/

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

		/*---------------------------------------------------*/
		/*													 */
		/*					Typenames						 */
		/*													 */
		/*---------------------------------------------------*/
			typedef size_t	size_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;

		// typedef implementation defined iterator;		// See 23.1
		// typedef implementation defined const_iterator;	// See 23.1
		// typedef implementation defined size_type;		// See 23.1
		// typedef implementation defined difference_type; // See 23.1
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef pointer iterator;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		/*---------------------------------------------------*/
		/*													 */
		/*			Constructors / Destructors			     */
		/*													 */
		/*---------------------------------------------------*/

		explicit vector(const Allocator & alloc = Allocator()) : __size(0), __value(0), __capacity(0), __allocator(alloc)
		{};

		explicit vector(size_type n, const T &value = T(),
									const Allocator & alloc = Allocator()) : __size(0), __value(0), __capacity(0), __allocator(alloc)
		{
			reserve(n);
			std::cout << __capacity << std::endl;
			assign(n, value);
		};

		/*				Besoin d'Input Iterator
		template <class InputIterator>

		vector(InputIterator first, InputIterator last,
			   const Allocator & = Allocator());
		{

		}*/

		vector(const vector<T, Allocator> &x);

		~vector()
		{
			clear();
			__allocator.deallocate(__value, 0);
		};
		vector<T, Allocator> &operator=(const vector<T, Allocator> &x);
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			insert(begin(), first, last);
		};
		void assign(size_type n, const T &u)
		{
			clear();
			insert(begin(), n, u);
		};
		allocator_type get_allocator() const
		{
			return (__allocator);
		};

		// iterators:
		iterator begin()
		{
			return (&__value[0]);
		};
		// const_iterator begin() const;
		iterator end()
		{
			return (&__value[__size]);
		};
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		/*---------------------------------------------------*/
		/*													 */
		/*					Capacity						 */
		/*													 */
		/*---------------------------------------------------*/

		size_type size() const {
			return (__size);
		};

		size_type max_size() const
		{
			return (__allocator.max_size());
		};

		void resize(size_type sz, T c = T());

		size_type capacity() const
		{
			return (__capacity);
		};
		bool empty() const
		{
			return (begin() == end());
		};
 	/**
       *  @brief  Attempt to preallocate enough memory for specified number of
       *          elements.
       *  @param  __n  Number of elements required.
       *  @throw  std::length_error  If @a n exceeds @c max_size().
       *
       *  This function attempts to reserve enough memory for the
       *  %vector to hold the specified number of elements.  If the
       *  number requested is more than max_size(), length_error is
       *  thrown.
       *
       *  The advantage of this function is that if optimal code is a
       *  necessity and the user can determine the number of elements
       *  that will be required, the user can reserve the memory in
       *  %advance, and thus prevent a possible reallocation of memory
       *  and copying of %vector data.
    */
		void reserve(size_type n)
		{
			value_type	*new_tab;
			

			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (n <= __capacity)
				return ;
			else
			{
				new_tab = __allocator.allocate(n);
				for (size_type i = 0; i < __size; i++)
				{
					__allocator.construct(new_tab + i, *(__value + i));
					__allocator.destroy(__value + i);
				}
				if (__value || __capacity)
					__allocator.deallocate(__value, sizeof(value_type) * __capacity);
			}
			__capacity = n;
			__value = new_tab;
		};

		/*---------------------------------------------------*/
		/*													 */
		/*					Element Access					 */
		/*													 */
		/*---------------------------------------------------*/

		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		const_reference at(size_type n) const;
		reference at(size_type n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		/*---------------------------------------------------*/
		/*													 */
		/*					Modifiers						 */
		/*													 */
		/*---------------------------------------------------*/

		void push_back(const T &x);
		void pop_back();
		iterator insert(iterator position, const T &x)
		{
			insert(position, )	
		};
		void insert(iterator position, size_type n, const T &x)
		{
			size_type new_size = n + __size;
			size_type tmp = position - __value;
			if (new_size > __capacity)
			{
				if (__capacity * 2 > new_size)
					reserve(__capacity);
				else
					reserve (new_size);
			}
			position = __value + tmp;
			iterator i = __value + new_size;
			
			for (; i > position; i--)
			{
				__allocator.construct(i, i - std::distance(first, last));
				__allocator.destroy(i);
			}
			for (;i > position - std::distance(first, last); i--)
				__allocator.construct(i, last--);
			__size += 1;
		};
		template <class InputIterator>
		void insert(iterator position,
					InputIterator first, InputIterator last)
		{
			size_type new_size = std::distance(first, last) + __size;
			size_type tmp = position - __value;
			if (new_size > __capacity)
			{
				if (__capacity * 2 > new_size)
					reserve(__capacity);
				else
					reserve (new_size);
			}
			position = __value + tmp;
			iterator i = __value + new_size;
			
			for (; i > position; i--)
			{
				__allocator.construct(i, i - std::distance(first, last));
				__allocator.destroy(i);
			}
			for (;i > position - std::distance(first, last); i--)
				__allocator.construct(i, last--);
			__size += 1;
		};

		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<T, Allocator> &);
		void clear()
		{
			size_type i;
			
			for (i = 0; i < __size; i++)
				__allocator.destroy(&__value[i]);
			__size = 0;
		}

		/*---------------------------------------------------*/
		/*													 */
		/*				Private Members						 */
		/*													 */
		/*---------------------------------------------------*/

		private :
			size_type __size;
			value_type *__value;
			size_type __capacity;
			allocator_type __allocator;
	};

		/*---------------------------------------------------*/
		/*													 */
		/*				Relational operators			 	 */
		/*													 */
		/*---------------------------------------------------*/
		template< class T, class Allocator>
		bool operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y);

		template <class T, class Allocator>
		bool operator<(const vector<T, Allocator> &x,
				   const vector<T, Allocator> &y);
		template <class T, class Allocator>
		bool operator!=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y);
		template <class T, class Allocator>
		bool operator>(const vector<T, Allocator> &x,
				   const vector<T, Allocator> &y);
		template <class T, class Allocator>
		bool operator>=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y);
		template <class T, class Allocator>
		bool operator<=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y);

	/*---------------------------------------------------*/
	/*													 */
	/*				Specialization Algorithm			 */
	/*													 */
	/*---------------------------------------------------*/
	template <class T, class Allocator>
	void swap(vector<T, Allocator> &x, vector<T, Allocator> &y);
};

#endif
