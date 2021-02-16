#include <iostream>
#include <string_view>
#include <vector>
#include <optional>
#include"queue.h"

Queue<int>::type_t& enter_number(int condition);

int main()
{
    setlocale(LC_ALL, "Russian");
    Queue<int> m_queue{  };


    int menu{ -1 };
    constexpr std::string_view str_menu[]{
        "0-�����",
        "1-����������� �������",
        "2-�������� �������� ��������",
        "3-�������� �������",
        "4-����� �������",
        "5-������� �������� �������",
        "6-��������� ����������",
        "7-������� �� �����",
        "8-������ � ����",
        "9-�������� �������",
        "10-����� ����"
    };

    auto print_menu = [&]() constexpr {
        for (auto&& element : str_menu) {
            std::cout << element << std::endl;

        }
    };

    print_menu();

    while (menu) {
        std::cout << "������� ���������: "; std::cin >> menu;
        switch (menu)
        {

        case 1:
            m_queue.print_stack();
            break;
        case 2:
        {
            try {
                std::cout<<"������� ������� ������� - "<< m_queue.front()<<std::endl;
            }
            catch(const std::exception& e){
                std::cout << e.what() << std::endl;
            }

        }
        break;
        case 3:
        {
            try {
                auto number = enter_number(3);
                m_queue.push(number);
            }
            catch (const std::exception& e) {
                std::cout << "������ �����" << std::endl;
            }
        }
        break;
        case 4:
        {
            try {
                auto number = enter_number(4);
                std::cout << "������� ����� � ������� - " << m_queue.findValue(number) <<std::endl;
                // temp==-1? std::cout << "����� �� �������" : std::cout << temp<<std::endl;
            }
            catch (const std::exception& e) {
                // std::cout << "������ �����"<<std::endl;
                std::cout << e.what() << std::endl;
            }
        }
        break;
        case 5:
        {
            try {
                m_queue.pop();
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }
        break;
        case 6:
        {
            int ld{}, rd{}, count{};
            std::cout << "������� �������� � ���������� ����� :";
            std::cin >> ld >> rd >> count;
            m_queue.fill_rnumb(count, ld, rd);
        }
        break;
        case 7:
        {
            m_queue.read_fr_file("m_txt.txt");
        }
        break;
        case 8:
        {
            m_queue.write_to_file("m_txt.txt");
        }
        break;
        case 9:
        {
            m_queue.clear();
        }
        break;
        case 10:
        {
            print_menu();
        }
        break;

        case 0:
            break;

        default:
            std::cout << "������" << std::endl;
        }

    }

}

template<typename T>
inline void Queue<T>::print_stack() const noexcept
{
    if (this->isEmpty() == true) std::cout << "������� ����� " << std::endl;
    else {
        for (Queue<T>::Iterator iterator = this->Begin(); iterator != this->End(); ++iterator) {
            std::cout << iterator.get_value() << " ";
        }
        std::cout << std::endl;
    }
}


Queue<int>::type_t& enter_number(int condition) {
    condition == 4 ? std::cout << "������� ������� ��� ����������:" : std::cout << "������� �����:";
    Queue<int>::type_t number;
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //std::cout << "������ ����� " << std::endl;
        throw std::exception("������ ����� ");
    }
    else {
        return number;
    }
}
