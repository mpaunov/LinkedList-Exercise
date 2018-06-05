#pragma once
#include "Container.h"
#include <ostream>

template <typename DataType> class LinkedList : public Container<DataType> {
private:
	class Node {
	public:
		DataType element;
		Node * next;

		Node();

		Node(Node& other);

		Node& operator=(const Node& other);

		Node(DataType element);

		Node(DataType element, Node* next);
		~Node();

		friend std::ostream& operator<<(std::ostream& ostream, const Node& other) {
			ostream << other.element;
			return ostream;
		}
	};

	Node* head;
	Node* tail;
	size_t items = 0;
public:
	class Iterator {
	private:
		Node * ptr;
	public:
		Iterator(Node* ptr);

		Iterator& operator=(const Node* other) const;

		Iterator operator++();

		Iterator& operator++(int);

		bool operator !=(const Iterator& other) const;

		bool operator ==(const Iterator& other) const;

		DataType& operator*();
		~Iterator();
	};
public:
	LinkedList();

	LinkedList(const LinkedList& other);

	LinkedList(LinkedList&& other) noexcept;

	LinkedList& operator=(LinkedList&& other) noexcept;

	LinkedList& operator=(const LinkedList& other);

private:
	bool operator!=(const LinkedList& other) const;
public:
	LinkedList & operator()(LinkedList& other);

	~LinkedList();

	void add(DataType element) override;

	Iterator begin();

	Iterator end();

	size_t size() override;
};

template <typename DataType>
LinkedList<DataType>::Node::Node() :
	next(nullptr) {
}

template <typename DataType>
LinkedList<DataType>::Node::Node(Node& other) {
	this->element = other.element;
	this->next = other.next;

	return *this;
}

template <typename DataType>
LinkedList<DataType>::Node::Node(DataType element) :
	element(std::move(element)),
	next(nullptr) {
}

template <typename DataType>
LinkedList<DataType>::Node::Node(DataType element, Node* next) :
	element(element),
	next(next) {
}

template <typename DataType>
LinkedList<DataType>::Node::~Node() = default;

template <typename DataType>
LinkedList<DataType>::Iterator::Iterator(Node* ptr) :
	ptr(ptr) {
}

template <typename DataType>
typename LinkedList<DataType>::Iterator& LinkedList<DataType>::Iterator::operator=(const Node* other) const {
	return this->ptr = other->next;
}

template <typename DataType>
typename LinkedList<DataType>::Iterator LinkedList<DataType>::Iterator::operator++() {
	return this->ptr = this->ptr->next;
}

template <typename DataType>
typename LinkedList<DataType>::Iterator& LinkedList<DataType>::Iterator::operator++(int) {
	Iterator temp = this->ptr;
	this->ptr = this->ptr->next;
	return temp;
}

template <typename DataType>
bool LinkedList<DataType>::Iterator::operator!=(const Iterator& other) const {
	return this->ptr != other.ptr;
}

template <typename DataType>
bool LinkedList<DataType>::Iterator::operator==(const Iterator& other) const {
	return this->ptr == other.ptr;
}

template <typename DataType>
DataType& LinkedList<DataType>::Iterator::operator*() {
	return this->ptr->element;
}

template <typename DataType>
LinkedList<DataType>::Iterator::~Iterator() = default;

template <typename DataType>
LinkedList<DataType>::LinkedList() :
	head(nullptr),
	tail(nullptr),
	items(0) {
}

template <typename DataType>
LinkedList<DataType>::LinkedList(const LinkedList& other) {
	std::cout << "Copy Assignment Ctor Called" << std::endl;
	if (*this != other) {
		this->head = nullptr;
		this->tail = nullptr;
		this->items = 0;

		Node* current = other.head;
		while (current != nullptr) {
			this->LinkedList<DataType>::add(current->element);
			current = other.head->next;
		}
	}
}

template <typename DataType>
LinkedList<DataType>::LinkedList(LinkedList&& other) noexcept :
	head(nullptr),
	tail(nullptr),
	items(0){
	std::cout << "Move Ctor Called" << std::endl;

	this->head = other.head;
	this->tail = other.tail;
	this->items = other.items;

	other.head = nullptr;
	other.tail = nullptr;
	items = 0;
}

template<typename DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(LinkedList&& other) noexcept {
	std::cout << "Move Assingment operator called" << std::endl;
	if (this != &other) {
		while (this->head != nullptr) {
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
		this->head = other.head;
		this->tail = other.head;
		this->items = other.items;

		other.head = nullptr;
		other.tail = nullptr;
		other.items = 0;

		return *this;
	}
	return *this;
}

template <typename DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList& other) {
	if (*this != other) {
		while (this->head != nullptr) {
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
		Node* current = other.head;
		while (current != nullptr) {
			this->add(current->element);
			current = current->next;
		}
	}
	return *this;
}

template <typename DataType>
bool LinkedList<DataType>::operator!=(const LinkedList& other) const {
	return this->head != other.head && this->tail != other.tail;
}

template <typename DataType>
LinkedList<DataType>& LinkedList<DataType>::operator()(LinkedList& other) {
	if (*this != other) {
		while (this->head != nullptr) {
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
		Node* current = other.head;
		while (current != nullptr) {
			this->add(current->element);
			current = current->next;
		}
	}
	return *this;
}

template <typename DataType>
LinkedList<DataType>::~LinkedList() {

	std::cout << "Destructor Called" << std::endl;
	while (this->head != nullptr) {
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
}

template <typename DataType>
void LinkedList<DataType>::add(DataType element) {
	auto* newNode = new Node(element);

	if (this->items > 0 && (this->tail != nullptr && this->head != nullptr)) {
		this->tail->next = newNode;
		this->tail = newNode;
	}
	else {
		this->head = newNode;
		this->tail = newNode;
	}
	++this->items;
}

template <typename DataType>
typename LinkedList<DataType>::Iterator LinkedList<DataType>::begin() {
	return Iterator(this->head);
}

template <typename DataType>
typename LinkedList<DataType>::Iterator LinkedList<DataType>::end() {
	return Iterator(nullptr);
}

template <typename DataType>
size_t LinkedList<DataType>::size() {
	return this->items;
}

template<typename DataType>
typename LinkedList<DataType>::Node & LinkedList<DataType>::Node::operator=(const Node & other) {
	this->element = other.element;
	this->next = other.next;
	return  *this;
}