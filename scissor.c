#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int game(char you, char computer) {

    if (you == computer)
	return -1;

    if (you == 's' && computer == 'p')
	return 0;

    if (you == 'p' && computer == 's')
	return 1;

}


int main() {

    int n;
    char computer, you, result;

    srand(time(0));

    n = rand() % 100;

    printf("n = %d\n", n);

    if (n < 33)
	/* stone */
	computer = 's';
    else if (n > 33 && n < 66)
	/* papper */
	computer = 'p';
    else
	/* scizzor */
	computer = 'z';

    printf("computer = %c\n", computer);

    printf("your choice : ");
    scanf("%c", &you);
    printf("you choose : %c\n", you);

    result = game(you, computer);
    if (result == -1)
	printf("DRAW !!!\n");

    if (result == 1)
	printf("You win !!!\n");

}








