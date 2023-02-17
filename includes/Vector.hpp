#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

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
		{
		};

		explicit vector(size_type n, const T &value = T(),
									const Allocator & alloc = Allocator()) : __size(n), __value(0), __capacity(n), __allocator(alloc)
		{
			std::cout << "Fill Constructor Called" << std::endl;
			// construct
			reserve(n);
			assign(n, value);
		};
		
		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,
		// 	   const Allocator & = Allocator());
		// vector(const vector<T, Allocator> &x);
		~vector()
		{
			delete __value;
		};
		vector<T, Allocator> &operator=(const vector<T, Allocator> &x);
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			(void) first;
			(void) last;
		};
		void assign(size_type n, const T &u)
		{
			size_type	i;

			i = 0;
			while (i < n)
			{
				__allocator.construct(&__value[i], u);
				i++;
			}
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
		bool empty() const;

		void reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (!n)
				__value = __allocator.allocate(1);
			else
				__value = __allocator.allocate(n);
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
		// iterator insert(iterator position, const T &x);
		// void insert(iterator position, size_type n, const T &x);
		// template <class InputIterator>
		// void insert(iterator position,
		// 			InputIterator first, InputIterator last);
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);
		void swap(vector<T, Allocator> &);
		void clear();

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
