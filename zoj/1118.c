#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

long long mp[MAXN << 1];
long long s, t, re[MAXN][2];
char board[MAXN][MAXN];
char mark[MAXN];

int cmp(const void *pa, const void *pb)
{
    return (*(long long *)pa == *(long long *)pb) ? 0 : ((*(long long *)pa < *(long long *)pb) ? -1 : 1);
}

/*(For this problem, n will not exceed 10, and all coordinate values will be less than 10.)*/
long long getpos(int n)
{
    int i, t;
    long long res;
    scanf("%lld", &res);
    if(res == -1) return -1;
    for (i = 1; i < n; i++) {
        res *= 10;
        scanf("%d", &t);
        res += t;
    }
    return res;
}

void dfs(int n, int p)
{
    int i;
    for (i = 0; i < n; i++)
        if(!mark[i] && board[p][i]) {
            mark[i] = 1;
            dfs(n, i);
        }
}

int main()
{
    int ri = 0;
    int i, j, k, n, m;

    while(scanf("%d", &n) != EOF && n) {
        j = 0;
        s = getpos(n);
        mp[j++] = s;
        t = getpos(n);
        mp[j++] = t;
        for (i = 0; ; i++) {
            re[i][0] = getpos(n);
            if(re[i][0] < 0) break;
            re[i][1] = getpos(n);
            mp[j++] = re[i][0];
            mp[j++] = re[i][1];
        }
        k = i;
        m = j;
        qsort(mp, m, sizeof(long long), cmp);
        j = 1;
        for (i = 1; i < m; i++) {
            if(mp[i] == mp[i - 1]) continue;
            mp[j++] = mp[i];
        }
        m = j;

        for (i = 0; i < m; i++) {
            mark[i] = 0;
            for (j = 0; j < m; j++)
                board[i][j] = 0;
        }
        while(k--) {
            i = (long long *)bsearch(&re[k][0], mp, m, sizeof(long long), cmp) - mp;
            j = (long long *)bsearch(&re[k][1], mp, m, sizeof(long long), cmp) - mp;
            board[i][j] = board[j][i] = 1;
        }
        s = (long long *)bsearch(&s, mp, m, sizeof(long long), cmp) - mp;
        t = (long long *)bsearch(&t, mp, m, sizeof(long long), cmp) - mp;

        mark[s] = 1;
        dfs(m, s);
        printf("Maze #%d %s be travelled\n", ++ri, mark[t] ? "can" : "cannot");
    }
    return 0;
}

/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2722014    2008-01-09 13:38:21     Accepted    1118    C   00:00.00    408K    �錄�� */

// 2012-09-07 00:37:58 | Accepted | 1118 | C | 0 | 176 | watashi | Source
