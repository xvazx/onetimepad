#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//test
int main (int argc, char* argv[])
{
	if (argc < 2){
		std::cerr << "Usage:" << argv[0] << " filename" <<std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::ofstream keyfile;
		keyfile.open(filename+"_key");
		std::ofstream datafile;
		datafile.open(filename+"_data");
       		srand (time(NULL));
		char c;
		std::string ks;
		std::string os;
		while (file.get(c))
		{ 
			int k;
		        k = rand() % 126+ 1;
			int o;
			o = c+(char)k;
			keyfile.put((char)k);
			datafile.put((char)o);
		}
		file.close();
		datafile.close();
		keyfile.close();
	}
	else std::cerr << "Error: " << strerror(errno) << std::endl;
	return 0;
}
