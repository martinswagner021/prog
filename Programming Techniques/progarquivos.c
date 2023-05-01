#include<stdio.h>
#include<stdlib.h>

/* This program gets a name of a file and appends your name to it */

int main(){
	// char nomefentrada[100];
	char foutname[101];

	printf("Type your file name [100]: ");
	scanf("%s", foutname);

	FILE* fout = fopen(foutname, "at");
	if(fout == NULL){
		printf("There was an error with your file!\n");
		exit(1);
	}

	char name[100];
	char tempc;
	printf("Type your name: ");
	
	scanf(" %c", &tempc);
	int j = 0;
	while(tempc!='\n'){
		name[j] = tempc;
		j++;
		scanf("%c", &tempc);
	}
	name[j] = '\0';

	fprintf(fout, "%s\n", name);

	
	fclose(fout);
}
