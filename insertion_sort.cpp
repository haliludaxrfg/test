#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> nums;
    int n;
    cin>>n;
    int _;
    for(int i = 0;i<n;i++){
        cin>>_;
        nums.push_back(_);
    }

    cout<<"INPUT:";
    for(const auto &x:nums){
        cout <<x<<" ";
    }cout <<endl;

    //insertion_sort
    int key;
    for(int j=1;j<n;j++){
        key = nums[j];
        int i = j-1;
        while (i>=0&&nums[i]>key)
        {
            nums[i+1]=nums[i];
            i--;
        }
        nums[i+1]=key;
    }

    cout<<"OUTPUT:";
    for(const auto &x:nums){
        cout <<x<<" ";
    }cout <<endl;
}