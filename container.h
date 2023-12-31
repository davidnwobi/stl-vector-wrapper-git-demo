#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

template <
	typename T,
	typename Compare = std::less<T>,
	typename Allocator = std::allocator<T>>
	class container { //container class that keeps elements sorted
private:
		using vector_type = std::vector<T, Allocator>;
		vector_type m_v;

		void push_back(const T& value);
		void push_back(T&& value);

		template<typename... Args>
		void emplace_back(Args&&... args){
			m_v.emplace_back(std::forward<Args>(args)...);
			std::sort(m_v.begin(), m_v.end());
		}
public:
	using value_type = typename vector_type::value_type;
	using allocator_type = typename vector_type::allocator_type;
	using size_type = typename vector_type::size_type;
	using difference_type = typename vector_type::difference_type;
	using const_reference = typename vector_type::const_reference;
	using const_pointer = typename vector_type::const_pointer;
	using compare_type = Compare;
 

	container() noexcept(noexcept (Allocator()));
	explicit container (const Allocator& alloc) noexcept;
	container (size_type count, const T& value, const Allocator &alloc = Allocator());
	explicit container (size_type count, const Allocator &alloc = Allocator());
	container(const container& other, const Allocator& alloc = Allocator());
	container(container&& other) noexcept;
	container(container&& other, const Allocator& alloc);
	container(std::initializer_list<T> init, const Allocator& alloc = Allocator());
	~container() = default;

	//methods

	void pop_back() ;
	


	// Relevant parts from std::set
	void insert(const T& value);
	void insert(T&& value);
	template <typename... Args>
	void emplace(Args&&... args){
		m_v.emplace(std::forward<Args>(args)...);
		std::sort(m_v.begin(), m_v.end());
	}




};

template <
	typename T,
	typename Compare,
	typename Allocator>
container<T,Compare, Allocator>::container() noexcept(
	noexcept (Allocator())
	){}

template <
	typename T,
	typename Compare,
	typename Allocator>

container<T,Compare, Allocator>::container (
	const Allocator& alloc
	) noexcept : 
	m_v(alloc){}

template <
	typename T,
	typename Compare,
	typename Allocator>
container<T,Compare, Allocator>::container (
	size_type count, 
	const T& value, 
	const Allocator &alloc
	) : m_v(count,value, alloc){}

template <
	typename T,
	typename Compare,
	typename Allocator>
container<T,Compare, Allocator>::container (
	size_type count, 
	const Allocator &alloc
	) : m_v(count,alloc){}

template <
	typename T,
	typename Compare,
	typename Allocator>
container<T,Compare, Allocator>::container (
	const container& other, 
	const Allocator& alloc
	) : m_v(other.m_v, alloc){}

template <
	typename T,
	typename Compare,
	typename Allocator>
container<T,Compare, Allocator>::container (
	container&& other
	) noexcept : m_v(std::move(other.m_w)){}

template <
	typename T,
	typename Compare,
	typename Allocator>
container<T,Compare, Allocator>::container (
	container&& other, 
	const Allocator& alloc
	) : m_v(std::move(other.m_v),alloc){}

template <
	typename T,
	typename Compare,
	typename Allocator>
container<T,Compare, Allocator>::container (
	std::initializer_list<T> init, 
	const Allocator& alloc
	) : m_v(init,alloc){}

template <
	typename T,
	typename Compare,
	typename Allocator>
void container<T,Compare, Allocator>::push_back(const T& value){
	m_v.push_back(value);
	std::sort(m_v.begin(), m_v.end());
}

template <
	typename T,
	typename Compare,
	typename Allocator>
void container<T,Compare, Allocator>::push_back(T&& value){
	m_v.push_back(std::move(value));
	std::sort(m_v.begin(), m_v.end());
}

template <
	typename T,
	typename Compare,
	typename Allocator>
void container<T,Compare, Allocator>::pop_back(){
	m_v.pop_back();
}

template <
	typename T,
	typename Compare,
	typename Allocator>
void container<T,Compare, Allocator>::insert(const T& value){
	push_back(value);
}

template <
	typename T,
	typename Compare,
	typename Allocator>
void container<T,Compare, Allocator>::insert(T&& value){				
	push_back(std::move(value));
}

