#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
int minimum_positive_integer(int arr[]){
    //����������
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

//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
int minimum_positive_integer2(int arr[]){
    for (int i = 0; i < 20; i++){
        //Ҫ�жϸ�Ԫ����[1,N]֮�䣬���Ҳ����������(0����)�����Ҳ����Ҫ���������ظ�����������ѭ����
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
һ��ʼ�Ƿ���1��û��1��Ȼ����һ������Ƭ�Σ�������Ƭ�����ֵ+1����1������Ҫ�ҵ���Сֵ����������������ô�ҵ�����Ƭ��
�����ڲ�ȷ������˴����Ŀ����Ҫ������ó���ԭ��n�������Բ���ʹ1-n�ĳ��롰�����
���Ǵ���һ��0-n�����飬�����������пգ�����Сֵ����0����������ֵ������n+1Ϊ��Сֵ
-----------------------------------------------------------------------------
�������ÿռ临�Ӷ�̫����,����ԭ���ǳ������鷶Χ���������ȷ����������û�������ϡ�
������ҵ�һ������������ԭ�����Ͻ��в����͸����ˣ��ָ����飬�ָ�����1-N�����У�
*/