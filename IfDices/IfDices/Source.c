#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int get_levs(int player_score) {
    switch (player_score)
    {
    case 1:
        return 1;

    case 2:
        return 2;

    case 3:
        return 4;
        break;

    case 4:
        return 6;

    case 5:
        return 8;

    case 6:
        return 12;

        // operator doesn't match any case constant /
    default:
        return -1;
    }
}

int main() {
    int player_one_score, player_two_score;
    int player_one_levs, player_two_levs;
    int winner_num, profit;

    printf("Player One Score: ");
    /*int inputNumOne = */ scanf_s("%d", &player_one_score);
    printf("Player Two Score: ");
    /*int inputNumTwo = */ scanf_s("%d", &player_two_score);

    player_one_levs = get_levs(player_one_score);
    player_two_levs = get_levs(player_two_score);

    if (player_one_levs == -1 || player_two_levs == -1) {
        printf("Invalid input!\n");
        return 0;
    }

    if (player_one_levs > player_two_levs) {
        winner_num = 1;
        profit = player_one_levs - player_two_levs;
    }
    else if (player_two_levs > player_one_levs) {
        winner_num = 2;
        profit = player_two_levs - player_one_levs;
    }
    else {
        winner_num = 0;
    }

    if (winner_num == 0) {
        printf("DRAW!");
    }
    else {
        printf("Winner Number: %d, Profit: %d", winner_num, profit);
    }
	
	return 0;
}