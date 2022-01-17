// The MIT License (MIT)
// 
// Copyright (c) 2020 Trevor Bakker 
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stdint.h>
#include <ctype.h>

#define MAX_NUM_ARGUMENTS 5

#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

struct __attribute__((__packed__)) DirectoryEntry
{
  char DIR_Name[11];
  uint8_t DIR_Attr;
  uint8_t Unused1[8];
  uint16_t DIR_FirstClusterHigh;
  uint8_t Unused2[4];
  uint16_t DIR_FirstClusterLow;
  uint32_t DIR_FileSize;
};

struct DirectoryEntry dir[16];


char BS_OEMName[8];
int16_t BPB_BytsPerSec;
int8_t BPB_SecPerClus;
int16_t BPB_RsvdSecCnt;
int8_t BPB_NumFATs;
int16_t BPB_RootEntCnt;
char BS_VolLab[11];
int32_t BPB_FATSz32;
int32_t BPB_RootClus;

int32_t RootDirSectors = 0;
int32_t FirstDataSector = 0;
int32_t FirstSectorofCluster = 0;

FILE *fp;

int32_t curr_direct;
char new_formatted[12] = " ";

int LBAToOffset(int32_t sector)
{
  if(sector == 0) 
  {
    sector = 2;
  }
  return ((sector - 2) * BPB_BytsPerSec) + (BPB_BytsPerSec * BPB_RsvdSecCnt)
                  + (BPB_NumFATs * BPB_FATSz32 * BPB_BytsPerSec);
}

int16_t NextLB(uint32_t sector)
{
  uint32_t FATAddress = (BPB_BytsPerSec * BPB_RsvdSecCnt) + (sector * 4);
  int16_t val;
  fseek(fp, FATAddress, SEEK_SET);
  fread(&val, 2, 1, fp);
  return val;
}

void openfile(char* token)
{
    fp = fopen(token, "r");
    if(fp == NULL)
    {
      perror("\nError: File system image not found.\n");
      return;
    }
    
    fseek(fp, 3, SEEK_SET);
    fread(&BS_OEMName, 8, 1, fp);

    fseek(fp, 43, SEEK_SET);
    fread(&BS_VolLab, 11, 1, fp);

    fseek(fp, 11, SEEK_SET);
    fread(&BPB_BytsPerSec, 2, 1, fp);

    fseek(fp, 13, SEEK_SET);
    fread(&BPB_SecPerClus, 1, 1, fp);

    fseek(fp, 14, SEEK_SET);
    fread(&BPB_RsvdSecCnt, 2, 1, fp);

    fseek(fp, 16, SEEK_SET);
    fread(&BPB_NumFATs, 1, 1, fp);

    fseek(fp, 36, SEEK_SET);
    fread(&BPB_FATSz32, 4, 1, fp);

    fseek(fp, 17,SEEK_SET);
    fread(&BPB_RootEntCnt, 2, 1, fp);

    fseek(fp, 44, SEEK_SET);
    fread(&BPB_RootClus, 4, 1, fp);   

    curr_direct = BPB_RootClus;

    int offset = LBAToOffset(curr_direct);
    fseek(fp, offset, SEEK_SET);
    fread(&dir, sizeof(struct DirectoryEntry), 16, fp);

}

void closefile(char* token)
{
    if(fp == NULL)
    {
        perror("\nError: File system not open\n");
        return;
    }
    fclose(fp);
    fp = NULL;
}

void PrintInfo(FILE* fp)
{
  if(fp == NULL)
  {
    printf("\nFile is not opened.\n");
    return;
  }
  printf("BPB_BytsPerSec: %d - %x\n", BPB_BytsPerSec, BPB_BytsPerSec);
  printf("BPB_SecPerClus: %d - %x\n", BPB_SecPerClus, BPB_SecPerClus);
  printf("BPB_RsvdSecCnt: %d - %x\n", BPB_RsvdSecCnt, BPB_RsvdSecCnt);
  printf("BPB_NumFATs:    %d - %x\n", BPB_NumFATs, BPB_NumFATs);
  printf("BPB_FATSz32:    %d - %x\n", BPB_FATSz32, BPB_FATSz32);
}

