/*


1、插入排序
将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。
如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相等元素的后面。所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，所以插入排序是稳定的。
两层循环，时间复杂度 O(n^2)。


1、
要点：设立哨兵，作为临时存储和判断数组边界之用。


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
	int list[50] = { 3, 7, 5, 4, 2, 6, 1, 8, 9};
	// 默认第一个已经插入，后面的节点往前面插入
	for (int i = 1; i < 10; i++){
		// 哨兵
		int k = list[i];
		// 要插入的位置
		int index = i;
		// 从已排序的最后一个点开始插入
		for (int j = i - 1; j >= 0; j-- ) {
			if ( list[j] > k ){
				// 如果 j 节点的值大于 k，那么就将 j 节点后移一位，并更新插入位置
				list[j + 1] = list[j];
				index = j;
				printList(list);
			}
			else {
				break;
			}
		}
		list[index] = k;
	}
	printList(list);
}


2、这似乎是冒泡排序?
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


3、2 的优化， 更少的代码
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

void printList(int *l) {
	while (*l != '\0') {
		printf("%d ", *l);
		l++;
	}
	printf("\n");
}


///////
template<class T>
void insertSort(T *list, bool(cp)(T *a, T *b), void (swap)(T *a, T *b), T *(next)(T *a, bool pre), bool(isend)(T *a)) {
	T *tl = next(list, false);
	while (!isend(tl)) {
		T *ti = tl;
		T *tj = next(ti, true);
		while (ti != list && cp(ti, tj)) {
			swap(ti, next(ti, true));
			ti = next(ti, true);
			tj = next(ti, true);
		}
		tl = next(tl, false);
	}
}
///////


bool compareInt(int *a, int *b) {
	return *a < *b;
}
bool compareIntL(int *a, int *b) {
	return *a > *b;
}
void swapInt(int *a, int *b) {
	int k = *a;
	*a = *b;
	*b = k;
}
int *nextInt(int *a, bool pre) {
	return pre ? a - 1: a + 1;
}
bool isEnd(int *a) {
	return *a == '\0';
}

int main()
{
	int list[50] = { 10, 7, 1 , 5, 8, 12, 6, 3, 8, 9};
	printList(list);

	// 默认第一个已经插入，后面的节点往前面插入
	for (int i = 1; i < 10; i++){
		// 哨兵
		int k = list[i];
		// 要插入的位置
		int index = i; 
		// 从已排序的最后一个点开始插入
		for (int j = i - 1; j >= 0; j-- ) {
			if ( list[j] > k ){
				// 如果 j 节点的值大于 k，那么就将 j 节点后移一位，并更新插入位置
				list[j + 1] = list[j];
				index = j;
				printList(list);
			}
			else {
				break;
			}
		}
		list[index] = k;
	}
	printList(list);





	insertSort<int>(list, compareInt, swapInt, nextInt, isEnd);
	printList(list);

	insertSort<int>(list, compareIntL, swapInt, nextInt, isEnd);
	printList(list);

	insertSort<int>(list, compareInt, swapInt, nextInt, isEnd);
	printList(list);

	system("pause");
    return 0;
}

