#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include "bitmap.h"
#include <map>
using namespace std;

class FileInfo {
       public:
 	int file_id;  // unique ID of file
	int file_size;  // number of blocks of file
	int* block_ids;  // block indices assigned to file
	FileInfo(int id, int sz);
	~FileInfo();
};

class FileManagement
{

       public:
	int total_blocks;		// keep track of total number of blocks
	Bitmap *bitmap;
	int total_files;		// keep track of total number of files

	FileManagement(int blocks);
	bool create(int file_id, int file_blocks);
	bool remove(int file_id);
	map<int, FileInfo*> files; 	// keep tracks of files created
};

#endif
