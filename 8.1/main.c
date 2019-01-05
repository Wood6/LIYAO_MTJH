#include <stdio.h>

int s1;
int s2 = 2;
extern int S;

int main(int argc, char* argv[])
{
	printf("&s1 = %p\n", &s1);
	printf("&s1 = %p\n", &s2);
	printf("&S = %p\n", &S);
	
	printf("s1 = %d\n", s1);
	printf("s1 = %d\n", s2);
	printf("S = %d\n", S);

	printf("liyao test!\n");
	
	return 0;
}