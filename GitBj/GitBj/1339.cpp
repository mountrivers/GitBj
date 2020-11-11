#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <functional>
using namespace std;

int main() {
	int n;
	string temp;
	cin >> n;
	long long result = 0;
	vector<long long > v(10, 0);
	vector<int> b(10, 0);
	vector<int> done(10, 0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int m = temp.length();
		b[temp.at(0) - 'A'] ++;
		for (int j = 0; j < temp.length(); j++) {
			v[(temp.at(j) - 'A')] += pow(10, m - j - 1);
		}
	}
	for (int i = 0; i < 10; i++) {
		int smallest = -1;

		for (int j = 0; j < 10; j++) {
			if (done[j] > 0) continue;
			if (i == 0 && b[j] > 0) continue;
			if (smallest == -1) smallest = j;
			else if (v[smallest] > v[j]) smallest = j;
			
		}
		if (smallest == -1)  smallest = 0;
		result += v[smallest] * i;
		done[smallest] = 1;
	}
	cout << result << endl;

	return 0;
}