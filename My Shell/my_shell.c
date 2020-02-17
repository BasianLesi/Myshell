#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_CHARS 512

void interactive();
void batch(char *batch);
/*MAIN***********************************************************************/

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        printf("Interactive\n");
        interactive();
    }

    else if (argc == 2)
    {
        char *batchfile = argv[1];
        printf("Batch\n");
        batch(batchfile);
    }
    return 0;
}
/*PARSE_FUNCTION************************************************************/
/*source->http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html*/

void parse(char *line, char **argv)
{
    while (*line != '\0')
    { /* if not the end of line ....... */
        while (*line == ' ' || *line == '\t' || *line == '\n')
            *line++ = '\0'; /* replace white spaces with 0    */
        *argv++ = line;     /* save the argument position     */
        while (*line != '\0' && *line != ' ' &&
               *line != '\t' && *line != '\n')
            line++; /* skip the argument until ...    */
    }
    *argv = '\0'; /* mark the end of argument list  */
}

/*EXECUTE_FUNCTION**********************************************************/
/*source->http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html*/

void execute(char **argv)
{

    pid_t pid;
    int status;

    if ((pid = fork()) < 0)
    { /* fork a child process           */
        printf("*** ERROR: forking child process failed\n");
        exit(1);
    }
    else if (pid == 0)
    { /* for the child process:         */
        if (execvp(*argv, argv) < 0)
        { /* execute the command  */
            printf("*** ERROR: exec failed\n");
            exit(1);
        }
    }
    else
    {                                /* for the parent:      */
        while (wait(&status) != pid) /* wait for completion  */
            ;
    }
}

/*INTERACTIVE**********************************************************/

void interactive()
{
    char line[MAX_CHARS + 1];  // +1 because of NULL
    char *argv[MAX_CHARS + 1]; // at the end
    char **commands;
    char *token;       //  strtok()
    char *delim = ";"; //  args
    int numofcommands = 0;
    int i = 0; //,j=0;
    int flag = 0;
    //int end=1;

    //perror("lsh");

    while (1)
    {

        printf("Demetriou_8331>"); /**********************/
                                   // printf("test_acces\n");                   /* I think you can't  */
        if (fgets(line, MAX_CHARS, stdin) == NULL)
        {                                        /* reach this section */
            printf("ERROR ... ASTA LA VISTA\n"); /* manually           */
            exit(0);                             /**********************/
        }

        //       else if(line[strlen(line)-1] == '\n'){ /* in case of new line char at the end */
        //           line[strlen(line)]-1 == '\0' ;   /* replce with null char */
        //                }

        commands = malloc(MAX_CHARS * sizeof(char *)); /* 1-D array    */
        for (i = 0; i < MAX_CHARS; i++)
        {                                                   /* for produced */
            commands[i] = malloc(MAX_CHARS * sizeof(char)); /* tokens       */
        }

        numofcommands = 0;           /*hashing of line of commands*/
        token = strtok(line, delim); /*into tokens, removing      */
        while (token != NULL)
        {                                           /*delimiter ";" and put them */
            strcpy(commands[numofcommands], token); /*in array.                  */
            token = strtok(NULL, delim);            /*Source->www.tutorialspoint.com/c_standard_library/c_function_strtok.htm*/
            numofcommands++;
        }

        for (i = 0; i < numofcommands; i++)
        {
            parse(commands[i], argv);
            if (strcmp(argv[0], "quit") == 0)
            {             /* in case of "quit" */
                flag = 1; /* command line  */
            }

            execute(argv); /* call execute function */
        }
        if (flag == 1)
        {
            //end==2;
            //break;
            exit(1);
        }
    }
}
//   printf("test_acces\n");

/*BATCHFILE**********************************************************/

void batch(char *batch)
{
    char line[MAX_CHARS + 1];
    char *argv[MAX_CHARS + 1];
    char **commands;
    char *token;
    int numofcommands = 0;
    int i = 0;
    int flag = 0;
    char *delim = ";";

    FILE *data;
    data = fopen(batch, "r"); /*open batch file, only for reading*/

    if (data == NULL)
    {                                                /* in case of    */
        printf("Something went wrong, try again\n"); /* wrong file or */
        exit(0);                                     /* the file      */
    }                                                /* doesn't exist */

    while (fgets(line, MAX_CHARS, data) != NULL)
    { // S
        if (line[strlen(line) - 1] == '\n')
        {                                                   // A
            line[strlen(line) - 1] = '\0';                  // M
        }                                                   // E
                                                            //
        commands = malloc(MAX_CHARS * sizeof(char *));      // A
        for (i = 0; i < MAX_CHARS; i++)                     // S
        {                                                   // 
            commands[i] = malloc(MAX_CHARS * sizeof(char)); // I
        }                                                   // N 
                                                            // T
        numofcommands = 0;                                  // E
        token = strtok(line, delim);                        // R
        while (token != NULL)                               // A
        {                                                   // C
            strcpy(commands[numofcommands], token);         // T
            token = strtok(NULL, delim);                    // I
            numofcommands++;                                // V
        }                                                   // E
                                                            
        for (i = 0; i < numofcommands; i++)                 // M 
        {                                                   // O       
            parse(commands[i], argv);                       // D 
            if (strcmp(argv[0], "quit") == 0)               // E  
            {                                               // 
                flag = 1;                                   // A  
            }                                               // B  
            execute(argv);                                  // O  
        }                                                   // V  
                                                            // E   
        if (flag == 1)                                      //       
        {                                                   //         
            exit(0);                                        //          
        }                                                   //   
    }                                                    
}

/****************************************************************************************************************************************** 
Funcionality of parse and execute() functions

Source -> http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html

- Function parse() takes an input line and returns a zero-terminated array of char pointers, each of which points to a zero-terminated character string. This function loops until a binary zero is found, which means the end of the input line line is reached. If the current character of line is not a binary zero, parse() skips all white spaces and replaces them with binary zeros so that a string is effectively terminated. Once parse() finds a non-white space, the address of that location is saved to the current position of argv and the index is advanced. Then, parse() skips all non-whtitespace characters. This process repeats until the end of string line is reached and at that moment argv is terminated with a zero.

For example, if the input line is a string as follows:

    "cp  abc.CC   xyz.TT"

Function parse() will return array argv[] with the following content:   
                                                               argv --> 0 cp
                                                                        1 abc.CC 
                                                                        2 xyz.TT

- Function execute() takes array argv[], treats it as a command line arguments with the program name in argv[0], forks a child process, and executes the indicated program in that child process. While the child process is executing the command, the parent executes a wait(), waiting for the completion of the child. In this special case, the parent knows the child's process ID and therefore is able to wait a specific child to complete. 
 
*******************************************************************************************************************************************/
