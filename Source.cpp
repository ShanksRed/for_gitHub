#include <iostream>
#include "queue.h"


int main() {
	Queue<int> m_queue{};
	std::cout<<m_queue.isEmpty();
	m_queue.push(5);
	m_queue.push(6);
	m_queue.push(7);
	m_queue.push(8);
	std::cout << m_queue.isEmpty();
	m_queue.clear();
	std::cout << m_queue.isEmpty();

}