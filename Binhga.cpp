#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct contact
{
    string Name;
    string id;
    string DOB;
    string phone;
    string email;
    string Address;
    string assignee;
};

// Global variable
int n;


void Input_data(contact *data_user)
{
    cout << "Nhap so luong nguoi dung: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "So khong hop le! Yeu cau nhap lai: ";
        cin >> n;
    }
    cin.ignore();
    for (int i=0; i<n; i++)
    {
        cout << "Nhap thong tin cua nguoi dung thu " << i+1;
        cout << "\nHo va ten: "; getline(cin, data_user[i].Name);
        cout << "ID: "; getline(cin, data_user[i].id);
        cout << "Ngay sinh (dd/mm/yy): "; getline(cin, data_user[i].DOB);
        cout << "So dien thoai: "; getline(cin, data_user[i].phone);
        cout << "Email: "; getline(cin, data_user[i].email);
        cout << "Dia chi: "; getline(cin, data_user[i].Address);
        cout << "Nguoi phu trach: "; getline(cin, data_user[i].assignee);
        cout << "----------------------------------------\n";
    }
}
//-------------------------------

void Tim_kiem_theo_sdt(contact *data_user)
{
    bool check=false;
    string sdt;
    cout << "Nhap SDT muon tim kiem: ";
    cin >> sdt;
    
    for (int i=0; i<n ; i++)
    {
        if (data_user[i].phone == sdt)
        {
            cout << "Thong tin cua nguoi dung thu " << i+1;
            cout << "\nHo va ten: " << data_user[i].Name;
            cout << "\nID: " << data_user[i].id;
            cout << "\nNgay sinh (dd/mm/yy): " << data_user[i].DOB;
            cout << "\nSo dien thoai: " << data_user[i].phone;
            cout << "\nEmail: " << data_user[i].email;
            cout << "\nDia chi: " << data_user[i].Address;
            cout << "\nNguoi phu trach: " << data_user[i].assignee;
            cout << "\n----------------------------------------\n";
            check == true;
        }
    }
    if (!check)
        cout << "Nguoi ban tim khong co trong du lieu1!";
}
//---------------------------

void Tim_kiem_theo_email(contact *data_user)
{
    bool check=false;
    string email;
    cout << "Nhap email muon tim kiem: ";
    cin >> email;
    
    for (int i=0; i<n; i++)
    {

        if (data_user[i].email == email)
        {
            cout << "Thong tin cua nguoi dung thu " << i+1;
            cout << "\nHo va ten: " << data_user[i].Name;
            cout << "\nID: " << data_user[i].id;
            cout << "\nNgay sinh (dd/mm/yy): " << data_user[i].DOB;
            cout << "\nSo dien thoai: " << data_user[i].phone;
            cout << "\nEmail: " << data_user[i].email;
            cout << "\nDia chi: " << data_user[i].Address;
            cout << "\nNguoi phu trach: " << data_user[i].assignee;
            cout << "\n----------------------------------------\n";
            check = true;
        }
    }
    if (!check)
        cout << "Nguoi ban tim khong co trong du lieu2!";
}
//---------------------------

void Search_data(contact *data_user)
{
    cout << "Ban muon tim kiem thong tin dua vao: ";
    cout << "\n1.SDT";
    cout << "\n2.email";
    cout << "\nNhap lua chon: ";
    int chosse;
    cin >> chosse;
    cout << "\n";
    if (chosse == 1)
        Tim_kiem_theo_sdt(data_user);
    else if(chosse == 2)
        Tim_kiem_theo_email(data_user);
}
//----------------------------

void Xuat_danh_ba(contact *data_user)
{
    for (int i=0; i<n; i++)
    {
        cout << "Thong tin cua nguoi dung thu " << i+1;
        cout << "\nHo va ten: " << data_user[i].Name;
        cout << "\nID: " << data_user[i].id;
        cout << "\nNgay sinh (dd/mm/yy): " << data_user[i].DOB;
        cout << "\nSo dien thoai: " << data_user[i].phone;
        cout << "\nEmail: " << data_user[i].email;
        cout << "\nDia chi: " << data_user[i].Address;
        cout << "\nNguoi phu trach: " << data_user[i].assignee;
        cout << "\n----------------------------------------\n";
    }
}
//-----------------------------

void Remove_user(contact *data_user)
{
    int index;
    cout << "Nhap so thu tu cua danh ba muon xoa: ";
    cin >> index;
    index --;
    for (int i=index; i<n-1; i++)
    {
        data_user[i] = data_user[i+1];
    }
    n --;
}

void Add_user(contact *data_user)
{
    cin.ignore();
    cout << "Nhap thong tin cua nguoi dung thu " << n+1;
    cout << "\nHo va ten: "; getline(cin, data_user[n].Name);
    cout << "ID: "; getline(cin, data_user[n].id);
    cout << "Ngay sinh (dd/mm/yy): "; getline(cin, data_user[n].DOB);
    cout << "So dien thoai: "; getline(cin, data_user[n].phone);
    cout << "Email: "; getline(cin, data_user[n].email);
    cout << "Dia chi: "; getline(cin, data_user[n].Address);
    cout << "Nguoi phu trach: "; getline(cin, data_user[n].assignee);
    cout << "----------------------------------------\n";
    n ++;
}

void Edit_user(contact *data_user)
{
    int num;
    cout << "Nhap so danh ba can sua: ";
    cin >> num;
    //Sua thong tin
    cin.ignore();
    cout << "Nhap thong tin cua nguoi dung thu " << num;
    cout << "\nHo va ten: "; getline(cin, data_user[num-1].Name);
    cout << "ID: "; getline(cin, data_user[num-1].id);
    cout << "Ngay sinh (dd/mm/yy): "; getline(cin, data_user[num-1].DOB);
    cout << "So dien thoai: "; getline(cin, data_user[num-1].phone);
    cout << "Email: "; getline(cin, data_user[num-1].email);
    cout << "Dia chi: "; getline(cin, data_user[num-1].Address);
    cout << "Nguoi phu trach: "; getline(cin, data_user[num-1].assignee);
    cout << "----------------------------------------\n";
}

int main()
{
    contact *data_user = new contact[100];
    cout << "Can tao danh ba moi khi dung lan dau dung chuong trinh!\n";
    Input_data(data_user);

    //Hien thi cac chuc nang
    cout << "1. Tao danh ba moi";
    cout << "\n2. Chinh sua danh ba";
    cout << "\n3. Xoa danh ba";
    cout << "\n4. Xuat danh ba";
    cout << "\n5. Tim danh ba";
    cout << "\n6. Tim danh ba thieu email";
    cout << "\n7. Tim nhung SDT duoc giao cho 1 nhan vien";
    cout << "\n0. Thoat chuong trinh";
    cout << "\nNhap lua chon cua ban: ";
    int lua_chon;
    bool thoat = false;
    cin >> lua_chon;
    do
    {
        switch (lua_chon)
        {
        case 1:
            Add_user(data_user);
            cout << "\nNhap lua chon cua ban: ";
            cin >> lua_chon;
            break;
        case 2:
            Edit_user(data_user);
            cout << "\nNhap lua chon cua ban: ";
            cin >> lua_chon;
            break;
        case 3:
            Remove_user(data_user);
            cout << "\nNhap lua chon cua ban: ";
            cin >> lua_chon;
            break;
        case 4:
            Xuat_danh_ba(data_user);
            cout << "\nNhap lua chon cua ban: ";
            cin >> lua_chon;
            break;
        case 5:
            Search_data(data_user);
            cout << "\nNhap lua chon cua ban: ";
            cin >> lua_chon;
        case 0:
            break;
        default:
            lua_chon = 0;
            break;
        }
    } while (lua_chon != 0);
    delete data_user;
}
