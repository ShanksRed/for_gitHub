#include <iostream>
#include "queue.h"


int main() {
	Queue<int> m_queue{};
	m_queue.fill_rnumb(9, 1, 10);
	m_queue.write_to_file("m_txt.txt");
	m_queue.read_fr_file("m_txt.txt");

	for (auto temp = m_queue.Begin(); temp != m_queue.End(); ++temp) {
		std::cout << temp.get_value();
	}

	

}