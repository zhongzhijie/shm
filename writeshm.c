#include <sys/types.h>     
#include <sys/ipc.h>     
#include <sys/shm.h>     
#include <stdio.h>     
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024     
#define MYKEY 25     

int main()    
{    
	int shmid;    
	char *shmptr;    

	/* ���������ڴ� */
	if((shmid = shmget(MYKEY,BUF_SIZE,IPC_CREAT)) ==-1)
	{    
		printf("shmget error \n");    
    return 1;    
	}    

	/* ���ӹ����ڴ浽���̵�ַ�ռ� */
	if((shmptr =shmat(shmid,0,0))==(void *)-1)    
	{    
    printf("shmat error!\n");    
    return 1;    
	}    
    
	while(1)    
	{    
    printf("input:");    
    scanf("%s",shmptr);    /* д�����ڴ����� */
    if (strcmp(shmptr, "quit") == 0)
    {
    	sleep(5);
    	shmdt(shmptr);
    	return 0; 
    }
	}    
    
	return 0;     
}   