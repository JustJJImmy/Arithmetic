// BubbleSort.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

void printList(int *l, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", l[i]);
	}
	printf("\n");
}

int main()
{
	int list[50] = { 12, 7, 1 , 8, 5, 10, 6, 3, 9 };
	int n = 9;
	printList(list, n);

	//// 升序，大的先排，小的向上冒泡
	//for ( int i = n - 1; i > 0; ){
	//	//　以 i 为哨兵，从 顶部 开始。
	//	printf("i:%d\n", i);
	//	int lastIndex = 0;
	//	bool hasSwap = false;
	//	for (int j = 0; j < i; j++){
	//		// 如果 j 比它后面的数大，那么就交换
	//		if ( list[j] > list[j+1] ){
	//			int k = list[j];
	//			list[j] = list[j + 1];
	//			list[j + 1] = k;
	//			hasSwap = true;
	//			lastIndex = j;
	//		}
	//	}
	//	// 如果一次遍历没有发生交换，说明已经排好了，可以提前结束
	//	if ( !hasSwap ){
	//		break;
	//	}
	//	// 记录最后一次交换的 index，用来当做下一次循环的哨兵
	//	i = lastIndex;
	//	printList(list, n);
	//}
	//printList(list, n);

	//printf("==================\n");
	//// 升序，小的先排，大的向下沉
	//for (int i = 0; i < n;) {
	//	//　以 i 为哨兵，从 底部 开始。
	//	printf("i:%d\n", i);
	//	int lastIndex = i;
	//	bool hasswap = false;
	//	for (int j = n - 1; j > i; j--) {
	//		// 如果 j 比它前面的数小，那么就交换
	//		if (list[j] < list[j - 1]) {
	//			int k = list[j];
	//			list[j] = list[j - 1];
	//			list[j - 1] = k;
	//			hasswap = true;
	//			lastIndex = j;
	//		}
	//	}
	//	// 如果一次遍历没有发生交换，说明已经排好了，可以提前结束
	//	if ( !hasswap ){
	//		break;
	//	}
	//	i = lastIndex;
	//	printList(list, n);
	//}
	//printList(list, n);


	//printf("==================\n");
	// 升序，双向冒泡，先从底部开始向上冒泡
	int leftIndex = 0;
	int rightIndex = n - 1;
	while (leftIndex < rightIndex) {
		int lastIndex = leftIndex;
		bool hasSwap = false;

		// 先向上冒泡一轮
		for (int j = leftIndex; j < rightIndex; j++) {
			if ( list[j] > list[j + 1] ){
				int k = list[j];
				list[j] = list[j + 1];
				list[j + 1] = k;
				hasSwap = true;
				lastIndex = j;
			}
		}
		// 提前结束
		if ( !hasSwap )	{
			break;
		}
		// 向上冒泡，更新的是下限
		rightIndex = lastIndex;
		printList(list, n);
		printf("leftIndex:%d， rightIndex:%d\n", leftIndex, rightIndex);

		// 再向下冒泡一轮
		for (int j = rightIndex; j > leftIndex; j--) {
			if (list[j] < list[j - 1] ) {
				int k = list[j];
				list[j] = list[j - 1];
				list[j - 1] = k;
				hasSwap = true;
				lastIndex = j;
			}
		}
		// 提前结束
		if (!hasSwap) {
			break;
		}
		// 向下冒泡，更新的是上限
		leftIndex = lastIndex;
		printList(list, n);
		printf("leftIndex:%d， rightIndex:%d\n", leftIndex, rightIndex);
	}
	printList(list, n);




	system("pause");
    return 0;
}

