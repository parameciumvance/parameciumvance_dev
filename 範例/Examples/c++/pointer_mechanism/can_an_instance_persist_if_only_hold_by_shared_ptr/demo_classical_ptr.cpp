#include <string>
#include <iostream>
using namespace std;

class Item
{
private:
    string m_name;

    /* data */
public:
    Item(string name);
    ~Item();
    string getName(){ return m_name;}
};

Item::Item(string name): m_name(name)
{
}

Item::~Item()
{
}

class ClassicalPtrHolder
{
private:
    Item* m_item_ptr;
    /* data */
public:
    ClassicalPtrHolder(/* args */);
    ~ClassicalPtrHolder();
    void printName();
};

ClassicalPtrHolder::ClassicalPtrHolder(/* args */)
{
    //Item my_item = Item("classical");
    //m_item_ptr = &my_item;
    m_item_ptr = new Item("classical");
    cout << "in construction, " << endl;
    cout << m_item_ptr->getName() << endl;
}

ClassicalPtrHolder::~ClassicalPtrHolder()
{
}

void ClassicalPtrHolder::printName()
{
    cout << "after construction, "<< endl;
    cout << m_item_ptr->getName() << endl;
}


int main(){
    ClassicalPtrHolder holder;
    holder.printName();

    return 0;
}