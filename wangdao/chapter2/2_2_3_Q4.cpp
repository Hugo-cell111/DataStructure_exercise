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
    cout << "��ʼ˳���Ϊ" << endl;
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
    cout << "ɾ�����˳���Ϊ" << endl;
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
˳�����ָ �����ڴ洢λ�������ڣ�������ֵ��һ��������ݼ�;
����˳����������ֵ������ݼ���˳���.
�磺[1,2,3,4,5,6]��˳���Ҳ������˳���
[1,2,3,4,6,5]��˳�����������˳���
*/