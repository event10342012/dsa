//
// Created by Leo Chen on 2023/8/9.
//

#ifndef DSA_SEQLIST_H
#define DSA_SEQLIST_H


#define InitSize 10   //动态数组的初始尺寸
#define IncSize  5    //当动态数组存满数据后每次扩容所能多保存的数据元素数量

template<typename T> //T代表数组中元素的类型
class SeqList {
public:
    SeqList(int length = InitSize); //构造函数，参数可以有默认值
    ~SeqList();                   //析构函数

public:
    bool ListInsert(int i, const T &e);  //在第i个位置插入指定元素e
    bool ListDelete(int i);              //删除第i个位置的元素
    bool GetElem(int i, T &e);           //获得第i个位置的元素值
    int LocateElem(const T &e);         //按元素值查找其在顺序表中第一次出现的位置

    void DispList();                     //输出顺序表中的所有元素
    int ListLength();                   //获取顺序表的长度
    void ReverseList();                  //翻转顺序表

private:
    void IncreaseSize();         //当顺序表存满数据后可以调用此函数为顺序表扩容

private:
    T *m_data;                   //存放顺序表中的元素
    int m_length;                 //顺序表当前长度（当前有几个元素）
    int m_maxsize;                //动态数组最大容量
};


#endif //DSA_SEQLIST_H
