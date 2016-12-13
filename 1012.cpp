#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
char mm[21][21];
int a[21][21];
int h;
int w;
int count;
using namespace std;

int wow(int i, int j)
{

    if(i + 1 < h and !a[i+1][j] and mm[i+1][j] == '.') {
        a[i+1][j] = 1;
        count++;
        wow(i+1, j);
    }

    if(i - 1 >= 0 and !a[i-1][j] and mm[i-1][j] == '.') {
        a[i-1][j] = 1;
        count++;
        wow(i-1, j);
    }

    if(j + 1 < w and !a[i][j+1] and mm[i][j+1] == '.') {
        a[i][j+1] = 1;
        count++;
        wow(i, j+1);
    }

    if(j - 1 >= 0 and !a[i][j-1] and mm[i][j-1] == '.') {
        a[i][j-1] = 1;
        count++;
        wow(i, j -1);
    }

}



int main()
{

    int x;
    int p;
    int r;
    int t;


    cin >> t;
    for (int k = 1; k <= t; k++) {

        cin >> w;
        cin >> h;
        count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {

                cin >> mm[i][j];
                if(mm[i][j] == '@') {
                    p = i;
                    r = j;
                    count = 1;
                }

            }

        }

        memset(a, 0, sizeof(a));
        a[p][r] = 1;
        wow(p, r);
        printf("Case %d: %d\n",k, count);
    }

}
