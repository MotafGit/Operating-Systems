#define _OPEN_SYS_ITOA_EXT
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <sys/time.h> 
#include <time.h>

int processID = 1;
int commandCount = 0;


#define MAX_LINE_SIZE 1024

  char* parseCommand (char* command){
        int size = strlen(command);
        char teste[size];
        int i = 0;
        char * aux;
        int flag = 0;
       
 
        return command;
        
    }


int main(int argc, char* argv[]){

    
	int fifo2 = mkfifo("./fifo2", 0666);
	int myfifo = mkfifo("./myfifo", 0666);
	char* parsedCommand;


    int fd,bytes_read, outputFolder, fd1;
	char buffer[MAX_LINE_SIZE] ;
	char buffer2[MAX_LINE_SIZE];

    	if((outputFolder = open(argv[1], O_CREAT | O_TRUNC| O_WRONLY, 0666)) == -1){
		perror("Open");
		return -1;
	}

    

    

    while(1){
       
		if((fd = open("fifo2", O_RDONLY)) == -1){
			perror("open");
			return -1;
		} else {
			printf("[DEBUG] opened fifo for reading\n");
		}

        if((fd1 = open("myfifo", O_WRONLY)) == -1){
			perror("open");
			return -1;
		} else {
			printf("[DEBUG] opened fifo for writing\n");
		}


        while((bytes_read = read(fd, buffer, MAX_LINE_SIZE)) > 0){

            char *execute = "execute";
            int i = 0;
            int j = 0;
            int l = 0;
            char *aux;
            char *dividedArray;
            char *empty;
            int argsNumber=0;
            char testeArray[5][20];
            char space[2] = " ";
            char *splitedCommand;

            char processInfo[100];

            sprintf (processInfo, "TASK %d received\n", processID);

		        write (fd1,processInfo,strlen(processInfo));
           	int bufferSize = strlen(buffer);
                int res, startHour, startMin,startSec,startMs, endHour, endMin, endSec, endMs;

                buffer[bufferSize-2] = '\0'; 
                char newBuffer[400];
                while (i < bufferSize){
                    if (buffer[i] == '"'){
                        i++;
                    }
                    else{
                        newBuffer[j] = buffer[i];
                        j++;
                        i++;
                    }
                }



                        int flag = 0;
                        i = 0;
                        argsNumber=0;
                        char del[20] = " ";  
                        char* in = newBuffer;  
                        char* out;  
                        char** arr = malloc(20 * sizeof(char *));

                        while ((out = strsep(&in, del)) != NULL && flag == 0) {  
                            if (out == NULL){flag = 1;}
                            arr[i++] = out;
                        }  
                        argsNumber = i;

                        j = i;
                        i = 0;
                      
          


                i = 0;
                
              

                if (argsNumber > 2 && (strcmp(arr[0], "execute")== 0) && (strcmp(arr[2], "-u")== 0)){
                    
          
            
                
                int status;

                pid_t child = 0;

                clock_t start = clock();
              

                if((child = fork()) == 0) {
                int bytes;
                
                dup2 (outputFolder, 1);
                printf ("Child: %d Parent: %d\n", getpid(), getppid());

                dup2 (outputFolder, 2);


                close(outputFolder);

                
                char pidToClt[1024];
              

                parsedCommand = parseCommand(arr[3]);
                if (argsNumber == 4){
                    char *option[] = {parsedCommand, NULL};
                execvp(parsedCommand,  option);
                

                }

                if (argsNumber > 4){
                    i = 4;
                    j = 1;
                    char* auxCommand;
                     char* options[] = {parsedCommand};

                     while (i<=argsNumber){
                        
                          options[j] = arr[i];
                        j++;
                        i++;
                     }
                          options[j] = NULL;

                     j = 0;
                     i=argsNumber;
                   

                    char* arr[0] = {};
                    argsNumber = 0;
                    execvp(parsedCommand,  options);
                    _exit(1);
                   
                }

            }
            child = wait(&status);
            if(WIFEXITED(status)) {
                char executionTime[100];
                printf("Process %d exited with code %u\n", child, WEXITSTATUS(status));

                clock_t end = clock();

                double clockTime = ((double)(end-start)) / CLOCKS_PER_SEC;
                sprintf (executionTime, "O processo com ID %d demorou %f segundos a executar\n\n",processID, clockTime);
                write (outputFolder, executionTime , 100);  

            }
          
            processID++;
        

        }



        // multichain


            if (argsNumber > 2 && (strcmp(arr[0], "execute")== 0) && (strcmp(arr[2], "-p")== 0)){
                int chainNumber=0;
                
                i = 0;
                        while ( i < j){
                            if (arr[i][0] == '|'){
                                chainNumber ++;
                            }
                            i++; 

                        }

                i = 0;
                j= 4;
                int k = 4;
                int l = 1;
                char* compare = "|";
                int flag = 0;
                // memcpy(dest, arr[3] + 1,sizeof(execSize)); // removes " from the 1st character

                parsedCommand = parseCommand(arr[3]);
                char *options[] = {parsedCommand};

                while (k < argsNumber && flag == 0 ){

                       if ( arr[j][0] == '|' ){
                       flag = 1;
                    }
                    else{
                        options[l] = arr[j];
                        
                        j++;
                        k++;
                        l++;
                    }   


                  
                }

                options[l] = NULL;
                j = j+1;
                



                i = 0;
               
                

                chainNumber++;
                i = 0;
                int count = 0;
                 while (count<chainNumber){   
                   
                pid_t child = 0;
                int pipo[chainNumber][2];
                
                if ( count == 0){
                pipe(pipo[0]);


                if((child = fork()) == 0) {
                    dup2(pipo[0][1], 1);
                    close(pipo[0][0]);
                    close(pipo[0][1]);

                    // execlp("cat", "cat", "ex1.c", NULL);
                    // execvp(commands[i][0], commands[i]);
                         execvp(options[0],  options);

                    perror("Exec failed");
                    _exit(1);
                }
                close(pipo[0][1]);
                count ++;
                
                }
                if(count < chainNumber-1) {
                    
                pipe(pipo[count]);
                if(fork() == 0) {
                    int countTeste = 0;
                    
                    flag = 0;
                    l = 0;
                    if (countTeste != 0){j = countTeste;}
                    
                    while (k < argsNumber && flag == 0 ){

                       if ( arr[j][0] == '|' ){
                      
                    
                     flag = 1;
                    }
                    else{
                        options[l] = arr[j];
                        
                        j++;
                        k++;
                        l++;
                        commandCount++;

                    }   
                    
                }
                
                l++;

                options[l] = NULL;
                
                 i = 0;
                
                

                    dup2(pipo[count - 1][0], 0);
                    // o de escrita anterior está fechado
                    close(pipo[count - 1][0]);

                    dup2(pipo[count][1], 1);
                    close(pipo[count][0]);
                    close(pipo[count][1]);

                    //  execlp("grep", "grep", "palavra", NULL);
                         execvp(options[0],  options);


                    perror("Exec failed");
                    _exit(1);
                }
                close(pipo[count - 1][0]);
                close(pipo[count][1]);
                int flag2 = 0;
                while (flag2 == 0){
                    if(arr[j][0] == '|'){
                        flag2 = 1;
                    }
                    j++;
                }
                


            }
            if (count == chainNumber-1){
            if(fork() == 0) {
                
                 flag = 0;
                    l = 0;
                   


                   
                    
                    while (k < argsNumber && flag == 0 && j < argsNumber){

                       if ( arr[j][0] == '|' ){
                       flag = 1;
                    }
                    else{
                        options[l] = arr[j];
                        
                        
                        j++;
                        k++;
                        l++;
                    }   
                    
                }
                options[l] = NULL;
                 i = 0;

                dup2(pipo[count - 1][0], 0);
                close(pipo[count - 1][1]);
                close(pipo[count - 1][0]);
                // char * optionsTeste[] = { "wc","-w", NULL};

                    // execlp("wc", "wc", "-l", NULL);
                         execvp(options[0],  options);

                         



                perror("Exec failed");
                 i = 0;
            
                _exit(1);
            }
            close(pipo[count - 1][0]);
           
            }
                    processID++;
                     count++;
                 }
                 i = 0;
             

        
            }



           
        }
          

	close(fd);
    close (fd1);

    }


}