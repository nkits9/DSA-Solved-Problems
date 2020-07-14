//The structure of petrolPump is 
struct petrolPump {
    int petrol;
    int distance;
};

// Method 1 : Using Queue
int tour(petrolPump p[],int n) {
    queue<int> q;
    int i = 0;
    while(i<n) {
        q.push(p[i].petrol - p[i].distance);
        i++;
    }

    int curr=0, start=0; i=0;
    while(!q.empty()) {
        curr += q.front();
        q.pop();
        i++;
        if(curr < 0) {
            q.push(curr);
            curr = 0;
            start = i;
        }
        if(start >= n)  return -1;
    }

    return start;
}

//Method 2 :
int tour(petrolPump p[],int n) {
    int start=0, curr=0, sum = 0;
    for(int i=0; i<n; i++) {
        curr += p[i].petrol - p[i].distance;
        if(curr < 0) {
            sum += curr;
            curr = 0;
            start = i+1;
        } 
        if(i==n-1 && curr+sum<0)    return -1;
    }
    return start;
}