#include <iostream>  
using namespace std;
 
void BubbleSort(int array[], int n)
{
	for (int i= 0;i<n-1;i++)
	{
		for (int j = n-1;j>=i;j--)
		{
			if (array[j-1] > array[j])
			{
				swap(array[j - 1], array[j]);
			}
		}
	}
}