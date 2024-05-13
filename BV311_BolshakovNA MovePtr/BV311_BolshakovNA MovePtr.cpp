// BV311_BolshakovNA MovePtr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename T>
class UniquePointer 
{
public:
    UniquePointer() {}
    UniquePointer(T* ptr) : ptr(ptr) {}//конструктор создания объекта

    UniquePointer(UniquePointer&& moved) : ptr(moved.ptr)//конструктор перемещения
    {
        moved.ptr = nullptr;
    }


    UniquePointer& operator = (UniquePointer&& moved)//присваивание перемещением 
    {
        delete ptr;
        this->ptr = moved.ptr;
        moved.ptr = nullptr;
        
        return *this;
    }

    ~UniquePointer() 
    {
        delete ptr;
    }

    void print()
    {
        std::cout << ptr << std::endl;
    }

private:
    T* ptr;

    //запрет копирования и присваивания копированием
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;
};

int main()
{

    int a = 5;


    UniquePointer <int> ptr1(new int(a));

    ptr1.print();//адрес переменной А записан 

    std::cout << std::endl;

    UniquePointer <int> ptr2(std::move(ptr1)); //адрес переменной А перемещен из ptr1 в ptr2 с помощью конструктора перемещения

    ptr1.print();
    ptr2.print();

    std::cout << std::endl;

    UniquePointer <int> ptr3;

    ptr3 = std::move(ptr2);//адрес переменной А перемещен из ptr2 в ptr3 с помощью присваивания перемещением

    ptr2.print();
    ptr3.print();

}

