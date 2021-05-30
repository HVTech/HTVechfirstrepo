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
    int j=1;
    for (auto i=data_user;j<=n; ++i)
    {
        cout << "Nhap thong tin cua nguoi dung thu " << j; j++;
        cout << "\nHo va ten: "; getline(cin, i->Name);
        cout << "ID: "; getline(cin, i->id);
        cout << "Ngay sinh (dd/mm/yy): "; getline(cin, i->DOB);
        cout << "So dien thoai: "; getline(cin, i->phone);
        cout << "Email: "; getline(cin, i->email);
        cout << "Dia chi: "; getline(cin, i->Address);
        cout << "Nguoi phu trach: "; getline(cin, i->assignee);
        cout << "----------------------------------------\n";
    }
}

void Tim_kiem_theo_sdt(contact *data_user)
{
    bool check=false;
    string sdt;
    cout << "Nhap SDT muon tim kiem: ";
    cin >> sdt;
    int h=1;
    for (auto i=data_user; h<=n ; ++i)
    {
        h ++;
        if (i->phone == sdt)
        {
            cout << "Thong tin cua nguoi dung thu " << i;
            cout << "\nHo va ten: " << i->Name;
            cout << "\nID: " << i->id;
            cout << "\nNgay sinh (dd/mm/yy): " << i->DOB;
            cout << "\nSo dien thoai: " << i->phone;
            cout << "\nEmail: " << i->email;
            cout << "\nDia chi: " << i->Address;
            cout << "\nNguoi phu trach: " << i->assignee;
            cout << "\n----------------------------------------\n";
            check == true;
        }
    }
    if (!check)
        cout << "Nguoi ban tim khong co trong du lieu1!";
}

void Tim_kiem_theo_email(contact *data_user)
{
    bool check=false;
    string email;
    cout << "Nhap email muon tim kiem: ";
    cin >> email;
    int h=1;
    for (auto i=data_user; h<=n; ++i)
    {
        h ++;
        if (i->email == email)
        {
            cout << "Thong tin cua nguoi dung thu " << h;
            cout << "\nHo va ten: " << i->Name;
            cout << "\nID: " << i->id;
            cout << "\nNgay sinh (dd/mm/yy): " << i->DOB;
            cout << "\nSo dien thoai: " << i->phone;
            cout << "\nEmail: " << i->email;
            cout << "\nDia chi: " << i->Address;
            cout << "\nNguoi phu trach: " << i->assignee;
            cout << "\n----------------------------------------\n";
            check = true;
        }
    }
    if (!check)
        cout << "Nguoi ban tim khong co trong du lieu2!";
}

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

contact *Tao_du_lieu_moi(contact *data_user)
{
    delete data_user;
    contact *data_user2 = new contact[10000];
    return data_user2;
}

void Xoa_du_lieu_cu(contact *data_user)
{
    delete data_user;
}

void Xuat_danh_ba(contact *data_user)
{
    int h=1;
    for (auto i=data_user; h<=n; ++i)
    {
        cout << "Thong tin cua nguoi dung thu " << h;
        h ++;
        cout << "\nHo va ten: " << i->Name;
        cout << "\nID: " << i->id;
        cout << "\nNgay sinh (dd/mm/yy): " << i->DOB;
        cout << "\nSo dien thoai: " << i->phone;
        cout << "\nEmail: " << i->email;
        cout << "\nDia chi: " << i->Address;
        cout << "\nNguoi phu trach: " << i->assignee;
        cout << "\n----------------------------------------\n";
    }
}

int main()
{
    contact *data_user = new contact[10000];
    //Input_data(data_user);
    cout << "1. Tao danh ba moi";
    cout << "\n2. Chinh sua danh ba";
    cout << "\n3. Xoa danh ba";
    cout << "\n4. Tim danh ba theo ten";
    cout << "\n5. Tim danh ba theo SDT";
    cout << "\n6. Tim danh ba theo khu vuc";
    cout << "\n7. Tim danh ba thieu email";
    cout << "\n8. Tim nhung SDT duoc giao cho 1 nhan vien";
    cout << "\n0. Thoat chuong trinh";
    cout << "\nNhap lua chon cua ban: ";
    /*int lua_chon;
    do
    {
        cin >> lua_chon;
        switch (lua_chon)
        {
        case 1:
            Input_data(data_user);
            break;
        case 3:
            Xoa_du_lieu_cu(data_user);
            break;
        case 4:
            Search_data(data_user);
            break;
        case 5:
            Search_data(data_user);
        default:
            cout << "Khong co lua chon phu hop";
            break;
        }
    }
    while (lua_chon != 0);  */
    Input_data(data_user);
    Search_data(data_user);
    data_user = Tao_du_lieu_moi(data_user);
    Xuat_danh_ba(data_user);
    delete data_user;
}
