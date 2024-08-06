#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// 合并两个已排序的子数组
void merge(vector<int>& arr, int left, int mid, int right) {
    // 创建临时数组
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    // 合并两个子数组
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // 处理剩余元素
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将临时数组中的元素拷贝回原数组
    for (int i = 0; i < temp.size(); ++i) {
        arr[left + i] = temp[i];
    }
}

// 自顶向下的归并排序函数
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);         // 排序左半部分
        mergeSort(arr, mid + 1, right);    // 排序右半部分
        merge(arr, left, mid, right);      // 合并两部分
    }
}

// 自底向上的归并排序函数
void mergeSortBU(vector<int>& arr) {
    int n = arr.size();
    // 每次合并的子数组的大小
    for (int size = 1; size < n; size *= 2) {
        // 遍历每个子数组
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}