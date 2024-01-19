#include <iostream>
#include <string>
#include <vector>
using namespace std;


class student{
private:
    string name;
    vector<unsigned int> marks;
public:
    void getMark(unsigned int m){
        marks.push_back(m);
    }
    bool exst(){
        int s=0;
        if (marks.empty()) return 0;
        for (int i=0;i<marks.size();i++){
            s+=marks[i];
        }
        if ((s/i)>=4.6) {return 1;}
        else return 0;
    }
};
class list_stud{
private:
    vector<student> klass;
public:
    void add(student s){
        klass.push_back(s);
    }
};
int main(){
    setlocale(0,"");
    return 0;

}
