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
    cout << "��ʼ˳���Ϊ" << endl;
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
    cout << "ɾ��Ԫ�غ�õ���˳���Ϊ:" << endl;
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
    cout << "����1ɾ�����˳���Ϊ" << endl;
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
    //��ʼ������˳���
    sequentiallist L_example = initialize();
    //ɾ���ظ�Ԫ�ط���1
    repeat_element1(L_example);
    //��ʼ������˳���
    L = initialize();
    //ɾ���ظ�Ԫ�ط���2:���ظ���Ԫ���滻Ϊ���ֵ+1��Ȼ����Q3��ɾ��Ԫ�صķ���������ʱ�临�Ӷ�O(2n)
    repeat_element2(L_example);   
    return 0;
}
/*
Q: Ϊʲô��һ�ַ�����L��Ӱ�쵽�ڶ��ַ�����
*/