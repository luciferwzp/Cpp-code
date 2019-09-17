int substr(string & str1, string &str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>>dp(len1,vector<int>(len2,0));
    for (int i = 0; i < len1; i++)
    {
        dp[i][0] = str1[i]==str1[0]?1:0;
    }
    for (int j = 0; j <= len2; j++)
    {
        dp[0][j] = str1[0]==str2[j]?1:0;
    }
    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = dp[i - 1][j - 1]+1;
            }
        }
    }
    int longest = 0;
    int longest_index = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (longest < dp[i][j])
            {
                longest = dp[i][j];
                longest_index = i;

            }
        }
    }
    //字符串为从第i个开始往前数longest个
    for (int i = longest_index-longest+1; i <=longest_index; i++)
    {
        cout << str1[i] << endl;
    }
    return longest;
}
