#include <bits/stdc++.h>
using namespace std;
typedef struct llnode *lptr;

struct llnode
{
    int data;
    llnode *next = NULL;
};
void insert(lptr &LL, int x)
{
    lptr temp;
    temp = new (llnode);
    temp->data = x;
    if (LL == NULL)
    {
        LL = temp;
        return;
    }
    lptr temp2 = LL;
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp;
}

void print(lptr LL)
{
    if (LL == NULL)
        return;
    cout << LL->data << " ";
    print(LL->next);
}

lptr findIntersection(lptr l1, lptr l2)
{
    lptr l3 = NULL, l3temp;
    bool first = true;
    while (l2 != NULL && l1 != NULL)
    {
        if (l1->data < l2->data)
        {
            l1 = l1->next;
        }
        else if (l1->data > l2->data)
        {
            l2 = l2->next;
        }
        else
        {
            if (first)
            {
                l3 = l2;
                l3temp = l3;
                first = false;
                l2 = l2->next;
                l1 = l1->next;
                continue;
            }
            l3temp->next = l2;
            l2 = l2->next;
            l1 = l1->next;
            l3temp = l3temp->next;
            l3temp->next = NULL;
        }
    }
    return l3;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lptr LL = NULL;
    int x;
    cin >> x;
    while (x != -1)
    {
        insert(LL, x);
        cin >> x;
    }

    lptr LL2 = NULL;
    cin >> x;
    while (x != -1)
    {
        insert(LL2, x);
        cin >> x;
    }
    print(findIntersection(LL, LL2));
}