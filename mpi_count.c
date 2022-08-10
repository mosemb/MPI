#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <mpi.h> 

#define LEN 16


int main(int argc, char * argv[]) {

	int rank, size,buf[LEN], i, count;

        MPI_Status status;
        MPI_Init(&argc, &argv); 
        MPI_Comm_size(MPI_COMM_WORLD, &size); // Gets the number of processes
        MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Gets the rank of an individual process

	if(rank == 0) {
		srand(time(NULL)); // Generate some random number
		count = 1 + rand()%LEN;
		for(i=0; i< count; i++) 
		{      
		  buf[i] = i; 
	        }
               
	       printf("The number of digits sent is %d from rank %d \n",count, rank);
               MPI_Send(buf, count, MPI_INT, 1, 0, MPI_COMM_WORLD);

	
	}else if(rank ==1) {

                MPI_Recv(buf, LEN, MPI_INT, 0,0,MPI_COMM_WORLD,&status);
		MPI_Get_count(&status,MPI_INT, &count);
		printf("Recieved values are %d on rank %d \n",count, rank);  
		

	        for(i=0; i<count; i++) {

			printf(" %d ", buf[i] ); 
		}
	     
	        printf("\n");
	}

	MPI_Finalize();  

   return 0; 
}
