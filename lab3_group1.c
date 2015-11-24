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
char rs_out[] = "00000";
char rt_out[] = "00000";
char rd_out[] = "00000";
char * shamt = "00000";
char * function = "000000";
char i_address[] = "0000000000000000";
char j_address[] = "00000000000000000000000000";
char address[] = "00000000000000000000000000000000";




// Method: to_Binary
// Input: Integer check, Integer j, Character array type
// Output: void
// Description: to_Binary takes in an integer check of the numerical value to be converted into binary
//   integer j is the number of bits and type is where it needs to be saved to. If the check is greater
//   then the number of bits an error occurs.

void to_Binary(int check, int j, char * type)
{
  int binary[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};
  int i = 0;

  if(check > binary[j])
  {
     printf("You are trying to access a refrence or an address outside your bounds you should have %i bits which is less then %i. \n", j, binary[j]);
     exit(0);
  } 

  while(0 < j)
  {
     if(check >= binary[j - 1])
     {
        if(strcmp(type,"rs") == 0)
          rs_out[i] = 49;
        else if(strcmp(type,"rt") == 0)
          rt_out[i] = 49;
        else if(strcmp(type,"rd") == 0)
          rd_out[i] = 49;
        else if(strcmp(type,"i_address") == 0)
          i_address[i] = 49;
        else if(strcmp(type,"j_address") == 0)
          j_address[i] = 49;
        check = check - binary[j - 1];
     }
     else
     {
        if(strcmp(type,"rs") == 0)
          rs_out[i] = 48;
        else if(strcmp(type,"rt") == 0)
          rt_out[i] = 48;
        else if(strcmp(type,"rd") == 0)
          rd_out[i] = 48;
        else if(strcmp(type,"i_address") == 0)
          i_address[i] = 48;
        else if(strcmp(type,"j_address") == 0)
          j_address[i] = 48;      
     }
    j--;
    i++;
  }

}






////////////////////////////////////////////////////////
//                 R-format                           //
////////////////////////////////////////////////////////


// Method: control
// Input: None
// Output: void
// Description: Control takes the current global variable address and writes to file
//  binary and then sends to be proccessed to to_hex for hexedecimal.

void control()
{
  printf("%s\n", address);
}

// Method: addu, subu, slt, and, or
// Input: char array rs, char array rt, char array rd
// Output: void
// Description: takes in rs, rt, rd values and translates to binary in accordance with the method's
//   function . Then sends to control for further processing.

void addu(char *rs,char *rt,char *rd)
{
  int j = 0;
  char address_buffer[33];

  opcode = "000000";
  shamt = "00000";
  function = "100001";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(rd, "%d", &j);
  to_Binary(j,5,"rd");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s%s%s", opcode, rs_out, rt_out, rd_out, shamt, function);
  strcpy(address, address_buffer);
  control();
  
}

void subu(char *rs,char *rt,char *rd)
{
  int j = 0;
  char address_buffer[33];
  opcode = "000000";
  shamt = "00000";
  function = "101011";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(rd, "%d", &j);
  to_Binary(j,5,"rd");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s%s%s", opcode, rs_out, rt_out, rd_out, shamt, function);
  strcpy(address, address_buffer);
  control();
}

void slt(char *rs,char *rt,char *rd)
{
  int j = 0;
  char address_buffer[33];
  opcode = "000000";
  shamt = "00000";
  function = "101010";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(rd, "%d", &j);
  to_Binary(j,5,"rd");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s%s%s", opcode, rs_out, rt_out, rd_out, shamt, function);
  strcpy(address, address_buffer);
  control();
}

void and(char *rs,char *rt,char *rd)
{
  int j = 0;
  char address_buffer[33];
  opcode = "000000";
  shamt = "00000";
  function = "100100";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(rd, "%d", &j);
  to_Binary(j,5,"rd");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s%s%s", opcode, rs_out, rt_out, rd_out, shamt, function);
  strcpy(address, address_buffer);
  control();
}

void or(char *rs,char *rt,char *rd)
{
  int j = 0;
  char address_buffer[33];
  opcode = "000000";
  shamt = "00000";
  function = "100101";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(rd, "%d", &j);
  to_Binary(j,5,"rd");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s%s%s", opcode, rs_out, rt_out, rd_out, shamt, function);
  strcpy(address, address_buffer);
  control();
}




////////////////////////////////////////////////////////
//                 I-format                           //
////////////////////////////////////////////////////////

// Method: lw, sw, bne
// Input: char array rs, char array rt, char array offset
// Output: void
// Description: takes in rs, rt, offset/constant values and translates to binary in accordance with the method's
//   function . Then sends to control for further processing.


void lw(char *rs,char *rt, char *offset)
{
  int j = 0;
  char address_buffer[33];
  opcode = "100011";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(offset, "%d", &j);
  to_Binary(j,16,"i_address");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s", opcode, rs_out, rt_out, i_address);
  strcpy(address, address_buffer);
  control();
}

void sw(char *rs,char *rt, char *offset)
{
  int j = 0;
  char address_buffer[33];
  opcode = "101011";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(offset, "%d", &j);
  to_Binary(j,16,"i_address");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s", opcode, rs_out, rt_out, i_address);
  strcpy(address, address_buffer);
  control();
}

void bne(char *rs,char *rt, char *offset)
{
  int j = 0;
  char address_buffer[33];
  opcode = "000101";

  sscanf(rs, "%d", &j);
  to_Binary(j,5,"rs");

  sscanf(rt, "%d", &j);
  to_Binary(j,5,"rt");
  
  sscanf(offset, "%d", &j);
  to_Binary(j,16,"i_address");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s%s%s", opcode, rs_out, rt_out, i_address);
  strcpy(address, address_buffer);
  control();
}



////////////////////////////////////////////////////////
//                 J-format                           //
////////////////////////////////////////////////////////


void j(char *offset)
{
  int j = 0;
  char address_buffer[33];
  opcode = "000010";

  sscanf(offset, "%d", &j);
  to_Binary(j,26,"j_address");

  snprintf( address_buffer, sizeof( address_buffer ), "%s%s", opcode, j_address);
  strcpy(address, address_buffer);
  control();
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
  			addu(trim(buf[2], ','),trim(buf[3], ','),trim(buf[1], '\n'));
  		} 
  		else if (strcmp(buf[0],"subu") == 0)
  		{
  			subu(trim(buf[2], ','),trim(buf[3], ','),trim(buf[1], '\n'));
  		}
  		else if(strcmp(buf[0],"slt") ==0)
  		{
  			slt(trim(buf[2], ','),trim(buf[3], ','),trim(buf[1], '\n'));
  		}
  		else if(strcmp(buf[0],"and") == 0)
  		{
  			and(trim(buf[2], ','),trim(buf[3], ','),trim(buf[1], '\n'));
  		}
  		else if(strcmp(buf[0],"or") == 0)
  		{
  			or(trim(buf[2], ','),trim(buf[3], ','),trim(buf[1], '\n'));
  		}
  		else if(strcmp(buf[0],"lw") == 0)
  		{
  			lw(rs_I(buf[2]), trim(buf[1], ','), trim(buf[2], '('));
  		}
  		else if (strcmp(buf[0],"sw") == 0)
  		{
  			sw(rs_I(buf[2]), trim(buf[1], ','), trim(buf[2], '('));
  		}
  		else if(strcmp(buf[0],"bne") == 0)
  		{
  			bne(trim(buf[2], ','),trim(buf[1], ','),trim(buf[3], 'j'));
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







