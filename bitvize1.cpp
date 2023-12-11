#include <iostream>
bool bit(int);
bool bit2(int n);
bool bit3(int n);
bool bit_rec(int n);
int index(int n, int i);
int index1(int n, int i, int j);
void bynar(int n);

int main(){
	int n = 0;
	int  i = 0;
	int j = 0;
	std::cin >> n;
	bynar(n);

}

bool bit(int n){
	int tmp = 0;
	while(n){
		if(n & 1){
		++tmp;
		}
		n >>= 1;
	}
	return tmp &= 1;
}

bool bit2(int n){
	int tmp = 0;
	for(int i = 0; i != sizeof(int) * 8; ++i){
		if(n & 1){
			++tmp;
		}
		n >>= 1;
	}
	return tmp &= 1;
}

bool bit3(int n){
	bool flag = 0;
	while(n){
		flag ^= (n & 1);
		n >>= 1;
	}
	return flag;
}


bool bit_rec(size_t n){
	if(n == 0){
		return 0;
	}
	return (n & 1) ^ bit_rec(n >> 1);
}

int index1(int n, int i, int j){
	if((n & (1 << i)) == (n & (1 << j))){
		return n;
	} 
	n ^= (1 << i);
	n ^= (1 << j);
	return n;
}

int index(int n, int i){
	return n | (1 << i);
}

void bynar(int n){
	if(n == 0){
		return;
	}
	bynar( n >> 1);
	std::cout << (n & 1);
}
