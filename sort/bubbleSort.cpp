#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序
void bubbleSort(vector<int> &arr, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        bool mark = true;
        for (int j = i + 1; j <= high; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                mark = false;
            }
        }
        if (mark)
            break;
    }
}