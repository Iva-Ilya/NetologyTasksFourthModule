//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include<catch2/catch_session.hpp>
#include <cstdint>

//проверяемая функция
uint32_t factorial( uint32_t number ) {
    return number <= 1 ? number : factorial(number-1) * number;
}

//юнит-тест
TEST_CASE( "Factorials are computed", "[factorial]" ) {
    CHECK( factorial( 1) == 1 );
    SECTION("factorial > 1") {
        CHECK(factorial(2) == 2);
        CHECK(factorial(3) == 6);
        CHECK(factorial(10) == 3'628'800);
    }
}


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

TEST_CASE("Test Empty function") {
    List list;

    CHECK(list.Empty() == true);

    list.PushBack(1);
    CHECK(list.Empty() == false);

    list.PopBack();
    CHECK(list.Empty() == true);
}
TEST_CASE("Test Size function") {
    List list;
    
    list.PushBack(11);
    CHECK(list.Size() == 1);

    list.PushFront(22);
    CHECK(list.Size() == 2);

    list.PopFront();
    CHECK(list.Size() == 1);

    list.PopBack();
    CHECK(list.Size() == 0);
}
TEST_CASE("Test CLear function") {
    List list;

    list.PushBack(11);
    list.PushFront(22);
    CHECK(list.Size() == 2);

    list.Clear();
    CHECK(list.Empty() == true);
    CHECK(list.Size() == 0);

    list.PushFront(22);
    list.PushBack(11);
    list.PopBack();
    CHECK(list.Size() == 1);
    CHECK(list.PopBack() == 22);
}

int  main()
{
    return Catch::Session().run();
}