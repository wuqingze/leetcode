#include <iostream>
#include <vector>
#include <algorithm>

bool isUgly(int n){
    while(n%2 == 0){
        n /= 2;
    }
    while(n%3 == 0){
        n /= 3;
    }
    while(n%5 == 0){
        n /= 5;
    }
    return n == 1;
}

int main(){
    int cnt = 0;
    int i = 1;
    while(cnt < 1690){
        if(isUgly(i)){
            std::printf("%d,", i);
            cnt += 1;
        }
        i += 1;
    }
    return 0;
}