void PrintDirectory()
{
  if(fp == NULL)
  {
    printf("The File is not opened.\n");
    return;
  }
  int offset = LBAToOffset(curr_direct);
  fseek(fp, offset, SEEK_SET);
  fread( &dir, sizeof(struct DirectoryEntry), 16, fp);

  int i;
  for(i = 0; i < 16; i++)
  {
    if((dir[i].DIR_Name[0] != (char) 0xe5) 
                && (dir[i].DIR_Attr == 0x01 || dir[i].DIR_Attr == 0x10 || dir[i].DIR_Attr == 0x20))
    {
      char filename[12];
      strncpy(&filename[0], &dir[i].DIR_Name[0], 11);
      filename[11] = '\0';
      printf("%s\n", filename);
    }
  }
}

void FormatDirectory(char* file_name)
{
  int i;
  char name_change[12];
  memset(name_change, ' ', 12);
  char* word = strtok(file_name, ".");

  if(word != NULL)
  {
    strncpy(name_change, word, strlen(word));
    word = strtok(NULL, ".");
    if(word != NULL)
    {
      strncpy((char*)(name_change + 8), word, strlen(word));
    }
    name_change[11] = '\0';

    for(i = 0; i < 11; i++)
    {
      name_change[i] = toupper(name_change[i]);
    }
    strncpy(new_formatted, name_change, 12);
  }
  else
  {
    strncpy(name_change, file_name, strlen(file_name));
    name_change[11] = '\0';
  }
}

int32_t GetLowCluster(char* file_name)
{
  FormatDirectory(file_name);
  int i;
  int low;
  for(i = 0; i < 16; i++)
  {
    char temp[11];
    memset(temp, ' ', 11);
    strncpy(temp, dir[i].DIR_Name, 11);
    temp[11] = '\0';
    if(strncmp(new_formatted, temp, 11) == 0)
    {
      low = dir[i].DIR_FirstClusterLow;
      return low;
    }
  }
  return -1;
}

int32_t GetFileSize(int32_t cluster)
{
  int file_size = 0;
  int i;
  for(i = 0; i < 16; i++)
  {
      if(cluster == dir[i].DIR_FirstClusterLow)
      {
         file_size = dir[i].DIR_FileSize;
         return file_size;
      }
  }
  return 0;
}

void PrintStat(char* file_name)
{
  int LowCluster = GetLowCluster(file_name);
  printf("First Cluster Low is: %d\n", LowCluster);
  int File_Size = GetFileSize(LowCluster);
  printf("File or Directory Size: %d\n", File_Size);
  int i;
  for(i = 0; i < 16; i++)
  {
    if(LowCluster == dir[i].DIR_FirstClusterLow)
    {
      printf("Attribute: %d\n", dir[i].DIR_Attr);
      printf("First Cluster High: %d\n", dir[i].DIR_FirstClusterHigh);
    }
  }
}


void ReadFile(char* file_name, int pos, int num_bytes) 
{
    int LowCluster = GetLowCluster(file_name);
    int offset = LBAToOffset(LowCluster);
    fseek(fp, offset + pos, SEEK_SET);
    char buffer[num_bytes];
    memset(buffer, ' ', num_bytes);
    fread(&buffer, 1, num_bytes, fp);
    printf("Data read from file: %s\n", buffer);
}

