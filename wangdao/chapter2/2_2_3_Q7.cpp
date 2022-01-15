#include <iostream>
using namespace std;

int main(){
    int arr1[10] = {1,2,5,7,13,14,16,24,28,36};
    int arr2[7] = {2,4,6,8,12,20,35};
    int arr3[17];
    int head1 = 0;
    int head2 = 0;
    int index = 0;
    while(head1 < 10 or head2 < 7){
        if (arr1[head1] <= arr2[head2]){
            arr3[index] = arr1[head1];
            head1++;
            index++;
        }
        else{
            arr3[index] = arr2[head2];
            head2++;
            index++;
        }
    }
    for (int k = 0; k < 17; k++){
        cout << arr3[k] << " ";
    }
    cout << endl;
    return 0;
}
