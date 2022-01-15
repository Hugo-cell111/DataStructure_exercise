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
    cout << "������˳���ĳ���(����0������)" << endl;
    cin >> L.length;

    //��ʼ��˳���
    srand((int)time(0));
    L.data = new float[L.length];
    cout << "��ʼ˳���Ϊ:" << endl;
    for(int i = 0; i < L.length; i++){
        L.data[i] = rand();
        cout << L.data[i] << " ";
    }
    cout << endl;

    //����
    inverselist(L);
    cout << "������˳���Ϊ:" << endl;
    for(int j = 0; j < L.length; j++){
        cout << L.data[j] << " ";
    }    
    cout << endl;
    return 0;
}
/*
����˼·��
������Ҫ�ռ临�Ӷ�ΪO(1)�����ֻ����ԭ������в�����������ı���Ҫʹ��new�������ڴ档
�¶���ı���tmp����ֻ��һ������������ĳ����ж�󣩣����Կռ临�Ӷ�ΪO(1)
������������ռ�ռ�ֻ���������Ȿ�����㷨�޹أ���ֻ��Ҫ����������ͳ���֮��Ĵ洢�ռ�
Ҫ��ʼ����ʶ�ض�дvoid������������main�������ɹ���Ĺ��ܵײ���룬ֻ��main���������㷨����
*/