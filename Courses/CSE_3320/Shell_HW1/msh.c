/*
  Name: Gia Dao
  Student ID: 1001747062.
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

#define MAX_NUM_ARGUMENTS 5     // Mav shell only supports five arguments


int main()
{
  char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE );
  int  * temp_pid = (int*) malloc( 255 * sizeof(int) );
  char *hist_cmd[255] = { NULL };
  char s[100];

  int ret;
  int total_count = 0;
  int temp_ptr;
  int position = 0;
  

  while( 1 )
  {
    // Print out the msh prompt
    printf ("msh> ");

    // Read the command from the commandline.  The
    // maximum command that will be read is MAX_COMMAND_SIZE
    // This while command will wait here until the user
    // inputs something since fgets returns NULL when there
    // is no input
    
    while( !fgets (cmd_str, MAX_COMMAND_SIZE, stdin) );
    if(cmd_str[0] == '\0' || strcmp(cmd_str, "\n") == 0)
    {
      continue;
    }

    /* Parse input */
    char *token[MAX_NUM_ARGUMENTS];

    int   token_count = 0;   
                                                           
    // Pointer to point to the token
    // parsed by strsep
    char *argument_ptr;                                         
                                                           
    char *working_str  = strdup( cmd_str );                

    // we are going to move the working_str pointer so
    // keep track of its original value so we can deallocate
    // the correct amount at the end
    char *working_root = working_str;

    // Tokenize the input strings with whitespace used as the delimiter
    while ( ( (argument_ptr = strsep(&working_str, WHITESPACE ) ) != NULL) && 
              (token_count<MAX_NUM_ARGUMENTS) ) 
    {
      token[token_count] = strndup( argument_ptr, MAX_COMMAND_SIZE );

      if( strlen( token[token_count] ) == 0 )
      {
        token[token_count] = NULL;
      }

        token_count++;
    }

    // Now print the tokenized input as a debug check
    // \TODO Remove this code and replace with your shell functionality

    if(strcmp(token[0],"exit") == 0 || strcmp(token[0], "quit") == 0)
    {
      return 0;
    }
    else if(strcmp(token[0],"cd") == 0)
    {
      chdir(token[1]);
      strcat(token[0], " ");
      strcat(token[0], token[1]);
      
      hist_cmd[total_count] = token[0];
      total_count = total_count + 1;

      temp_ptr = getpid();
      temp_pid[position] = temp_ptr;
      position = position + 1;

      printf("%s\n\n", getcwd(s, 100));
      printf("PID: %d\n", temp_ptr);
      continue;
    }
    else if(strcmp(token[0], "history") == 0)
    {
      //If token[0] is identified as "history",
      //it will also be added to the array hist_cmd for display if the user types "history"
      hist_cmd[total_count] = token[0];
      total_count = total_count + 1;

      temp_ptr = getpid();
      temp_pid[position] = temp_ptr;
      position = position + 1;
      
      int i;
      for(i = 0; i < total_count; i++)
      {
        printf("%d: %s\n", i, hist_cmd[i]);
      }
      
      printf("PID: %d\n", temp_ptr);
    }
    else if(strcmp(token[0], "listpids") == 0)
    {
      int t;
      for (t = 0; t < position; t++)
      {
          printf("%d: %d\n", t, temp_pid[t]);
      }
      return 0;
    }
    else
    {
      pid_t child_pid = fork();

      if(child_pid == -1)
      {
        printf("\nFailed forking child.\n");
      }
      else if(child_pid == 0)
      {
        temp_ptr = getpid();
        temp_pid[position] = temp_ptr;
        position = position + 1;
        printf("PID: %d\n", temp_ptr);

        ret = execvp(token[0], token);
        if(ret < 0)
        {
          printf("%s: Command not found.\n\n", token[0]);
          return 0;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        int status;
        wait(&status);
        //Once we finished executing command line, the child process terminated
        //token[0], in the parent process, will be added to hist_cmd, which is an array of char pointers
        //that serve for the use of "history" command.
        hist_cmd[total_count] = token[0];
        total_count = total_count + 1;
      }
    } 

    /* int token_index  = 0;
    for( token_index = 0; token_index < token_count; token_index ++ ) 
    {
      printf("token[%d] = %s\n", token_index, token[token_index] );  
    } */

    free( working_root );
  }
  return 0;
}
