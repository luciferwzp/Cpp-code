int LongestPalindromicSubstring(string & a)
{
    int len = a.length();
    vector<vector<int>>dp(len, vector<int>(len, 0));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
    }
    int max_len = 1;
    int start_index = 0;
    for (int i= len - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] == a[j])
            {
                if (j - i == 1)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    if (j - i > 1)
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                if (max_len < dp[i][j])
                {
                    max_len =  dp[i][j];
                    start_index = i;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << "max len is " << max_len << endl;
    cout << "star index is" << start_index << endl;
    return max_len;
}
