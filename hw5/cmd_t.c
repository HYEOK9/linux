#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define	MAX_CMD		256

void
DoCmd(char *cmd)
{
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");

	pthread_exit(NULL);
}

int main()
{
	char		cmd[MAX_CMD];
	pthread_t	tid;

	while (1)  {
		printf("CMD> ");
		fgets(cmd, MAX_CMD, stdin);	
		if (cmd[0] == 'q')
			break;

		//thread생성 후 cmd를 인자로 DoCmd실행
		if (pthread_create(&tid,NULL,(void*) DoCmd,(void*) cmd)<0)  {
			perror("pthread_create");
			exit(1);
		}

#if 0
		pthread_join(tid, NULL);
#endif
	}
}
