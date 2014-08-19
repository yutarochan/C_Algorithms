#include <stdio.h>
#include <stdlib.h>

/*
 * marriage.c
 * The Stable Marriage Problem: N males and N females rank and choose their partner's through ranking.
 * By employing this method, they can find the "love of their life" in the most 'stable' and 'logical' way.
 * (Can this be a great algorithm to match together jobs or couples together???)
 *
 */

#define N 3
int boy[N+1], girl[N+1][N+1], pos[N+1], rank[N+1][N+1];

int main()
{
	int b, g, r, s, t;
	
	for (g = 1; g <= N; g++)
	{
		for (r = 1; r <= N; r++)
		{
			scanf("%d", &b);
			rank[g][b] = r;
		}
		
		boy[g] = 0;
		rank[g][0] = N + 1;
	}

	for (b = 1; b <= N; b++)
	{
		for (r = 1; r <= N; r++) scanf("%d", &girl[b][r]);
		pos[b] = 0;
	}

	for (b = 1; b <= N; b++)
	{
		s = b;
		while (s != 0)
		{
			g = girl[s][pos[s]++];
			if (rank[g][s] < rank[g][boy[g]])
			{
				t = boy[g];
				boy[g] = s;
				s = t;
			}
		}
	}
	
	for (g = 1; g <= N; g++) printf("GIRL %d - BOY %d\n", g, boy[g]);
	return EXIT_SUCCESS;
}
