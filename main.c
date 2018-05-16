#include <stdio.h>
#include <stdlib.h>

short n;         // cube size
short **cube[3]; // cube representation
short *row[3];   // for storing row | 1 | 1 |

short *col[3];   // column storing  | 0 |
                 //                 | 0 |


//force exit
void exit_error(int code)
{
    printf("-1\n");
    exit(0);
}

// checks for '1' in (type) ? row : col;
void colorow_check(short **array, short h, short type)
{
    if (type)
    {
        for (short i = 0; i < n; i++)
            if (array[h][i]) exit_error(1);
    }
    else
        for (short i = 0; i < n; i++)
            if (array[i][h]) exit_error(1);
}

//data validating
void part_check(short **p, short **c1, short **c2, int type)
{
    int k;

    for (short i = 0; i < n; i++)
    {
        //for each row
        k = 0;
        while (k < n && !p[i][k])
            k++;
        if (k == n)
            colorow_check(c1, i, 1);

        //for each column
        k = 0;
        while (k < n && !p[k][i])
            k++;
        if (k == n)
            colorow_check(c2, i, 0);
    }
}

//data writing / reading
void part_scan(short ***part, short side)
{
    short r,c; //flags for row and col

    //scanning projection values for each row
    for (short i = 0; i < n; i++)
    {
        r = 0;

        //each col
        for (short j = 0; j < n; j++)
        {
            scanf("%hi", part[i][j]);
            if (part[i][j]) r++;
        }
    }
}

int main(int ac, char **av)
{
    //scanning n(cube size) value
    scanf("%hi", &n);


    for (short side = 0; side < 3; side++)
    {
        //allocates memory for cube parts matrix representation
        cube[side] = (short **)malloc((sizeof(short)) * n + 1);

        //allocates memory for each row in matrix
        for (short h = 0; h < n; h++)
            cube[side][h] = (short *)malloc(sizeof(short) * n);

        //allocates memory for array, where row[n] - array for rows on side
        //                                  col[n] - array for columns on side
        row[side] = (short *)malloc(sizeof(short) * n);
        col[side] = (short *)malloc(sizeof(short) * n);
    }

    //scanning data for each side
    for (short side = 0; side < 3; side++)
        part_scan(&cube[side], side);

    //checks for valid input values for each cube part
    part_check(a, b, c, 0);
    part_check(b, a, c, 1);

    //part_check(c, b, a);
    return (0);
}