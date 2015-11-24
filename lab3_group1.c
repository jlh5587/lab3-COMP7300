#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<limits.h>
#include<assert.h>
#include<string.h>

char * progname;
FILE * fp;
char * opcode = "000000";
char * rs_out = "00000";
char * rt_out = "00000";
char * rd_out = "00000";
char * shamt = "00000";
char * function = "000000";
char * i_address = "000000000000000";
char * j_address = "00000000000000000000000000";

void to_Binary(int check, int j, char * output)
{
  int binary[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};
  printf("Input :%i :%i :%s \n", check, j, output);
  int i = 0;
  char out[j];
  while(i < j)
  {
     printf(":%i :%i :%i :%i :%c\n", i, j, check, binary[j - 1], output[4]);
     if(check >= binary[j - 1])
     {
        printf("1\n");
        strcat(out, "1");
   //   check = check - binary[j - 1];
     }
     else
     {
        printf("0, %i\n", binary[j-1]);
        strcat(out, "0");
     }
    j--;
  }
  printf("Binary out :%s\n", out);
}

void addu(char *rs,char *rt,char *rd)
{
  opcode = "000000";
  shamt = "00000";
  function = "100001";
  int j = 0;
  sscanf(rs, "%d", &j);
  to_Binary(j,5,rs_out);
  sscanf(rt, "%d", &j);
  printf("Output rt: %i\n", j);
  sscanf(rd, "%d", &j);
  printf("Output rd: %i\n", j);
  printf("Output addu:%s :%s :%s\n", rs,rt,rd);

}

void subu(char *rs,char *rt,char *rd)
{
  opcode = "000000";
  shamt = "00000";
  function = "101011";

  printf("Output subu:%s :%s :%s\n", rs,rt,rd);
}

void slt(char *rs,char *rt,char *rd)
{
  opcode = "000000";
  shamt = "00000";
  function = "101010";

  printf("Output slt:%s :%s :%s\n", rs,rt,rd);
}

void and(char *rs,char *rt,char *rd)
{
  opcode = "000000";
  shamt = "00000";
  function = "100100";

  printf("Output and:%s :%s :%s\n", rs,rt,rd);
}

void or(char *rs,char *rt,char *rd)
{
  opcode = "000000";
  shamt = "00000";
  function = "100101";

  printf("Output or:%s :%s :%s\n", rs,rt,rd);
}

void lw(char *rs,char *rt, char *offset)
{
  opcode = "100011";
  printf("Output lw:%s :%s :%s\n", rs,rt,offset);
}

void sw(char *rs,char *rt, char *offset)
{
  opcode = "101011";

  printf("Output sw:%s :%s :%s\n", rs,rt,offset);
}

void bne(char *rs,char *rt, char *offset)
{
  opcode = "000101";

  printf("Output bne:%s :%s :%s\n", rs,rt,offset);
}

void j(char *address)
{
  opcode = "000010";

  printf("Output j:%s\n", address);
}

void write_to_file(char * data)
{

}


char * trim(char * check, char arg)
{
  char * check_string = malloc(sizeof(char) * 3);
  int i = 1;
  int j = 0;

  if(arg == '(')
  {
    i = 0;
  }
  else if (arg == 'j')
  {
    i = 0;
    arg = '\n';
  }

  while(i < sizeof(check[i] - 1) && check[i] != arg)
  {
    check_string[j] = check[i];
    i++;
    j++;
  } 
  
  return check_string;
}


char * rs_I(char * check)
{
  char * check_string = malloc(sizeof(char) * 3);
  int i = 1;
  while(1)
  {
    if(check[i] == '$')
    {
      int j = 0;
      while(1)
      {
        i++;
        if(check[i] == ')')
        {
          return check_string;
        }
        check_string[j] = check[i];
        j++;
      }
    }
    i++;
  } 
  return check_string;
}


void read_file(char * filename)
{
	fp = fopen(filename, "r");

    char * line = malloc(sizeof(char) * 255);
   	while (fgets(line,255,fp) != NULL) 
  	{

      char * buf[] = {" "," "," "," "};
      char * check = strtok(line, " ");
      int i = 0;
      while (check != NULL)
      {

        if (check != NULL)
        {
          buf[i] = malloc(strlen(check) + 1);
          strcpy(buf[i],check);
        }
        check = strtok(NULL, " ");
        i++;
      } 


  		if(strcmp(buf[0],"addu") == 0)
  		{
  			addu(trim(buf[1], ','),trim(buf[2], ','),trim(buf[3], '\n'));
  		} 
  		else if (strcmp(buf[0],"subu") == 0)
  		{
  			subu(trim(buf[1], ','),trim(buf[2], ','),trim(buf[3], '\n'));
  		}
  		else if(strcmp(buf[0],"slt") ==0)
  		{
  			slt(trim(buf[1], ','),trim(buf[2], ','),trim(buf[3], '\n'));
  		}
  		else if(strcmp(buf[0],"and") == 0)
  		{
  			and(trim(buf[1], ','),trim(buf[2], ','),trim(buf[3], '\n'));
  		}
  		else if(strcmp(buf[0],"or") == 0)
  		{
  			or(trim(buf[1], ','),trim(buf[2], ','),trim(buf[3], '\n'));
  		}
  		else if(strcmp(buf[0],"lw") == 0)
  		{
  			lw(trim(buf[1], ','), rs_I(buf[2]), trim(buf[2], '('));
  		}
  		else if (strcmp(buf[0],"sw") == 0)
  		{
  			sw(trim(buf[1], ','), rs_I(buf[2]), trim(buf[2], '('));
  		}
  		else if(strcmp(buf[0],"bne") == 0)
  		{
  			bne(trim(buf[1], ','),trim(buf[2], ','),trim(buf[3], 'j'));
  		}
  		else if(strcmp(buf[0],"j")== 0)
  		{
  			j(trim(buf[1], 'j'));
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
