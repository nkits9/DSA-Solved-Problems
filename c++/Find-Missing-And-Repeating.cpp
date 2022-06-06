int *findTwoElement(int *arr, int n) {
    int missing, repeating;

    for(int i=0; i<n; i++) {
        if(arr[abs(arr[i]) - 1] > 0) 
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            repeating = abs(arr[i]); 
    }

    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            missing = i+1;
        }
    }

    int *ans = new int[2];
    ans[0] = repeating;
    ans[1] = missing;

    return ans;
}
