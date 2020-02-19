#ifndef NODE	
#define NODE

template<class T>
class myList {
private:
	myList<T>* head;
	int size;
public:
	myList() : head(nullptr),size(0){}
	~myList() {
		while (!isEmpty()) {
			remove();
		}
	}
	void insert(T item) {
		node<T>* tmp = new node<T>(item);
		tmp->next = head;
		head = tmp;
		size++;
	}
	void remove() {
		node<T>* tmp;

		if (head != nullptr)
		{
			tmp = head;
			head = tmp->next;
			delete(tmp);
			size--;
		}
	}
	bool find(T item) {
		node<T>* tmp;
		for (tmp = head; tmp != nullptr; tmp = tmp->next)
		{
			if (tmp->data == item)
			{
				return true;
			}
			else {
				return false;
			}
		}
	};
	bool isEmpty() {
		return size == 0;
	}
	int getSize() { return size; }

};

template<class T>
class node {
public:
	T data;
	node<T>* next;

	node() {
		next = nullptr;
	};
	node(T word) {
		data = word;
		next = nullptr;
	}
};

#endif
