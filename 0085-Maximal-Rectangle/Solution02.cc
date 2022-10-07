#include <iostream>

using namespace std;
int main(){
//    pair<int, int> t = ('a'=='a')?{1,2}:{1==1?2:5, 4==2?3:1};
    pair<int, int> t = (1==1)?pair<int,int>{1,2}:pair<int,int>{2,2};
//    int t = 1==1?2:3;
    return 0;
}
