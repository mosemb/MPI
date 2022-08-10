#include <stdio.h>
#include <mpi.h>



int main(int argc, char * argv[]) {

	int rank, size, length; 
	char hostname[MPI_MAX_PROCESSOR_NAME];

	// Initialize MPI 
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank); // This is the index of process in the group MPI_COMM_WORLD
	MPI_Comm_size(MPI_COMM_WORLD,&size); // This is the number of processes in the group MPI_COMM_WORLD
	MPI_Get_processor_name(hostname,&length); // This gets the name of the host and respective length

	printf("Greetings from process %d of %d running on %s with string length %d  \n",rank,size,hostname,length);

        MPI_Finalize();	





   return 0; 
}
