#include <stdio.h>  
#include "log.h"  
  
int main(void)  
{   
    // log_open("<span style=\"color: rgb(51, 51, 51); line-height: 20px;\">mycat</span>");  
    int result = log_open("snso.log");
    printf("result = %d\n",result);  
    LOG_NOTICE("LOG_NOTICE");
    LOG_TRACE("trace");
    LOG_DEBUG("LOG_DEBUG");   
    LOG_ERROR("error");  
	log_close(); 
    printf("finish\n");
    return 0;  
}  