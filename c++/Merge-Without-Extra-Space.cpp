class Solution{
public:
    int findGap(int gap) {
        if(gap <= 1)    return 0;
        return gap/2 + gap%2;
    }

	void merge(int arr1[], int arr2[], int n, int m) {
	    int gap = findGap(n+m);
        
        while(gap > 0) {
            int i=0;
            while(i+gap < n) {
                if(arr1[i] > arr1[i+gap])
                    swap(arr1[i], arr1[i+gap]);
                i++;
            }
            while(i<n && i+gap-n < m) {
                if(arr1[i] > arr2[i+gap-n]) 
                    swap(arr1[i], arr2[i+gap-n]);
                i++;
            }
            while(i+gap-n < m) {
                if(arr2[i-n] > arr2[i-n+gap])
                    swap(arr2[i-n], arr2[i-n+gap]);
                i++;
            }
            gap = findGap(gap);
        }
	}
};
