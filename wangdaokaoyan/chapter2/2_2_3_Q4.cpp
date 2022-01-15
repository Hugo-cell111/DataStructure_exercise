#include <iostream>
using namespace std;

struct sequentiallist{
    int* data;
    int length;
};

int main(){
    sequentiallist L;
    L.length = 30;
    int s = 7;
    int t = 13;
    cout << "初始顺序表为" << endl;
    for(int i = 0; i < L.length; i++){
        L.data[i] = 2 * i;
        cout << L.data[i] << " ";
    }
    cout << endl;
    int k = 0;
    int flag = 0;
    int i = 0;
    while(flag == 0){
        if(L.data[i + k] >= s){
            while(L.data[i + k] <= t){
                k++;
            }
            for(int j = i; j < L.length - k; j++){
                L.data[j] = L.data[j + k];
            }
            flag += 1;
            L.length -= k;
        }
        i++;
    }
    cout << "删除后的顺序表为" << endl;
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
顺序表是指 数据在存储位置上相邻，但数据值不一定递增或递减;
有序顺序表就是数据值递增或递减的顺序表.
如：[1,2,3,4,5,6]是顺序表也是有序顺序表
[1,2,3,4,6,5]是顺序表但不是有序顺序表
*/