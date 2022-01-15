#include <iostream>
using namespace std;

struct sequentiallist{
    int* data;
    int length;
};

sequentiallist initialize(){
    sequentiallist L;
    L.length = 20;
    L.data = new int[L.length];
    int arr[L.length] = {1,2,3,3,3,4,5,5,7,9,9,10,11,12,13,13,13,15,15,15};
    cout << "初始顺序表为" << endl;
    for(int i = 0; i < L.length; i++){
        L.data[i] = arr[i];
        cout << L.data[i] << " ";
    }
    cout << endl;
    return L;
};

sequentiallist substitue_ele(sequentiallist L){
    int i = 0;
    int ele = L.data[0] - 1;
    while(i < L.length){
        int k = 1;
        while(L.data[i] == L.data[i + k]){
                L.data[i + k] = ele;
                k++;
            }
        i += k;
    }
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    } 
    cout << endl;
    return L;
};

void delete_ele(sequentiallist L){
    int k = 0;
    int x = L.data[0] - 1;
    for(int i = 0; i < L.length; i++){
        while(L.data[i + k] == x){
            L.length--;
            k++;
        }
        L.data[i] = L.data[i + k];
    }
    cout << "删除元素后得到的顺序表为:" << endl;
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    } 
    cout << endl;
};

void repeat_element1(sequentiallist L){
    int i = 0;
    while(i < L.length){
        if(L.data[i + 1] == L.data[i]){
            int k = 0;
            while(L.data[i + k + 1] == L.data[i]){
                k++;
            }
            
            for(int j = i + 1; j < L.length; j++){
                L.data[j] = L.data[j + k];
            }    
            L.length -= k;        
        }
        i++;
    }
    cout << "方法1删除后的顺序表为" << endl;
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
};

void repeat_element2(sequentiallist L){
    L = substitue_ele(L);
    delete_ele(L);
};

int main(){
    //初始化有序顺序表
    sequentiallist L_example = initialize();
    //删除重复元素方法1
    repeat_element1(L_example);
    //初始化有序顺序表
    L = initialize();
    //删除重复元素方法2:把重复的元素替换为最大值+1，然后用Q3的删除元素的方法。这样时间复杂度O(2n)
    repeat_element2(L_example);   
    return 0;
}
/*
Q: 为什么第一种方法的L会影响到第二种方法？
*/