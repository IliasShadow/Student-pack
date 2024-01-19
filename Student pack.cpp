#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;


class student{
private:
    string name{"Nobody"};
    vector<unsigned int> marks;
public:
    void getMark(unsigned int m){
        marks.push_back(m%5+1);
    }
    bool exst(){
        int s=0;
        if (marks.empty()) return 0;
        int i;
        for (i=0;i<marks.size();i++){
            s+=marks[i];
        }
        if ((s/i)>=4.6) {return 1;}
        else return 0;
    }
    string get_name(){return name;
    }
    void set_name(string s){
        name=s;
    }
};
class list_stud{
private:
    vector<student> klass;
public:
    void add(string s){
        student r;
        r.set_name(s);
        klass.push_back(r);
    }

    void getmark(unsigned int i,unsigned int j){
        if ((i==0)||(i>klass.size())){cout<<"Ученика под таким номером нет в списке"<<endl;}
        else
        klass[i-1].getMark(j);
    }
    bool printKlass(){
        if (klass.empty()) {cout<<"Список учеников пуст - добавьте хотя бы одного"<<endl; return 0;}
        cout<<"Список"<<endl;
        for(int i=0;i<klass.size();i++){
            cout<<i+1<<". "<<klass[i].get_name()<<endl;
        }
        return 1;
    }
    bool excelst(unsigned int i){
        if ((i==0)||(i>klass.size())){cout<<"Ученика под таким номером нет в списке"<<endl;return 0;}
        return klass[i-1].exst();
    }
    int size(){return klass.size();}
};
class teacher{
private:
    string name;
    list_stud ls;
public:
    void give_mark(unsigned int i,unsigned int j){
        ls.getmark(i,j);
    }
    void give_randmark(unsigned int i){
        unsigned int j;
        srand(time(0));
        j=rand()%ls.size()+1;
        ls.getmark(j,i);
    }
    void set_name(string s){
    name=s;
    }
};
class list_teach{
private:
    vector<teacher> ls;
public:
    void add(string s){
        teacher r;
        r.set_name(s);
        ls.push_back(r);
    }
};
int main(){
    setlocale(0,"");
    list_stud kl;
    list_teach tl;
    int i=0;
    while(i!=1){
    cout<<"Что вы хотите сделать?(Введите соответсвующее число)"<<endl;
    cout<<"1. Добавить ученика"<<endl;
    cout<<"2. Выставить ученику оценку "<<endl;
    cout<<"3. Проверить является ли ученик отличником"<<endl;
    cout<<"4. Добавить учителя"<<endl;
    int t;
    cin>>t;
    switch (t){
    case 1:{cout<<"Введите имя ученика"<<endl; string s; cin>>s; kl.add(s);break;}
    case 2:{if(kl.printKlass()){cout<<"Введите номер ученика в списке и оценку,ему поставленную"<<endl; unsigned int x,y; cin>>x>>y; kl.getmark(x,y);};break;}
    case 3:{if (kl.printKlass()){
        cout<<"Введите номер ученика в списке"<<endl;
        unsigned int l;
        cin>>l;
        if(kl.excelst(l)){cout<<"Да"<<endl;}else cout<<"Нет"<<endl;}break;}
    case 4:{cout<<"Введите имя учителя"<<endl; string s; cin>>s; tl.add(s);break;}
        default:cout<<"Такого варианта нет - введите заново"<<endl; break;
    }
    cout<<"Хотите продолжить?(1-да,0-нет)"<<endl;
    bool k;
    cin>>k;
    if (!k) i=1;
    }
    return 0;

}
