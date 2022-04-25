#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{

	}
	~Vector()
	{
		if (_data)
		{
			delete[] _data;
		}

	}
	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
			{
				++newCapacity;
			}

			reserve(newCapacity);
		}

		_data[_size] = value;

		++_size;
	}
	void reserve(int capacity)
	{
		if (_capacity >= capacity)
		{
			return;
		}
		_capacity = capacity;

		// data copy
		T* newData = new T[_capacity];
		for (int i = 0; i < _size; ++i)
		{
			newData[i] = _data[i];
		}
		
		if (_data)
		{
			delete[] _data;
		}
		// pointing
		_data = newData;
	}

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}
		_size = 0;
	}

	T& operator[](const int pos) { return _data[pos]; }
	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T*		_data = nullptr;
	int		_size = 0;
	int		_capacity = 0;
};
template<typename T>
class Node
{
public:
	Node()
		: _prev(nullptr), _next(nullptr), _data(T())
	{

	}
	Node(const T& value)
		: _prev(nullptr), _next(nullptr), _data(value)
	{

	}
	
public:
	Node* _prev;
	Node* _next;
	T	  _data;
};
template<typename T>
class Iterator
{
public:
	Iterator()
		: _node(nullptr)
	{

	}

	Iterator(Node<T>* node)
		: _node(node)
	{

	}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	// it++
	Iterator& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}
	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	// it--
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}
	// *it
	T& operator*()
	{
		return _node->data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};
template<typename T>
class List
{
public:
	List()
		: _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		while (_size > 0)
		{
			pop_back();
		}
		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}
	void pop_back()
	{
		RemoveNode(_tail->prev);
	}
private:
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}
	
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

public:
	using iterator = Iterator<T>;

	iterator begin(){ return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}


private:
	Node<T>* _head;
	Node<T>* _tail;
	int		 _size;
};

template<typename T>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }

	int size() { return _container.size(); }

private:
	vector<T> _container;
};



void main()
{
	stack<int> s;
	
	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);

	// 최상위 원소
	int data = s.top();

	// 최상위 원소 삭제
	s.pop();
}	