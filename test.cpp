/*

template<bool Cond, class T = void>
struct enable_if
{
};

template<class T>
struct enable_if<true, T> 
{
	typedef T type;
};


template <class T, T v>
struct integral_constant {
  static constexpr T value = v;
  typedef T value_type;
  typedef integral_constant<T,v> type;
  constexpr operator T() { return v; }
};


typedef integral_constant<bool,false> false_type;
typedef integral_constant<bool,true> true_type;


template <class T> 
struct is_integral : public false_type {};

template<> 
struct is_integral<unsigned char> : public true_type {};
*/


// template <class T> typename std::enable_if<std::is_integral<T>::value,bool>::type
// 	is_odd (T i)
// 	{
// 		return bool(i%2);
// 	}



// isodd(12) ok car type integral
// isodd(12.0) pas ok car type double

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
    int sz = 100;
    std::vector<int> v;
	std::vector<int> test;
	std::vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
		test.push_back(i);


	v.push_back(1);
	it = v.begin();
	v.insert(it + 1, test.begin(), test.end());
 
    auto cap = v.capacity();
    std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';
 
    std::cout << "\nDemonstrate the capacity's growth policy."
                 "\nSize:  Capacity:  Ratio:\n" << std::left;
    while (sz-- > 0) {
        // v.push_back(sz);
        if (cap != v.capacity()) {
            std::cout << std::setw( 7) << v.size()
                      << std::setw(11) << v.capacity()
                      << std::setw(10) << v.capacity() / static_cast<float>(cap) << '\n';
            cap = v.capacity();
        }
    }
 
    std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';
}