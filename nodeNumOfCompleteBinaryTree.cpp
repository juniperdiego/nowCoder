#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};

class Solution {
private:
        int calcHeight(TreeNode *head)
        {
            int height = 0;
            while(head)
            {
                head = head->left;
                height ++;
            }
            return height;
        }
    public:
        int nodeNum(struct TreeNode* head)
        {
            if(head == NULL)
                return 0;

            int height = calcHeight(head);
            //cout << "height\t" <<height << endl;

            if(calcHeight(head->right) == height - 1)//left sub-tree is full 
                return (1 << (height - 1) )+ nodeNum(head->right);
            else// right sub-tree is full
                return (1 << (height - 2) )+ nodeNum(head->left);
        }
};
int main()
{
    TreeNode node0(4);
    TreeNode node1(2);
    TreeNode node2(7);
    TreeNode node3(1);
    TreeNode node4(3);
    TreeNode node5(5);
    TreeNode node6(8);

    node0.left = &node1;
    node0.right= &node2;

    node1.left = &node3;
    //node1.right= &node4;

    //node2.left = &node5;
    //node2.right= &node6;

    Solution sl;
    cout << sl.nodeNum(&node0) << endl;
    return 0;
}
