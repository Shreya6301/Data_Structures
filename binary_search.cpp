#include <iostream>
#include <vector>
using namespace std;

//Iterative approach for Binary Search Algorithm
int binarySearch(vector<int> arr,int target){
    int start =0, end = arr.size()-1;
     while(start<=end){
        int mid = (start+end)/2;
        if(target > arr[mid]){
            start = mid+1;
        } else if(target < arr[mid]){
            end = mid -1;
        }else{
            return mid;
        }
        
}
  return -1;
}

int main(){
    vector<int> arr1 = {-1,0,3,4,5,9,12};
    int target1 = 12;

    cout<< binarySearch(arr1,target1) <<endl;
    return 0;
}
