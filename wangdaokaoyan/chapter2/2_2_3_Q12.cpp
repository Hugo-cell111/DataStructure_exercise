#include <iostream>
using namespace std;

int main(){
    int arr[9] = {0, 5, 5, 3, 5, 3, 7, 5, 3};
    int times = 1, length = 9;
    int x = arr[0];
    //必要条件
    for(int i = 1; i < length; i++){
        if(arr[i] == x){
            times++;
        }
        else{
            times--;
        }
        if(times < 0){
            x = arr[i];
            times = 1;
        }
    }
    //再次检查
    times = 0;
    for(int i = 0; i < length; i++){
        if(arr[i] == x){
            times++;
        }
    }
    if(times > length/2){
        cout << "main element exists:" << x << endl;
    }
    else{
        cout << "Not exist" << endl;
    }
    return 0;
}
/*
解题思路：
有几个限定条件：
(1)落于区间[0,n-1];(2)一共n个数
这是一个很典型的抽屉原理问题，比较极端的情形是主元素（如果有）和其它数交错排序，或者全部排在一起。
一个特点是主元素（如果有）比其它所有元素都多，可以两两配对下还有多余的出来。
那有没有什么量，是主元素独有而非主元素没有的？可以引入“求和量”，当遇到下一个不一样的数，就减1；减到负数时立刻保存下一个数。
这样循环下，因为除主元素（如果有）外的所有元素都无法保证在扫描一遍数组后还能使得“求和量”＞=0
但是，有这个性质的数并不一定是主元素。所以要再扫描一次数组再做确定。
*/
