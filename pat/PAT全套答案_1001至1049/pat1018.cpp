#include <stdio.h>
#include <math.h>
using namespace std;

struct {
int parent;
int pp;
int send;
int back;
} record[512][512];

int C, N, sp, M, c2, G[512][512], cur[512];
int dist[512], known[512], p[512];

void dijkstra(int x)
{
	int v, w, i, j, k, len, temp;
	dist[0] = 0;
    record[0][0].parent = -1;
    record[0][0].pp = -1;
    record[0][0].send = record[0][0].back = 0;
    p[0] = 1;
    while (!known[x]) {
		len = 0x7fffffff;
		for (i = 0; i <= N; i++) {
			if (known[i])
				continue;
			if (dist[i] >= 0 && dist[i] < len) {
  				len = dist[i];
  				v = i;
			}
		}
		known[v] = 1;
		for (w = 1; w <= N; w++) {
			if (!G[v][w] || known[w])
				continue;
			if (dist[w] >= 0 && dist[w] < dist[v] + G[v][w])
				continue;
			else if (dist[w] == -1 || dist[w] >= dist[v] + G[v][w]) {
				if (dist[w] == -1 || dist[w] > dist[v] + G[v][w])
					p[w] = 0;
				dist[w] = dist[v] + G[v][w];
				temp = fabs(cur[w] - c2);
				for (i = 0, j = p[w]; i < p[v]; i++, j++) {
					record[w][j].parent = v;
					record[w][j].pp = i;
					if (cur[w] >= c2) {
						record[w][j].back = record[v][i].back + temp;
						record[w][j].send = record[v][i].send;
					}
					else {
						if (temp <= record[v][i].back) {
							record[w][j].back = record[v][i].back - temp;
							record[w][j].send = record[v][i].send;
						}
						else {
							record[w][j].send = record[v][i].send + temp - record[v][i].back;
							record[w][j].back = 0;
						}
					}
				}
				p[w] = j;
			}
		}
	}
 }
  														
int main()
{
	int v, w, i, j, k, l, path[512];
	int send, back, pre, prep;
	scanf("%d %d %d %d", &C, &N, &sp, &M);
	c2 = C / 2;
	for (i = 1; i <= N; i++) {
		scanf("%d", &cur[i]);
		dist[i] = -1; known[i] = 0;
		p[i] = 0;
	}
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++) {
			G[i][j] = 0;
			record[i][j].parent = record[i][j].pp = 0;
			record[i][j].send = record[i][j].back = 0;
		}
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &v, &w, &j);
		G[w][v] = G[v][w] = j;
	}
	dijkstra(sp);
	send = back = 0x7fffffff;
	for (i = 0; i < p[sp]; i++) {
		if (send > record[sp][i].send ||(send == record[sp][i].send && back > record[sp][i].back)) {
			send = record[sp][i].send;
			back = record[sp][i].back;
			pre = record[sp][i].parent;
			prep = record[sp][i].pp;
		}
	}
	for (i = pre, j = prep, k = 0; i >= 0; ) {
		path[k++] = i;
		pre = record[i][j].parent;
		prep = record[i][j].pp;
		i = pre;
		j = prep;
	}
	printf("%d ", send);
	for (--k; k >= 0; k--)
		printf("%d->", path[k]);
	printf("%d %d\n", sp, back);
	return 0;
}
