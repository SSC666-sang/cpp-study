/*#include<iostream>
using namespace std;
int main() {
    double a;
    cin >> a;
    int b = int(a * 10) % 10;   //为什么加int
    int c = a;//直接取整
    int d = c /100;
    int e = (c - d * 100) / 10;
    int f = c % 10;
    double g = b + 0.1 * f + 0.01 * e + 0.001 * d;
    cout << g << endl;
    return 0;





}*/
/*#include<iostream>
#include<iomanip>//头文件
using namespace std;
int main() {
    double t;
    int n;
    cin >> t >> n;
    double a;
    int b;
    a = t / n;
    b = n * 2;
    cout << fixed << setprecision(3) << a << endl;//fixed要存在
    cout << b << endl;
    return 0;
}*/
/*#include<iostream>
#include<cstdio>
#include<iomanip>//cout
using namespace std;
int main() {
    int s, v;
    cin >> s >> v;
   //int walktime = ceil((double)s / v);//向上取整，哈哈出错了，原本没加double
    int walktime = (s + v - 1) / v;
    int totaltime = walktime + 10;
    int start = 8 * 60 - totaltime;
    if (start < 0) {
        start += 24 * 60;

    }
    int h = start / 60;
    int m = start % 60;
    printf("%02d:%02d\n", h, m);//输出格式为 HH:MM不会
    //cout<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<endl;
    return 0;
}*/
//P1035
/*#include<iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    int n=0;
    double s=0.0;//开始没有初始化
    while (s <= k) {
        n++;
        s += 1.0 / n;
    }
    cout << n << endl;
    return 0;
}*/




//顺序表
/*#include<iostream>
using namespace std;
#define maxsize 6
struct sqlist {
    int data[maxsize];//定数组上限，后续动态变化，插入删除
    int length;//记录实际长度
};

sqlist l;//创建一个空表
l.length = 0;

//查找元素
int find(sqlist l, int e) {
    for (int i = 0; i < l.length; i++)
    {
        if (l.data[i] == e) { return i + 1;//i是返回序号 }
    }
    return -1;
}

//插入元素
//成功返回true
    bool insert(sqlist &l,int i,int e){ //在i处插入e
    if (l.length == maxsize)return false;//达到上限
        if (i<1 || i>l.length + 1)return false;//
        for (int j = l.length - 1; j >= i - 1:j++) {//让j从最后一个位置枚举到第i处也就是下标i-1
            l.data[j + 1] = l.data[j];//每枚举就把值后移一个
        }
        l.data[i - 1] = e;//完成后i处位置就腾出
        l.length++;//长度增加
        return ture;
    }


//删除操作
    bool delete(sqlist& l, int i) {//删除第i个元素
        if（i<1 || i>l.length)return false;
        for (int j = i; j <= l.length - 1; j++)//要删下标i-1的，让j从下标i处向后枚举到最后
        {
            l.data[j - 1] = l.data[j];//每一次就把j的值给前一个
        }
        l.length--;
        return ture;
    }*/



/*#include<iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b = a / 2;
    int d = 0;
    for (int c = b; c >= 1; c--)
    {
        d += 1 + (c / 2);
        
    }
   int  s = 1 +  d;
   cout << s << endl;
   return 0;
}
*///我的错误
/*#include<iostream>
using namespace std;
int n;
int f[1005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            f[i] += f[j];
        }
        f[i]++;
    }
    cout << f[n];
    return 0;
}*/

/*#include<iostream>
#include<cstring>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int hui=1, dui=1;
    for (int i = 0; i < a.length(); i++)hui *= a[i] - 64;
    for(int i=0;i<b.length();i++)dui*=b[i]-64;
    hui %= 47; dui %= 47;
    if (hui == dui) { cout << "Go" << endl; }
    else { cout << "STAY" << endl; }
    return 0;
}*/
/*#include <iostream>
using namespace std;
typedef int ElemType;//起别名，后面改类型更容易
class SeqList  //定义顺序表类，属性，操作封装在一起
{
private:                   //私有成员，外部（main函数）无法访问，
    ElemType* arr;
    int size;//有效元素个数
    int cap;//总容量
public:
    SeqList()
    {
        arr = nullptr;//杜绝野指针
        size = 0;
        cap = 0;
    }
    // 扩容
    void expand()
    {
        if (size < cap) return;
        int newCap = cap == 0 ? 4 : cap * 2;
        ElemType* newArr = new ElemType[newCap];
        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];
        delete[] arr;//释放旧数组
        arr = newArr;
        cap = newCap;
    }
    // 尾插
    void push_back(ElemType val)
    {
        expand();//先扩容
        arr[size++] = val;
    }
 // 清空元素
    void clear()
    {
        size = 0;
    }
    // 销毁整张表
    void destroy()
    {
        delete[] arr;
        arr = nullptr;//防止野指针访问以释放内存
        size = cap = 0;
    }
    // 打印
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // 析构
    ~SeqList()
    {
        destroy();
    }
};

int main()
{
    SeqList s;
    for (int i = 1; i <= 10; i++)
        s.push_back(i);

    s.print();
    s.clear();    // 清空
    s.push_back(999);
    s.print();

    return 0;
}
*/


