#include <iostream>
using namespace std;

void reverse(int (&arr)[30], int head, int tail){
    int head1 = head;
    int head2 = tail;
    int tmp;
    while(head1 < head2){
        cout << "s";
        tmp = arr[head1];
        arr[head1] = arr[head2];
        arr[head2] = tmp;
        head1++;
        head2--;
    }
}

int main(){
    int arr[30];
    cout << "��ʼ����" << endl;
    for (int i = 0; i < 30; i++){
        arr[i] = -2 * i + 7;
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse(arr, 0, 17);
    reverse(arr, 18, 29);
    reverse(arr, 0, 29);
    cout << "����������" << endl;
    for (int i = 0; i < 30; i++){
        cout << arr[i] << " ";
    }
    cout << endl;    
    return 0;
}
/*
˼·��
��һ����������ӣ�����ʹ֮�ظ���
1 2 3 4 7 8 9 1 2 3 4 7 8 9 (a)
������о���Գƣ���õ���
1 2 3 4 7 8 9 9 8 7 4 3 2 1 (b)
����������ԭ�������Ŀ�����������ƴ��������õ���
1 2 3 4 7 8 9 7 8 9 1 2 3 4 (c)
�Ա�b��c���顣���ǻᷢ���в�������Ƭ����ת���˵ġ���������ʾ���ǣ����ϣ���õ�c�Ľ�������ԣ�
��1��a��b������ߵ���
��2��b��c�����ֵߵ���
���ԣ���������Ĳ��������ؿ�˼·��
��1���ռ���ؿ��縴���������飻��2���������ؿ��ƶ���ת�õ�
*/