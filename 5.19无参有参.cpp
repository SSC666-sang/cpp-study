//1.无参函数
/*#include<iostream>
using namespace std;
void showtips() {//没有返回值，只会执行它里面的代码
	cout << "无参函数执行" << endl;
}
int main() {
	showtips();
	return 0;
}*/
//运行结果：无参函数执行

//2.有参函数----主函数传入数据，函数接收数据完成运算
/*#include<iostream>
using namespace std;
int getsum(int a, int b)
{
	return a + b;
}
int main() {
	int x = 10; int y = 15;
	cout<<getsum(x, y)<<endl;
	return 0;
}*/
//运行结果：25

//3.函数返回值
/*int用return返回数据
void无返回值函数，只打印内部的*/

//4.传值调用--主函数打印原始参数，修改形参只会改变函数内部打印结果
/*#include<iostream>
using namespace std;
int square(int n)
{
	n = n * n;
	return n;
}
int main() {
	int num = 7;
	int res = square(num);
	cout << num << endl;
	cout << res << endl;
	return 0;
}*/
//结果：7   49

//洛谷P1018,动态规划，先把前半段的最优解算好，就只需枚举最后一个符号的位置
//不管前面怎分，最后一个符号后数固定，保证前面最优解
/*#include<iostream>
#include<cstring>
#include<algorithm>
const int maxn = 45;
long long dp[maxn][10];//dp[i][j]前i个书，j个乘号最大值
long long num[maxn][maxn];//num[a][b]第a到第b位组成的数
using namespace std;
int main() {
	int N, K;//N数字个数；K乘号个数
	string s;
	cin >> N >> K >> s;
	//下面求两个乘号之间的数字
	for (int i = 1; i <= N; i++) {
		num[i][i] = s[i - 1] - '0';//求第i位的那个数数组下标-1；且s存的是
		//字符，需要用-'0'转化为数
		for (int j = i+1; j <= N; ++j) {
			num[i][j] = num[i][j - 1] * 10 + (s[j - 1] - '0');
			//起点固定为i，拼接终点位j；已经拼好i---j-1位的，整体*10加j处的就是新数字
		}
	}
	//0个*的情况，初始化
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = num[1][i];
	}
	//动态规划
	for (int j = 1; j <= K; ++j) { // 乘号数量，以此计算1到K个*情况，先算出
		//少乘号才能算出多*
		for (int i = j + 1; i <= N; ++i) { // 数字长度，j个*至少j+1个数字
			for (int k = j; k < i; ++k) { // 最后一个乘号放在k处后面
				dp[i][j] = max(dp[i][j], dp[k][j - 1] * num[k + 1][i]);
//dp[k][j - 1] * num[k + 1][i]前k个数最有*最后组成的数，旧与新比，大的赋值	
			}
		}
	}
	cout << dp[N][K] << endl;
	return 0;
}
*/
//洛谷P5710
//原本是想写一堆函数的现在看来不用
/*#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	bool p1 = (x % 2 == 0);
	bool p2 = (x > 4 && x <= 12);
	int a = (p1 && p2) ? 1 : 0;
	int u = (p1 || p2) ? 1 : 0;
	int b = (p1 != p2) ? 1 : 0;
	int z = (!p1 && !p2) ? 1 : 0;
	cout << a << " " << u << " " << b << " " << z << endl;
	return 0;
}*/

//洛谷P5711很典型的闰年判断
//不知道为啥今天很想用函数
/*#include<iostream>
using namespace std;
bool a1(int x) {
	return x % 4 == 0 && x % 100 != 0;
}
bool a2(int x) {
	return x % 400 == 0;
}
bool a3(int x) {
	return a1(x) || a2(x);
}
int main() {
	int x;
	cin >> x;
	cout << a3(x) << endl;
	return 0;
}*/
//这是另一种
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}