#include <iostream>

using namespace std;

#define MAX_ELEMENT 100010

typedef struct HeapType {
	int heap[MAX_ELEMENT];
	int	heap_size;
}HeapType;

HeapType* createHeap(HeapType* h, int N) {
	for (int i = 0; i < N; i++) h->heap[i] = 0;
	h->heap_size = 0;
	return h;
}

void insertHeap(HeapType* h, int item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int deleteHeap(HeapType* h) {
	int parent, child;
	int item, temp;

	if (h->heap_size == 0) return 0;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1; child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) child++;
		if (temp >= h->heap[child]) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;

	return item;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	h = createHeap(h, N);

	int num;
	while (N--) {
		cin >> num;
		if (num == 0) cout << deleteHeap(h) << '\n';
		else insertHeap(h, num);
	}
}