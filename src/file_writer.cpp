#include "file_writer.h"

using namespace std;

namespace myrps
{
FileWriter::FileWriter(string file_name, string directory)
{
  this->file_name = file_name;
  this->directory = "data/" + directory;
  EnsureFileExists();
}

void FileWriter::SetFileName(string file_name)
{
  this->file_name = file_name;
}

void FileWriter::writeToFile(string payload)
{
  string file_to_write = this->directory + this->file_name;
  ofstream file;

  file.open(file_to_write, ofstream::out | ofstream::app);
  file << payload;
  file.close();
}

void FileWriter::EnsureFileExists()
{
  if(!FileExists())
  {
    string cmd;
    if(!DirectoryExists())
    {
      cmd = "mkdir -p " + this->directory;
      system(cmd.c_str());
    }
    cmd = "touch " + this->directory + this->file_name;
  }
}

bool FileWriter::FileExists()
{
  string file_path = this->directory + this->file_name;
  struct stat buffer;
  return stat(file_path.c_str(), &buffer) == 0;
}

bool FileWriter::DirectoryExists()
{
  struct stat info;
  return stat(this->directory.c_str(), &info) == 0;
}

}

