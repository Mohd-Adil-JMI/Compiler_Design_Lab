#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFinal(int curr, int *finalStates, int no_finalStates)
{
	for (int i = 0; i < no_finalStates; i++)
	{
		if (curr == finalStates[i])
			return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	FILE *fp;
	fp = fopen("DFA.txt", "r");
	int finalStates[100];
	int DFA[100][100];
	int init;
	char ch;
	fscanf(fp, "%d%c", &init, &ch);
	int row = 0, col = 0;
	int no_finalStates = 0;
	do
	{
		fscanf(fp, "%d%c", &finalStates[no_finalStates++], &ch);

	} while (ch != '\n');
	row = 0;
	int i = 7;
	while (ch != EOF)
	{
		fscanf(fp, "%d", &DFA[row][col++]);
		ch = getc(fp);
		// printf("%c", ch);
		if (ch == '\n')
		{
			row++;
			col = 0;
		}
	}
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", DFA[i][j]);
		}
		printf("\n");
	}
	fp = fopen("input.txt", "r");
	int curr = init;
	while ((ch = getc(fp)) != EOF && curr != -1)
	{
		// printf("%c", ch);
		curr = DFA[curr][atoi(&ch)];
		// printf("%d", curr);
	}
	// printf("%d", curr);
	// printf("%d", isFinal(curr, finalStates, no_finalStates));
	if (curr == -1 || !isFinal(curr, finalStates, no_finalStates))
		printf("STRING NOT ACCEPTED\n");
	else
		printf("STRING ACCEPTED\n");
	fclose(fp);
	return 0;
}