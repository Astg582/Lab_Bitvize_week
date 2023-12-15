#include <iostream>
void count_S(int*, int);
int max1(int*, int);
const int s = 10;
void quick_S(int* arr, int f, int e);
int partion(int* arr, int f, int e);

int main(){
	int arr[s];
	for(int i = 0; i < s; ++i){
		std::cin >> arr[i];
	}	
	std::cout << "quicic araj" << std::endl;
	count_S(arr, s);
	std::cout << " quicic heti" << std::endl; 	
	for(int i = 0; i < s; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void quick_S(int* arr, int f, int e){
	if(e > f){
		int ind = partion(arr, f, e);
		quick_S(arr, f, ind - 1);
		quick_S(arr, ind + 1, e);
	}
}

int partion(int* arr, int f, int e){
	int pivot = arr[f];
	int i = f + 1;
	int j = e;
	while(i <= j){
		while(arr[i] <= pivot){
			++i;
		}
		while(arr[j] > pivot){
			--j;
		}
		if(i < j){
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	int tmp = arr[j];
	arr[j] = arr[f];
	arr[f] = tmp;
	return j;
}


int max1(int* arr, int s){
	int max = INT_MIN;
	for(int i = 0; i < s; ++i){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

void count_S(int* arr, int s){
	int max = max1(arr, s);
	int* tmp = new int[max + 1];
	int* res = new int[s];
	for(int i = 0; i < max + 1; ++i){
		tmp[i] += tmp[i - 1];
	}
	
	for(int i = 0; i <s; ++i){
		res[tmp[arr[i]] - 1] = arr[i];
		--tmp[arr[i]];
	}

	for(int i = 0; i < s; ++i){
		arr[i] = res[i];
	}
	delete[] tmp;
	delete[] res;
}
