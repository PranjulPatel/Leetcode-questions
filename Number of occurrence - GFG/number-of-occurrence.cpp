//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int binarySearch(int arr[], int l, int r, int x)
{
    if (r < l)
        return -1;
 
    int mid = l + (r - l) / 2;
 
    // If the element is present at the middle
    // itself
    if (arr[mid] == x)
        return mid;
 
    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);
 
    // Else the element can only be present
    // in right subarray
    return binarySearch(arr, mid + 1, r, x);
}	
		
	int count(int arr[], int n, int x) {
	    int ind = binarySearch(arr, 0, n - 1, x);
 
    // If element is not present
    if (ind == -1)
        return 0;
 
    // Count elements on left side.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;
 
    // Count elements on right side.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;
 
    return count;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends