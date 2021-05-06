Given a list(Arr) of N integers, print sums of all subsets in it. Output should be printed in increasing order of sums.

Input:
N = 2
Arr = [2, 3]
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.

  vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        solve(arr,N,0,0,ans); //firsr zero - index second zero - sum
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void solve(vector<int>arr,int N, int ind, int sum, vector<int>&ans)
    {
        if(ind==N)
        {
            ans.push_back(sum);
            return;
        }
        solve(arr,N,ind+1,sum+arr[ind],ans); //including this number to be sum
        solve(arr,N,ind+1,sum,ans); //not including this number to be sum
    }