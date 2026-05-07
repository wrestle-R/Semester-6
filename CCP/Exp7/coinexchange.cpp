int greedyCoinChange(vector<int>& coins, int amount)
{
    sort(coins.rbegin(), coins.rend());

    int count = 0;

    for(int coin : coins)
    {
        while(amount >= coin)
        {
            amount -= coin;
            count++;
        }
    }

    if(amount != 0)
        return -1;

    return count;
}

int dpCoinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, 1e9);

    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
    {
        for(int coin : coins)
        {
            if(i >= coin)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if(dp[amount] == 1e9)
        return -1;

    return dp[amount];
}