#include <iostream>
#include <string>

using namespace std;

int main() {
    string a = "program";
    string b = "algorithm";
    int l = a.length(), s = b.length();
    int dp[s+1][l+1];
    for (int i = 0; i <= l; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= s; i++)
    {
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            if(a[j - 1] == b[i - 1])    dp[i][j] = dp[i-1][j-1] + 1;
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        } 
        
    }
    
    for (int i = 0; i <= s; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}