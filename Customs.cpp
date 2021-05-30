#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
int customs = 0;

    map<string,vector<string>> name_of_assignee;
    set<string> name_of_assignee_set;

struct contact{
    string name = "NULL",id = "NULL",DOB ="NULL",phone = "NULL",email = "NULL",address = "NULL",assignee = "NULL";
    void Name(){
        string s; cout << "Ho ten: "; getline(cin,s);
        s = ' ' + s;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' ') continue;
            if(s[i-1] == ' '){
                if(s[i] >= 'a' && s[i] <= 'z') s[i] -=32;
            }
            if(s[i-1] != ' ') {
                if(s[i] >= 'A' && s[i] <= 'Z') s[i] +=32;
            }
        }
        s.erase(0,1);
        name = s;
    }
    void getID(){
        string a = "";
        for(int i = 0;i<name.size();i++){
            a += to_string((int)(name[i]));
        }
        id = a;
        cout << "ID cua ban la: "<< id << endl;
    }
    void signcheck(){
        assignee = ' ' + assignee;
        for(int i = 0;i<assignee.size();i++){
            if(assignee[i] == ' ') continue;
            if(assignee[i-1] == ' '){
                if(assignee[i] >= 'a' && assignee[i] <= 'z') assignee[i] -=32;
            }
            if(assignee[i-1] != ' ') {
                if(assignee[i] >= 'A' && assignee[i] <= 'Z') assignee[i] +=32;
            }
        }
        assignee.erase(0,1);
    }

};


void input(contact *user){
    int n = 0; cout << "Nhap so luong nguoi dung: "; cin >> n;
    while(n <= 0){
        cout << "Khong hop le! Yeu cau nhap lai: "; cin >> n;
    }
    cin.ignore();
    for(int i = 0;i<n;i++) {
        cout << "Nhap thong tin khach hang thu " << i + 1 << endl;
        user[i].Name();
        user[i].getID();
        cout << "Ngay sinh(dd/mm/yy): "; getline(cin,user[i].DOB);
        cout << "So dien thoai: "; getline(cin,user[i].phone);
        cout << "Email "; getline(cin,user[i].email);
        cout << "Dia chi: "; getline(cin,user[i].address);

        cout << "Nguoi phu trach: "; getline(cin,user[i].assignee);
        user[i].signcheck();
        name_of_assignee[user[i].assignee].push_back(user[i].phone);
        if(name_of_assignee_set.find(user[i].assignee) == name_of_assignee_set.end()) name_of_assignee_set.insert(user[i].assignee);
    }
    system("cls");
}
void search_infor(contact *user){
    cout << "Lua chon thong tin: "<<endl;
    cout << "1.email" << endl;
    cout << "2.sdt" << endl;
    cout << "3.Nhan vien phu trach" << endl;
    cout << "4.Khu vuc" << endl;
    cout << "5.Ten khack hang" << endl;
    int n; cin >> n;
    if(n == 1){
        string s; cin >> s;
        for(int i = 0;i<n;i++){
            if(s == user[i].email){
                cout << "---------------------------------" << endl;
                cout << "HO TEN: " << user[i].name << endl;
                cout << "ID: "<<user[i].id << endl;
                cout << "Ngay sinh: " << user[i].DOB << endl;
                cout << "SDT: "<<user[i].phone << endl;
                cout << "Email: " << user[i].email << endl;
                cout << "Dia chi: " << user[i].address << endl;
                cout << "Nguoi quan ly: " << user[i].assignee << endl;
            }
        }
    }else if(n == 2){

    }else if(n == 3){
        set<string> :: iterator i = name_of_assignee_set.begin();
        for(i;i!=name_of_assignee_set.end();i++){
                cout << "Nhan vien: "<< *i << " quan ly cac so: " << endl;
            for(int j = 0;j<name_of_assignee[*i].size();j++){
                cout << name_of_assignee[*i][j] << " ";
            }
            cout << endl;
        }
    }else if(n == 4){

    }else if(n == 5){


    }



}
int main(){

    contact *user;
    user = new contact[100000];
    input(user);
    search_infor(user);




}
