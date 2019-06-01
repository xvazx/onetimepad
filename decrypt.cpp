#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main (int argc, char* argv[])
{
	if (argc < 4){
		std::cerr << "Usage:" << argv[0] << " datafile" << "keyfile" << "output" <<std::endl;
		return 1;
	}
	string dataname;
	string keyname;
	dataname = argv[1];
	keyname = argv[2];
	ifstream datafile;
	ifstream keyfile;
	datafile.open(dataname);
	keyfile.open(keyname);
	if (keyfile.is_open() && datafile.is_open())
	{
		string lined;
		string linek;
		ofstream outfile (argv[3]);
		char d;
		char k;
		while ( datafile.get(d) && keyfile.get(k) )
		{ 
				int o = d-k;
				outfile.put((char)o);

		}
		keyfile.close();
		datafile.close();
		outfile.close();
	}
	else std::cerr << "Error: " << strerror(errno) << std::endl;
	return 0;
}
