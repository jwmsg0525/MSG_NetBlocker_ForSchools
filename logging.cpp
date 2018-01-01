#include "logging.h"

Logging::Logging(string filepath)
{
this->filepath = filepath;
}


void Logging::insertlog(string data){
 data +="\n";
 FILE * fp;
 fp = fopen(filepath.c_str(),"a");
 fprintf(fp,data.c_str());
 fclose(fp);
}
