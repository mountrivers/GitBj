//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//int main() {
//	int n;
//	int edge = 1;
//	int remain = 0;
//	int result = 0;
//	cin >> n;
//	
//	while (edge * edge <= n) edge ++;
//	edge--;
//	remain = n - edge*edge;
//	
//
//	for (int i = 1; i < edge; i++)
//	{
//		result += (edge - i)*(edge - i);
//	}
//	for (int i = 0; i < edge; i++) {
//		if (remain == 0) break;
//		result += i;
//		remain--;
//	}
//	for (int i = 0; i < edge; i++) {
//		if (remain == 0) break;
//		result += i;
//		remain--;
//	}
//
//	cout << result;
//
//
//
//	return 0;
//}