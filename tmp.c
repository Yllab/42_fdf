#include <stdio.h>

int main()
{
	int a;
	a = 0xFF60FFFF;

	printf("%c\n", (char)(a >> 16));
}
