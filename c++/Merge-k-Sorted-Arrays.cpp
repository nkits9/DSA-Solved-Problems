int n;
// A min heap node
struct MinHeapNode {
	int element; // The element to be stored
	int i; // index of the array from which the element is taken
	int j; // index of the next element to be picked from array
};

// A utility function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y) {
	MinHeapNode temp = *x; *x = *y; *y = temp;
}

// A class for Min Heap
class MinHeap {
	MinHeapNode *harr;
	int heap_size;

public :
	// Constructor: creates a min heap of given size
	MinHeap(MinHeapNode a[], int size) {
		heap_size = size;
		harr = a; // store address of array
		for(int i=(heap_size-1)/2; i>=0; i--) {
			MinHeapify(i);
		}
	}

	void MinHeapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && harr[l].element < harr[i].element)
			smallest = l;
		if (r < heap_size && harr[r].element < harr[smallest].element)
			smallest = r;
		if (smallest != i) {
			swap(&harr[i], &harr[smallest]);
			MinHeapify(smallest);
		}
	}

	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }

	MinHeapNode getMin() { return harr[0]; }

	// to replace root with new node x and heapify() new root
	void replaceMin(MinHeapNode x) { 
		harr[0] = x; 
		MinHeapify(0); 
	}
};

int *mergeKArrays(int arr[][N], int k) {
    n = k;
	int *output = new int[n*k]; // To store output array

	// Create a min heap with k heap nodes. Every heap node has first element of an array.
	MinHeapNode *harr = new MinHeapNode[k];
	for (int i = 0; i < k; i++) {
		harr[i].element = arr[i][0]; // Store the first element
		harr[i].i = i; // index of array
		harr[i].j = 1; // Index of next element to be stored from array
	}
	
	MinHeap heap(harr, k); // Create the heap

	// Now one by one get the minimum element from minheap and replace it with next element of its array.
	for (int count = 0; count < n*k; count++) {
		
		MinHeapNode root = heap.getMin();
		output[count] = root.element;

		// Find the next elelement that will replace current root of heap.
		if (root.j < n) {
			root.element = arr[root.i][root.j];
			root.j += 1;
		}
		// If root was the last element of its array
		else root.element = INT_MAX; //INT_MAX is for infinite

		// Replace root with next element of array
		heap.replaceMin(root);
	}
 
	return output;
}

