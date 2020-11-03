#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	int result = 5;
	set<int> us;
	cin >> n; 
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		us.insert(temp);
	}
	for (auto iter = us.begin(); iter != us.end(); iter++) {
		int temp = 4;
		if (us.find(*iter + 5) == us.end()) {
			for (int i = 1; i <= 4; i++) {
				temp -= us.find(*iter + i) != us.end() ? 1 : 0;
			}
			if (result > temp) result = temp;
		}
	}

	cout << result;

    return 0;
}

