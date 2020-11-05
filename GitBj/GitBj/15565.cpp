#include <iostream>
#include <vector>

using namespace std;


int main() {
	int n, k;
	int temp;
	int dpn = 0;
	int result = 10000000;
	cin >> n >> k;
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 1) {
			dp[dpn] = i;
			if (dpn >= k - 1) {
				temp = dp[dpn] - dp[dpn -k + 1];
				if (temp +1 < result)
					result = temp +1;
			}
			dpn++;
		}
	}
	if (result == 10000000)
		cout << "-1";
	else
		cout << result;


	return 0;
}