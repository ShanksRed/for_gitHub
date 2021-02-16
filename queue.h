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
		pointNode* next;

		pointNode() :data(0), next(nullptr) {}
		pointNode(T n_data, pointNode* ptr) : data(n_data), next(ptr) {}

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
	pointNode* p_first;
	pointNode* p_last;

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
				this->current_node = this->current_node->next;
		}
		bool operator !=(const Iterator& pNode) {
			return this->current_node != pNode.current_node;
		}
		T const get_value() {
			return this->current_node->data;
		}
		Iterator& Next(Iterator& Node) {
			if (Node.current_node)
				Node.current_node = Node.current_node->next.get();
			return Node;
		}


	private:

		Iterator_type* current_node;

	};

	using type_t = T;
	Queue() : p_first(nullptr), p_last(nullptr) {}
	void push(const T& item);
	void pop();
	T front();
	void clear();
	bool isEmpty()const;
	inline Iterator Begin() const noexcept;
	inline Iterator Next(Iterator&)const noexcept;
	inline Iterator End()const noexcept;
	T& findValue(T);
	void fill_rnumb(int, int, int);
	void write_to_file(std::filesystem::path filePath);
	void read_fr_file(std::filesystem::path filePath);
	inline void print_stack() const noexcept;

};



template <class T>
void Queue<T>::push(const T& item)
{

	pointNode* new_end = new pointNode(item, nullptr);

	if (p_last)
	{
		p_last->next = new_end;
	}
	p_last = new_end;
	if (!p_first)
	{
		p_first = p_last;
	}
}


template <class T>
void Queue<T>::pop()
{

	if (p_first == nullptr) 
		throw std::exception("Cтек пуст");
	auto temp = p_first;
	p_first = p_first->next;
	delete(temp);
	if (p_first == nullptr) p_last = nullptr;

}

template<typename T>
inline T Queue<T>::front()
{
	if(p_last)
	return this->p_last->data;
	else throw std::exception("Cтек пуст");
}

template<typename T>
inline void Queue<T>::clear()
{
	while (p_first) this->pop();
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	if (!p_first) return true;
	else return false;
}

template<typename T>
inline typename Queue<T>::Iterator Queue<T>::Begin() const noexcept
{
	//auto temp = this->p_first.get();
	return Iterator(p_first);
}

template<typename T>
inline typename Queue<T>::Iterator Queue<T>::Next(Iterator& current) const noexcept
{
	/*
	if (current.current_node)
		Iterator(current.current_node->next.get());
	else return Iterator(nullptr);
	*/
	return current.Next(current);
}

template<typename T>
inline typename Queue<T>::Iterator Queue<T>::End() const noexcept
{
	return Iterator(nullptr);
}

template<typename T>
inline T& Queue<T>::findValue(T search_numb)
{
	pointNode* head = this->p_first;
	int count{1};
	while (head) {
		if (head->data == search_numb)
			return count;
		else {
			count++;
			head = head->next;
		}
	}
	throw std::exception("число не найдено");
}

template<typename T>
inline void Queue<T>::fill_rnumb(int counter, int l_border, int r_border)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(l_border, r_border);
	while (counter) {
		auto random_integer = uni(rng);
		this->push(random_integer);
		counter--;
	}
}
template<typename T>
inline void Queue<T>::write_to_file(std::filesystem::path filePath)
{
	std::wofstream writeFile(filePath, std::ios::trunc);
	pointNode* head = this->p_first;
	while (head) {
		writeFile << head->data << " ";
		head = head->next;

	}
	writeFile.close();
}

template<typename T>
inline void Queue<T>::read_fr_file(std::filesystem::path filePath)
{

	std::wifstream readFile(filePath, std::ios::end);
	T symb;
	while (readFile >> symb) {
		this->push(symb);
	}


}