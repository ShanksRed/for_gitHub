#include <iostream>
#include <memory>
#include <random>
#include <filesystem>
#include <fstream>


template <typename T>
class Queue {

private:
	struct pointNode {
		T data;
		std::shared_ptr<pointNode> next;

		pointNode() :data(std::move(T{})), next(std::move(std::shared_ptr<pointNode>{})) {}
		pointNode(T n_data, std::shared_ptr<pointNode> ptr) : data(std::move(n_data)), next(std::move(ptr)) {}

		bool operator!=(Queue<T>::pointNode obj1) const {
			if (this) return true;
			else return false;
		}
		pointNode* operator++() {
			return this->next.get();
			//return m_temp;

		}

		const T& getValue() {
			return this->data;
		}


	};
	std::shared_ptr<pointNode> p_first;
	std::shared_ptr<pointNode> p_last;
	int size;
public:

	class Iterator {
		using Iterator_type = Queue<T>::pointNode;
	public:
		Iterator() = default;

		Iterator(Iterator_type* rNode) {
			current_node = rNode;
		}

		Iterator& operator=(Iterator_type* rNode) {
			this->current_node = rNode;
			return *this;
		}
		void operator++() {
			if (this->current_node)
				this->current_node = this->current_node->next.get();
		}
		bool operator !=(const Iterator& pNode) {
			return this->current_node != pNode.current_node;
		}
		T& const get_value() {
			return this->current_node->data;
		}

	private:

		Iterator_type* current_node;

	};

	using type_t = T;
	Queue() : p_first(std::shared_ptr<pointNode>{}), p_last(std::shared_ptr<pointNode>{}), size(0) {}
	void push(const T& item);
	void pop();
	void clear();
	bool isEmpty();

};



template <class T>
void Queue<T>::push(const T& item)
{
	std::shared_ptr<pointNode> new_end = std::make_shared<pointNode>(item,nullptr);
	if (p_last)
	{
		p_last->next = new_end;
	}
	p_last = new_end;
	if (!p_first)
	{
		p_first = p_last;
	}
	++size;
}


template <class T>
void Queue<T>::pop()
{
	/*
	auto ptr = std::move(p_first);
	p_first = ptr->next;
	if (!p_first)
	{
		p_last.reset();
	}
	ptr.reset();
	--size;
	*/
	p_first = std::move(p_first->next);
	if (!p_first) p_last.reset();
	--size;
}

template<typename T>
inline void Queue<T>::clear()
{
	while (p_first) this->pop();
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	if (!p_first) return true;
	else return false;
}


