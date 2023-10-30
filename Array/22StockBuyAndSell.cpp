#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void stockBuySell(int price[], int n) {
	int profit = 0, minPrice = price[0];
	for (int i = 0; i < n; i++) {
		minPrice = min(price[i], minPrice);
		profit = max(profit, price[i] - minPrice);
	}
	cout << profit;
}

// GFG solution not working
void stockBuySellGfg(int price[], int n) {
	bool temp = false; //if profit obtained becomes true and vice versa
	bool temp1 = false; //if no profit is obtained it always remain at false
	for (int i = 0; i < n - 1; i++)
	{	//initially no profit
		if (price[i] <= price[i + 1] && temp == false)
		{
			cout << "(" << i << " ";
			temp = true;
			temp1 = true;
		}
		if (price[i] >= price[i + 1] && temp == true)
		{
			cout << i << ")" << " ";
			temp = false;
		}
	}
	//if the loop ended with profit the variable temp remains true
	if (temp == true)
	{
		cout << n - 1 << ")";
	}

	if (temp1 == false)
	{
		cout << "No Profit";
	}
	cout << endl;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	stockBuySellGfg(arr, n);
	cin.get();
}