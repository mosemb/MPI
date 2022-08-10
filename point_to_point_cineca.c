#include <stdio.h> 
#include <mpi.h> 



int main(int argc, char * argv[])
{   
	int rank, err, nprocs;
	float a[2];
        MPI_Status status; 	

	err = MPI_Init(&argc,&argv);
	err = MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	err = MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank ==0) {

		a[0] = 3.0, a[1] = 5.0; 
		MPI_Send(a,2,MPI_FLOAT,1,10,MPI_COMM_WORLD); // Send message
	       // a = data to be sent
	       // 2 = number of elements to send
	       // MPI_FLOAT - Data type to be sent 
	       // 1 - Id of sender 
	       // 10 - The tag used to identify the message 
	       // MPI_COMM_WORLD - This is used to show the processes involved	
	}else if (rank ==1 ) {
              
		MPI_Recv(a,2,MPI_FLOAT,0,10,MPI_COMM_WORLD,&status); // Recieve message
	       // a = message to be recieved
	       // 2 = number of elements to be recieved
	       // MPI_FLOAT - data type to be recieved 
	       // 0 = id of process
	       // 10 = Tag used to indentify the message 
	       // MPI_COMM_WORLD - Group of processes

		printf("My rank is %d , and values are a[0]=%f , a[1]=%f  \n", rank, a[0], a[1]);

	}

	err= MPI_Finalize(); 

	return 0; 

}
