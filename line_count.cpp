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

#include "common.h"

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
static uint total_line_count = 0 ;

void execute_file_operation(char *full_path, char *filename)
{
   if (full_path == NULL) {
      total_line_count = 0 ;
      return ;
   }
   char target_file[MAX_PATH+1] ;
   
   sprintf(target_file, "%s%s\n", full_path, filename);
   printf("%s\n", target_file);
}  //lint !e818
      
