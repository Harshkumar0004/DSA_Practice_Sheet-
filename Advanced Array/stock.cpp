#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//two pass approach-O(n2)
int maxprofit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            profit = max((prices[j] - prices[i]), profit);
        }
    }
    return profit;
}


int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxprofit(prices)<<endl;
    return 0;
}