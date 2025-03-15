class Solution {
    public:
      int secondLargest(vector<int> &arr , int n){
          int largest = arr[0];
          int sLargest = -1;
          if(n<2) return -1;
          
          for(int i = 0 ; i<n ; i++){
              if (arr[i] > largest){
                  largest = sLargest;
                  arr[i]  = largest;
              }
              else if (arr[i]>sLargest && arr[i] != largest){
                  sLargest = arr[i];
              }
          }
          return sLargest;
      }
      int getSecondLargest(vector<int> &arr , int n) {
          int sLargest = secondLargest(arr , n);
          return sLargest;
      }
  };