#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int inf = 987654321;
const int MAXN = 606;
const int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

int x1[606], y1[606], x2[606], y2[606], c[606];
int v[1234][1234], d[1234][1234], e[1234][1234][4];

int main(void)
{
    int re;

    scanf("%d", &re);
    while (re--) {
        /*************************************************/
        vector<int> x, y;
        int n;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i], &c[i]);
            x.push_back(x1[i]);
            x.push_back(x2[i]);
            y.push_back(y1[i]);
            y.push_back(y2[i]);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        /*************************************************/
        int nx, ny, l, r, m;

        nx = x.size();
        ny = y.size();
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                v[i][j] = 0;
                d[i][j] = inf;
                for (int k = 0; k < 4; k++) {
                    e[i][j][k] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (x1[i] == x2[i]) {
                m = lower_bound(x.begin(), x.end(), x1[i]) - x.begin();
                l = lower_bound(y.begin(), y.end(), y1[i]) - y.begin();
                r = lower_bound(y.begin(), y.end(), y2[i]) - y.begin();
                if (l > r) {
                    swap(l, r);
                }
                for (int j = l + 1; j <= r; j++) {
                    e[m][j][0] = c[i];
                    e[m + 1][j][2] = c[i];
                }
            }
            else if (y1[i] == y2[i]) {
                m = lower_bound(y.begin(), y.end(), y1[i]) - y.begin();
                l = lower_bound(x.begin(), x.end(), x1[i]) - x.begin();
                r = lower_bound(x.begin(), x.end(), x2[i]) - x.begin();
                if (l > r) {
                    swap(l, r);
                }
                for (int j = l + 1; j <= r; j++) {
                    e[j][m][1] = c[i];
                    e[j][m + 1][3] = c[i];
                }
            }
        }
        /***************************************************/
        int x0, y0, xx, yy, dd;
        long long ans = 0;
        set<pair<int, pair<int, int> > > pq;

        d[0][0] = 0;
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                pq.insert(make_pair(d[i][j], make_pair(i, j)));
            }
        }
        while (!pq.empty()) {
            ans += pq.begin()->first;
            x0 = pq.begin()->second.first;
            y0 = pq.begin()->second.second;
            pq.erase(pq.begin());
            v[x0][y0] = 1;
            //printf("%d %d %d\n", x0, y0, d[x0][y0]);
            /*for (int i = 0; i <= nx; i++) {
                for (int j = 0; j <= ny; j++) {
                    printf("\t%d", d[i][j]);
                }
                printf("\n");
            }*/
            for (int k = 0; k < 4; k++) {
                xx = x0 + dir[k][0];
                yy = y0 + dir[k][1];
                dd = e[x0][y0][k];
                if (xx < 0 || yy < 0 || xx > nx || yy > ny || v[xx][yy]) {
                    continue;
                }
                else if (dd < d[xx][yy]) {
                    pq.erase(make_pair(d[xx][yy], make_pair(xx, yy)));
                    d[xx][yy] = dd;
                    pq.insert(make_pair(d[xx][yy], make_pair(xx, yy)));
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
//25972     2008-07-05 11:55:54       Accepted      B   C++     1570    44676   watashi

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//26137     2008-07-06 05:13:52     Accepted    1002    C++     1560    44676   watashi     Source

//3040688   2008-08-18 16:19:21     Accepted    3016    C++     00:03.10    45340K      Re:ReJudge

// 2012-09-07 01:55:17 | Accepted | 3016 | C++ | 1250 | 44592 | watashi | Source
