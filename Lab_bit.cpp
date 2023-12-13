#include <iostream>

bool astich(int n){
    if((n & ( n - 1)) == 0){
        return true;
    }
    return false;
}

int main(){
    int n = 0;
        std::cin >> n;
        std::cout << astich(n) << std::endl;
}
