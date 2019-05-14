#pragma once
template<class T>
class elem
{		
public:	
	T obj;
	elem<T>*next=nullptr;
		
};		
		
		
template<class T>
class SingleLinkedList
{		
	elem<T>*head=nullptr;
	int size_=0;
public:	
	void push_back(const T&obj);
	void push_front(const T&obj);
	void pop_back();
	void pop_front();
	void insert(int pos, const T&obj);
	T& getElement(int pos);

	//const T& getElement(int pos)const;
	
	~SingleLinkedList();
	operator=(const SingleLinkedList<T>& right);
	operator=(SingleLinkedList<T>&& right);
	SingleLinkedList(const SingleLinkedList& obj);
	&&SingleLinkedList(const SingleLinkedList&& obj);

};

template<class T>
inline void SingleLinkedList<T>::push_back(const T & obj)
{
	elem<T> *nElem = new elem<T>;
	nElem->obj = obj;
	if (head==nullptr){
		this->head = nElem;
		size_ = 1;
		return;
	}
	elem<T>*tmp = head;
	while (tmp->next!nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = nElem;
	size_++;
}

template<class T>
inline void SingleLinkedList<T>::push_front(const T & obj)
{
	elem<T> *nElem = new elem<T>;
	nElem->obj = obj;
	nElem->next = head;
	head = nElem;
	size_++;
}

template<class T>
inline void SingleLinkedList<T>::pop_back()
{
	if (head == nullptr)
		return;
	if (size_ == 1) {
		delete head;
		head = nullptr;
		size_ = 0;
		return;
	}
	elem<T>*tmp = head;
	for (size_t i = 0; i < size_-2; i++)
	{
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = nullptr;
	size_--;
}

template<class T>
inline void SingleLinkedList<T>::pop_front()
{
	if (head == nullptr)
		return;
	if (size_==1){
		delete head;
		head = nullptr;
		size_ = 0;
		return;
	}
	elem<T>*tmp = head;
	head = head->next;
	delete tmp;
	size_--;
}

template<class T>
inline void SingleLinkedList<T>::insert(int pos, const T & obj)
{
	if (pos<0||pos>size_)
		return;
	if (pos == 0) { push_front(obj); return; }
	if (pos == size_) { push_back(obj); return; }
	
	elem<T>*tmp=head
		for (size_t i = 0; i < pos-1; i++)
		{
			tmp = tmp->next;
		}
	elem<T>*nElem = new elem<T>;
	nElem->obj = obj;
	nElem->next = tmp->next;
	tmp->next = nElem;
	size_++;
	
}

template<class T>
inline T & SingleLinkedList<T>::getElement(int pos)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
inline SingleLinkedList<T>::~SingleLinkedList()
{
	while (head==nullptr)
	{
		pop_front();
	}
}



template<class T>
inline SingleLinkedList<T>::operator=(const SingleLinkedList<T>& right)
{
	if (this == &right)
	{
		return *this<T>;
	}
	this->~list_();
	this->size_ = right.size_;
	if (size_ == 0)
	{
		head = nullptr;
		return *this;
	}
	elem<T> *tmp;
	tmp = right.head;
	for (size_t i = 0; i < this->size_; i++)
	{
		this->push_back(tmp->obj);
		tmp = tmp->next;
	}
	return *this<T>;
}
template<class T>
inline SingleLinkedList<T>::operator=(SingleLinkedList<T>&& right)
{
	swap(this->size_, right.size_);
	swap(this->head, right.head);
	return *this<T>;
}