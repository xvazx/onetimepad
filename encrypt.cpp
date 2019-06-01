#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main (int argc, char* argv[])
{
	if (argc < 2){
		std::cerr << "Usage:" << argv[0] << " filename" <<std::endl;
		return 1;
	}
	string filename;
	filename = argv[1];
	ifstream is(filename);
	if (is.is_open())
	{
		ofstream keyfile;
		keyfile.open(filename+"_key");
		ofstream datafile;
		datafile.open(filename+"_data");
       		srand (time(NULL));
		char c;
		string ks;
		string os;
		while (is.get(c))
		{ 
			int k;
		        k = rand() % 126+ 1;
			int o;
			o = c+(char)k;
			keyfile.put((char)k);
			datafile.put((char)o);
		}
		is.close();
		datafile.close();
		keyfile.close();
	}
	else std::cerr << "Error: " << strerror(errno) << std::endl;
	return 0;
}
