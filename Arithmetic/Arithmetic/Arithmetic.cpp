/*


1、插入排序
将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。
如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相等元素的后面。所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，所以插入排序是稳定的。
两层循环，时间复杂度 O(n^2)。


1、
要点：设立哨兵，作为临时存储和判断数组边界之用。

int main()
{
int list[50] = { 3, 7, 5, 4, 2, 6, 1, 8, 9};

int n = lenth(list);
for (int i = 1; i < n; i++) {
if (list[i] < list[i - 1]) {   // 如果 i 比 i - 1 小，那么 i 应该要前移
int j = i - 1;	//
int x = list[i];	// 这个就是哨兵了，所有比 x 大的，都往后移动一个位置
list[i] = list[i - 1]; //
while (x < list[j]) {
list[j + 1] = list[j];
j--;
printList(list);
}
list[j + 1] = x; // 此时的 j 是最后一个 比 x 小的，所以将 x 赋值到 j + 1 即可。
}
}
}

2、
不设立哨兵，如果 i 比 i - 1 那么就交换 i 和 i - 1，再 i --， 直到 i 为 0 或 i 比 i - 1 大
int main()
{
int list[50] = { 3, 7, 5, 4, 2, 6, 1, 8, 9};

int l = lenth(list);
for (int i = 1; i < l; i++) {			// 从 1 开始
for (int j = i; j > 0; j--) {		//
if (list[j] < list[j - 1]) {		//  j 从 i 开始，向前遍历， 如果 j 比 j - 1 小， 那么就交换，否则退出循环
int k = list[j];
list[j] = list[j - 1];
list[j - 1] = k;
printList(list);
}
else {
break;
}
}
}
}


3、
2 的优化， 更少的代码
int main()
{
int list[50] = { 3, 7, 5, 4, 2, 6, 1, 8, 9};
int *tl = list + 1;
while (*tl != '\0') {
int *ti = tl;
int *tj = tl - 1;
while (*ti < *tj) {
int k = *ti;
*ti-- = *tj;
*tj-- = k;
printList(list);
}
tl++;
}
}



*/



#include <iostream>
int lenth(int *l) {
	int count = 0;
	while (*l) {
		count++; 
		l++;
	}
	return count;
}

void printList(int *l) {
	while (*l != '\0') { 
		printf("%d ", *l);
		l++;
	}
	printf("\n");
}

void swap(int *s, int *d) {
	int k = *s;
	*s = *d;
	*d = k;
}

int main()
{
	int list[50] = { 1, 7, 5, 4, 2, 6, 3, 8, 9};


	printList(list);

	//int n = lenth(list);
	//for (int i = 1; i < n; i++) {
	//	if (list[i] < list[i - 1]) {
	//		int j = i - 1;
	//		int x = list[i];
	//		list[i] = list[i - 1];
	//		while (x < list[j]) {
	//			list[j + 1] = list[j];
	//			j--;
	//			printList(list);
	//		}
	//		list[j + 1] = x;
	//		printList(list);
	//	}
	//}


	//int l = lenth(list);
	//for (int i = 1; i < l; i++) {
	//	for (int j = i; j > 0; j--) {
	//		if (list[j] < list[j - 1]) {
	//			int k = list[j];
	//			list[j] = list[j - 1];
	//			list[j - 1] = k;
	//			printList(list);
	//		}
	//		else {
	//			break;
	//		}
	//	}
	//}


	int *tl = list + 1;
	while (*tl != '\0') {
		int *ti = tl;
		int *tj = tl - 1;
		int k = 0;
		while (*ti < *tj) {
			k = *ti;
			*ti-- = *tj;
			*tj-- = k;
			printList(list);
		}
		tl++;
	}

	system("pause");
    return 0;
}

