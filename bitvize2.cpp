#include <iostream>

void swap1(int&, int, int);
int sum1(int, int);
void revers(int&, int, int);
int sum2(int, int);
int sub1(int, int);
int sub2(int, int);
int mull(int, int);
int mull_rec(int a, int b);

int main(){
	int n = 0;
	int j = 0;
	std::cin >> n >> j;
	//revers(n, i, j);
	std::cout << mull_rec(n, j) << std::endl;
}

int sum1(int a, int b){
	if(b == 0){
		return a;
	}
	return sum1((a ^ b), (a & b) << 1); 
}

int sum2(int a, int b){
	while(b){
		int c = a ^ b;
		b = (a & b) << 1;
		a = c;
	}
	return a;
}

int sub1(int a, int b){
	while(b){
		a ^= b;
		b = (a & b) << 1;
	}
	return a;
}

int sub2(int a, int b){
	if(b == 0){
		return a ^ b;
	}
	return sub2(a ^ b, ((a ^ b) & b) << 1);
}


void revers(int& n, int i, int j){
	if((i < 32) && (i > -1) && (j < 32) && (j > -1)){
		while(i < j){
			swap1(n, i, j);
			--j;
			++i;
		}
	}
}


void swap1(int& n, int i, int j){
	if(!(i < 0) && !(j < 0) && (i < 32) && (j < 32)){ 
		if(bool(n & (1 << i)) == bool(n & (1 << j))){
			return;
		}
		n ^= (1 << i);
		n ^= (1 << j);
	}
}

int mull(int a, int b){
	int rec = 0;
	while(b){
		if(b & 1){
			rec = sum1(rec, a);
		}
		a <<= 1;
		b >>= 1;
		
	}
	return rec;
}


int mull_rec(int a, int b){
	if(b == 0){
		return 0;
	}
	if(b & 1){
	return sum1(mull_rec(a << 1, b >> 1), a);
	}
	return mull_rec(a << 1, b >> 1);
}









