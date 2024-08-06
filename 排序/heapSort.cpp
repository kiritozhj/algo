#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 将一个子树调整为最大堆
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;    // 将当前节点作为最大值
    int left = 2 * i + 1;   // 左子节点
    int right = 2 * i + 2;  // 右子节点

    // 如果左子节点大于当前最大值
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于当前最大值
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是当前节点
    if (largest != i) {
        swap(arr[i], arr[largest]);  // 交换
        heapify(arr, n, largest);    // 递归调整
    }
}

// 主堆排序函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 逐个从堆中取出元素并调整堆
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // 将当前最大值（堆顶）移到数组末尾
        heapify(arr, i, 0);    // 调整剩余元素成为最大堆
    }
}

int main()
{
    vector<int>arr{5,4,3,2,1};
    heapSort(arr);
    for(int i:arr)
        cout<<i<<" ";
}