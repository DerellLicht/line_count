//**********************************************************************************
//  line_count.cpp 
//  
//  Recursively scan through folder tree, count lines in all files with 
//  specified file extensions.
//  
//  Written by:  Derell Licht
//**********************************************************************************
//  non-class version of this program is 12,800 bytes
//      class version of this program is 13,312 bytes
//**********************************************************************************
#include <windows.h>
#include <stdio.h>
#include <errno.h>

//lint -e10  Expecting '}'

#include "common.h"
#include "line_count.h"

#define  MAX_LINE_LEN   4096

//***********************************************************************
DLineCount::DLineCount() :
   total_line_count(0)
{
}

//***********************************************************************
void DLineCount::line_count_reset(void)
{
   total_line_count = 0 ;
}

//***********************************************************************
//  This is the function which actually does the work in the application
//***********************************************************************
int DLineCount::execute_file_operation(char *full_path, char *filename)
{
   char target_file[MAX_PATH+1] ;
   
   sprintf(target_file, "%s%s", full_path, filename);
   
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
   printf("%5u %s\n", lcount, target_file);
   total_line_count += lcount ;
   return 0;
   
}  //lint !e818
      
