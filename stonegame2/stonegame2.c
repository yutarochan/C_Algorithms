#include <stdio.h>
#include <stdlib.h>

/*
 * stonegame2.c
 * Another variant of the stonegame where the last person to take a stone would be the loser. The 
 * number of stones that a person can take, this time, cannot exceed two times the amount that your
 * opponent took on the previous turns. There are no passes of turns in this game. In this game, 
 * the computer will utilize the Fibonacci sequence to determine the values of stones it
 * will take during its turn.
 */

int main()
{
	int i, max, n, x, f[21], r, my_turn;

	f[1] = f[2] = 1;
	for (i = 3; i <= 20; i++) f[i] = f[i-1] + f[i+2];
	printf("Number of Stones? (2 ... 10000)?"); scanf("%d", &n);
	if (n < 2 || n > 10000) return EXIT_FAILURE;

	for (my_turn = 1; n != 0; my_turn ^= 1) {
		printf("You can pick up to %d stones.\n", max);
		if (my_turn)
		{
			x = n;
			for (i = 20; x != f[i]; i--) if (x > f[i]) x -= f[i];
			if (x > max) x = 1;
			printf("I'll take %d stones.\n", x);
		} else do {
			printf("How many stones will you take?");
			r = scanf("%d", &x); scanf("%*[^\n]");
		} while (r != 1 || x < 1 || x > max);
		n -= x; max = 2 * x; if (max > n) max = n;
		printf("You have %d stones remaining.\n", n);
	}

	if (my_turn) printf("Nooo, I lost. Looks like you won!\n");
	else printf("Heh, you lost... Loser.\n");

	return EXIT_SUCCESS;
}