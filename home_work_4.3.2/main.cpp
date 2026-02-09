//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include<catch2/catch_session.hpp>
#include <cstdint>


struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("Test PushBack function") {
    List list;
    SECTION("") {
        CHECK(list.Size() == 0);
        list.PushBack(111);
        CHECK(list.Size() == 1);
        CHECK(list.Empty() == false);
        CHECK(list.PopBack() == 111);
    }
    SECTION("") {
        // Очередь данных типов LIFO
        list.PushBack(111);
        list.PushBack(222);
        list.PushBack(333);
        CHECK(list.Size() == 3);
        CHECK(list.Empty() == false);
        
        CHECK(list.PopBack() == 333);
        CHECK(list.PopBack() == 222);
        CHECK(list.PopBack() == 111);

        // Очередь данных типов FIFO
        list.PushBack(111);
        list.PushBack(222);
        list.PushBack(333);
        
        CHECK(list.PopFront() == 111);
        CHECK(list.PopFront() == 222);
        CHECK(list.PopFront() == 333);
    }
}
TEST_CASE("Test PushFront function") {
    List list;
    SECTION("") {
        CHECK(list.Size() == 0);
        list.PushFront(111);
        CHECK(list.Size() == 1);
        CHECK(list.Empty() == false);
        CHECK(list.PopFront() == 111);
    }
    SECTION("") {
        // Очередь данных типов FIFO
        list.PushFront(111);
        list.PushFront(222);
        list.PushFront(333);
        CHECK(list.Size() == 3);
        CHECK(list.Empty() == false);
        
        CHECK(list.PopBack() == 111);
        CHECK(list.PopBack() == 222);
        CHECK(list.PopBack() == 333);

        // Очередь данных типов LIFO
        list.PushFront(111);
        list.PushFront(222);
        list.PushFront(333);
        
        CHECK(list.PopFront() == 333);
        CHECK(list.PopFront() == 222);
        CHECK(list.PopFront() == 111);
    }
}
TEST_CASE("Test PopFront function") {
    List list;
    SECTION("") {
        CHECK(list.Size() == 0);
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}
    SECTION("") {
        list.PushFront(1);  
        list.PushFront(2);  
        list.PushFront(3);  

        REQUIRE(list.PopFront() == 3);  
        REQUIRE(list.PopFront() == 2);  

        list.PushFront(4);  

        REQUIRE(list.PopFront() == 4);  
        REQUIRE(list.PopFront() == 1);  
    }
}
TEST_CASE("Test PopBack function") {
    List list;
    SECTION("") {
        CHECK(list.Size() == 0);
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }
    SECTION("") {
        list.PushBack(1);
        list.PushBack(2);
        list.PushBack(3);

        REQUIRE(list.PopBack() == 3);
        REQUIRE(list.PopBack() == 2);

        list.PushBack(4);

        REQUIRE(list.PopBack() == 4);
        REQUIRE(list.PopBack() == 1);
    }
}

int  main()
{
    return Catch::Session().run();
}