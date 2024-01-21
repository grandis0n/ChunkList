#include "ChunkList.h"
#include <cassert>
#include <iostream>

using namespace fefu_laboratory_two;

void default_constructor_test()
{
    ChunkList<int, 3> list;
    assert(list.get_size() == 0);
    assert(list.empty() == true);
}

void value_constructor_test()
{
    Allocator<int> allocator;
    ChunkList<int, 3> list(5, 4, allocator);

    assert(list.get_size() == 5);

    for (int i = 0; i < 5; i++)
    {
        assert(list[i] == 4);
    }
}

void default_value_constructor_test()
{
    Allocator<int> allocator;
    ChunkList<int, 3> list(5, int(), allocator);

    assert(list.get_size() == 5);

    for (int i = 0; i < 5; i++)
    {
        assert(list[i] == int());
    }
}

void copy_constructor_test()
{
    ChunkList<int, 3> first_list;
    for (int i = 0; i < 5; i++)
    {
        first_list.push_back(i);
    }

    auto second_list = first_list;

    for (int i = 0; i < 5; i++)
    {
        assert(first_list[i] == second_list[i]);
    }

    assert(first_list.get_size() == second_list.get_size());
}

void copy_constructor_with_allocator_test()
{
    Allocator<int> allocator;
    ChunkList<int, 3> first_list;

    for (int i = 0; i < 5; i++)
    {
        first_list.push_back(i);
    }

    ChunkList<int, 3> second_list(first_list, allocator);

    for (int i = 0; i < 5; i++)
    {
        assert(first_list[i] == second_list[i]);
    }

    assert(first_list.get_size() == second_list.get_size());
}

void assign_test()
{
    Allocator<int> allocator;
    ChunkList<int, 3> list(5, 4, allocator);

    list.assign(3, 3);

    assert(list.get_size() == 3);

    for (int i = 0; i < list.get_size(); i++)
    {
        assert(list[i] == 3);
    }
}

void At_test()
{
    ChunkList<int, 3> list;

    for (int i = 0; i < 5; i++)
    {
        list.push_back(i);
    }

    assert(list.At(2) == 2);
    assert(list.At(4) == 4);
}

void brackets_test()
{
    ChunkList<int, 3> list;

    for (int i = 0; i < 30; i++)
    {
        list.push_back(i);
    }

    for (int i = 0; i < 30; i++)
    {
        assert(list[i] == i);
    }
}

void clear_test()
{
    ChunkList<int, 5> list;

    for (int i = 4; i < 42; i++)
    {
        list.push_back(i);
    }

    list.clear();

    assert(list.empty() == true);
}

void erase_test()
{
    ChunkList<int, 8> list;

    for (int i = 0; i < 10; i++)
        list.push_back(i);

    auto it = list.cbegin();
    it += 2;

    auto result = list.erase(it);

    assert(list[2] == 3);
    assert(result == list.cbegin() + 2);
}

void erase_range_test()
{
    ChunkList<int, 8> list;

    for (int i = 0; i < 10; i++)
        list.push_back(i);

    auto first = list.cbegin() + 2;
    auto last = list.cbegin() + 5;

    auto result = list.erase(first, last);

    assert(list[2] == 5);
    assert(result == list.cbegin() + 2);
}

void front_test()
{
    ChunkList<int, 5> list;

    for (int i = 4; i < 42; i++)
    {
        list.push_back(i);
    }

    assert(list.front() == 4);
}

void back_test()
{
    ChunkList<int, 5> list;

    for (int i = 4; i < 42; i++)
    {
        list.push_back(i);
    }

    assert(list.back() == 41);
}

void iterators_test()
{
    ChunkList<int, 8> list;
    int* test_arr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        list.push_back(i);
        test_arr[i] = i;
    }

    int j = 0;
    for (auto iter : list)
        assert(test_arr[j++] == iter);

    auto it1 = list.begin();
    auto it2 = list.begin();
    assert(it1 == it2);
    assert(it1 >= it2);

    it2++;
    assert(it2 > it1);

    it1 += 2;
    it2 -= 1;
    assert(it1 > it2);

    auto it3 = list.back();
    assert(it3 == 9);
}

void insert_test()
{
    ChunkList<int, 8> list;

    for (int i = 0; i < 10; i++)
        list.push_back(i);

    auto it = list.cbegin();
    it += 2;
    list.insert(it, 2);

    assert(list[2] == 2);
}

void pop_back()
{
    ChunkList<int, 3> list;

    for (int i = 0; i < 10; i++)
        list.push_back(i);

    list.pop_back();
    assert(list[list.get_size() - 1] == 8);
}

void swap_test()
{
    ChunkList<int, 5> list1;
    ChunkList<int, 5> list2;

    for (int i = 0; i < 5; i++)
    {
        list1.push_back(i);
        list2.push_back(i + 5);
    }

    list1.swap(list2);

    assert(list1.front() == 5);
    assert(list1.back() == 9);
    assert(list2.front() == 0);
    assert(list2.back() == 4);
}

void push_back_test()
{
    ChunkList<int, 3> list;

    for (int i = 0; i < 5; i++)
        list.push_back(i);

    list.push_back(10);

    assert(list[list.get_size() - 1] == 10);
    assert(list.get_size() == 6);
}

int main()
{
    default_constructor_test();
    value_constructor_test();
    default_value_constructor_test();
    copy_constructor_test();
    copy_constructor_with_allocator_test();
    assign_test();
    At_test();
    brackets_test();
    clear_test();
    erase_test();
    erase_range_test();
    front_test();
    back_test();
    iterators_test();
    insert_test();
    pop_back();
    swap_test();
    push_back_test();
    std::cout << "All tests passed." << std::endl;
    return 0;
}
