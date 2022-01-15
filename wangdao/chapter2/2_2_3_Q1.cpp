#include <iostream>
#include <cstdlib> //随机数
#include <ctime> //随机数时间种子
using namespace std;

#define Initlength 20
#define Maxsize 100 

struct sequentiallist{
    float *data;
    int length;
};

void minimum(sequentiallist &L, int initlength){
    int index = 0;
    float min = L.data[index]; //不需要另外定义一个最小值
    float lastelement = L.data[initlength-1]; //注意索引是initlength-1
    cout << "最后一个元素是" << lastelement << endl;
    if(L.data == NULL){
        cout << "顺序表为空" << endl;
    }
    else{
        for(int i = 0; i < initlength; i++){ //循环变量也要提前声明。C++是强类型语言
            if(L.data[i] < min){
                min = L.data[i];
                index = i;
            }
        }
        cout << "最小索引是" << index+1 << endl;
        cout << "最小元素是" << min << endl;
        L.data[index] = lastelement; //若该数组不是由new定义的，则定义出来的数组是不可变的，也就不能进行元素更改操作
    }
};

int main(){
    sequentiallist L;
    L.data = new float[Initlength]; 

    //初始化顺序表
    srand((int)time(0));
    cout << "初始顺序表为" << endl;
    for (int i = 0 ; i < Initlength ; i++){
        L.data[i] = rand() / double(RAND_MAX); //生成0-1之间的浮点数
        cout << L.data[i] << " ";
    }
    cout << endl;

    //调整顺序表
    minimum(L, Initlength);
    cout << "调整后的顺序表为" << endl;
    for (int i = 0 ; i < Initlength ; i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
1.一定要记得加分号，如定义新变量/新数据类型/操作类语句（define不用）；
2.new开辟长度为Initlength的新内存，指针指向的是数组的首地址，每个区域存储的数据是很接近于0的浮点数；
3.凡是涉及改动实参的操作，函数导入的形参要加上&作为引用。在调用了函数后再次输出顺序表，发现内容变了，也证实了这个性质；
4.C++是强类型语言，在初定义新变量或定义函数参数的时候，必须声明数据类型（struct字段有时候可省略）；
5.define定义好的常量不能在其它地方再次定义。
*/