Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack.


bool comp(Item a , Item b)
{
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    
    return r1 > r2;
}

class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        
        double ans = 0.0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=W)
            {
                  ans+=arr[i].value;
                  W -= arr[i].weight;
            }
            else
            {
                  ans += arr[i].value * (double)W/arr[i].weight;
                  break;
            }
        }
        return ans;
    }
};