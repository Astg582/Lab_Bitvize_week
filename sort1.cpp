#include <iostream>
void buble(int* arr, int n);
const int s = 10;
void fill(int arr[s], int s);
void print(int arr[s], int s);
void insert_S(int* arr, int s);

int main(){
    int arr[s];
    fill(arr, s);
    insert_S(arr, s);
    print(arr, s);
}

void print(int arr[], int s){
    std::cout << std::endl;
    for(int i = 0; i < s; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void fill(int arr[], int s){
    std::cout << "fill arr" << std::endl;
    for(int i = 0; i < s; ++i){
        std::cin >> arr[i];
    }
}

void buble(int* arr, int n){
    for(int i = 0; i <  n - 1; ++i){
        bool flag = true;
        for(int j = 0; j < n - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = false;
            }
        }
        if(flag){
            return;
        }
    }
}

void insert_S(int* arr, int s){
    int key = 0;
	int j = 0;
    for(int i = 1; i < s; ++i){
        key = arr[i];
		j = i - 1;
		
		while(j >= 0 && key < arr[j]){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
    }
}
