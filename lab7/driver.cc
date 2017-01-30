#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;
		/* ADD YOUR TEST CODE HERE */
		m=500;
		n=500;
		Hashtable H(m);
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		cout << "Quadratic: ";
		H.print();
		H.printStats();
		H.clear();
		return 0;
	}

	if (argc != 4 && argc != 5) {
		usage(argv);
	}
	n = atoi(argv[argc-2]);
	m = atoi(argv[argc-1]);
	Hashtable H(m);

	switch(argv[argc-3][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		if(argc == 5 && argv[1][0]=='-' && argv[1][1]=='v' ){
			H.print();
		}
		cout << "Linear: ";
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		if(argc == 5 && argv[1][0]=='-' && argv[1][1]=='v' ){
			H.print();
		}
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		if(argc == 5 && argv[1][0]=='-' && argv[1][1]=='v' ){
			H.print();
		}
		cout << "Double Hashing: ";
		H.printStats();
		break;
	default:
		usage(argv);
	}
}