void ChangeDirectory(int32_t LowCluster, char* directory_name)
{
  int offset;
  int i;
  if(strcmp(directory_name, "..") == 0)
  {
    for(i = 0; i < 16; i++)
    {
      if(strncmp(dir[i].DIR_Name, "..", 2) == 0)
      {
          offset = LBAToOffset(dir[i].DIR_FirstClusterLow);
          curr_direct = dir[i].DIR_FirstClusterLow;
          fseek(fp, offset, SEEK_SET);
          fread(&dir, sizeof(struct DirectoryEntry), 16, fp);
          return;
      }
    }
  }
  else
  {
    offset = LBAToOffset(LowCluster);
    curr_direct = offset;
    fseek(fp, offset, SEEK_SET);
    fread(&dir, sizeof(struct DirectoryEntry), 16, fp);
  }
}

void GetFile(char* file_name)
{
    int length = strlen(file_name);
    char new_name[length];
    memset(new_name, ' ', length);
    strncpy(new_name, file_name, length);

    int LowCluster = GetLowCluster(new_name);
    int offset = LBAToOffset(LowCluster);
    int file_size = GetFileSize(LowCluster);
    fseek(fp, offset, SEEK_SET);
    FILE *move = fopen(file_name, "w");
    
    char p[file_size];
    memset(p, ' ', file_size);
    fread(p, file_size, 1, fp);
    fwrite(p, file_size, 1, move);
    fclose(move);
}

int main()
{

  char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE );

  while( 1 )
  {
    // Print out the mfs prompt
    printf ("mfs> ");

    // Read the command from the commandline.  The
    // maximum command that will be read is MAX_COMMAND_SIZE
    // This while command will wait here until the user
    // inputs something since fgets returns NULL when there
    // is no input
    while( !fgets (cmd_str, MAX_COMMAND_SIZE, stdin) );

    /* Parse input */
    char *token[MAX_NUM_ARGUMENTS];

    int   token_count = 0;                             
                                                               
    // Pointer to point to the token
    // parsed by strsep
    char *arg_ptr;                                         
                                                           
    char *working_str  = strdup( cmd_str );                

    // we are going to move the working_str pointer so
    // keep track of its original value so we can deallocate
    // the correct amount at the end
    char *working_root = working_str;

    // Tokenize the input strings with whitespace used as the delimiter
    while ( ( (arg_ptr = strsep(&working_str, WHITESPACE ) ) != NULL) && 
              (token_count<MAX_NUM_ARGUMENTS))
    {
      token[token_count] = strndup( arg_ptr, MAX_COMMAND_SIZE );
      if( strlen( token[token_count] ) == 0 )
      {
        token[token_count] = NULL;
      }
        token_count++;
    }

    if(token[0] == NULL)
    {
      continue;
    }


    if( strcmp(token[0], "open") == 0 )
    {
      if(fp != NULL)
      {
        perror("\nFile system image already open.\n");
      }
      else
      {
        openfile(token[1]);
      }
    }
    else if( strcmp(token[0], "close") == 0)
    {
      closefile(token[1]);
    }
    else if( strcmp(token[0], "info") == 0)
    {
      PrintInfo(fp);
    }
    else if( strcmp(token[0], "stat") == 0)
    {
      PrintStat(token[1]);
    }
    else if( strcmp(token[0], "read") == 0)
    {
      if(token[1] == NULL || token[2] == NULL || token[3] == NULL)
      {
          printf("Missing arguments. Please enter more.\n");
      }
      else
      {
          int position = atoi(token[2]);
          int NumberofBytes = atoi(token[3]);
          ReadFile(token[1], position, NumberofBytes);
      }
    }
    else if( strcmp(token[0], "cd") == 0)
    {
        ChangeDirectory(GetLowCluster(token[1]), token[1]);
    }
    else if( strcmp(token[0], "ls") == 0)
    {
        PrintDirectory();
    }
    else if( strcmp(token[0], "get") == 0)
    {
        if(token[1] == NULL)
        {
          printf("Please enter file name to get.\n");
        }
        GetFile(token[1]);
    }
    else
    {
      printf("\nCannot find command line\n");
    }

    free( working_root );



  }
  return 0;
}
