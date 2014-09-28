#include <stdio.h>
#include <stdlib.h>

/*
 * stonegame1.c
 * A simple stone game where the last person to take a stone would be the loser. The 
 * number of stones that a person can take is predetermined at the beginning of the 
 * gane. There are no passes of turns in this game.
 */

int main()
{
	int n, m, x, r, my_turn;

	printf("How many stones? ");
	scanf("%d", &n);

	printf("How many stones to pick up at once? ");
	scanf("%d", &m);

	if (n < 1 || m < 1) return EXIT_FAILURE;
	for (my_turn = 1; n != 0; my_turn ^= 1) {
		if (my_turn)
		{
			x = (n - 1) % (m + 1);
			if (x == 0) x = 1;
			printf("I'll take %d stones.\n", x);
		} else do {
			printf("How many stones will you take?");
			r = scanf("%d", &x);
			scanf("%*[^\n]");
		} while (r != 1 || x <= 0 || x > m || x > n);
		
		n -= x;
		printf("You have %d stones remaining.\n", n);
	}

	if (my_turn) printf("Heh, you lost... Loser.\n");
	else printf("Nooo, I lost. Looks like you won!\n");

	return EXIT_SUCCESS;
}