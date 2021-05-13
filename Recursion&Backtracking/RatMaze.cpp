A Maze is given as N*N matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. Find the minimum number of Hops required for the rat to reach from the source block to the destination block. The number of steps rat can jump from (i, j) is represented by maze[i][j].

Note:
If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward.
In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].

N = 4
maze[][] = {{2,1,0,0},{3,0,0,1},
{0,1,0,1},{0,0,0,1}}
Output:
1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1
Explanation: Rat started with m[0][0] and
can jump up to 2 steps right/down. First
check m[0][1] as it is 1, next check
m[0][2], this won't lead to the solution.
Then check m[1][0], as this is 3(non-zero)
so we can make 3 jumps to reach m[1][3].
From m[1][3] we can move downwards taking
1 jump each time to reach destination at
m[3][3].

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends



bool isSafe(int a, int b, int n, vector<int> maze[]) {
    // the safe condition is when a, b is in bounds and matrix value != 0
    if (a >= 0 && a < n && b >= 0 && b < n && maze[a][b] != 0) return true;
    return false;
}

bool solveMaze(int a, int b, int n, vector<int> maze[], vector<int> sol[]) {
    // if the condition matches return true here
    // also the base case for recursion
    if (a == n - 1 && b == n - 1) {
        // marking (a,b) as part of solution
        sol[a][b] = 1;
        return true;
    }

    if (isSafe(a, b, n, maze) == true) {
        // marking (a,b) as part of solution
        sol[a][b] = 1;

        // checking for further path
        for (int i = 1; i <= maze[a][b] && i < n; i++) {
            if (solveMaze(a, b + i, n, maze, sol) == true) return true;

            if (solveMaze(a + i, b, n, maze, sol) == true) return true;
        }
        // if no possible path in the direction, then mark (a,b) as not part of
        // solution
        // doing backtracking and return false
        sol[a][b] = 0;
        return false;
    }
    // if not safe return false
    return false;
}

void solve(int n, vector<int> maze[]) {
    vector<int> sol[n];
    for (int i = 0; i < n; i++) sol[i].assign(n, 0);
    //    memset(sol, 0, sizeof sol);
    // if no path found
    if (solveMaze(0, 0, n, maze, sol) == false)
        cout << "-1" << endl;
    else {
        // if path found
        print(n, sol);
    }
}