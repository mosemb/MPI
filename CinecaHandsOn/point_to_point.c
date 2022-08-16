#include <mpi.h> 
#include <stdio.h> 


int  main(int argc, char * argv []) {


	int size, rank, i;
        float A[1000], B[1000]; 	
	MPI_Status status;
	

        MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size); 	

	if(rank == 0) {

		for(i=0; i<1000; i++) {
		
			A[i] = rank;
		}

		MPI_Send(A,1000,MPI_FLOAT,1,11,MPI_COMM_WORLD);
	       // A is the array we are sending 
	       // 1000 is the number of elements we are sending 
	       // MPI_FLOAT is the type of data we are sending
	       // 1 is the id we are sending to 
	       // 10 is the tag we are using the identify the message 
	       // MPI_COMM_WORLD is the grouping for all the processes
	       

	} else if(rank ==1) {

		MPI_Recv(A,1000,MPI_FLOAT,0,11,MPI_COMM_WORLD,&status);
	       // A this is the array message we are recieving 
	       // 1000 this is the number of elements we are recieving 
	       // MPI_FLOAT is the type of data we are recieving 
	       // 0 is the id we are recieving the data from 
	       // MPI_COMM_WORLD is the grouping we are getting the processes from 	
	
		printf("I am rank %d and i have recieved %f \n",rank,A[0]);

	        for(i=0; i<1000; i++){
			B[i] = rank; 
		}	

		MPI_Send(B,1000,MPI_FLOAT,0,12,MPI_COMM_WORLD); 
	
	
	}

	     if(rank ==0) {
	     
	       MPI_Recv(B,1000, MPI_FLOAT, 1,12,MPI_COMM_WORLD,&status);

	      printf("I am rank  %d and have recieved %f  \n",rank, B[0]);  
	     
	     }

	MPI_Finalize(); 






     return 0; 
}
