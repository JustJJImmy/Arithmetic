#include <iostream>

void printList(int *l, int n) {

	for (int i = 0; i < n;i++ ) {
		printf("%d ", l[i]);
	}
	printf("\n");
}

void shellInsertSort(int *a, int n, int jp) {
	printf("n:%d, jp:%d\n", n, jp);
	// ֱ�Ӳ�������� jp Ϊ1��һ��һ���ƶ�
	for (int i = jp; i < n; i++ ) {
		// ����Ŀ�� Ϊ jp����ѭ���� step ��ȻΪ 1
		int k = a[i];
		// Ҫ�����λ��
		int index = i;
		for ( int j = i - jp; j >= 0; j = j - jp){
			if ( a[j] > k ){
				// ��� j �ڵ��ֵ���� k����ô�ͽ� j �ڵ����jpλ�������²���λ��
				a[j + jp] = a[j];
				index = j;
				printList(a, 8);
			}
			else {
				break;
			}
		}
		a[index] = k;
		printList(a, 8);
		printf("%d\n", i);
	}
}

// �� ���ȵ�һ���ȷ����飬Ȼ�������С��ֱ����СΪ1����ʱ����ֱ�Ӳ���������
void shellSort(int *a, int n) {
	int step = 2;
	int jp = n / step;   // ��һ�η�����
	while (jp >= 1) {
		shellInsertSort(a, n, jp);
		jp /= step;
	}
}


int main() {


	int a[9] = { 3, 10, 1,5,7,2,4,9,6 };
	printList(a, 9);

	// ֱ�Ӳ�������
	//shellInsertSort(a, 9, 1);

	shellSort(a, 4);

	printList(a, 9);

	system("pause");
	return 0;
}
