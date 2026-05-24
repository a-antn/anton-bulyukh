#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>

/**
 * @brief Линейный двусвязный список целых чисел
 */
class DoublyLinkedList {
    private:
        /**
         * @brief узел списка
         */
        struct Node {
            int value;
            Node* prev;
            Node* next;
        };

        /**
         * @brief первый узел
         */
        Node* head;

        /**
         * @brief последний узел
         */
        Node* tail;

        /**
         * @brief количество элементов
         */
        std::size_t count;

    public:
        /**
         * @brief конструктор по умолчанию
         */
        DoublyLinkedList();

        /**
         * @brief конструктор из списка инициализации
         * @param values список значений
         */
        DoublyLinkedList(const std::initializer_list<int> values);

        /**
         * @brief конструктор копирования
         * @param other список-источник
         */
        DoublyLinkedList(const DoublyLinkedList& other);

        /**
         * @brief конструктор перемещения
         * @param other список-источник
         */
        DoublyLinkedList(DoublyLinkedList&& other) noexcept;

        /**
         * @brief деструктор
         */
        ~DoublyLinkedList();

        /**
         * @brief оператор копирующего присваивания
         * @param other список-источник
         * @return ссылка на текущий объект
         */
        DoublyLinkedList& operator=(const DoublyLinkedList& other);

        /**
         * @brief оператор перемещающего присваивания
         * @param other список-источник
         * @return ссылка на текущий объект
         */
        DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

        /**
         * @brief добавить элемент в конец
         * @param value значение элемента
         */
        void PushBack(const int value);

        /**
         * @brief добавить элемент в начало
         * @param value значение элемента
         */
        void PushFront(const int value);

        /**
         * @brief удалить последний элемент
         * @return true если элемент был удалён, false если список был пуст
         */
        bool PopBack();

        /**
         * @brief удалить первый элемент
         * @return true если элемент был удалён, false если список был пуст
         */
        bool PopFront();

        /**
         * @brief получить значение первого элемента
         * @return значение головы списка
         * @throw std::out_of_range если список пуст
         */
        int Front() const;

        /**
         * @brief получить значение последнего элемента
         * @return значение хвоста списка
         * @throw std::out_of_range если список пуст
         */
        int Back() const;

        /**
         * @brief получить значение по индексу
         * @param index позиция элемента
         * @return значение элемента
         * @throw std::out_of_range если индекс вне диапазона
         */
        int At(const std::size_t index) const;

        /**
         * @brief количество элементов
         * @return текущий размер списка
         */
        std::size_t Size() const;

        /**
         * @brief проверка на пустоту
         * @return true если в списке нет элементов
         */
        bool IsEmpty() const;

        /**
         * @brief удалить все элементы
         */
        void Clear();

        /**
         * @brief сериализация в строку
         * @return строка вида "[1, 2, 3]"
         */
        std::string ToString() const;

        /**
         * @brief равенство списков
         * @param other второй список
         * @return true если все элементы попарно равны
         */
        bool operator==(const DoublyLinkedList& other) const;

        /**
         * @brief неравенство списков
         * @param other второй список
         * @return true если списки различаются
         */
        bool operator!=(const DoublyLinkedList& other) const;
};
