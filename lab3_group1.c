#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<limits.h>
#include<assert.h>
#include<string.h>

char * progname;
FILE * fp;



void addu(char *parameters)
{
	printf("Called Add\n");
}

void subu(char *parameters)
{

}

void slt(char *parameters)
{

}

void and(char *parameters)
{

}

void or(char *parameters)
{

}

void lw(char *parameters)
{

}

void sw(char *parameters)
{

}

void bne(char *parameters)
{

}

void jump(char *parameters)
{

}

void write_to_file(char *data)
{

}


void read_file(char * filename)
{
	fp = fopen(filename, "r");

    char * line = malloc(sizeof(char) * 255);
    char  * instruct = malloc(sizeof(char) * 5);
    char * parameters = malloc(sizeof(char) * 255);
    
   	while (fgets(line,255,fp) != NULL) 
  	{

  		sscanf (line, "%s %s\n", instruct, parameters);
  		
  		//printf("printf %s\n", line);
  		printf("i = %s, p = %s\n", instruct, parameters);

  		if(strcmp(instruct,"addu") == 0)
  		{
  			addu(parameters);
  		} 
  		else if (strcmp(instruct,"subu") == 0)
  		{
  			subu(parameters);
  		}
  		else if(strcmp(instruct,"slt") ==0)
  		{
  			slt(parameters);
  		}
  		else if(strcmp(instruct,"and") == 0)
  		{
  			and(parameters);
  		}
  		else if(strcmp(instruct,"or") == 0)
  		{
  			or(parameters);
  		}
  		else if(strcmp(instruct,"lw") == 0)
  		{
  			lw(parameters);
  		}
  		else if (strcmp(instruct,"sw") == 0)
  		{
  			sw(parameters);
  		}
  		else if(strcmp(instruct,"bne") == 0)
  		{
  			bne(parameters);
  		}
  		else if(strcmp(instruct,"jump")== 0)
  		{
  			jump(parameters);
  		}

  		
  	}

  	printf("End Scan\n");
}



int main(int argc, char ** argv)
{
    char * filename;
    progname = argv[0];

    filename = argv[1];

    read_file(filename);

    printf("Filename: %s\n", filename);

    return 0;

}