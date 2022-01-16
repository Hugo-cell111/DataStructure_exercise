#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//时间复杂度O(n),空间复杂度O(n)
int minimum_positive_integer(int arr[]){
    //开辟新数组
    int tmp_arr[20 + 1];
    for (int i = 0; i < 20 + 1; i++){
        tmp_arr[i] = 0;
    }
    for (int i = 0; i < 20; i++){
        if (arr[i] <= 20 and arr[i] >= 1){
            tmp_arr[arr[i]] = 1;
        }
    }
    int c = 21;
    for (int i = 1; i < 20; i++){
        if (tmp_arr[i] == 0){
            c = i;
            break;
        }
    }
    return c;
} 

//时间复杂度O(n),空间复杂度O(1)
int minimum_positive_integer2(int arr[]){
    for (int i = 0; i < 20; i++){
        //要判断该元素在[1,N]之间，而且不等于其序号(0计数)，而且不会和要交换的数重复（否则无限循环）
        while(arr[i] >= 1 and arr[i] <= 20 and arr[i] != i + 1 and arr[i] != arr[arr[i] - 1]){
            swap(arr[i], arr[arr[i] - 1]);
        }
        cout << i << endl;
    }
    int c = 21;
    for (int i = 0; i < 20; i++){
        if (arr[i] != i + 1){
            c = i + 1;
            break;
        }
    }
    return c;
} 

int main(){
    int arr[20] = {6,7,4,3,2,8,1,9,4,2,6,7,9,4,23,5,78,42,11,23};
    int min = minimum_positive_integer(arr);
    cout << min << endl;
    int min2 = minimum_positive_integer2(arr);
    cout << min2 << endl;
    return 0;
}
/*
一开始是分有1和没有1，然后找一个连续片段，“连续片段最大值+1”或“1”就是要找的最小值。但是困难在于怎么找到连续片段
所以在不确定性如此大的题目，需要充分利用抽屉原理，n个数绝对不会使1-n的抽屉“溢出”
于是创建一个0-n的数组，如果这个数组有空，则最小值（除0）就是所求值；否则n+1为最小值
-----------------------------------------------------------------------------
后来觉得空间复杂度太高了,究其原因是超出数组范围以外的数和确定下来的数没有利用上。
如果能找到一个方法，能在原数组上进行操作就更好了（恢复数组，恢复的是1-N的序列）
*/