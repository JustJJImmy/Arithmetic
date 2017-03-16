// BubbleSort.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//// ���򣬴�����ţ�С������ð��
	//for ( int i = n - 1; i > 0; ){
	//	//���� i Ϊ�ڱ����� ���� ��ʼ��
	//	printf("i:%d\n", i);
	//	int lastIndex = 0;
	//	bool hasSwap = false;
	//	for (int j = 0; j < i; j++){
	//		// ��� j ���������������ô�ͽ���
	//		if ( list[j] > list[j+1] ){
	//			int k = list[j];
	//			list[j] = list[j + 1];
	//			list[j + 1] = k;
	//			hasSwap = true;
	//			lastIndex = j;
	//		}
	//	}
	//	// ���һ�α���û�з���������˵���Ѿ��ź��ˣ�������ǰ����
	//	if ( !hasSwap ){
	//		break;
	//	}
	//	// ��¼���һ�ν����� index������������һ��ѭ�����ڱ�
	//	i = lastIndex;
	//	printList(list, n);
	//}
	//printList(list, n);

	//printf("==================\n");
	//// ����С�����ţ�������³�
	//for (int i = 0; i < n;) {
	//	//���� i Ϊ�ڱ����� �ײ� ��ʼ��
	//	printf("i:%d\n", i);
	//	int lastIndex = i;
	//	bool hasswap = false;
	//	for (int j = n - 1; j > i; j--) {
	//		// ��� j ����ǰ�����С����ô�ͽ���
	//		if (list[j] < list[j - 1]) {
	//			int k = list[j];
	//			list[j] = list[j - 1];
	//			list[j - 1] = k;
	//			hasswap = true;
	//			lastIndex = j;
	//		}
	//	}
	//	// ���һ�α���û�з���������˵���Ѿ��ź��ˣ�������ǰ����
	//	if ( !hasswap ){
	//		break;
	//	}
	//	i = lastIndex;
	//	printList(list, n);
	//}
	//printList(list, n);


	//printf("==================\n");
	// ����˫��ð�ݣ��ȴӵײ���ʼ����ð��
	int leftIndex = 0;
	int rightIndex = n - 1;
	while (leftIndex < rightIndex) {
		int lastIndex = leftIndex;
		bool hasSwap = false;

		// ������ð��һ��
		for (int j = leftIndex; j < rightIndex; j++) {
			if ( list[j] > list[j + 1] ){
				int k = list[j];
				list[j] = list[j + 1];
				list[j + 1] = k;
				hasSwap = true;
				lastIndex = j;
			}
		}
		// ��ǰ����
		if ( !hasSwap )	{
			break;
		}
		// ����ð�ݣ����µ�������
		rightIndex = lastIndex;
		printList(list, n);
		printf("leftIndex:%d�� rightIndex:%d\n", leftIndex, rightIndex);

		// ������ð��һ��
		for (int j = rightIndex; j > leftIndex; j--) {
			if (list[j] < list[j - 1] ) {
				int k = list[j];
				list[j] = list[j - 1];
				list[j - 1] = k;
				hasSwap = true;
				lastIndex = j;
			}
		}
		// ��ǰ����
		if (!hasSwap) {
			break;
		}
		// ����ð�ݣ����µ�������
		leftIndex = lastIndex;
		printList(list, n);
		printf("leftIndex:%d�� rightIndex:%d\n", leftIndex, rightIndex);
	}
	printList(list, n);




	system("pause");
    return 0;
}

