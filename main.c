#include <stdio.h>  
#include <string.h>  
#include<windows.h>

int main()
{
		int count = 0;
		int totalCount = 0;
		char data[1000];
		unsigned char val = 0;

		int uBits = 0;

		int uDataLen = 0;
		unsigned char pBuf[1000] = {0};

		int leixing5 = 0;
		int Index = 6;
		int count_i = 0;
	//	int judgeID = 0;

		FILE *fp = fopen("hd10_F00x_565958301.txt", "rb");
		if (fp == NULL)
		{
			printf("open file faild\n");
			getchar();
			return -1;
		}
		printf("open file success\n");


	while (!feof(fp))
	{
		count = fread(data, 1, 10, fp);
		totalCount += count;

		for (int i = 0; i < count; i++)
		{
			if (data[i] == 0x20)
			{
				continue;
			}
			if (data[i] >= '0' && data[i] <= '9')
			{
				data[i] = data[i] - '0';
			}
			else if (data[i] >= 'a' && data[i] <= 'f')
			{
				data[i] = data[i] - 'a' + 10;
			}
			else
			{
				uBits = 0;
				break;
			}
			if (uBits)
			{
				count_i++;
				pBuf[uDataLen++] = val | data[i];
				uBits = 0;
				printf("pBuf[%d] = 0x%x   ", uDataLen - 1, pBuf[uDataLen - 1]);
			}
			else {
				uBits = 1;
				val = data[i] << 4;
			}
		//	printf("0x%x ", data[i]);
		}

		if (count_i >= 200)
		{
			switch (pBuf[Index])
			{
				case 0x00:
					printf("0x00OK!!!!!!!!!!!!--Index = %d", Index);
					leixing5++;
					Index = Index + 5;
					break;
				case 0x01:
					printf("0x01OK!!!!!!!!!!!!");
					leixing5++;
					Index = Index + 5;
					break;
				case 0x02:
					printf("0x02OK!!!!!!!!!!!!");
					leixing5++;
					Index = Index + 4;
					break;
				case 0x03:
					printf("0x03OK!!!!!!!!!!!!");
					leixing5++;
					Index = Index + 4;
					break;
				case 0x04:
					printf("0x04OK!!!!!!!!!!!!");
					leixing5++;
					Index = Index + 5;
					break;
				case 0x05:
					printf("0x05OK!!!!!!!!!!!!");
					leixing5++;
					Index = Index + 4;
					break;
				case 0x06:
					printf("0x05OK!!!!!!!!!!!!");
					leixing5++;
					Index = Index + 8;
					break;
				case 0x07:
					printf("0x07OK!!!!!!!!!!!!");
					leixing5++;
					Index = Index + 7;
					break;
			}

		}

		Sleep(100);
		printf("\n");
		
	}

	fclose(fp);

	return 0;
}
