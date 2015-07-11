#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int getUpMedian(vector<int> arr1, vector<int> arr2) {

        if(arr1.size() != arr2.size())
            return -1;
        if(arr1.size() == 0)
            return -1;
        
        return getUpMedian(arr1, 0, arr1.size() -1, 
                arr2, 0, arr1.size() -1 );
        }

        int getUpMedian(const vector<int> & arr1, int start1, int end1,
                const vector<int> & arr2, int start2, int end2)
        {
            //cout << "start1\t" << start1 << endl;
            //cout << "end1\t" << end1 << endl;
            //cout << "start2\t" << start2 << endl;
            //cout << "end2\t" << end2 << endl;

            if(start1 == end1)
            {
                return min(arr1[start1], arr2[start2]);
            }

            int size = end1 - start1 + 1;
            int halfSize;
            if(size & 0x1 == 0x1)
            {
                halfSize = (size + 1)/2;
            }
            else
            {
                halfSize = size/2;
            }

            if(arr1[start1 + halfSize - 1] == arr2[start2 + halfSize - 1])
                return arr1[start1 + halfSize - 1];
            else if(arr1[start1 + halfSize - 1] > arr2[start2 + halfSize - 1])
                return getUpMedian(arr1, start1, start1 + halfSize - 1,
                                    arr2, end2-(halfSize-1), end2);
            else //if(arr1[start1 + halfSize - 1] > arr2[start2 + halfSize - 1])
                return getUpMedian(arr1, end1-(halfSize-1) , end1,
                                    arr2, start2, start2 + halfSize -1);
        }
};

int main()
{
    vector<int> vec1;
    vector<int> vec2;

    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(7);
    //vec1.push_back(9);

    vec2.push_back(2);
    vec2.push_back(4);
    vec2.push_back(6);
    vec2.push_back(8);
   // vec2.push_back(10);

    Solution sl;
    //cout << sl.getUpMedian(vec1, vec2) << endl;
    cout << sl.getUpMedian(vec2, vec1) << endl;
    return 0;
}
