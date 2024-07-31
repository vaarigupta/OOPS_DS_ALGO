#include <cstdio>
#include <cstdlib>

int main()
{
	FILE* fp = fopen("test1.txt","w");
	fprintf(fp,"%s","This is written to test21222.txt");

	if (freopen("test2.txt","w",fp))
		fprintf(fp,"%s","This is written to test2.txt");
	else
	{
		printf("freopen failed");
		exit(1);
	}

	fclose(fp);
	return 0;
}
