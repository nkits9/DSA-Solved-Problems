
struct Job { 
    int id;	 // Job Id 
    int dead; 	 // Deadline of job 
    int profit;  // Profit if job is over before or on deadline 
};


class Solution {
    public:
    
    static bool comparator(Job A, Job B) {
        return A.profit > B.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) { 
        vector<bool> slot(100, true);  //  1 <= Deadline <= 100
        
        sort(arr, arr+n, comparator);   // sort in decreasing order of their profit
        
        int task = 0, profit = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=arr[i].dead; j>0; j--) {
                if(slot[j] != false) {
                    task++;
                    profit += arr[i].profit;
                    slot[j] = false;
                    break;
                }
            }
        }
        
        return {task, profit};
    } 
};
