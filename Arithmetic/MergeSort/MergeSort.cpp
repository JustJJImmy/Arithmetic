// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

void printList(int *l, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", l[i]);
	}
	printf("\n");
}

void merge(int *list, int *listResult, int laStartIndex, int seperateIndex, int lbEndIndex) {
	cout << "归并前：";
	printList(list, 10);
	int index = laStartIndex;
	int i = laStartIndex;
	int j = seperateIndex;
	for (; i < seperateIndex && j <= lbEndIndex; index++){
		if (list[i] > list[j]) {
			listResult[index] = list[j++];
		} else {
			listResult[index] = list[i++];
		}
	}
	while (i < seperateIndex) {
		listResult[index++] = list[i++];
	}
	while (j <= lbEndIndex) {
		listResult[index++] = list[j++];
	}

	i = laStartIndex;
	while (i <= lbEndIndex) {
		list[i] = listResult[i];
		i++;
	}

	cout << "归并后：";
	printList(list, 10);
}

static int countM = 0;
void  mergeSort(int *list, int *listResult, int startIndex, int len) {
	if (len == 1) {
		return;
	}
	int c = countM++;
	int seperateIndex = startIndex + len / 2;
	int endIndex = startIndex + len - 1;
	cout << endl<< c <<":归并排序前：len：" << len << ",startIndex:" << startIndex << ", seperateIndex:" << seperateIndex << ", endIndex:" << endIndex<<endl;
	printList(list, 10);

	mergeSort(list, listResult, startIndex, seperateIndex - startIndex);
	cout << c << ":归并排序 左子表：";
	printList(list, 10);
	mergeSort(list, listResult, seperateIndex, endIndex - seperateIndex + 1);
	cout << c << ":归并排序 右子表：";
	printList(list, 10);

	merge(list, listResult, startIndex, seperateIndex, endIndex);
	cout <<c<< ":归并排序后：";
	printList(list, 10);
	cout << endl;
}

int main()
{
	int a[10] = { 3,7,5,1,2,4,9,6,10,8 };
	int b[10] = {0};
	cout << "初始值：";
	printList(a, 10);

	/// 归并
	mergeSort(a, b, 0, 10);

	cout << "归并排序后：";
	printList(a, 10);

	system("pause");

    return 0;
}

