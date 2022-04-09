#include <stdio.h>
#include <string.h>
#include <unistd.h>

void move(int pegA[9], int pegB[9])
{
	int x, i;

	if (sizeof(pegA) == 9)
	{
		x = pegA[8];
		pegA[8] = 0;
	}
	else
	{
		for (i = 8; i >= 0; i--)
		{
			if (pegA[i] != 0)
			{
				x = pegA[i];
				pegA[i] = 0;
				break;
			}
		}
	}

	for (i = 0; i < 9; i++)
	{
		if (pegB[i] == 0)
		{
			pegB[i] = x;
			break;
		}
	}
}

void display_pegs(int peg1[9], int peg2[9], int peg3[9])
{
	int i, j, k, l, m;

	for (i = 8; i >= 0; i--)
	{

		// size of disk
		int p1 = peg1[i];
		int p2 = peg2[i];
		int p3 = peg3[i];

		// number of spaces required for each disk
		int sp1 = 10 - p1;
		int sp2 = 10 - p2;
		int sp3 = 10 - p3;

		// printing peg1	disk
		for (j = 0; j < sp1; j++)
		{
			printf(" ");
		}
		for (k = 0; k < p1; k++)
		{
			printf("+");
		}
		printf("|");

		for (k = 0; k < p1; k++)
		{
			printf("+");
		}
		for (j = 0; j < sp1; j++)
		{
			printf(" ");
		}
		printf("     ");

		// printing peg2 disk
		for (j = 0; j < sp2; j++)
		{
			printf(" ");
		}
		for (k = 0; k < p2; k++)
		{
			printf("+");
		}
		printf("|");

		for (k = 0; k < p2; k++)
		{
			printf("+");
		}
		for (j = 0; j < sp2; j++)
		{
			printf(" ");
		}
		printf("     ");

		// printing peg3 disk
		for (j = 0; j < sp3; j++)
		{
			printf(" ");
		}
		for (k = 0; k < p3; k++)
		{
			printf("+");
		}
		printf("|");

		for (k = 0; k < p3; k++)
		{
			printf("+");
		}
		for (j = 0; j < sp3; j++)
		{
			printf(" ");
		}
		printf("\n");
	}

	for (m = 0; m <= 2; m++)
	{
		for (l = 0; l < 21; l++)
		{
			printf("X");
		}
		printf("     ");
	}
	printf("\n");
	printf("\n");
}

void hantow(int nod, int pego[9], int pegd[9], int pegh[9], int *p1, int *p2, int *p3)
{
	if (nod > 1)
	{
		hantow(nod - 1, pego, pegh, pegd, p1, p2, p3);
	}
	move(pego, pegd);
	display_pegs(p1, p2, p3);
	sleep(1);
	if (nod > 1)
	{
		hantow(nod - 1, pegh, pegd, pego, p1, p2, p3);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Incorrect number of command line arguments\n");
		return 0;
	}
	if (strlen(argv[1]) != 1)
	{
		printf("Incorrect command line arguemnt\n");
		return 0;
	}
	if (argv[1][0] > '9' || argv[1][0] < '1')
	{
		printf("Incorrect range for command line argument\nCommand line argument should be between 1 and 9\n");
		return 0;
	}

	int num_of_disks = argv[1][0] - '0';

	int peg1[9] = {0};
	int peg2[9] = {0};
	int peg3[9] = {0};

	int *p1 = peg1;
	int *p2 = peg2;
	int *p3 = peg3;

	int i = 0;
	int temp = num_of_disks;

	while (temp > 0)
	{
		peg1[i] = temp;
		i++;
		temp--;
	}

	display_pegs(peg1, peg2, peg3);
	sleep(1);
	hantow(num_of_disks, peg1, peg2, peg3, p1, p2, p3);
	printf("done\n");
	return 0;
}
