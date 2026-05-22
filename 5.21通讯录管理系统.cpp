#include<iostream>
#include<cstring>
using namespace std;
#define MAX  1000
//显示菜单界面
void showMenu() {
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出联系人 *****" << endl;
}
//设计联系人的结构体
struct Person {
	int age;
	string m_Name;
	int m_Sex;
	string m_Phone;
	string m_Add;


};
//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];//中保存的人的联系人数组
	int m_size;//通讯录中人的个数

};
//添加联系人
void addperson(Addressbooks* abs)//case1是地址
{//判断通讯论是否已满
	if (abs->m_size == MAX) {
		cout << "通讯录已满" << endl;
		return; }
	else {//添加联系人
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		cout << "请输入性别" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
			{	abs->personArray[abs->m_size].m_Sex = sex;
			break;
		}
			cout << "输出有误" << endl;
		}
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_size].age = age;
		cout << "请输入电话" << endl;
		string  phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Add = address;
		abs->m_size++;//更新人数
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作

	}

}
//显示联系人
void showperson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女")
				<< "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Add << endl;
		}
	}
	system("pause");
	system("cls");

}
//判断联系人是否存在
int isexist(Addressbooks*abs,string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_Name == name) { return i; }//*****返回自己的下标*****
	}return -1;

}
//删除联系人
void deleteperson(Addressbooks* abs) {
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if(ret!=-1){//将后面的数据前移，然后再做一个-1
		for (int i = ret; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");

}

//查找联系人
void Findperson(Addressbooks* abs) {
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1) {
		cout << "姓名" << abs->personArray->m_Name << "\t";
		cout << "性别" << abs->personArray->m_Sex << "\t";
		cout << "年龄" << abs->personArray->age << "\t";
		cout << "电话" << abs->personArray->m_Phone << "\t";
		cout << "住址" << abs->personArray->m_Add << endl;
	}
	else { cout << "查无此人" << endl; }
	system("pause");
	system("cls");

}
//修改联系人
void modifyperson(Addressbooks* abs) {
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		cout << "请输入性别" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输出有误" << endl;
		}
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_size].age = age;
		cout << "请输入电话" << endl;
		string  phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Add = address;
	}
	else{
		cout << "未找到联系人" << endl;

	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanperson(Addressbooks* abs) {
	abs->m_size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}






int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	abs.m_size = 0;//初始化

	int select = 0;
	while (true) {//选择功能
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addperson(&abs);//利用地址传递可以修饰实参
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
			deleteperson(&abs);
			break;
		case 4:
			Findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause"); return 0;
			break;
		default:
			break;
		}
	}

}