#include<bits/stdc++.h>
using namespace std;
int counter;
int partitioned(int a[],int left,int right){
    int median;
    if(a[left] < a[right]){
        if(a[left] > a[(left+right)/2])
            median = left;
        else if(a[right] < a[(left+right)/2])
            median = right;
        else
            median = (left+right)/2;
    }
    else{
        if(a[right] > a[(left+right)/2])
            median = right;
        else if(a[left] < a[(left+right)/2])
            median = left;
        else
            median = (left+right)/2;
    }
    swap(a[left],a[median]);
    int pivot = left,i = left+1,j;
    while(i < right+1){
        if(a[i] > a[pivot])
            break;
        i++;
    }
    j = i;
    while(1){
        while(j < right+1){
            if(a[j] < a[pivot])
                break;
            j++;
        }
        if(j == right+1)
            break;
        swap(a[i],a[j]);i++;j++;
    }
    swap(a[pivot],a[i-1]);
    return i-1;
}
void quicksort(int a[],int left,int right){
    int p;
    if(left < right){
        p = partitioned(a,left,right);
        quicksort(a,left,p-1);
        quicksort(a,p+1,right);
        counter += right-left;
    }
}
int main(){
    int a[10001],i = 0;
    string c;
    ifstream f("QuickSort.txt");
    getline(f,c,'\n');
    while(!f.eof()){
        a[i++] = stoi(c);
        getline(f,c,'\n');
    }
    quicksort(a,0,9999);
    cout<<counter;
}
