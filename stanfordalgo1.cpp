#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inversions;
ll j = 0,i,temp;char b[10];
int a[1000001];
void merger(int nums[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;
    int lAr[leftLength];
    int rAr[rightLength];
    for (int i = 0; i < leftLength; i++) {
        lAr[i] = nums[left + i];
    }
    for (int i = 0; i < rightLength; i++) {
        rAr[i] = nums[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < leftLength && j < rightLength) {
        if (lAr[i] <= rAr[j]) {
            nums[k] = lAr[i];
            inversions += j;
            i++;
        }
        else{
            nums[k] = rAr[j];
            j++;
        }
        k++;
    }
    inversions += (long) j * (leftLength - i);
    if (i >= leftLength) {
        for (; j < rightLength; j++, k++) {
            nums[k] = rAr[j];
        }
    }
    else {
        for (; i < leftLength; i++, k++) {
            nums[k] = lAr[i];
        }
    }
}
void getInversions(int nums[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        getInversions(nums, left, mid);
        getInversions(nums, mid + 1, right);
        merger(nums, left, mid, right);
    }
}

int main(){
    ifstream input("IntegerArray.txt",ifstream::in);
    //ifstream input;
    while(!input.eof()){
        input.getline(b,10);
        temp = 0;
        for(i = 0; b[i] != '\0'; i++){
            temp = temp*10 + (b[i]-'0');
        }
        a[j++] = temp;
    }
    input.close();
    getInversions(a,0,j-1);
    cout<<inversions;
}
