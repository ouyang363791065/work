# include <stdio.h>

void hannuota(int n, char A, char B, char C)
{
/*
	�����1������
		ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
	����
		�Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
		ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
		���B�����ϵ�n-1�����ӽ���A�Ƶ�C
*/
	if (1 == n)
	{
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
	}
	else
	{
		hannuota(n-1, A, C, B);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
		hannuota(n-1, B, A, C);
	}
}

int main(void)
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("������Ҫ�ƶ����ӵĸ���: ");
	scanf("%d", &n);

	hannuota(n, 'A', 'B', 'C');


	return 0;
}