/*#include<iostream>
using namespace std;
int main() {
    int l, r; int count = 0;
    cin >> l >> r;
    //for (int n; n >= l && n <= r; n++) {//局部变量只
    //声明没有初始化，成了个垃圾值
    for (int n= l; n <= r; n++) {
        int temp = n;//最开始没有这个，没有临时变量
        //n不断变小，无法做到n++
        while (temp> 0) {
            int w = temp% 10;
            if (w == 2) { count++; }

            temp= temp/ 10;
        }

    }
    cout << count << endl;
    return 0;
}*/
/*#include<iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int c = (10 * a + b) / 19;
    cout << c << endl;
}*/

/*#include <iostream>
using namespace std;

int main()
{
    int cost[13];  // 1~12月存花费，下标1好用
    int money = 0; // 手里零钱
    int cun = 0;   // 存起来的钱

    // 第一步：把12个月花费全部读进数组
    for (int i = 1; i <= 12; i++)
    {
        cin >> cost[i];
    }

    // 第二步：按月模拟
    for (int i = 1; i <= 12; i++)
    {
        money += 300;       // 每月领300
        money -= cost[i];   // 花掉当月钱

        if (money < 0)       // 没钱了
        {
            cout << -i;
            return 0;
        }

        // 存整百
        int bai = money / 100;
        cun += bai * 100;
        money = money % 100;
    }

    // 年底结算
    int ans = cun * 1.2 + money;
    cout << ans;
    return 0;
}*/

//单链表
/*#include <iostream>
using namespace std;
// 节点定义，模板
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// 头插法建表：输入n个元素，返回链表头指针
ListNode* createListByHeadInsert() {
    ListNode* head = nullptr;  // 初始化空链表
    int n, val;
    cout << "请输入链表元素个数n：";
    cin >> n;
    cout << "请输入" << n << "个元素（空格分隔）：";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        ListNode* s = new ListNode(val);  // 创建新节点
        s->next = head;                   // 新节点next指向原头结点
        head = s;                         // 更新头指针为新节点
    }
    return head;
}

// 遍历链表（输出所有元素）
void printList(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 释放链表内存（避免内存泄漏）
void freeList(ListNode* head) {
    ListNode* p;
    while (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}

int main() {
    ListNode* head = createListByHeadInsert();
    cout << "头插法生成的链表：";
    printList(head);
    freeList(head);  // 释放内存
    return 0;
}*/



/*#include<iostream>
using namespace std;
int main() {
    int ping[10];
    for (int i = 0; i < 10; i++) {
        cin >> ping[i];
    }
    int tao;
    cin >> tao;
    int a = 0;
    for (int i=0; i < 10; i++) {
        if (tao + 30 >= ping[i])
            a++;
    }
    cout << a << endl;
}
*/
/*#include<iostream>
using namespace std;
int main() {
    int n, c;
    cin >> n >> c;
    long long* a = new long long[n];//动态数组
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (a[i] - a[j] == c)
            {
                count += 1;
            }
        }
    }
    cout << count << endl;
        delete[]a;
        return 0;
}
*/
//5.18
/*#include <iostream>
using namespace std;
struct student {
    string name;
    int id;
    double score;
};
int main() {
    student st1;
    student st4;
    st1.name = "张三";
    st1.id = 123456;
    st1.score = 96.3;
    st4 = st1;
    cout << "姓名" << st1.name <<st4.name<< endl;
    cout << "学号" << st1.id << st4.id<<endl;
    cout << "成绩" << st1.score <<st4.score<< endl;
    return 0;

}*/
//结构体与数组
/*#include<iostream>
using namespace std;
struct student {
    string name;
    int id;
};
int main() {
    student st[2];
    st[0].name = "ming";
    st[0].id = 123;
    st[1].name = "hei";
    st[1].id = 456;
    cout << st[0].name<<st[0].id<< endl;
}*/
//洛谷P1090
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10001;//果子堆数
int a[maxn];//每堆树
int n;
long long stre = 0;//记录体力消耗
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (n > 1) {//判断条件堆数大于1
        sort(a, a + n);//把数组的a前n个元素小到大排序
        int newn = a[0] + a[1];//两个小的合并成一个大的
        stre += newn;
        a[0] = newn;//新和成的在a[0]
        for (int i = 1; i < n - 1; i++) {
            a[i] = a[i + 1];//之后每一位都前移
        }
        n--;//堆数减一
    }//开始进行下一次排序，累加，直到堆数为一
    cout << stre << endl;
    return 0;
}












































































































