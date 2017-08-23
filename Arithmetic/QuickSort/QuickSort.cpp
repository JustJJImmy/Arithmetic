// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

void printList(int *l, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", l[i]);
	}
	printf("\n");
}

void swap(int &m, int &n) {
	int j = m;
	m = n;
	n = j;
}

void quickSort(int l[], int lenth ) {
	if (lenth > 1) {
		int index = 0;
		// 升序 
		bool left = false;
		printf("\nquik sort start\n");
		printList(l, lenth);

		for (int i = 0, j = lenth - 1; i < j;) {
			printf("left: %d, i;%d, j:%d, index: %d\n", left, i, j, index);
			if ( left ) {
				// 从左往右 找第一个大于 l[index] 的
				if (l[i] > l[index]) {
					swap(l[i], l[index]);
					index = i;
					left = false;
					printList(l, lenth);
				}
				else {
					i++;
				}
			} else {
				// 从右往左 找第一个小于 l[index] 的
				if ( l[j] < l[index]) {
					swap(l[j], l[index]);
					index = j;
					left = true;
					printList(l, lenth);

				}
				else {
					j--;
				}
			}
		}

		printList(l, lenth);
		printf("quik sort end\n");

		quickSort(l, index);
		quickSort(l + index + 1, lenth - index - 1);
	}
}



int main()
{

	int a[10] = { 3,7,5,1,2,4,9,6,10,8 };
	cout << " 初始值： ";
	printList(a, 10);

	//quickSort(a, 10);

	cout << " 结果： ";
	printList(a, 10);

	system("pause");
    return 0;
}

