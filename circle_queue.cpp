/*
 *  ┌─────────────────────────────────────────────────────────────┐
 *  │┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐│
 *  ││Esc│!1 │@2 │#3 │$4 │%5 │^6 │&7 │*8 │(9 │)0 │_- │+= │|\ │`~ ││
 *  │├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤│
 *  ││ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{[ │}] │ BS  ││
 *  │├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤│
 *  ││ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  ││
 *  │├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤│
 *  ││ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│Shift │Fn ││
 *  │└─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘│
 *  │      │Fn │ Alt │         Space         │ Alt │Win│   HHKB   │
 *  │      └───┴─────┴───────────────────────┴─────┴───┘          │
 *  └─────────────────────────────────────────────────────────────┘
 * 
 * @Author      : shunshun 786174502@qq.com
 * @Date        : 2023-01-29 23:19:04
 * @LastEditors : shunshun 786174502@qq.com
 * @LastEditTime: 2023-01-31 00:09:36
 * @FilePath    : /Downloads/cartoon_algorithm/circle_queue.cpp
 * 
 * @Description : 实现循环队列
 * 
 * If you have any problem, please contact:
 *     QQ    : 786174502
 *     WeChat: 19121765520
 * 
 * Copyright (c) 2023 by shunshun 786174502@qq.com, All Rights Reserved.
 */

#include <cstring>
#include <iostream>
#include <iomanip>

class Queue
{
public:
    Queue()
    {
        _capacity = 10;
        _arr = new int[_capacity];
        _front = 0;
        _rear = 0;
    }

    ~Queue()
    {
        delete[] _arr;
    }
    
    int push(int val)
    {
        if (full())
            return -1;
        _arr[_rear] = val;
        _rear = (_rear + 1) % _capacity;
        return 0;
    }

    int pop(int& val)
    {
        if (empty())
            return -1;
        val = _arr[_front];
        _front = (_front + 1) % _capacity;
        return 0;
    }
    
    bool empty()
    {
        return _front == _rear;
    }

    bool full()
    {
        return (_rear + 1) % _capacity == _front;
    }

    void print()
    {
        for (int i = 0; i < _capacity; i++)
        {
            std::cout << i << std::setw(10);
        }
        std::cout << "\n";
        for (int i = 0; i < _capacity; i++)
        {
            std::cout << _arr[i] << std::setw(10);
        }
        std::cout << "\n";

        std::cout << "front = " << _front << std::endl;
        std::cout << "rear = " << _rear << std::endl;
    }


private:
    int *_arr;
    int _capacity;
    int _front;
    int _rear;
};

int main()
{
    Queue q;
    q.push(100);
    q.push(200);
    q.print();

    return 0;
}