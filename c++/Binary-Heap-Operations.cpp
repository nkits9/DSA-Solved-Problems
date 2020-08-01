struct MinHeap {
    int *harr;
    int capacity, heap_size;

    MinHeap(int cap) {
    	heap_size = 0; 
    	capacity = cap; 
    	harr = new int[cap];
    }

    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};


void MinHeap::insertKey(int k) {
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // iterating upto first index till parent is larger than the the child
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Function to change value and store min value at first index
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin() {
    if (heap_size <= 0) return -1;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1]; // putting last element at first index
    harr[heap_size - 1] = 0;
    heap_size--;

    MinHeapify(0); // calling Minheapify

    return root;
}

void MinHeap::deleteKey(int i) {
    if (i < heap_size) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    
    if (l < heap_size && harr[l] < harr[smallest]) 
        smallest = l;
        
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r;
        
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest); 
    }
}