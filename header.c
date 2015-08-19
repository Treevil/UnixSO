#include "header.h"


int band_load_resource(const char* file_name, resource risorse[], int* n)
{
	//apertura file
	FILE *fp = fopen(file_name, "r");
	if(!fp) //se fallisce
	{
		perror("Error while opening the file.\n");
		return -1;
	}

	*n=0;
	//scorrimento e lettura file
	while(fscanf(fp,"%s",risorse[*n].name)!=EOF)
	{		
		fscanf(fp,"%d",&(risorse[*n].quantity));
		fscanf(fp,"%d",&(risorse[*n].price));
		fgetc(fp);
		(*n)++;
	}
	//chiusura file
	if(fclose(fp))
		return -1;//se fallisce chiusura
	return 1;
}


void printTAO_resources(resource arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("-> %d %s a %d€\n",arr[i].quantity,arr[i].name,arr[i].price);
}