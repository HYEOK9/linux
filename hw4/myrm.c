#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int		i;

	if (argc == 1)  {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}
	
	//argv를 순회하며 파일 삭제
	for (i = 1 ; i < argc ; i++)  {
		if (remove(argv[i])<0)  {
			perror("remove");
			exit(1);
		}
	}
}
