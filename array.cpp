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
 * @Date        : 2023-01-29 22:03:27
 * @LastEditors : shunshun 786174502@qq.com
 * @LastEditTime: 2023-01-31 00:08:47
 * @FilePath    : /Downloads/cartoon_algorithm/array.cpp
 *
 * @Description : 实现数组的插入、删除等操作
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

class MyArray
{
public:
    MyArray()
    {
        _size = 0;
        _capacity = 2;
        _arr = new int[_capacity];
    }

    ~MyArray()
    {
        delete[] _arr;
    }

    /**
     * @description: 两倍扩容
     */
    void resize()
    {
        int *temp = new int[_capacity * 2];
        memcpy(temp, _arr, sizeof(int) * _size);
        delete[] _arr;
        _capacity = _capacity * 2;
        _arr = temp;
    }

    /**
     * @description: 不扩容插入
     * @param  index 插入位置
     * @param  val   要插入的值
     * @return -1——插入失败，0——插入成功
     */
    int insert(int index, int val)
    {
        // index是否有效
        if (index < 0 || index > _size)
            return -1;

        // 是否还有余量
        if (_size == _capacity)
            return -1;

        // 从后往前，把元素挪到下一位
        for (int i = _size - 1; i >= index; i--)
        {
            _arr[i + 1] = _arr[i];
        }

        // 插入
        _arr[index] = val;
        _size += 1;
        return 0;
    }

    /**
     * @description: 扩容插入
     * @param  index 插入位置
     * @param  val   要插入的值
     * @return -1——插入失败，0——插入成功
     */
    int insert_v2(int index, int val)
    {
        // index是否有效
        if (index < 0 || index > _size)
            return -1;

        // 如果没有空间，扩容
        if (_size >= _capacity)
            resize();

        // 从后往前，把元素挪到下一位
        for (int i = _size - 1; i >= index; i--)
        {
            _arr[i + 1] = _arr[i];
        }

        // 插入
        _arr[index] = val;
        _size += 1;
        return 0;
    }

    /**
     * @description: 打印数组信息
     */
    void print()
    {
        for (int i = 0; i < _size; i++)
        {
            std::cout << i << std::setw(10);
        }
        std::cout << "\n";
        for (int i = 0; i < _size; i++)
        {
            std::cout << _arr[i] << std::setw(10);
        }
        std::cout << "\n";
    }

    /**
     * @description: 删除元素
     * @param  index 要删除的元素下标
     * @return -1——删除失败，0——删除成功
     */
    int remove(int index)
    {   
        // index是否有效
        if (index < 0 || index >= _size)
            return -1;

        // 从前往后，把东西往前挪一位
        for (int i = index + 1; i < _size; i++)
        {
            _arr[i - 1] = _arr[i];
        }
        _size--;
        return 0;
    }

    /**
     * @description: 快速删除————把最后一个元素挪到index的位置实现删除
     * @param  index 要删除的元素下标
     * @return -1——删除失败，0——删除成功
     */
    int quick_remove(int index)
    {
        // index是否有效
        if (index < 0 || index >= _size)
            return -1;

        _arr[index] = _arr[_size - 1];
        _size--;
        return 0;
    }

private:
    int *_arr;
    int _size;
    int _capacity;
};

int main()
{
    MyArray arr;
    arr.insert(0, 100);
    arr.insert(0, 200);
    arr.insert_v2(2, 300);
    arr.print();
    arr.quick_remove(1);
    arr.print();

    return 0;
}