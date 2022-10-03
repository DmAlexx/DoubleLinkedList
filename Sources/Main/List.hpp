#pragma once
#include <iostream>


using namespace std;

template<typename T>
class List
{
private:
	struct Node
	{
		T m_data;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	Node* m_head;
	Node* m_tail;
	int m_length;
public:
	class Iterator
	{
	private:
		Node* m_node;

	public:
		Iterator(Node* node);
		Iterator& operator++();
		Iterator& operator--();
		bool operator!=(const Iterator& right);
		T operator*();
	};
	List();
	~List();
	T& operator[](const int pos);
	void push_back(T data);
	void insert(int pos, T data);
	void print();
	void pop_front();
	Iterator begin() const;
	Iterator end() const;
};
template<typename T>
inline List<T>::List()
	: m_head(nullptr)
	, m_tail(nullptr)
	, m_length(0)
{

}
template<typename T>
inline List<T>::~List()
{
	while (m_length > 0)
	{
		pop_front();
	}
}
template <class T>
typename List<T>::Iterator List<T>::begin() const
{
	return List<T>::Iterator(m_head);
}
template <class T>
typename List<T>::Iterator List<T>::end() const
{
	return List<T>::Iterator(nullptr);
}
template <class T>
List<T>::Iterator::Iterator(Node* node)
	: m_node(node)
{
}
template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	if (m_node)
	{
		m_node = m_node->next;
	}
	return *this;
}
template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	if (m_node)
	{
		m_node = m_node->prev;
	}
	return *this;
}
template <class T>
T List<T>::Iterator::operator*()
{
	if (m_node)
	{
		return m_node->m_data;
	}
	return T();
}
template <class T>
bool List<T>::Iterator::operator!=(const List<T>::Iterator& right)
{
	return m_node != right.m_node;
}
template<typename T>
inline void List<T>::push_back(T data)
{
	Node* temp = new Node;
	temp->m_data = data;
	++m_length;

	if (m_length == 1)
	{
		m_head = temp;
		m_tail = temp;
	}
	else
	{
		temp->prev = m_tail;
		m_tail->next = temp;
		m_tail = temp;
	}
}
template<typename T>
inline void List<T>::pop_front()
{
	Node* temp = m_head;
	m_head = m_head->next;
	delete temp;
	--m_length;
}
template<typename T>
inline T& List<T>::operator[](const int pos)
{
	int counter = 0;
	Node* temp = m_head;
	while (temp != nullptr)
	{
		if (counter == pos)
		{
			return temp->m_data;
		}
		++counter;
		temp = temp->next;
	}
}
template<typename T>
inline void List<T>::insert(int pos, T data)
{
	if (pos >= 0 && pos <= m_length)
	{
		if (pos == 0)
		{
			Node* temp = new Node;
			temp->m_data = data;
			temp->next = m_head;
			m_head->prev = temp;
			m_head = temp;
			++m_length;
		}
		else
		{
			Node* nodeNext = new Node;
			Node* nodePrev = new Node;
			Node* temp = new Node;
			temp->m_data = data;
					
			nodeNext = m_head;
			for (int i = 0; i < pos; ++i)
			{
				nodeNext = nodeNext->next;
			}

			nodePrev = m_head;
			for (int i = 0; i < (pos - 1); ++i)
			{
				nodePrev = nodePrev->next;
			}

			temp->next = nodeNext;
			temp->prev = nodePrev;
			nodePrev->next = temp;
			nodeNext->prev = temp;
			++m_length;
		}
	}
	else
	{
		cout << "Wrong position" << endl;
	}
}
template<typename T>
inline void List<T>::print()
{
	if (m_length != 0)
	{
		Node* temp = m_head;
		while (temp->next != nullptr)
		{
			cout << temp->m_data << ", ";
			temp = temp->next;
		}
		cout << temp->m_data << endl;
	}
}

