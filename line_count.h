//lint -e1066  Symbol declared as "C" conflicts with line 11, file line_count.h
//lint -esym(757, execute_file_operation)
//lint -esym(1714, DLineCount::line_count_reset)

//***********************************************************************
//  This is the function which actually does the work in the application
//***********************************************************************
int execute_file_operation(char *full_path, char *filename);

class DLineCount {
private:
   uint total_line_count ;

public:
   DLineCount() ;
   ~DLineCount() {};
   void usage(void) const;
   void line_count_reset(void);
   int execute_file_operation(char *full_path, char *filename);
   unsigned line_count_total(void) const 
      { return total_line_count ; } ;
} ;
