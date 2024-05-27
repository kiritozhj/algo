#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// 快速排序
// 标准做法（递归）
/* i是最终枢轴的位置，以最后一个元素作为比较的枢轴元素，依次寻找小于pivot的元素，将i向后移动，最终停止的位置即为枢轴位置
 */
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // 选择最后一个元素作为枢轴
    int i = low - 1;       // i是较小元素的索引

    for (int j = low; j < high; j++)
    {
        // 如果当前元素小于或等于枢轴
        if (arr[j] <= pivot)
        {
            i++;                  // 增加较小元素的索引
            swap(arr[i], arr[j]); // 交换arr[i]和arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // 交换arr[i+1]和枢轴元素
    return i + 1;                // 返回枢轴的位置
}

// 快速排序的递归函数
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // 分区索引

        // 递归排序分区
        quickSort(arr, low, pi - 1);  // 排序左边分区
        quickSort(arr, pi + 1, high); // 排序右边分区
    }
}

// 非递归快速排序
void quickSort(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;

    // 创建一个栈来保存数组的边界
    stack<pair<int, int>> s;
    s.push({low, high});

    while (!s.empty())
    {
        // 取出栈顶的边界
        auto [low, high] = s.top();
        s.pop();

        // 分区
        if (low < high)
        {
            int pi = partition(arr, low, high);

            // 将子数组的边界推入栈中
            s.push({low, pi - 1});
            s.push({pi + 1, high});
        }
    }
}

// // 挖坑法
// int partition(vector<int>& arr, int low, int high) {
//     int pivot = arr[low]; // 选择第一个元素作为枢轴
//     int hole = low; // 初始化挖坑的位置

//     while (low < high) {
//         // 从右向左找小于枢轴的元素
//         while (low < high && arr[high] >= pivot) {
//             high--;
//         }
//         if (low < high) {
//             arr[hole] = arr[high]; // 将找到的元素放入挖坑处
//             hole = high; // 更新挖坑的位置
//         }

//         // 从左向右找大于枢轴的元素
//         while (low < high && arr[low] <= pivot) {
//             low++;
//         }
//         if (low < high) {
//             arr[hole] = arr[low]; // 将找到的元素放入挖坑处
//             hole = low; // 更新挖坑的位置
//         }
//     }

//     arr[hole] = pivot; // 将枢轴放入挖坑的位置
//     return hole; // 返回枢轴的位置
// }

// // 递归快速排序
// void quickSort(vector<int>& arr, int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high); // 分区
//         quickSort(arr, low, pi - 1); // 排序左半部分
//         quickSort(arr, pi + 1, high); // 排序右半部分
//     }
// }