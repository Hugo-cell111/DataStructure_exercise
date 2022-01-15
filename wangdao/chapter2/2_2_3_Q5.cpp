#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct sequentiallist{
    float* data;
    int length;
};

void delete_element(sequentiallist &L, int s, int t){
    if(s >= t){
        cout << "输入的s和t不合法" << endl;
        exit(0);
    }
    else if(L.data == NULL){
        cout << "顺序表为空" << endl;
        exit(0);
    }
    else{
        int k = 0;
        for(int i = 0; i < L.length; i++){
            while(L.data[i + k] >= s and L.data[i + k] <= t){
                L.length--;
                k++;
            }
            L.data[i] = L.data[i + k];
        }
    }
    cout << "删除元素后得到的顺序表为:" << endl;
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    } 
    cout << endl;
}

int main(){
    srand((int)time(0));
    sequentiallist L;
    L.length = 10;
    L.data = new float[L.length];
    for(int i = 0;i < L.length; i++){
        L.data[i] = rand()*10 / double(RAND_MAX);
    }
    cout << "初始顺序表为" << endl;
    for(int i = 0 ; i < L.length ; i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
    int s = 3;
    int t = 5;
    delete_element(L, s, t);
    return 0;
}