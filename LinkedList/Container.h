#pragma once
template <typename DataType> class Container {
public:
	Container() = default;
	virtual void add(DataType element) = 0;
	virtual size_t size() = 0;
	Container(const Container & other) = default;
	Container(Container&& other) = default;
	virtual ~Container() = default;
};

