#include <iostream>

void printList(int *l, int n) {

	for (int i = 0; i < n;i++ ) {
		printf("%d ", l[i]);
	}
	printf("\n");
}

void shellInsertSort(int *a, int n, int jp) {
	printf("n:%d, jp:%d\n", n, jp);
	// 直接插入排序的 jp 为1，一格一格移动
	for (int i = jp; i < n; i++ ) {
		// 插入的跨度 为 jp，但循环的 step 仍然为 1
		int k = a[i];
		// 要插入的位置
		int index = i;
		for ( int j = i - jp; j >= 0; j = j - jp){
			if ( a[j] > k ){
				// 如果 j 节点的值大于 k，那么就将 j 节点后移jp位，并更新插入位置
				a[j + jp] = a[j];
				index = j;
				printList(a, 8);
			}
			else {
				break;
			}
		}
		a[index] = k;
		printList(a, 8);
		printf("%d\n", i);
	}
}

// 按 长度的一半先分两组，然后继续缩小，直到缩小为1，此时则是直接插入排序了
void shellSort(int *a, int n) {
	int step = 2;
	int jp = n / step;   // 第一次分两组
	while (jp >= 1) {
		shellInsertSort(a, n, jp);
		jp /= step;
	}
}


int main() {


	int a[9] = { 3, 10, 1,5,7,2,4,9,6 };
	printList(a, 9);

	// 直接插入排序
	//shellInsertSort(a, 9, 1);

	shellSort(a, 4);

	printList(a, 9);

	system("pause");
	return 0;
}
