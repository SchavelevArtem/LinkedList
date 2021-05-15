//
// Created by admin on 11.05.2021.
//
#pragma once
#include <cstddef>

using ValueType = double;

class LinkedList {

    struct Node {
        explicit Node(const ValueType &value, Node *next = nullptr);

        ~Node();

        void insertNext(const ValueType &value);

        void removeNext();

        ValueType value;
        Node *next;
    };

public:
    ////
    LinkedList();

    LinkedList(const LinkedList &copyList);

    LinkedList &operator=(const LinkedList &copyList);

    LinkedList(LinkedList &&moveList) noexcept;

    LinkedList &operator=(LinkedList &&moveList) noexcept;

    ~LinkedList();
    ////

    // доступ к значению элемента по индексу
    const ValueType &operator[](size_t pos) const;

    ValueType &operator[](const size_t pos);

    // доступ к узлу по индексу
    LinkedList::Node *getNode(const size_t pos) const;

    // вставка элемента по индексу, сначала ищем, куда вставлять (О(n)), потом вставляем (O(1))
    void insert(const size_t pos, const ValueType &value);

    // вставка элемента после узла, (O(1))
    void insertAfterNode(Node *node, const ValueType &value);

    // вставка в конец (О(n))
    void pushBack(const ValueType &value);

    // вставка в начало (О(1))
    void pushFront(const ValueType &value);

    // удаление
    void remove(const size_t pos);

    void removeNextNode(Node *node);

    void removeFrontNode();

    void removeBackNode();

    // поиск, О(n)
    long long int findIndex(const ValueType &value) const;

    Node *findNode(const ValueType &value) const;

    // разворот списка
    void reverse();                        // изменение текущего списка
    LinkedList reverse() const;            // полчение нового списка (для константных объектов)
    LinkedList getReverseList() const;    // чтобы неконстантный объект тоже мог возвращать новый развернутый список

    size_t size() const;

private:
    Node *_head;
    size_t _size;

    void forceNodeDelete(Node *node);

};