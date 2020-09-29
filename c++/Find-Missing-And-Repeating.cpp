class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2], i;
        for (i = 0; i < n; i++) {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                ans[0] = abs(arr[i]);
        }
        for (i = 0; i < n; i++) {
            if (arr[i] > 0) ans[1] = i + 1;
        }
        return ans;
    }
};