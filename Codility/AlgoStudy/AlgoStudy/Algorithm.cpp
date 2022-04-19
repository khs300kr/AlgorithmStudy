#include <iostream>
#include <vector>
#include <list>

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
	Iterator& operator(int)
	{
		Iterator<T> temp = *this;
		_node = node->_next;
		return temp;
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


private:
	Node<T>* _head;
	Node<T>* _tail;
	int		 _size;
};


void main()
{
	//Vector<int> v;
	//for (int i = 0; i < 100; ++i)
	//{
	//	v.push_back(i);
	//	cout << v[i] << " " <<  v.size() << " " << v.capacity() << endl;
	//}
	//v.clear();
	//cout << v.size() << " " << v.capacity() << endl;


	list<int> li;

	for (int i = 0; i < 10; ++i)
	{
		li.push_back(i);

		// li.push_front(i);
		
	}

	return;
}