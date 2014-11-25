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

int complexity;
int N;

int d(int n) {
	return rand()%n+1;
}

int main(int argc, char* argv[]) {
	if(argc==1) {
		N = 1000;
		complexity = 2;
	} else if(argc == 1) {
		N = atoi(argv[0]);
		complexity = 2;
	} else if(argc == 2) {
		N = atoi(argv[0]);
		complexity = atoi(argv[1]);
	} else {
		printf("Call with optional arguments [ N [complexity] ]\n");
	}

	std::srand(std::time(0));

	bool prime;
	for(int i = 3; i <= N; i++) {
		for(int j = 2; j <= complexity; j++) {
			prime = ( !(i%j==0) );
			if(!prime) {
				break;
			}
		}
		if(prime) {
			prime = ( d(6) == 1 );// change to d(6)==2 for Lawley method
		}
		if(!prime) printf("%i 0\n", i);
		if( prime) printf("%i 1\n", i);
	}
}