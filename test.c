#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	long double spaces = 12.3;
	//	spaces = atoi(argv[1]);
	/*printf("1 :4567 |%-10]5d| plip\n", -12);
	printf("2 :4567 |%10.5]d| plip\n", 12);
	printf("3 :|%10.5d|\n", 12);
	printf("4 :|%s|\n", "bonjour");*/
	printf("%Lf\n", spaces);
	printf("%f\n", spaces);
	printf("tab 'v' 'n' %% :\n");
	printf("5 :|%10.5d|\n", -12); 
	printf("6 :|%-10.5d|\n", -12);
	printf("7 :|%-010.5d|\n", -12);
	return (0);
}
