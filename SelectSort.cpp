/*************************************************************************
> File Name: SelectSort.cpp
> Author: Shorey
> Mail: shoreybupt@gmail.com
> Created Time: 2015年04月09日 星期四 09时06分49秒
************************************************************************/

#include<iostream>  
using namespace std;
void SelectSort(int a[], int n)//选择排序  
{
	for (int i = 0; i<n - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j<n; j++)
		{
			if (a[j]<a[index])//寻找无序区内的最小值  
				index = j;
		}
		if (index != i)             //把找到的最小值放到无序区的最前面  
		{
			swap(a[i], a[index]);
		}
	}
}

int main()
{
	int a[5] = {
		7,3,1,5,70
	};
	SelectSort(a, 5);
	for (int i = 0;i<5;i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}