#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int n, int i){
    int largest=i, l=2*i+1, r=2*i+2;

    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;

    if(largest!=i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSortIncreasing(vector<int>& a){
    int n=a.size();
    for(int i=n/2-1; i>=0; i--) heapify(a,n,i);

    for(int i=n-1; i>=1; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void heapSortDecreasing(vector<int>& a){
    heapSortIncreasing(a);
    reverse(a.begin(), a.end());
}

int main(){
    vector<int> a = {4,1,3,9,7};

    heapSortIncreasing(a);
    cout<<"Increasing: ";
    for(int x:a) cout<<x<<" ";

    vector<int> b = {4,1,3,9,7};
    heapSortDecreasing(b);
    cout<<"\nDecreasing: ";
    for(int x:b) cout<<x<<" ";
}
