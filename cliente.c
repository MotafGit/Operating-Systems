
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

int main(int agrc, char* argv[]){

    int fd, bytes_read,bytes_from_Server, fd1;
	// int fifo = mkfifo("./fifo2", 0666);
	
	char buffer[MAX_LINE_SIZE];
	char bufferFromServer[MAX_LINE_SIZE];


   if((fd = open("fifo2", O_WRONLY)) == -1){
		perror("Open");
	} else {
		printf("Opened FIFO for writing.\n");
	}

	if((fd1 = open("myfifo", O_RDONLY)) == -1){
		perror("Open");
	} else {
		printf("Opened FIFO for reading.\n");
	}
  
   while (1){


	while((bytes_read = read(0,buffer,MAX_LINE_SIZE)) > 0){
		if(write(fd,buffer,bytes_read) == -1){
			perror("Write");
		}
	}

	if((bytes_from_Server = read(fd1, bufferFromServer, MAX_LINE_SIZE)) > 0){
			
            write(1,bufferFromServer,bytes_from_Server);

	}


	}

	close(fd);
	close(fd1);

}