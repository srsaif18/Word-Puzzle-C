//  main.c
//  Word Search Solver
//
//  Created by MD Saifur Rahman on 20/03/20.
//  Copyright © 2020 MD Saifur Rahman. All rights reserved.

#include <stdio.h>
#include <string.h>

void openFile();
void readData();
void game();
void readWords();
int check(int a, int b);
int serch(int a, int n, int b, char test[]);
int serch1(int a, int n, int b, char test[]);
int serch2(int a, int n, int b, char test[]);
int serch3(int a, int n, int b, char test[]);
int serch4(int a, int n, int b, char test[]);
int serch5(int a, int n, int b, char test[]);
int serch6(int a, int n, int b, char test[]);
int serch7(int a, int n, int b, char test[]);

char word[30][30];
char puzzle[40][40];
int p, h;

int main()
{
    system("COLOR 4F");
    coverPage();
    openFile();
    readData();
    printf("Try First!\n\nThese are the words:\n\n");
    readWords();
    game();
    return 0;
}

void openFile()
{
    FILE *fp;
    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening file\n");
    }
    fscanf(fp, "%d %d", &p, &h);
    char line[40], line2[40];
    int i, rows = 0;
    while (fgets(line, sizeof(line), fp) != NULL && rows < p)
    {
        for (i = 0; i < (strlen(line) - 1); i++)
        {
            puzzle[rows - 1][i] = line[i];
        }
        rows++;
    }
    for (i = 0; i < (strlen(line) - 1); i++)
        puzzle[rows - 1][i] = line[i];
    rows = 0;
    while (fgets(line2, sizeof(line2), fp) != NULL)
    {
        for (i = 0; i < (strlen(line2) - 1); i++)
        {
            word[rows][i] = line2[i];
        }
        rows++;
    }
}
void readData()
{
    int i = 0;
    for (i = 0; i < p; i++)
        printf("%s\n", puzzle[i]);
    printf("\n\n");
}
void readWords()
{
    int i = 0;
    for (i = 0; i < h; i++)
    {
        printf("%10s", word[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
    printf("\n____________________________________________________________________\n");
}
void game()
{
    int i = 0, j = 0;
    int leter, x = 0;
    char choose[5];
    printf("\nTo see the solution enter 'Show'\n");
    scanf("%s", choose);
    system("COLOR 0A");
    printf("\n");
    if (strcmp(choose, "show") == 0 || strcmp(choose, "SHOW") == 0 || strcmp(choose, "Show") == 0)
    {
        printf("Word\t\tRow,Column \tDirection\t\n");
        printf("-----------------------------------------------\n");
        for (x = 0; x < h; x++)
        {
            for (i = 0; i < 40; i++)
            {
                for (j = 0; j < 40; j++)
                {
                    if (puzzle[i][j] == word[x][0])
                    {
                        leter = strlen(word[x]);
                        if (check(i + leter - 1, j) == 1 && serch(i, leter, j, word[x]) == 1)
                        {
                            printf("\t%d,%d \t\t Down \n", i + 1, j + 1);
                        }
                        else if (check(i, j + leter - 1) == 1 && serch1(i, leter, j, word[x]) == 2)
                        {
                            printf("\t%d,%d \t\t Right\n", i + 1, j + 1);
                        }
                        else if (check(i + leter - 1, j + leter - 1) == 1 && serch2(i, leter, j, word[x]) == 3)
                        {
                            printf("\t%d ,%d \t\t Down,Right \n", i + 1, j + 1);
                        }
                        else if (check(i, j - leter + 1) == 1 && serch3(i, leter, j, word[x]) == 4)
                        {
                            printf("\t%d,%d \t\t Left\n", i + 1, j + 1);
                        }
                        else if (check(i - leter + 1, j) == 1 && serch4(i, leter, j, word[x]) == 5)
                        {
                            printf("\t%d,%d \t\t Up\n", i + 1, j + 1);
                        }
                        else if (check(i - leter + 1, j + leter - 1) == 1 && serch5(i, leter, j, word[x]) == 6)
                        {
                            printf("\t%d,%d \t\t Up,Right \n", i + 1, j + 1);
                        }
                        else if (check(i - leter + 1, j - leter + 1) == 1 && serch6(i, leter, j, word[x]) == 7)
                        {
                            printf("\t%d,%d \t\t Up,Left \n", i + 1, j + 1);
                        }
                        else if (check(i + leter - 1, j - leter + 1) == 1 && serch7(i, leter, j, word[x]) == 8)
                        {
                            printf("\t%d,%d \t\t Down,Left \n", i + 1, j + 1);
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Invalid input\n ");
        game();
    }
}
int check(int a, int b)
{
    if (puzzle[a][b] != 0)
        return 1;
    else
        return -1;
}
int serch(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        a++;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 1;
    }
    else
        return -1;
}
int serch1(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        b++;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 2;
    }
    else
        return -1;
}
int serch2(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        b++;
        a++;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 3;
    }
    else
        return -1;
}
int serch3(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        b--;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 4;
    }
    else
        return -1;
}
int serch4(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        a--;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 5;
    }
    else
        return -1;
}
int serch5(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        a--;
        b++;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 6;
    }
    else
        return -1;
}
int serch6(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        a--;
        b--;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 7;
    }
    else
        return -1;
}
int serch7(int a, int n, int b, char test[])
{
    char test2[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        test2[i] = puzzle[a][b];
        a++;
        b--;
    }
    test2[n] = '\0';
    if (strcmp(test2, test) == 0)
    {
        printf("%10s", test2);
        return 8;
    }
    else
        return -1;
}
void coverPage()
{
    printf(" ==================WELCOME============================\n");
    printf("\n Press any key to continue ...\n");
    getchar();
    system("cls");
}
