#include <iostream>

void printList(int *l, int n) {

	for (int i = 0; i < n;i++ ) {
		printf("%d ", l[i]);
	}
	printf("\n");
}

void shellInsertSort(int *a, int n, int jp) {
	printf("n:%d, jp:%d\n", n, jp);
	// 插入排序的 jp 为1，一个一格移动
	for (int i = jp; i < n;i++ ) {
		if ( a[i] < a[i - jp] ){
			// 移动
			int k = a[i];
			int target = i;
			a[i] = a[i - jp];
			printList(a, 8);
			for (int j = i - jp; j >= jp; j = j - jp){
				if (a[j] > k) {
					a[j] = a[j - jp];
					target = j + jp;
					printList(a, 8);
				}
				else {
					break;
				}
			}
			a[target - jp] = k;
			//printList(a, 8);
		}
	}
}

// 按 长度的一半先分两组，然后继续缩小，直到缩小为1，此时则是插入排序了
void shellSort(int *a, int n) {
	int step = 2;
	int jp = n / step;   // 第一次分两组
	while (jp >= 1) {
		shellInsertSort(a, n, jp);
		jp /= step;
	}

}


int main() {


	int a[8] = { 3,1,5,7,2,4,9,6 };

	shellInsertSort(a, 8, 1);

	//shellSort(a, 8);

	printList(a, 8);

	system("pause");
	return 0;
}
