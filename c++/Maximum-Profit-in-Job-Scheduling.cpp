class Solution {
public:
    
    struct Job {
        int start, end, profit;
        Job(int s, int e, int p) {
            start = s, end = e, profit = p;
        }
    };
    
    static int compare(Job j1, Job j2) {
        return j1.end < j2.end;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<Job> jobs;
        vector<int> dp(n+1);
        
        jobs.push_back(Job(0, 0, 0));
        for(int i=0; i<n; i++) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), compare);
        
        for(int i=1; i<=n; i++) {
            int lastJob = i-1;
            while(lastJob > 0 && jobs[lastJob].end > jobs[i].start) {
                lastJob--;
            }
            dp[i] = max(jobs[i].profit + dp[lastJob], dp[i-1]);
        }
        
        return dp[n];
    }
    
};