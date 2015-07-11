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

        int findKthNum(vector<int> arr1, vector<int> arr2, int kth)
        {
            int size1 = arr1.size();
            int size2 = arr2.size();

            if(size1 > size2)
            {
                return findKthNum(arr2, arr1, kth);//ensure size1 < size2
            }
            cout << "size1\t" << size1 << endl;
            cout << "size2\t" << size2 << endl;

            if(kth <= size1)
                return getUpMedian(arr1, 0, kth - 1, arr2, 0, kth - 1);
           else if (kth <= size2 && kth > size1)
           //i.e.s1 = 10, s2 = 20, kth = 14; 
           // for arr2, kth + 1 ~ size2(15 ~ 20) is impossibly answer 
           // for arr2, 1 ~ kth - size1 -1 (1 ~ 3) is impossibly answer
           // so arr2 has  20 - 6 - 3  = 11 numbers, but arr1 has 10 numbers
           // so jundge one element of arr2 firstly, the call getUpMedian
           {
                if(arr2[kth - size1 - 1] >= arr1[size1 - 1] )
                    return arr2[kth - size1 - 1];
                return getUpMedian(arr1, 0, size1-1, arr2, kth-size1, size2-1);
           }

           else //if (kth > size2) 
           //i.e.s1 = 10, s2 = 20, kth = 25; 
           // first 4(kth - s2 - 1) of arr1 is impossibly answer. so just remove them
           // first 14(kth - s1 - 1) of arr2 is impossibly answer.so just remvoe them
           // arr1 still has s1 - (kth - s2 - 1) = s1 + s2 - kth + 1 numbers (6)
           // arr2 still has s2 - (kth - s1 - 1) = s1 + s2 - kth + 1 numbers (6)
           // we removes 2 * kth - s1 - s2 -2 numbers, (18)
           // now we junge if arr1[kth-s2-1] and arr2[kth-s1-1] is the answer,if not, we remother them
           // then we removes 2 * kth - s1 - s2  numbers (20)
           // and arr1 and arr2 both have s1 + s2 - kth numbers(5)
           // we just calc upMedia of them and got the answer, 20 + 5 = 25
           {
            cout << arr2[kth-size1-1]  << endl;
            cout << arr1[size1 - 1] << endl;
            cout << arr1[kth-size2-1]  << endl;
            cout << arr2[size2 - 1] << endl;
                if(arr2[kth-size1-1] >= arr1[size1-1])
                    return arr2[kth-size1-1];
                if(arr1[kth-size2-1] >= arr2[size2-1])
                    return arr1[kth-size2-1];
               return getUpMedian(arr1, kth-size2, size1-1, arr2, kth-size1, size2-1);
           }

                

        }
};

int main()
{
    vector<int> vec1;
    vector<int> vec2;

    vec1.push_back(6);
    vec1.push_back(6);
    vec1.push_back(9);
    vec1.push_back(9);
    vec1.push_back(9);
    vec1.push_back(11);
    vec1.push_back(14);

    vec2.push_back(6);
    vec2.push_back(10);
    vec2.push_back(18);
    vec2.push_back(23);
    vec2.push_back(41);
    vec2.push_back(43);
    vec2.push_back(45);

    Solution sl;
    cout << sl.findKthNum(vec1, vec2, 12) << endl;
    vec1.clear();
    vec2.clear();

    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(7);
    vec1.push_back(9);

    vec2.push_back(2);
    vec2.push_back(4);
    vec2.push_back(6);
    vec2.push_back(8);
    vec2.push_back(10);
    vec2.push_back(11);
    vec2.push_back(12);
    vec2.push_back(13);
    vec2.push_back(14);
    vec2.push_back(15);

    //cout << sl.getUpMedian(vec1, vec2) << endl;
    //cout << sl.getUpMedian(vec2, vec1) << endl;
    //for(int i = 1; i < 16; i++)
    //    cout << sl.findKthNum(vec1, vec2, i) << endl;
    return 0;
}
