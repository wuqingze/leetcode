#include <iostream>
#include <set>

using namespace std;

class MyCalendar {
public:
    set<pair<int,int>> intervals;

    bool book(int start, int end) {
        if(intervals.size() == 0){
            intervals.insert({start, end});
            return true;
        }

        bool ret = false;
        auto itr = intervals.lower_bound({start, end});
        if(itr == intervals.end()){
            auto last = intervals.rbegin();
            if(last->second<=start){
                ret = true;
                intervals.insert({start, end});
            }
        }else{
            if(intervals.begin() == itr){
                if(end<=itr->first){
                    ret = true;
                    intervals.insert({start, end});
                }else{
                    ret = false;
                }
            }else{
                auto tt = prev(itr);
                if(start>=tt->second and end <= itr->first){
                    ret = true;
                    intervals.insert({start, end});
                }else ret = false;
            }
        }
        return ret;
    }
};

int main(){
    MyCalendar c;
    cout<<c.book(10, 20)<<endl;;
    cout<<c.book(15, 25)<<endl;;
    cout<<c.book(20, 30)<<endl;;
    cout<<"-----"<<endl;
    set<pair<int,int>> ss;
    ss.insert({1,10});
    ss.insert({4,4});
    ss.insert({4,9});
    auto ii = ss.lower_bound({4,5});
    prev(ii);
    cout<<ii->second<<endl;
    cout<<"------------"<<endl;
    auto itr = ss.lower_bound({5,8});
    bool t = itr == ss.end();
    cout<<t<<endl;
   return 0;
}
