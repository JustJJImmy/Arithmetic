// selectSort.cpp : 定义控制台应用程序的入口点。
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
	int list[50] = { 10, 7, 1 , 8, 5, 12, 6, 3, 9};
	printList(list, 9);

	//// 简单选择排序，每次选取最小的放最前面
	//for (int i = 0; i < 9; i++ ) {
	//	int minIndex = i;
	//	for (int j = i+1; j < 9; j++){
	//		if ( list[j] < list[minIndex]){
	//			// 替换最小值得 index
	//			minIndex = j;
	//		}
	//	}

	//	int k = list[i];
	//	list[i] = list[minIndex];
	//	list[minIndex] = k;
	//	printList(list, 9);
	//}


	// 二元选择排序，每次选取最小的放最前面，选最大的放后面
	for (int i = 0; i < 9 / 2; i++) {
		int minIndex = i;
		int maxIndex = i;
		for (int j = i+1; j < 9 - i; j++){
			if ( list[j] < list[minIndex]  ){
				minIndex = j;
			} if ( list[j] > list[maxIndex] ){
				maxIndex = j;
			}
		}

		if ( i != minIndex ){
			int k = list[i];
			list[i] = list[minIndex];
			list[minIndex] = k;

		}

		// 要特别留意 maxIndex == i 的时候，i 可能会被换掉
		if ( maxIndex == i ){
			maxIndex = minIndex;
		}

		int m = list[9 - i - 1];
		list[9 - i - 1] = list[maxIndex];
		list[maxIndex] = m;
		printList(list, 9);
	}





	system("pause");

    return 0;
}

