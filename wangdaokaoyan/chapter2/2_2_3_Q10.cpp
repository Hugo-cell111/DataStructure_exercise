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
    cout << "初始数组" << endl;
    for (int i = 0; i < 30; i++){
        arr[i] = -2 * i + 7;
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse(arr, 0, 17);
    reverse(arr, 18, 29);
    reverse(arr, 0, 29);
    cout << "调整后数组" << endl;
    for (int i = 0; i < 30; i++){
        cout << arr[i] << " ";
    }
    cout << endl;    
    return 0;
}
/*
思路：
举一个数组的例子，并且使之重复：
1 2 3 4 7 8 9 1 2 3 4 7 8 9 (a)
如果进行镜像对称，会得到：
1 2 3 4 7 8 9 9 8 7 4 3 2 1 (b)
如果我们想把原数组和题目所输出的数组拼起来，会得到：
1 2 3 4 7 8 9 7 8 9 1 2 3 4 (c)
对比b和c数组。我们会发现有部分数组片段是转置了的。所以这提示我们，如果希望得到c的结果，可以：
（1）a到b：整体颠倒；
（2）b到c：部分颠倒。
所以，进行数组的操作可以拓宽思路：
（1）空间的拓宽：如复制扩充数组；（2）操作的拓宽：移动，转置等
*/