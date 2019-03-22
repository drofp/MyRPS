#ifndef FILE_WRITER_H_
#define FILE_WRITER_H_

#include <string>
#include <cstring>
#include <fstream>
#include <sys/stat.h>

using namespace std;

namespace myrps
{
class FileWriter
{
public:
  FileWriter() {}
  FileWriter(string file_name, string directory) : 
    file_name(file_name), directory("data/" + directory) {EnsureFileExists();}
  void SetFileName(string file_name);
  void writeToFile(string payload);
  bool DirectoryExists();
  bool FileExists();
private:
  void EnsureFileExists();
  string file_name;
  string directory;
};
}
#endif