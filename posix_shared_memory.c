//Program to demonstrate the shared memory creation, attachment, writing, detachment and deletion using POSIX API
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
	int segment_id;							//shared memory identifier
	char* shared_memory;						//pointer to shared memory segment
	const int size = 4096;						//in bytes

	segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);	//shared memory allocation, first param:new segment created, third param:Mode i.e R/W

	shared_memory = (char *) shmat(segment_id, NULL, 0);		//attaching shm, second param:pointer to attach (here attach anywhere), third:Flag (0 means read-write mode)

	sprintf(shared_memory, "Hi there!");				//writes to shared memory
	printf("%s\n", shared_memory);					//print from shared memory
	shmdt(shared_memory);						//detach shared memory segment
	shmctl(segment_id, IPC_RMID, NULL);				//removes shared memory segment
	return 0;
}
