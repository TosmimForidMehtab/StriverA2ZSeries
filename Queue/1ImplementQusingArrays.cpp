#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		// Write your code here.
		if (rear != arr.size()) {
			arr[rear++] = e;
		}
		else return;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		// Write your code here.
		if (rear == front) {
			rear = front = 0;
			return -1;
		}
		int temp = arr[front];
		front++;
		return temp;

	}
};
int32_t main() {
	fast

	cout << endl;
	cin.get();
}