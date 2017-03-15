// HeapSort.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>

/*
堆排序有 两个重点问题：
1、将整个序列转换成堆
2、取出堆顶后，如何将剩下的元素快速组成堆。
*/

void printList(int *l, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", l[i]);
	}
	printf("\n");
}

/*
从 父子 节点中选举最小的为父节点。
如果最小的不是父节点的话，那么交换过的子节点也需要检查。
*/
void adjustHeap(int *l, int n, int topIndex, int adjustIndex) {
	// 要检查的元素 index
	int minIndex = adjustIndex;
	// 堆顶不为 0 时，计算 adjustIndex 的子节点 index 要考虑到偏移
	int lcIndex = 2 * (adjustIndex - topIndex + 1) - 1 + topIndex;
	int rcIndex = 2 * (adjustIndex - topIndex + 1) + topIndex;

	// 跟 左子节点比较，替换 小的 index
	if (lcIndex < n && l[minIndex] > l[lcIndex] ){
		minIndex = lcIndex;
	}
	// 跟 右子节点比较，替换 小的 index
	if (rcIndex < n && l[minIndex] > l[rcIndex]){
		minIndex = rcIndex;
	}
	// 如果小的index 不是 堆顶的话，那么换顶，然后检查子堆
	if ( minIndex != adjustIndex ){
		int k = l[minIndex];
		l[minIndex] = l[adjustIndex];
		l[adjustIndex] = k;
		// 子堆 minIndex 换了 堆顶，要检查一下
		adjustHeap(l, n, topIndex, minIndex);
	}
}

/*
1、假设 长度 n 的 序列 k 为堆
2、最后一个节点为 n / 2 的子节点，从 n / 2 开始向上筛选
3、从 父子节点中选举最小的为 父节点
4、检查下一个 n / 2 - 1 ，重复 3， 直到 0
*/
void buildHeap(int *l, int n) {
	for (int i = n / 2; i > 0;i-- ) {
		// 节点 i 对应的 index 是 i - 1, 子节点 index  2 * i - 1、 2 * i
		int min = i - 1;
		int lc = 2 * i - 1;
		int rc = 2 * i;

		//　选举最小的为 堆顶
		if (l[i - 1] > l[lc]){
			min = lc;
		}
		if ( 2*i < n && l[min] > l[rc]){
			min = rc;
		}

		if ( min != i-1 ) {
			int k = l[i - 1];
			l[i - 1] = l[min];
			l[min] = k;
			// 子堆 min 换了堆顶，要检查堆 min
			adjustHeap(l, n, 0, min);
		}
	}
}


int main()
{
	int list[50] = { 10, 7, 1 , 8, 5, 12, 6, 3, 9 };
	int n = 9;
	printList(list, n);

	buildHeap(list, n);
	printList(list, n);

	// 建好堆后，初始堆顶就是最小的
	for (int i = 1; i < n - 1; i++ ) {
		//将堆底拿到堆顶 i.  这是小堆顶，每次都将最小的元素保持在堆顶，然后堆后移 1，最后得出升序
		int exchange = list[n - 1];
		for (int j = i; j < n; j++) {
			int k = list[j];
			list[j] = exchange;
			exchange = k;
		}
		// 堆 i 被破坏，执行检查
		adjustHeap(list, n, i, i);
		printList(list, n);
	}

	printf("======\n");

	// 建好堆后，初始堆顶就是最小的
	for (int i = n - 1; i > 0; i--) {
		//将堆顶换到堆底.  这是小堆顶，每次都将最小的元素换到堆底，然后 堆缩小 1，最后得出降序
		int exchange = list[0];
		list[0] = list[i];
		list[i] = exchange;
		// 堆 0 被破坏，执行检查
		adjustHeap(list, i, 0, 0);
		printList(list, n);
	}


	system("pause");
    return 0;
}

