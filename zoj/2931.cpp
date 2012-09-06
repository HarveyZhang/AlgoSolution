// solution for Typesetting by whatashya@ZJU
#include <stdio.h>
#include <string.h>
#define INF 999999999
#define LEN 22
char str[20][1000];
const char* ps = "......................";
int n, m;
int main()
{
    int ri = 0;
    int i, j, a, b, c;

    while(scanf("%d ", &n) != EOF && n) {
        //input
        for (i = 0; i < n; i++) {
            strcpy(str[i], ps);
            j = LEN;
            do {
                do {
                    str[i][j] = getchar();
                    if(str[i][j] == ' ') {
                        strcpy(str[i] + j, ps);
                        str[i][j += LEN] = ' ';
                        break;
                    }
                    else if(str[i][j] == '\n') {
                        strcpy(str[i] + j, ps);
                        str[i][m = j + LEN] = '\0';
                        j = 0;
                        break;
                    }
                }while(++j);
            }while(j++);
        }
        //doit
        for (j = 0; j < m; j++) {
            if(str[0][j] != ' ') continue;
            c = INF;
            for (i = 0; i < n; i++) {
                str[i][j] = '.';
                a = j;
                while(--a >= 0 && str[i][a] == '.');
                b = j;
                while(str[i][++b] == '.');
                if(b - a < c) c = b - a;
            }
            c -= 2;
            if(c == 0) continue;
            for (i = 0; i < n; i++) {
                b = j;
                while(str[i][++b] == '.');
                do {
                    str[i][b - c] = str[i][b];
                }while(++b <= m);
            }
            j -= c;
            m -= c;
        }
        //ouput
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if(str[i][j] == '0') str[i][j] = '.';
        for (j = m - 1; j >= 0; j--) {
            for (i = 0; i < n; i++)
                if(str[i][j] != '.') break;
            if(i < n) break;
        }
        m = j + 1;
        for (i = 0; i < n; i++)
            str[i][m] = '\0';
        for (j = 0; j < m; j++) {
            for (i = 0; i < n; i++)
                if(str[i][j] != '.') break;
            if(i < n) break;
        }
        printf("%d\n", ++ri);
        for (i = 0; i < n; i++)
            puts(str[i] + j);
    }
}
/*
real    0m0.437s
user    0m0.046s
sys     0m0.217s
*/

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2768701 2008-03-03 16:32:33 Accepted 2931 C++ 00:00.00 416K �錄��

// 2012-09-07 01:48:12 | Accepted | 2931 | C++ | 0 | 200 | watashi | Source
