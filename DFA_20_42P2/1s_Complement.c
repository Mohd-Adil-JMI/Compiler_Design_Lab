#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("DFA.txt", "r");
    int DFA[100][100][2];
    int init;
    char ch;
    fscanf(fp, "%d%c", &init, &ch);
    int row = 0, col = 0;
    row = 0;
    while (ch != EOF)
    {
        fscanf(fp, "%d", &DFA[row][col][0]);
        ch = getc(fp);
        fscanf(fp, "%d", &DFA[row][col][1]);
        col++;
        ch = getc(fp);
        if (ch == '\n')
        {
            row++;
            col = 0;
        }
    }
    printf("%d %d", row, col);
    for (int i = 0; i <= row; i++)
    {
        printf("q%d -> ",i);
        for (int j = 0; j < col; j++)
        {
            printf("State: %d   Output:%d ", DFA[i][j][0], DFA[i][j][1]);
        }
        printf("\n");
    }
    fp = fopen("input.txt", "r");
    int curr = init;
    while ((ch = getc(fp)) != EOF && curr != -1)
    {
        curr = DFA[curr][atoi(&ch)][0];
        // printf("Curr->%d ", curr);
        printf("%d", DFA[curr][atoi(&ch)][1]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}