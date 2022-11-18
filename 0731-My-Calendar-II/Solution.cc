#include <iostream>
#include <set>

using namespace std;

class MyCalendarTwo {
public:
    set<pair<int,int>> book1;
    set<pair<int,int>> book2;

    MyCalendarTwo() {
        
    }
    
    bool f(int start, int end, int no){
        auto book = no==1?book1:book2;

        if(book.size() == 0){
            return true;
        }

        auto nxt = book.lower_bound({start, end});
        auto prv = nxt==book.begin()?book.end():prev(nxt); 
        if(nxt == book.end()){
            return prv->second<=start;
        }
        if(prv == book.end()){
            return nxt->first>=end;
        }

        return start>=prv->second and end <= nxt->first;
    }

    bool book(int start, int end) {
       bool ret1 = f(start, end, 1);
       bool ret2 = f(start, end, 2);

       if(not ret1 and not ret2){
           return false;
       }else{
           if(ret1) book1.insert({start, end});
           else book2.insert({start, end});
           return true;
       }
    }
};

int main(){
    MyCalendarTwo calendar;
    cout<<calendar.book(10,20)<<endl;
    cout<<calendar.book(50,60)<<endl;
    cout<<calendar.book(10,40)<<endl;
    cout<<calendar.book(5,15)<<endl;
    cout<<calendar.book(5,10)<<endl;
    cout<<calendar.book(25,55)<<endl;;
    return 0;
}
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
