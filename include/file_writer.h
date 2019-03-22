#ifndef FILE_WRITER_H_
#define FILE_WRITER_H_

#include <string>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <boost/filesystem.hpp>

using namespace std;

namespace myrps
{
class FileWriter
{
public:
  FileWriter(string file_name, string directory);
  void SetFileName(string file_name);
  void writeToFile(string payload);
private:
  void EnsureFileExists();
  bool DirectoryExists();
  bool FileExists();
  string file_name;
  string directory;
};
}
#endif