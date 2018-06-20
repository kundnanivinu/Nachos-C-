#include "file_management.h"
#include "iostream"
#include <map>

using namespace std;

FileManagement :: FileManagement(int blocks)
{
	total_blocks= blocks;
	bitmap= new Bitmap(total_blocks);
}

bool FileManagement :: create(int file_id, int file_blocks)
{
	map <int, FileInfo*>:: iterator it;
	it= files.find(file_id);
	if(it != files.end())
	{
		cout << "\n***ERROR***File with ID " << file_id << " already exists. Cannot create a newFile with same id(unique_id)";
	}
	else
	{
		if(bitmap->NumClear() < file_blocks)
		{
			cout << "\n\nThe number of empty blocks is less than the required blocks (" << file_blocks << ")"; 
			cout << "\nCannot create FILE with id " << file_id << "and size " << file_blocks;
			return false;
		}

		else
		{
			int tempCount= 0;
			FileInfo *newFile= new FileInfo(file_id, file_blocks);

			cout << "\n\n*******CREATING NEW FILE**********";
			cout << "\nFILE ID:\t" << file_id << "\t\t\tNO OF BLOCKS:\t "<< file_blocks;
			cout << "\nFollwing are the blocks assigned to file " << file_id << endl;

			for(int i = 0; i < total_blocks; i++)
			{
				if(tempCount < file_blocks)
				{
					if(!bitmap->Test(i))
					{
						newFile->block_ids[tempCount]= i;
						cout << newFile->block_ids[tempCount] <<"\t\t";
						bitmap->Mark(i);
						tempCount++;
					}
				}
				else
				{
					break;
				}
			}
			files.insert(pair <int, FileInfo*>(file_id, newFile));
			cout << "\nNumber of unassigned blocks are:\t" << bitmap->NumClear();
		}
	}
	return true;
}

bool FileManagement :: remove(int file_id)
{
	map <int, FileInfo*>:: iterator it;
	it= files.find(file_id);
	if(it != files.end())
	{
		FileInfo *f= it->second;
		cout << "\n\n*******REMOVING EXISTING FILE**********";
		cout << "\nRemoving FILE with id " << file_id << " and size " << f->file_size;
		cout << "\nFollowing are the blocks that are freed up:\n";
		
		for(int i = 0; i < f->file_size; i++)
		{
			cout << f->block_ids[i] <<"\t\t";
			bitmap->Clear(f->block_ids[i]);
		}
		files.erase(file_id);
	}
	else
	{
		cout << "\nCannot remove FILE with id " << file_id << "as it does not exists!!";
		return false;
	}
	return true;
}

FileInfo::FileInfo(int id, int sz) {
  file_id = id;
  file_size = sz;
  block_ids = new int[file_size];
}

FileInfo::~FileInfo() {
  delete block_ids;
}

