#include <stdio.h>
#include <mpi.h>


int main(int argc, char * argv[]){

	int rank, nproc, root;
	float a[2];

	MPI_Status status;

        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &nproc);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if(rank == 0) {
		a[0] = 2.0;
		a[1] = 4.0;
	        root =0;	
	} 

        MPI_Bcast(a,2,MPI_FLOAT,root,MPI_COMM_WORLD);

        printf("The values of a[0] = %f and the value of a[1]=%f  \n", a[0], a[1]); 	

        MPI_Finalize(); 


	return 0; 

}
