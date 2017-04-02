#include <stdio.h>     
#include <sys/types.h>     
#include <sys/ipc.h>     
#include <sys/shm.h>     
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024     
#define MYKEY 25  
   
int  main()    
{    
	int shmid;    
	char * shmptr;    

	/* 获取共享内存ID */
	if((shmid = shmget(MYKEY,BUF_SIZE,IPC_CREAT)) ==-1)    
	{    
    printf("shmget error!\n");    
    return 1;    
	}    
    
	if((shmptr = shmat(shmid,0,0)) == (void *)-1)    
	{    
    printf("shmat error!\n");    
    return 1;    
	}    
    
	while(1)    
	{    
    printf("string :%s\n",shmptr);    /* 读共享内存数据 */   
    if (strcmp(shmptr, "quit") == 0)
    {
    	shmdt(shmptr);
    	return 0; 
    }
    sleep(3);    
	}    
    
	return 0;     
}    