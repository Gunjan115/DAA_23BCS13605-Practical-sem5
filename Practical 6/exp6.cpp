#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    // Initialize dp table
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;  // sum 0 is always possible

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false; // no elements → cannot make sum

    // Fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the target sum: ";
    cin >> sum;

    if (isSubsetSum(arr, n, sum))
        cout << "Subset with given sum exists." << endl;
    else
        cout << "No subset with given sum exists." << endl;

    return 0;
}
