#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;


class student{
private:
    string name{"Nobody"};
    vector<unsigned int> marks;
public:
    void getMark(unsigned int m){
        marks.push_back(m%6);
    }
    bool exst(){
        int s=0;
        if (marks.empty()) return 0;
        int i;
        for (i=0;i<marks.size();i++){
            s+=marks[i];
        }
        double k=(double)s/i;
        if (k>=4.6) {return 1;}
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
    bool mood{1};
public:
    void give_mark(unsigned int i,unsigned int j){
        ls.getmark(i,j);
    }
    void give_randmark(unsigned int i){
        unsigned int j;
        srand(time(0));
        j=abs(rand())%ls.size()+1;
        ls.getmark(j,i);
    }
    void set_name(string s){
    name=s;
    }
    string get_name(){return name;
    }
    void give_mark(unsigned int i){
        unsigned int j;
        srand(time(0));
        if ((ls.excelst(i))&&(mood)) j=5;
        if (!(ls.excelst(i))&&(mood)) j=4;
        if ((ls.excelst(i))&&!(mood)) j=abs(rand())%2+4;
        if (!(ls.excelst(i))&&!(mood)) j=abs(rand())%2+2;
        ls.getmark(i,j);
    }
    void give_randmark(){
        unsigned int i;
        i=abs(rand())%ls.size()+1;
        unsigned int j;
        srand(time(0));
        if ((ls.excelst(i))&&(mood)) j=5;
        if (!(ls.excelst(i))&&(mood)) j=4;
        if ((ls.excelst(i))&&!(mood)) j=abs(rand())%2+4;
        if (!(ls.excelst(i))&&!(mood)) j=abs(rand())%2+2;
        ls.getmark(i,j);
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
    bool printTeach(){
        if (ls.empty()) {cout<<"Список учителей пуст - добавьте хотя бы одного"<<endl; return 0;}
        cout<<"Список"<<endl;
        for(int i=0;i<ls.size();i++){
            cout<<i+1<<". "<<ls[i].get_name()<<endl;
        }
        return 1;
    }
    void give_mark1(unsigned int i,unsigned int k,unsigned int j){
    if ((i==0)||(i>ls.size())){cout<<"Учителя под таким номером нет в списке"<<endl;}
    else{ ls[i-1].give_mark(k,j%5+1);}
    }
    void give_mark2(unsigned int i,unsigned int k){
    if ((i==0)||(i>ls.size())){cout<<"Учителя под таким номером нет в списке"<<endl;}
    else{ ls[i-1].give_mark(k);}
    }
    void give_mark3(unsigned int i,unsigned int j){
    if ((i==0)||(i>ls.size())){cout<<"Учителя под таким номером нет в списке"<<endl;}
    else{ ls[i-1].give_randmark(j%5+1);}
    }
    void give_mark4(unsigned int i){
    if ((i==0)||(i>ls.size())){cout<<"Учителя под таким номером нет в списке"<<endl;}
    else{ ls[i-1].give_randmark();}
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
    cout<<"5. Пусть учитель поставить конкретную оценку конкретному ученику"<<endl;
    cout<<"6. Пусть учитель поставить случайную оценку конкретному ученику"<<endl;
    cout<<"7. Пусть учитель поставить конкретную оценку случайному ученику"<<endl;
    cout<<"8. Пусть учитель поставит случайную оценку оценку случайному ученику"<<endl;
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
    case 5:{if (tl.printTeach()){
        cout<<"Введите номер учителя в списке "<<endl;
        unsigned int s;
        cin>>s;
        if(kl.printKlass()){
        cout<<"Введите номер ученика в списке и оценку,ему поставленную"<<endl;
        unsigned int x,y;
        cin>>x>>y;
        tl.give_mark1(s,x,y);
        }
        };
        break;}
    case 6:{if (tl.printTeach()){
        cout<<"Введите номер учителя в списке "<<endl;
        unsigned int s;
        cin>>s;
        if(kl.printKlass()){
                cout<<"Введите номер ученика в списке "<<endl;
                unsigned int x;
                cin>>x;
                tl.give_mark2(s,x);
        }
        };
        break;}
    case 7:{if (tl.printTeach()){
        cout<<"Введите номер учителя в списке "<<endl;
        unsigned int s;
        cin>>s;
        if(kl.printKlass()){
                cout<<"Введите оценку "<<endl;
                unsigned int x;
                cin>>x;
                tl.give_mark3(s,x);
        }
        }
        break;}
    case 8:{if (tl.printTeach()){
        cout<<"Введите номер учителя в списке "<<endl;
        unsigned int s;
        cin>>s;
        tl.give_mark4(s);
    }
        break;}
        default:cout<<"Такого варианта нет - введите заново"<<endl; break;
    }
    cout<<"Хотите продолжить?(1-да,0-нет)"<<endl;
    bool k;
    cin>>k;
    if (!k) i=1;
    }
    return 0;

}
