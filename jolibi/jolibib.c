#include <stdio.h>
#include <stdlib.h>

char grid[6][6];
char route[36];
int N, M, routeCount = 0;

void findRoutes(int x, int y, int pos) {
    if (x == N && y == M) {
        route[pos] = '\0';
        printf("%s\n", route);
        routeCount++;
        return;
    }

    if (x + 1 <= N && grid[x + 1][y] == '.') {
        route[pos] = 'B';
        findRoutes(x + 1, y, pos + 1);
    }

    if (y + 1 <= M && grid[x][y + 1] == '.') {
        route[pos] = 'K';
        findRoutes(x, y + 1, pos + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    if (grid[0][0] == '#' || grid[N - 1][M - 1] == '#') {
        printf("Tidak ada solusi\n");
        return 0;
    }

    findRoutes(0, 0, 0);

    if (routeCount == 0) {
        printf("Tidak ada solusi\n");
    }

    return 0;
}
