/*


1����������
��һ����¼���뵽������õ�������У��Ӷ��õ�һ���£���¼����1������������Ƚ����еĵ�1����¼������һ������������У�Ȼ��ӵ�2����¼������в��룬ֱ��������������Ϊֹ��
�������һ���Ͳ���Ԫ����ȵģ���ô����Ԫ�ذ�������Ԫ�ط������Ԫ�صĺ��档���ԣ����Ԫ�ص�ǰ��˳��û�иı䣬��ԭ�������г�ȥ��˳������ź�����˳�����Բ����������ȶ��ġ�
����ѭ����ʱ�临�Ӷ� O(n^2)��


1��
Ҫ�㣺�����ڱ�����Ϊ��ʱ�洢���ж�����߽�֮�á�

int main()
{
int list[50] = { 3, 7, 5, 4, 2, 6, 1, 8, 9};

int n = lenth(list);
for (int i = 1; i < n; i++) {
if (list[i] < list[i - 1]) {   // ��� i �� i - 1 С����ô i Ӧ��Ҫǰ��
int j = i - 1;	//
int x = list[i];	// ��������ڱ��ˣ����б� x ��ģ��������ƶ�һ��λ��
list[i] = list[i - 1]; //
while (x < list[j]) {
list[j + 1] = list[j];
j--;
printList(list);
}
list[j + 1] = x; // ��ʱ�� j �����һ�� �� x С�ģ����Խ� x ��ֵ�� j + 1 ���ɡ�
}
}
}

2��
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


3��
2 ���Ż��� ���ٵĴ���
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

