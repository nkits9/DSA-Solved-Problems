class Solution {
public:
    
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> nsr, nsl;

        for(int i=n-1; i>=0; i--) {
            while(!s1.empty() && arr[s1.top()] >= arr[i])  s1.pop();
            if(s1.empty())   nsr.push_back(n);
            else    nsr.push_back(s1.top());
            s1.push(i);
        }
        reverse(nsr.begin(), nsr.end());
        
        for(int i=0; i<n; i++) {
            while(!s2.empty() && arr[s2.top()] >= arr[i])  s2.pop();
            if(s2.empty())   nsl.push_back(-1);
            else    nsl.push_back(s2.top());
            s2.push(i);
        }

        int maxArea = 0;
        for(int i=0; i<n; i++) {
            maxArea = max(arr[i]*(i-nsl[i] + nsr[i]-i - 1), maxArea);
        }

        return maxArea;       
    }
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()){
            return 0;
        }
        int maxRec = 0;
        vector<int> height(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j]++;
                }
            }
            maxRec = max(maxRec, largestRectangleArea(height));
        }
        return maxRec;
    }

};