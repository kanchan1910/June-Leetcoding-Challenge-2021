
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* dummy = NULL;
        ListNode* prev = dummy;
        ListNode* cur = head;
        while(cur != NULL)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left == right)
        {
            return head;
        }
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* cur = head;
        ListNode* startprev = NULL;
        ListNode* endnext = NULL;
        int count = 0;
        bool f = false;
        while(cur != NULL)
        {
            count++;
            if(count < left)
            {
                f = true;
                startprev = cur;
            }
            if(count == left)
            {
                start = cur;
            }
            if(count == right)
            {
                end = cur;
                endnext = cur->next;
                break;
            }
            cur = cur->next;
        }
        end->next = NULL;    
        ListNode* newstart = start;
        start = reverse(start);
        
        if(f == false)
        {
            head = end;
        }
        else
        {
           startprev->next = start; 
        }
        newstart->next = endnext;
        return head;
    }
};



// ONE PASS


class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* dummy = NULL;
        ListNode* prev = dummy;
        ListNode* cur = head;
        while(cur != NULL)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left == right)
        {
            return head;
        }
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* startprev = NULL;
        ListNode* endnext = NULL;
        int count = 0;
        bool f = false;
        while(cur != NULL)
        {
            count++;
            if(count < left)
            {
                f = true;
                startprev = cur;
            }
            if(count == left)
            {
                start = cur;
            }
            if(count == right)
            {
                end = cur;
                endnext = cur->next;
            }
            ListNode* next = cur->next;
            if(count > left && count <= right)
            {
                cur->next = prev;
            }
            if(count > right)
            {
                break;
            }
            prev = cur;
            cur = next;
        }

        if(f == false)
        {
            head = end;
        }
        else
        {
           startprev->next = end; 
        }
        start->next = endnext;
        return head;
    }
};
