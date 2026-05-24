#include <stdexcept>
#include <utility>

#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
    : head{nullptr}, tail{nullptr}, count{0}
{
}

DoublyLinkedList::DoublyLinkedList(const std::initializer_list<int> values)
    : head{nullptr}, tail{nullptr}, count{0}
{
    for (const int value : values)
    {
        PushBack(value);
    }
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
    : head{nullptr}, tail{nullptr}, count{0}
{
    for (Node* cur = other.head; cur != nullptr; cur = cur->next)
    {
        PushBack(cur->value);
    }
}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& other) noexcept
    : head{other.head}, tail{other.tail}, count{other.count}
{
    other.head = nullptr;
    other.tail = nullptr;
    other.count = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Clear();
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
    if (this != &other)
    {
        Clear();
        for (Node* cur = other.head; cur != nullptr; cur = cur->next)
        {
            PushBack(cur->value);
        }
    }
    return *this;
}

DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList&& other) noexcept
{
    if (this != &other)
    {
        Clear();
        head = other.head;
        tail = other.tail;
        count = other.count;
        other.head = nullptr;
        other.tail = nullptr;
        other.count = 0;
    }
    return *this;
}

void DoublyLinkedList::PushBack(const int value)
{
    Node* node = new Node{value, tail, nullptr};
    if (tail != nullptr)
    {
        tail->next = node;
    }
    else
    {
        head = node;
    }
    tail = node;
    ++count;
}

void DoublyLinkedList::PushFront(const int value)
{
    Node* node = new Node{value, nullptr, head};
    if (head != nullptr)
    {
        head->prev = node;
    }
    else
    {
        tail = node;
    }
    head = node;
    ++count;
}

bool DoublyLinkedList::PopBack()
{
    if (tail == nullptr)
    {
        return false;
    }
    Node* old = tail;
    tail = tail->prev;
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete old;
    --count;
    return true;
}

bool DoublyLinkedList::PopFront()
{
    if (head == nullptr)
    {
        return false;
    }
    Node* old = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    delete old;
    --count;
    return true;
}

int DoublyLinkedList::Front() const
{
    if (head == nullptr)
    {
        throw std::out_of_range("DoublyLinkedList: список пуст");
    }
    return head->value;
}

int DoublyLinkedList::Back() const
{
    if (tail == nullptr)
    {
        throw std::out_of_range("DoublyLinkedList: список пуст");
    }
    return tail->value;
}

int DoublyLinkedList::At(const std::size_t index) const
{
    if (index >= count)
    {
        throw std::out_of_range("DoublyLinkedList: индекс вне диапазона");
    }
    Node* cur = head;
    for (std::size_t i = 0; i < index; ++i)
    {
        cur = cur->next;
    }
    return cur->value;
}

std::size_t DoublyLinkedList::Size() const
{
    return count;
}

bool DoublyLinkedList::IsEmpty() const
{
    return count == 0;
}

void DoublyLinkedList::Clear()
{
    Node* cur = head;
    while (cur != nullptr)
    {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

std::string DoublyLinkedList::ToString() const
{
    std::string result = "[";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        result += std::to_string(cur->value);
        if (cur->next != nullptr)
        {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

bool DoublyLinkedList::operator==(const DoublyLinkedList& other) const
{
    if (count != other.count)
    {
        return false;
    }
    Node* a = head;
    Node* b = other.head;
    while (a != nullptr)
    {
        if (a->value != b->value)
        {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

bool DoublyLinkedList::operator!=(const DoublyLinkedList& other) const
{
    return !(*this == other);
}
