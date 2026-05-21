/*线性表入门
https://www.doubao.com/thread/a7da16f7e47cc

https://www.doubao.com/thread/a6ee383d69bae

https://www.doubao.com/thread/a335540c95671

https://www.doubao.com/thread/a23a2bdc2486d

https://www.doubao.com/thread/a86d8f21adf0c

https://www.doubao.com/thread/add2560e78995

https://www.doubao.com/thread/aa63b76245568
*/

/*#include <iostream>
using namespace std;

// 顺序表结构体封装
struct SeqList
{
    int* data;    // 动态数组指针
    int size;     // 当前有效元素个数
    int cap;      // 最大容量
};

// 1. 初始化顺序表
void InitList(SeqList &L)
{
    L.data = new int[4];  // 初始容量4
    L.size = 0;
    L.cap = 4;
}

// 2. 自动扩容函数
void Expand(SeqList &L)
{
    // 1. 计算新容量
    int newCap = L.cap * 2;
    // 2. 开辟新堆空间
    int* newData = new int[newCap];
    
    // 3. 旧数据全部拷贝到新空间
    for(int i = 0; i < L.size; i++)
    {
        newData[i] = L.data[i];
    }
    
    // 4. 释放旧堆内存
    delete[] L.data;
    // 5. 指针指向新空间
    L.data = newData;
    // 6. 更新容量
    L.cap = newCap;
    cout << "扩容成功！当前容量：" << L.cap << endl;
}

// 3. 尾部插入（带自动扩容）
void PushBack(SeqList &L, int val)
{
    // 存满就自动扩容
    if(L.size >= L.cap)
    {
        Expand(L);
    }
    // 尾部插入
    L.data[L.size] = val;
    L.size++;
}

// 4. 遍历打印
void PrintList(SeqList &L)
{
    for(int i = 0; i < L.size; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 5. 彻底释放内存
void FreeList(SeqList &L)
{
    delete[] L.data;
    L.data = nullptr;
    L.size = 0;
    L.cap = 0;
}

int main()
{
    SeqList L;
    InitList(L);

    // 连续插入超过初始4个，自动触发扩容
    for(int i = 1; i <= 10; i++)
    {
        PushBack(L, i);
    }

    cout << "顺序表所有元素：";
    PrintList(L);

    FreeList(L);
    return 0;
}*/
//洛谷P5712
/*#include<iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    if (x == 1) {
        cout << "Today, I ate 1 apple." << endl;
    }
    else if(x == 0){
        cout << "Today, I ate 0 apple." << endl;

    }
    else if(x > 1){
        cout << "Today, I ate "<<x<<" apples." << endl;
    }
    return 0;
}*/
