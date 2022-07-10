#include <iostream>
#define MAX_ELEMENT 100001

using namespace std;

typedef struct Heap {
	int data[MAX_ELEMENT];
	int heap_size;
}Heap;

void insertHeap(Heap* h, int item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item < h->data[i / 2])) {
		h->data[i] = h->data[i / 2];
		i /= 2;
	}
	h->data[i] = item;
}

int deleteHeap(Heap* h) {
	int parent, child;
	int temp, item;

	if (h->heap_size == 0) return 0;
	item = h->data[1];
	temp = h->data[(h->heap_size)--];

	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && h->data[child] > h->data[child + 1])child++;
		if (temp < h->data[child]) break;

		h->data[parent] = h->data[child];
		parent = child;
		child *= 2;
	}
	h->data[parent] = temp;
	return item;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Heap* h;
	h = (Heap*)malloc(sizeof(Heap));
	h->heap_size = 0;

	int N; cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) cout << deleteHeap(h) << '\n';
		else insertHeap(h, num);
	}
}