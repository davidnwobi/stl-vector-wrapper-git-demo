#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

template <
	typename T,
	typename Compare = std::less<T>,
	typename Allocator = std::allocator<T>>
	class container {
private:
		using vector_type = std::vector<T, Allocator>;
		vector_type m_v;
public:
	using value_type = typename vector_type::value_type;
	using allocator_type = typename vector_type::allocator_type;
	using size_type = typename vector_type::size_type;
	using difference_type = typename vector_type::difference_type;
	using const_reference = typename vector_type::const_reference;
	using const_pointer = typename vector_type::const_pointer;
	using compare_type = Compare;
 
};

