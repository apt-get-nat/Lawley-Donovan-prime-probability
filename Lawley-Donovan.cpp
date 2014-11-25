// Based on an algorithm suggested by
// Lawley, Donovan et al
// Author: Nathaniel Mathews
//
// Usage: ./{compiled program} [N] complexity]
//        where N is the maximum integer to stop
//        at, and complexity is the factor to
//        stop calculation at (2, for the titular
//        method.

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

int d(int n) {
	return rand()%n+1;
}

int main(int argc, char* argv[]) {
	int complexity = 2, N = 1000;
	std::string mode = "donovan";

	switch(argc) {
		case 4:
			mode = std::string(argv[3]);
		case 3:
			complexity = atoi(argv[2]);
		case 2:
			N = atoi(argv[1]);
			break;
		default:
			printf("USAGE: %s <num> [complexity] [lawley OR donovan]\n", argv[0]);
			return 1;
	}

	std::srand(std::time(0));

	bool prime;
	for(int i = 0; i <= N; i++) {
		for(int j = 2; j <= complexity; j++) {
			prime = ( !(i%j==0) );
			if(!prime) {
				break;
			}
		}
		if(prime) {
			if(mode == "lawley") {
				prime = ( d(6)==1 || d(6)==4 );
			} else {
				prime = ( d(6) == 1 );
			}
		}

		if(prime) printf("%d is probably prime\n", i);
		else	  printf("%d is probably not prime\n", i);
	}
}
