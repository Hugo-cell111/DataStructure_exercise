#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Sequentiallist{
    float* data;
    int length;
};

void inverselist(Sequentiallist &L){
    int tmp;
    for(int j = 0; j < L.length/2 ; j++){
        tmp = L.data[j];
        L.data[j] = L.data[L.length - 1 - j];
        L.data[L.length - 1 - j] = tmp;
    }
};

int main(){
    Sequentiallist L;
    cout << "请输入顺序表的长度(大于0的整数)" << endl;
    cin >> L.length;

    //初始化顺序表
    srand((int)time(0));
    L.data = new float[L.length];
    cout << "初始顺序表为:" << endl;
    for(int i = 0; i < L.length; i++){
        L.data[i] = rand();
        cout << L.data[i] << " ";
    }
    cout << endl;

    //逆序
    inverselist(L);
    cout << "逆序后的顺序表为:" << endl;
    for(int j = 0; j < L.length; j++){
        cout << L.data[j] << " ";
    }    
    cout << endl;
    return 0;
}
/*
解题思路：
由于需要空间复杂度为O(1)，因此只能在原数组进行操作。而数组改变需要使用new开辟新内存。
新定义的变量tmp由于只有一个（无论数组的长度有多大），所以空间复杂度为O(1)
若输入数据所占空间只决定于问题本身，和算法无关，则只需要分析除输入和程序之外的存储空间
要开始有意识地多写void函数，避免在main函数集成过多的功能底层代码，只让main函数体现算法流程
*/