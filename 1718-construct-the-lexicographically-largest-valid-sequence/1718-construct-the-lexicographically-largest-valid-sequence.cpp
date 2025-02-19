class Solution {
    bool solve(int n, vector<int>& visited, vector<int>& arr, int pos) {
        while (pos < arr.size() && arr[pos] != -1)
            pos++;
        if (pos >= arr.size())
            return true;
        for (int i = n; i > 0; i--) {
            if (visited[i] == 0) {
                if (i == 1) {
                    arr[pos] = i;
                    visited[i] = 1;
                    if (solve(n, visited, arr, pos + 1))
                        return true;
                    arr[pos] = -1;
                    visited[i] = 0;

                } else {

                    int nextpos = pos + i;
                    if (nextpos < arr.size() && arr[nextpos] == -1) {
                        arr[pos] = i;
                        arr[nextpos] = i;
                        visited[i] = 1;
                        if (solve(n, visited, arr, pos + 1))
                            return true;
                        arr[pos] = -1;
                        arr[nextpos] = -1;
                        visited[i] = 0;
                    }
                }
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        int siz = 2 * n - 1;
        vector<int> arr(siz, -1);

        vector<int> visited(n + 1, 0);
        bool temp = solve(n, visited, arr, 0);
        return arr;
    }
};