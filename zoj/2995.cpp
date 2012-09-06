#include <cstdio>

const static int status [8][3][2] = {
    {{0, 0}, {1, 0}, {4, 1}},
    {{0, 1}, {4, 0}, {3, 1}},
    {{0, 2}, {3, 0}, {2, 1}},
    {{0, 3}, {2, 0}, {1, 1}},
    {{5, 0}, {1, 2}, {2, 3}},
    {{5, 1}, {2, 2}, {3, 3}},
    {{5, 2}, {3, 2}, {4, 3}},
    {{5, 3}, {4, 2}, {1, 3}}
};

char buf[16];

int src[6][2];
int tar[3][2];

bool judge()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            if (src[status[i][j][0]][0] == tar[0][0] &&
                (src[status[i][j][0]][1] - status[i][j][1] + 4) % 4 == tar[0][1]) {
                if (
                    src[status[i][(j + 1) % 3][0]][0] == tar[1][0] &&
                    (src[status[i][(j + 1) % 3][0]][1] - status[i][(j + 1) % 3][1] + 4) % 4 == tar[1][1] &&
                    src[status[i][(j + 2) % 3][0]][0] == tar[2][0] &&
                    (src[status[i][(j + 2) % 3][0]][1] - status[i][(j + 2) % 3][1] + 4) % 4 == tar[2][1]
                ) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void)
{
    int re;
    int cnt;
    char ans[8];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%s", buf);
        for (int i = 0; i < 6; i++) {
            src[i][0] = buf[i * 2] - 'A';
            src[i][1] = buf[i * 2 + 1] - '1';
        }
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%s", buf);
            for (int j = 0; j < 3; j++) {
                tar[j][0] = buf[j * 2] - 'A';
                tar[j][1] = buf[j * 2 + 1] - '1';
            }
            if (judge()) {
                ++cnt;
                ans[i] = 'Y';
            }
            else {
                ans[i] = 'N';
            }
        }
        printf("%d %d", ri, cnt);
        for (int i = 0; i < 5; i++) {
            printf(" %c", ans[i]);
        }
        printf("\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2950537   2008-06-15 23:42:51     Accepted    2995    C++     00:00.00    392K    Re:ReJudge

// 2012-09-07 01:53:22 | Accepted | 2995 | C++ | 0 | 180 | watashi | Source
