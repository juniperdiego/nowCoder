#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        int getLessIndex(vector<int> arr) 
        {
            if(arr.size() == 0)
                return -1;
            if(arr.size() == 1)
                return 0;
            if(arr[0] < arr[1])
                return 0;

            int size = arr.size();
            if(arr[size - 1] < arr[size - 2])
                return size - 1;

            int low = 1;
            int high = size - 2;
            int mid;

            while(low < high)
            {
                mid = (low + high)/2;
                if(arr[mid] > arr[mid+1])
                {
                    low = mid+1;
                }
                else if(arr[mid] > arr[mid-1])
                {
                    high = mid-1;
                }
                else
                    return mid;
            }
            return low;
            
        }
};

int main()
{
    Solution sl;
    vector<int> vec;

    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);

    cout << sl.getLessIndex(vec) << endl;
}
