#include<iostream>
using namespace std;

int partition(int a[], int si, int ei) {
	int pivot = a[ei];
	int pos = si - 1;
	for(int i = si ; i < ei ; i++) {
		if(a[i] <= pivot) {
			pos++;
			int t = a[pos];
			a[pos] = a[i];
			a[i] = t;
		}
	}
	int t = a[pos + 1];
	a[pos + 1] = a[ei];
	a[ei] = t;
	return (pos + 1);
}

void quickSort(int a[], int si, int ei) {
	if(si >= ei) {
		return;
	}
	int pivot = partition(a, si, ei);
	quickSort(a, si, pivot - 1);
	quickSort(a, pivot + 1, ei);
}

int main() {

	int n;
	cin >> n;

	int a[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	quickSort(a, 0, n - 1);

	for(int i = 0 ; i < n ; i++) 
		cout << a[i] << " ";

	cout << endl;

	return 0;
}