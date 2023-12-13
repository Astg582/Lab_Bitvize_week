#include <iostream>

//2-i astichan e te che
bool astich(int n){
    if((n & ( n - 1)) == 0){
        return true;
    }
    return false;
}
const int s = 9;
int nocpy(int arr[s]);

int main(){
    int arr[s] = {1, 1, 2, 5, 8, 5, 8, 10, 10}; 
    int n = 0;
        std::cin >> n;
        std::cout << nocpy(arr) << std::endl;
}

int nocpy(int arr[]){
    int a = 0;
    for(int i = 0; i < s; ++i){
        a ^= arr[i];
    }
    return a;
}

