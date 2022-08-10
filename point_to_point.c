#include <stdio.h>
#include <mpi.h>


int main(int argc, char * argv[]) {

	int rank, buf; 
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

       if(rank ==0){

	       buf = 123456; 
	       MPI_Send(&buf,1,MPI_INT,1,0,MPI_COMM_WORLD); 
       
       
       }else if(rank==1) {

	       MPI_Recv(&buf,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
	       printf("Recieved %d \n",buf); 
       
       }
       
      MPI_Finalize();        


    return 0; 

}
