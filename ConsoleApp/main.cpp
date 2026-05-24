#include <clocale>
#include <iostream>
#include <stdexcept>
#include <string>

#include "/DoublyLinkedList/doubly_linked_list.h"

/**
 * @brief оператор вывода списка в поток
 * @param out выходной поток
 * @param list список
 * @return ссылка на поток
 */
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list)
{
    out << list.ToString();
    return out;
}

/**
 * @brief оператор чтения одного значения и добавления в конец списка
 * @param in входной поток
 * @param list список
 * @return ссылка на поток
 */
std::istream& operator>>(std::istream& in, DoublyLinkedList& list)
{
    int value = 0;
    if (in >> value)
    {
        list.PushBack(value);
    }
    return in;
}

/**
 * @brief точка входа
 * @return 0 при успехе иначе 1
 */
int main()
{
    std::setlocale(LC_ALL, "Russian");

    try
    {
        DoublyLinkedList a = { 1, 2, 3, 4, 5 };
        std::cout << "a = " << a << std::endl;
        std::cout << "a.IsEmpty() = " << (a.IsEmpty() ? "true" : "false") << std::endl;
        std::cout << "a.Size()    = " << a.Size() << std::endl;

        a.PushFront(0);
        a.PushBack(6);
        std::cout << "После PushFront(0) и PushBack(6): " << a << std::endl;

        DoublyLinkedList b = a;
        std::cout << "b = a;  b = " << b << std::endl;
        std::cout << "a == b ? " << ((a == b) ? "да" : "нет") << std::endl;

        a.PopFront();
        a.PopBack();
        std::cout << "a после PopFront и PopBack: " << a << std::endl;
        std::cout << "a != b ? " << ((a != b) ? "да" : "нет") << std::endl;

        DoublyLinkedList moved = std::move(b);
        std::cout << "moved (получен через std::move(b)) = " << moved << std::endl;
        std::cout << "b после move IsEmpty: " << (b.IsEmpty() ? "да" : "нет") << std::endl;

        DoublyLinkedList empty;
        std::cout << "пустой список: " << empty
                  << "; IsEmpty: " << (empty.IsEmpty() ? "да" : "нет") << std::endl;

        std::cout << "\nВведите 3 числа через пробел для добавления в конец списка a: ";
        for (int i = 0; i < 3; ++i)
        {
            std::cin >> a;
        }
        std::cout << "a после ввода: " << a << std::endl;
    }
    catch (const std::out_of_range& ex)
    {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
