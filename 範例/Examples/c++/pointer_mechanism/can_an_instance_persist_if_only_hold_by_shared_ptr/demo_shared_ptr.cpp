#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>
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

class SharedPtrHolder
{
private:
    shared_ptr<Item> m_item_ptr;
    /* data */
public:
    SharedPtrHolder(/* args */);
    ~SharedPtrHolder();
    void printName();
};

SharedPtrHolder::SharedPtrHolder(/* args */)
{
    m_item_ptr = make_shared<Item>("shared");
    cout << "in construction, " << endl;
    cout << m_item_ptr->getName() << endl;
}

SharedPtrHolder::~SharedPtrHolder()
{
}

void SharedPtrHolder::printName()
{
    cout << "after construction, "<< endl;
    cout << m_item_ptr->getName() << endl;
    cout << "?"<< endl;
}


int main(){
    SharedPtrHolder holder;
    holder.printName();
    holder.printName();
    cout << "??"<< endl;
    holder.printName();

    return 0;
}