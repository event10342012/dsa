//
// Created by Leo Chen on 2023/8/15.
//

#ifndef DSA_LINKLIST_H
#define DSA_LINKLIST_H

//单链表中每个节点的定义
template<typename T> //T代表数据元素的类型
struct Node {
    T data;    //数据域，存放数据元素
    Node<T> *next;  //指针域，指向下一个同类型（和本节点类型相同）节点
};

//单链表的定义
template<typename T>
class LinkList {
public:
    LinkList();      //构造函数
    ~LinkList() {};     //析构函数

public:
    bool ListInsert(int i, const T &e);  //在第i个位置插入指定元素e
    bool ListDelete(int i);              //删除第i个位置的元素

    bool GetElem(int i, T &e);           //获得第i个位置的元素值
    int LocateElem(const T &e);         //按元素值查找其在单链表中第一次出现的位置

    void DispList();                     //输出单链表中的所有元素
    int ListLength();                   //获取单链表的长度
    bool Empty();                        //判断单链表是否为空
    void ReverseList();                  //翻转单链表


private:
    Node<T> *m_head; //头指针（指向链表第一个节点的指针，如果链表有头结点则指向头结点）
    int m_length;    //单链表当前长度（当前有几个元素），为编写程序更加方便和提高程序运行效率而引入，但不是必须引入
};

//通过构造函数对单链表进行初始化
template<typename T>
LinkList<T>::LinkList() {
    m_head = new Node<T>; //先创建一个头结点
    m_head->next = nullptr;
    m_length = 0;  //头结点不计入单链表的长度
}


#endif //DSA_LINKLIST_H
