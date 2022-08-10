#include <stdio.h> 
#include <mpi.h> 


int main(int argc, char * argv[]) {

	int myid, numprocs, right, left; 
	int buffer[1] , buffer2[1]; 

	MPI_Status status;

	MPI_Init(&argc, &argv); 
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
        MPI_Comm_rank(MPI_COMM_WORLD, &myid);

	right = (1+myid)%numprocs;
	left = (myid-1); 

	if(left < 0) {

		left = numprocs -1; 
	
	
	}

	buffer[0] = myid; 

	MPI_Sendrecv(buffer,1,MPI_INT,right,123,buffer2,1,MPI_INT,left,123,MPI_COMM_WORLD,&status);

        printf("I am rank %d and have recieved %d \n",myid,buffer2[0]);

        MPI_Finalize();	


}
