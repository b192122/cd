#include<stdio.h>
#include<ctype.h>

void FIRST(char , int , int);
int count, n = 0;
char prodn[10][10], first[10];

main()
{
	int i, choice;
	char c, ch;
	printf("How many productions ? :");
	scanf("%d", &count);
	printf("Enter %d productions epsilon= $ :\n\n", count);
	for (i = 0; i < count; i++)
		scanf("%s%c", prodn[i], &ch);
	do
	{
		n = 0;
		printf("Element :");
		scanf("%c", &c);
		FIRST(c, 0, 0);
		printf("\n FIRST(%c)= { ", c);
		for (i = 0; i < n; i++)
			printf("%c ", first[i]);
		printf("}\n");

		printf("press 1 to continue : ");
		scanf("%d%c", &choice, &ch);
	}
	while (choice == 1);

	for (int j = 0; j < n; j++) {
		printf("%c ", first[j]);
	}
	printf("\n");

	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			printf(" %c ", prodn[j][k]);
		}
		printf("\n");
	}

}

void FIRST(char c, int q1, int q2)
{
	int j;
	if (!(isupper(c)))first[n++] = c;
	for (j = 0; j < count; j++)
	{
		if (prodn[j][0] == c)
		{
			if (prodn[j][2] == '$')
			{
				if (prodn[q1][q2] == '\0')
					first[n++] = '$';
				else if (prodn[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
					FIRST(prodn[q1][q2], q1, (q2 + 1));
				else
					first[n++] = '$';
			}
			else if (islower(prodn[j][2]))first[n++] = prodn[j][2];
			else FIRST(prodn[j][2], j, 3);
		}
	}
}
