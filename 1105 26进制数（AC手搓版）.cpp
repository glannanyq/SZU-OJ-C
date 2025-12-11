#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	//char arr[50][200];
	char arr[50][200] = { '\0' };
	/*for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++)arr[i][j] = '\0';
	}*/
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &arr[i]);
	}
	int len[50] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int index = 0;
		while (arr[i][index] != '\0')
		{
			index++;
		}
		len[i] = index;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (len[i] > len[j])
			{
				for (int k = 0; k < len[i]; k++)
				{
					char temp = arr[i][k];
					arr[i][k] = arr[j][k];
					arr[j][k] = temp;
				}
				int temp1 = len[i];
				len[i] = len[j];
				len[j] = temp1;
			}
			else if (len[i] == len[j])
			{
				int flag = 0;
				for (int k = 0; k < len[i]; k++)
				{
					if (arr[i][k] > arr[j][k])
					{
						flag = 1;
						break;
					}
					if (arr[i][k] < arr[j][k])
					{
						flag = -1;
						break;
					}
				}
				if (flag !=1)
				{
					for (int k = 0; k < len[j]; k++)
					{
						char temp = arr[i][k];
						arr[i][k] = arr[j][k];
						arr[j][k] = temp;
					}
					int temp1 = len[i];
					len[i] = len[j];
					len[j] = temp1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;
}
