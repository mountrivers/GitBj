#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, t;
int px[] = { 3,2,1,0,-1,-2,-3,-2,-1,0,1,2 ,1 , 0, -1, 0 };
int py[] = { 0,-1,-2,-3,-2,-1,0,1,2,3,2,1 ,0 , 1, 0 , -1};
queue<pair<int, int>> nextQue;

vector<vector<int>> map;
vector<vector<int>> dp;

void fun(int y, int x) {
	
	int tx, ty;
	int present = dp[y][x];
	for (int i = 0; i < 16; i++) {
		tx = px[i] + x;
		ty = py[i] + y;
		if (ty < 0 || tx < 0 || ty >= n || tx >= n) continue;
		int temp = t * 3 + map[ty][tx];
		if (dp[ty][tx] == 0) {
			dp[ty][tx] = present +  temp;
			nextQue.push(make_pair(ty, tx));
		}
		else if (present + temp < dp[ty][tx]) {
			dp[ty][tx] = present + temp;
			nextQue.push(make_pair(ty, tx));
		}
	}
	if (!nextQue.empty()) {
		int ny = nextQue.front().first;
		int nx = nextQue.front().second;
		nextQue.pop();
		fun(ny, nx);
	}
}
int main() {
	cin >> n >> t;

	map.assign(n, vector<int>(n, 0));
	dp.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	fun(0, 0);

	int dMin = dp[n - 3][n-1];
	if (dMin > dp[n - 2][n - 2]) dMin = dp[n - 2][n - 2];
	if (dMin > dp[n - 1][n - 3]) dMin = dp[n - 1][n - 3];

	int oMin = dp[n - 2][n - 1];
	if (oMin > dp[n - 1][n - 2]) oMin = dp[n - 1][n - 2];

	if (dp[n - 1][n - 1] > dMin + t*2)
		dp[n - 1][n - 1] = dMin + t*2;
	if (dp[n - 1][n - 1] > oMin + t)
		dp[n - 1][n - 1] = oMin + t;


	cout << dp[n - 1][n - 1];


	return 0;
}