#include <stdio.h>
#include <conio.h>
#include <unistd.h>

//fATORIAL ELE * ELE MESMO - 1



	

void proc_a(int i){
		printf("Exibicao Proc A: %d\n", i);
		sleep(1);
		i++;
		if(i<=4){
			proc_a(i);	
		}
		printf("\nExibicao Proc AA: %d", i);
		sleep(1);

}

void main(){
	int i = 0;
	printf("\nInicio da Recursividade\n", i);
	
	proc_a(i);
	
	printf("\nFim da Recursividade", i);
	
	
}
