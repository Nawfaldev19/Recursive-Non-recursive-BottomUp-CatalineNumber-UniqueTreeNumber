#include <iostream>
#include<vector>

using namespace std;


//cataline number-> uni
//____________________________________________________________________________________________________
int CatalineNumber_Standard(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int sum = 0;
    for (int i = 0; i <= n-1; i++)
    {
        sum += CatalineNumber_Standard(i) * CatalineNumber_Standard((n - 1) - i);
    }
    return sum;
}
//____________________________________________________________________________________________________

int CatalineNumber_RecursiveDPHelping(int n,vector<int>& cs)
{
    if (cs[n] != -1)
        return cs[n];
    int sum = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        sum += CatalineNumber_RecursiveDPHelping(i,cs) * CatalineNumber_RecursiveDPHelping((n - 1) - i,cs);
    }
    cs[n] = sum;
    return sum;
}

int CatalineNumber_RecursiveDP(int n)
{
    vector<int> cs(n + 1, {-1});
    cs[0] = 1;
    return CatalineNumber_RecursiveDPHelping(n,cs);
}

//____________________________________________________________________________________________________


int CatalineNumber_DynamicBottomUp_Helping(int n, vector<int>& cs)//Unique Binary tree structure
{
    cs[0] = 1;
    for (int ci = 1; ci <= n; ci++)
    {
        int sum = 0;
        for (int i = 0; i <= ci - 1; i++)
        {
            sum += cs[i] * cs[(ci-1)-i];
        }
        cs[ci] = sum;
    }
    return cs[n];
}

int CatalineNumber_DynamicBottomUp(int n)
{
    vector<int> cs(n + 1, { -1 });
    return CatalineNumber_DynamicBottomUp_Helping(n, cs);
}

//____________________________BEATS 100% In LEETCODE________________________________________________________________________

int numTrees(int n)
{
    vector<int> cs(n + 1);
    cs[0] = 1;
    for (int ci = 1; ci <= n; ci++)
    {
        int sum = 0;
        for (int i = 0; i <= ci - 1; i++)
        {
            sum += cs[i] * cs[(ci - 1) - i];
        }
        cs[ci] = sum;
    }
    return cs[n];
}
//____________________________________________________________________________________________________


int main()
{
    cout << numTrees(5);
    
}
