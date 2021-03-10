Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?

Input: V = 70
Output: 2
We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.


int micoins(int coins[], int n , int amount)
{
    sort(coins,coins+n); //coins in decreasing order
    
    int res = 0;
    
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=amount)
        {
            int c = floor(amount/coins[i]); // if it's amount is 52 and we can make 10 coins from 5 value coin 
            res += c; //total coin can used
            amount -= c*coins[i]; // remaining amount
        }
        if(amount==0)
        break;
    }
    return res;
}