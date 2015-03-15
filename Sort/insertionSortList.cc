 #include<iostream>
 using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//if the Algorithm has a haed that hard to deal with
//add a header to avoid it!
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *i = NULL, *j = NULL;
        ListNode *beforei = NULL, *beforej;
        ListNode *start = new ListNode(0);
        start->next = head;
        if(( head == NULL )||( head->next == NULL ))
            return head;
        beforei = j = head;
        i = j->next;
        while( i != NULL )
        {
            j = start->next;
            beforej = start;
            while(( j != i ) && ( j->val <= i->val ))
            {
                beforej = j;
                j = j->next;
            }
            if( j == i )
            {
                beforei = i;
                i = i->next;
            }
            else
            {
                beforei->next = i->next;
                beforej->next = i;
                i->next = j;
                i = beforei->next;
            }

        }
        head = start->next;
        delete start;
        return head;
    }
};



int main()
{
    ListNode *i4 = new ListNode(4);
    ListNode *i2 = new ListNode(2);
    ListNode *i1 = new ListNode(1);
    ListNode *i3 = new ListNode(3);

    ListNode *head = i4;

    i4->next = i2;
    i2->next = i1;
    i1->next = i3;


    Solution sl;
    head = sl.insertionSortList(head);
    while( head != NULL )
    {
        cout<< head->val << endl;
        head = head->next;
    }
    return 0;
}