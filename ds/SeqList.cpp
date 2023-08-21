//
// Created by Leo Chen on 2023/8/9.
//

#include "SeqList.h"
#include <iostream>

using namespace std;

//通过构造函数对顺序表进行初始化
template<typename T>
SeqList<T>::SeqList(int length) {
    m_data = new T[length]; //为一维数组动态分配内存
    m_length = 0;           //顺序表当前实际长度为0，表示还未向其中存入任何数据元素
    m_maxsize = length;     //顺序表最多可以存储m_maxsize个数据元素
}

//通过析构函数对顺序表进行资源释放
template<typename T>
SeqList<T>::~SeqList() {
    delete[] m_data;
    m_length = 0; //非必须
}

//在第i个位置（位置编号从1开始）插入指定元素e，时间复杂度：O(n)，时间开销主要源于元素的移动
template<typename T>
bool SeqList<T>::ListInsert(int i, const T &e) {
    //如果顺序表已经存满了数据，则不允许再插入新数据了
    if (m_length >= m_maxsize) {
        cout << "顺序表已满，不能再进行插入操作了!" << endl;
        return false;
    }

    //判断插入位置i是否合法，i的合法值应该是1到m_length+1之间
    if (i < 1 || i > (m_length + 1)) {
        cout << "元素" << e << "插入的位置" << i << "不合法，合法的位置是1到" << m_length + 1 << "之间!" << endl;
        return false;
    }

    //从最后一个元素开始向前遍历到要插入新元素的第i个位置，分别将这些位置中原有的元素向后移动一个位置
    for (int j = m_length; j >= i; --j) {
        m_data[j] = m_data[j - 1];
    }
    m_data[i - 1] = e;   //在指定位置i处插入元素e，因为数组下标从0开始，所以这里用i-1表示插入位置所对应的数组下标
    cout << "成功在位置为" << i << "处插入元素" << m_data[i - 1] << "!" << endl;
    m_length++;        //实际表长+1
    return true;
}

//删除第i个位置的元素
template<typename T>
bool SeqList<T>::ListDelete(int i) {
    if (m_length < 1) {
        cout << "当前顺序表为空，不能删除任何数据!" << endl;
        return false;
    }
    if (i < 1 || i > m_length) {
        cout << "删除的位置" << i << "不合法，合法的位置是1到" << m_length << "之间!" << endl;
        return false;
    }
    cout << "成功删除位置为" << i << "的元素，该元素的值为" << m_data[i - 1] << "!" << endl;
    //从数组中第i+1个位置开始向后遍历所有元素，分别将这些位置中原有的元素向前移动一个位置
    for (int j = i; j < m_length; ++j) {
        m_data[j - 1] = m_data[j];
    }
    m_length--;       //实际表长-1
    return true;
}


template<typename T>
int SeqList<T>::LocateElem(const T &e) {
    for (int i = 0; i < sizeof(m_data) / sizeof(m_data[0]); i++) {

    }
}

int main() {
    SeqList<int> seqobj(10);

    seqobj.ListInsert(1, 15);
    seqobj.ListInsert(2, 10);
    seqobj.ListInsert(30, 8);
}
