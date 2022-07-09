//The structure of petrolPump is 
struct petrolPump {
    int petrol;
    int distance;
};

// Method 1 : Using Queue
int tour(petrolPump p[], int n) {
    queue<int> q;
    for(int i=0; i<n; i++) {
        q.push(p[i].petrol - p[i].distance);
    }

    int currPetrol = 0, i = 0, start = 0;

    while(!q.empty()) {
        currPetrol += q.front();
        q.pop();
        if(currPetrol < 0) {
            start = i+1;
            q.push(currPetrol);
            currPetrol = 0;
            i++;
        }
        else {
            i++;
        }
        if(start >= n)  return -1;      // no starting point found
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
