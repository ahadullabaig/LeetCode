#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;

    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    if(head == nullptr || head -> next == nullptr || head -> next -> next == nullptr) return {-1, -1};

    ListNode *prev = head;

    ListNode *temp = head -> next;

    set<int> criticals;

    int count = 2;

    while(temp -> next != nullptr)
    {
        if((temp -> val < prev -> val) && (temp -> val < temp -> next -> val)) // minima
        {
            criticals.insert(count);
        }

        if((temp -> val > prev -> val) && (temp -> val > temp -> next -> val)) // maxima
        {
            criticals.insert(count);
        }

        prev = temp;

        temp = temp -> next;

        count++;
    }

    if(criticals.empty()) return {-1, -1};

    if(criticals.size() >= 2)
    {
        int minimum = INT_MAX;

        auto it = criticals.begin();
        auto prev = it;

        it++;

        while(it != criticals.end())
        {
            minimum = min(minimum, *it - *prev);

            prev = it;

            it++;
        }

        int maximum = *criticals.rbegin() - *criticals.begin();

        return {minimum, maximum};
    }

    return {-1, -1};
}

vector<int> op_nodesBetweenCriticalPoints(ListNode *head)
{
    if(head == nullptr || head -> next == nullptr || head -> next -> next == nullptr) return {-1, -1};

    ListNode *prev = head;

    ListNode *temp = head -> next;

    int position = 2;

    int firstCritical = -1, lastCritical = -1;

    int minDistance = INT_MAX;

    while(temp -> next != nullptr)
    {
        bool isCritical = ((temp -> val < prev -> val) && (temp -> val < temp -> next -> val)) ||
                          ((temp -> val > prev -> val) && (temp -> val > temp -> next -> val));

        if(isCritical)
        {
            if(firstCritical == -1)
            {
                firstCritical = position;
            }
            else
            {
                minDistance = min(minDistance, position - lastCritical);
            }

            lastCritical = position;
        }

        prev = temp;

        temp = temp -> next;
        
        position++;
    }

    if(firstCritical == -1 || firstCritical == lastCritical) return {-1, -1};

    int maxDistance = lastCritical - firstCritical;

    return {minDistance, maxDistance};
}

int main()
{
    ListNode *head = new ListNode(5);

    head -> next = new ListNode(3);
    head -> next -> next = new ListNode(1);
    head -> next -> next -> next = new ListNode(2);
    head -> next -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next -> next = new ListNode(1);
    head -> next -> next -> next -> next -> next -> next = new ListNode(2);

    vector<int> result = nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << endl;
    cout << "Maximum distance: " << result[1] << endl;

    cout << endl;

    result = op_nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << endl;
    cout << "Maximum distance: " << result[1] << endl;

    return 0;
}
