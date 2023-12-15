#include <iostream>
void buble(int* arr, int n);
const int s = 10;
void fill(int arr[s], int s);
void print(int arr[s], int s);
void insert_S(int* arr, int s);
void select_S(int* arr, int s);
void swap1(int&, int&);
void merge_S(int* arr, int f, int e);
void merge(int* arr, int f, int m, int e);

int main(){
    int arr[s];
    fill(arr, s);
    merge_S(arr, 0, s - 1);
    print(arr, s);
}

void merge_S(int* arr, int f, int e){
	if(e >= f){
		int m = (f + (e - f)) / 2;
		merge_S(arr, f, m);
		merge_S(arr, m + 1, e);

		merge(arr, f, m, e);
	}
}

void merge(int* arr, int f, int m, int e){
	int f1 = f;
	int e1 = m;
	int f2 = m + 1;
	int e2 = e;

	int s = (e - f) + 1;
	int* tmp = new int[s];
	int ind = 0;
	while(f1 <= e1 && f2 <= e2){
		if(arr[f1] <= arr[f2]){
			tmp[ind] = arr[f1];
			++f1;
		}else{
			tmp[ind] = arr[f2];
			++f2;
		}
		++ind;
	}
	while(f1 <= e1){
		tmp[ind] = arr[f1];
		++f1;
		++ind;
	}
	while(f2 <= e2){
		tmp[ind] = arr[f2];
		++f2;
		++ind;
	}
	for(int  i = 0; i < s; ++i){
		arr[f + i] = tmp[i];
	}
	delete[] tmp;
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
/*
void insert_rec(int* arr, int s){
	if(s - 1 == 0){
		return;
	}
	if(s != 0 && 

}*/

void swap1(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

void select_S(int* arr, int s){

	for(int i = 0; i < s - 1; ++i){
		int ind = i;
		for(int j = i + 1; j < s; ++j){
			if(arr[j] < arr[ind]){
				ind = j;
			}
		}
		swap1(arr[i], arr[ind]);
	}
}
