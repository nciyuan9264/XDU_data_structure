#define ARRAYSIZE 10000
#include<iostream>
#include <ctime>
using namespace std;
const int MAX = 65535;


void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void Mysort(int* a, int n) {
	int k;
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = 0; j + 1 < n - i; j++) {
			if (a[j] > a[j + 1]) {
				k = 1;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (k == 0) {
			break;
		}
	}
}


void Myprint(int* a,int s) {
	for (int i = 0; i < s; i++) {
		cout << a[i]<<" ";
	}
	cout << endl;
}


int main()
{
	cout << "请输入数组长度:" << endl;
	int size, * data, num;
	char stop;
	cin >> size;
	data = new int[ARRAYSIZE];
	srand(time(0));
	cout << "随机初始化" << size << "个数" << endl;
	for (int i = 0; i < size; i++) {
		data[i] = rand() % 1000 + 1;
	}
	cout << "排序前：";
	Myprint(data,size);
	while (size <= ARRAYSIZE)
	{
		num = rand() % 1000 + 1;
		cout << "加入的数：" << num << endl;
		data[size] = num;
		size++;
		Mysort(data, size);
		cout << "排序后：";
		Myprint(data,size);
		cout << "输入g继续，输入q退出";
		cin >> stop;
		if (stop == 'q')
			break;
	}
	system("pause");
	return 0;
}
/*
int main() {
	int data[ARRAYSIZE] = { 10,20,30,40,50 };
	int n = 5;
	int num;
	Myprint(data);
	while (n <= ARRAYSIZE)
	{
		cin >> num;
		if (num == 0) {
			break;
		}
		data[n] = num;
		n++;
		Mysort(data, n);
		Myprint(data);
	}
	system("pause");
	return 0;
}
*/
