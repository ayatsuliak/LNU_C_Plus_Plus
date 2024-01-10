#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<stack>
#include<memory>
#include<algorithm>

using namespace std;

template<typename T>
class List
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* p_next;
		T data;
		Node(T data = T(), Node* p_next = nullptr)
		{
			this->data = data;
			this->p_next = p_next;
		}
	};
	Node<T> head;
	size_t size;
public:
	List();

	void push_back(T data);
	void push_front(T data);  //�������� ������� ����
	void pop_front();  //������� ������� ����
	void pop_back();
	void insert(T data, int index);  //�������� ���� �� ������� �� �� ����, � ������ ���� ����� �� ��������� ������
	void removeAt(int index);

	size_t GetSize()
	{
		return size;
	}

	void clear();

	T& operator[](const size_t index);

	~List();
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->p_next != nullptr)
		{
			current = current->p_next;
		}
		current->p_next = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head.p_next;

	delete temp;

	size--;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);  //����� �� ������ head
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this.head;
		for (int i = 0; i < index - 1; i++)  //�� �������� ���� ����� ����� �������, ��� ������ ������
		{
			previous = previous->p_next;
		}

		Node<T>* newNode = new Node<T>(data, previous->p_next);
		previous->p_next = newNode;

		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this.head;
		for (int i = 0; i < index - 1; i++)  //�� �������� ���� ����� ����� �������, ��� ������ ������
		{
			previous = previous->p_next;
		}
		Node<T>* toDelete = previous->p_next;
		previous->p_next = toDelete->p_next;
		delete toDelete;

		size--;
	}
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const size_t index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->p_next;
		counter++;
	}
}

template<typename T>
List<T>::~List()
{
	clear();
}

//int main()
//{
//	//list<int> lst = { 2, 5, 12, 6, 7 };
//	//list<int> list2 = { 2, 1, 66, 2 };
//	//auto it = lst.begin();
//	//auto it2 = list2.begin();
//	//advance(it, 3);  //���� ���� ������ it(���������� 0)
//	//lst.splice(it, list2);  //���� ��������� lts �������� � ����� list2 ������ �������� � lst, � � list2 ���� ����������
//	//list2.splice(list2.begin(),lst, it);  //��� �� ������� list2 ���� ���������� ���� it � ����� lst(����������� ������ � 0)
//	//list2.assign(it2, lst.end()); //�������� ��������� ���������� it2 ������� ����� ������ lst, ����� �� ������ ���������
//	//lst.sort();
//	//list2.sort();
//	//lst.merge(list2);  //����� �����������, ���� � ������� ��������� ��� ������ �����
//	//
//
//	/*int number_count;
//	cin >> number_count;
//
//	for (size_t i = 0; i < number_count; i++)
//	{
//		list.push_back(rand() % 10);
//	}
//
//	for (size_t i = 0; i < list.GetSize(); i++)
//	{
//		cout << list[i] << " ";
//	}*/
//
//	stack<int, list<int>> st;
//	st.push(4);
//	st.push(45);
//	st.push(58);
//	auto a = st._Get_container();
//
//}