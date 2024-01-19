#include <iostream>
#include <string>
#include <vector>
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
};
int main(){
    setlocale(0,"");
    list_stud kl;
    int i=0;
    while(i!=1){
    cout<<"Что вы хотите сделать?(Введите соответсвующее число)"<<endl;
    cout<<"1. Добавить ученика"<<endl;
    cout<<"2. Выставить ученику оценку "<<endl;
    cout<<"3. Проверить является ли ученик отличником"<<endl;
    int t;
    cin>>t;
    switch (t){
    case 1:{cout<<"Введите имя ученика"<<endl; string s; cin>>s; kl.add(s);break;}
    case 2:{if(kl.printKlass()){cout<<"Введите номер ученика в списке и оценку,ему поставленную"<<endl; unsigned int x,y; cin>>x>>y; kl.getmark(x,y);};break;}
    case 3:{if (kl.printKlass()){cout<<"Введите номер ученика в списке"<<endl; unsigned i;cin>>i;if(kl.excelst(i)){cout<<"Да"<<endl;}else cout<<"Нет"<<endl;}break;}
        default:cout<<"Такого варианта нет - введите заново"<<endl; break;
    }
    cout<<"Хотите продолжить?(1-да,0-нет)"<<endl;
    bool k;
    cin>>k;
    if (!k) i=1;
    }
    return 0;

}
