#include <iostream>
using namespace std;

struct sequentiallist{
    int* data;
    int length;
};

void delete_element(sequentiallist L, int x){
    int k = 0;
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

int main(){
    sequentiallist L;
    L.length = 20;
    L.data = new int[L.length];
    int arr[L.length] = {1,2,4,7,8,3,4,3,3,5,6,1,7,3,8,3,5,6,7,8};
    for(int i = 0; i < L.length; i++){
        L.data[i] = arr[i];
    }
    cout << "初始顺序表为:" << endl;
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    }    
    cout << endl;
    int delete_x = 3;
    cout << "要删除的元素是:" << delete_x << endl;
    delete_element(L,delete_x);
    return 0;
}