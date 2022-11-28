#include <string>
#include <iostream>
using namespace std;

class SubItem
{
private:
    string m_name = "haha";
public:
    SubItem();
    SubItem(string name);
    ~SubItem();
    string getName() {return m_name;}
};

SubItem::SubItem()
{
    cout << "constructing default" << endl;
    m_name = "default";
}

SubItem::SubItem(string name): m_name(name)
{
    cout << "constructing " << name << endl;
}

SubItem::~SubItem()
{
}


class Item
{
private:
    string m_name;
    SubItem m_sub0;
    SubItem m_sub1;
    SubItem m_sub2;
    SubItem m_sub3 = SubItem("haha");

    /* data */
public:
    Item(string name);
    ~Item();

};

Item::Item(string name): m_name(name), m_sub0(m_name+"0"), m_sub2(m_sub1.getName()+"2"), m_sub1(m_sub0.getName()+"1")
{
    cout << "constructing" << endl;
    cout << m_sub0.getName() << "__" << m_sub1.getName() << "__" << m_sub2.getName() << endl;
}

Item::~Item()
{
}

int main(){
    Item inst("apple");
    

    return 0;
}