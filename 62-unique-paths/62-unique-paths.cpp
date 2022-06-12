class Solution {
public:
    int dp[101][101];
    int calcPaths(int x, int y, int n, int m){
        if(x == n - 1 && y == m - 1)
            return 1;
        if(dp[x][y])
            return dp[x][y];
        int goRight = 0;
        int goDown = 0;
        if(x < n - 1)
            goRight = calcPaths(x + 1, y, n, m);
        if(y < m - 1)
            goDown = calcPaths(x, y + 1, n, m);
        return dp[x][y] = (goRight + goDown);
    }
    int uniquePaths(int m, int n) {
        return calcPaths(0, 0, n, m);
    }
};