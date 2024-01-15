//**********************************************************************************
//  line_count.cpp 
//  
//  Recursively scan through folder tree, count lines in all files with 
//  specified file extensions.
//  
//  Written by:  Derell Licht
//**********************************************************************************
#include <windows.h>
#include <stdio.h>
#include <errno.h>

//lint -e10  Expecting '}'

#include "common.h"
#include "line_count.h"

#define  MAX_LINE_LEN   4096

static uint total_line_count = 0 ;

//***********************************************************************
void line_count_reset(void)
{
   total_line_count = 0 ;
}

//***********************************************************************
uint line_count_total(void)
{
   return total_line_count ;
}

//**********************************************************************************
void usage(void)
{
   puts("Usage: line_count [base_folder] [target_file_extension]");
   puts("");
   puts("base_folder is required; to specify current folder, use period (.)");
   puts("");
   puts("file_extension must include period; example: .cpp");
}

//***********************************************************************
//  This is the function which actually does the work in the application
//***********************************************************************
int execute_file_operation(char *full_path, char *filename)
{
   if (full_path == NULL) {
      total_line_count = 0 ;
      return EINVAL;
   }
   char target_file[MAX_PATH+1] ;
   
   sprintf(target_file, "%s%s\n", full_path, filename);
   printf("%s: ", target_file);
   
   FILE* infd = fopen(target_file, "rt");
   if (infd == NULL) {
      printf("%s: %s\n", target_file, strerror(errno));
      return errno;
   }
   uint lcount = 0 ;
   char inpstr[MAX_LINE_LEN+1];
   while (fgets(inpstr, MAX_LINE_LEN, infd) != NULL) {
      lcount++ ;
   }
   fclose(infd);
   printf("%u lines\n", lcount);
   total_line_count += lcount ;
   return 0;
   
}  //lint !e818
      
