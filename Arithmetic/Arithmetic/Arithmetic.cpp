/*


1����������
��һ����¼���뵽������õ�������У��Ӷ��õ�һ���£���¼����1������������Ƚ����еĵ�1����¼������һ������������У�Ȼ��ӵ�2����¼������в��룬ֱ��������������Ϊֹ��
�������һ���Ͳ���Ԫ����ȵģ���ô����Ԫ�ذ�������Ԫ�ط������Ԫ�صĺ��档���ԣ����Ԫ�ص�ǰ��˳��û�иı䣬��ԭ�������г�ȥ��˳������ź�����˳�����Բ����������ȶ��ġ�
����ѭ����ʱ�临�Ӷ� O(n^2)��


1��
Ҫ�㣺�����ڱ�����Ϊ��ʱ�洢���ж�����߽�֮�á�


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
	// Ĭ�ϵ�һ���Ѿ����룬����Ľڵ���ǰ�����
	for (int i = 1; i < 10; i++){
		// �ڱ�
		int k = list[i];
		// Ҫ�����λ��
		int index = i;
		// ������������һ���㿪ʼ����
		for (int j = i - 1; j >= 0; j-- ) {
			if ( list[j] > k ){
				// ��� j �ڵ��ֵ���� k����ô�ͽ� j �ڵ����һλ�������²���λ��
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


2�����ƺ���ð������?
�������ڱ������ i �� i - 1 ��ô�ͽ��� i �� i - 1���� i --�� ֱ�� i Ϊ 0 �� i �� i - 1 ��
int main()
{
	int list[50] = { 3, 7, 5, 4, 2, 6, 1, 8, 9};

	int l = lenth(list);
	for (int i = 1; i < l; i++) {			// �� 1 ��ʼ
		for (int j = i; j > 0; j--) {		//
			if (list[j] < list[j - 1]) {		//  j �� i ��ʼ����ǰ������ ��� j �� j - 1 С�� ��ô�ͽ����������˳�ѭ��
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


3��2 ���Ż��� ���ٵĴ���
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

	// Ĭ�ϵ�һ���Ѿ����룬����Ľڵ���ǰ�����
	for (int i = 1; i < 10; i++){
		// �ڱ�
		int k = list[i];
		// Ҫ�����λ��
		int index = i; 
		// ������������һ���㿪ʼ����
		for (int j = i - 1; j >= 0; j-- ) {
			if ( list[j] > k ){
				// ��� j �ڵ��ֵ���� k����ô�ͽ� j �ڵ����һλ�������²���λ��
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

