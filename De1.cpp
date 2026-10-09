// BTCChuong6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>  //thu vien xuw ly voi tap tin
#include <string> // ham su ly chuoi string
using namespace std;

const int MAX_SV = 100; 

//khai bao struct sinh vien
struct SinhVien {
    string MSSV;
    string ho;
    string ten;
    float diem1;
    float diem2;
};

//xuat mang danh sach sinh vien
void xuatDSSinhVien(SinhVien DSSinhvien[], int& soLuong) {
    cout << "Danh sach tong so luong sv la: " << soLuong << endl;
    for (int i = 0;i < soLuong;i++) {
        cout << "Mssv: " << DSSinhvien[i].MSSV << "\t";
        cout << "Ho: " << DSSinhvien[i].ho << "\t";
        cout << "Ten: " << DSSinhvien[i].ten << "\t";
        cout << "Diem mon A: " << DSSinhvien[i].diem1 << "\t";
        cout << "Diem mon B: " << DSSinhvien[i].diem2 << "\t" << endl;

    }
}
//xuat thong tin sinh vien
void xuatThongTinSV(SinhVien sv) {
    cout << "Mssv: " << sv.MSSV << "\t";
    cout << "Ho: " << sv.ho << "\t";
    cout << "Ten: " << sv.ten << "\t";
    cout << "Diem mon A: " << sv.diem1 << "\t";
    cout << "Diem mon B: " << sv.diem2 << "\t" << endl;
}

//CAU A: NHAP DANH SACH TU FILE TEXT DATA.TXT
void nhapDSSVtuFile(SinhVien DSSinhVien[], int& soLuong, string file) {

    cout << "Bat dau nhap du lieu tu file: " << endl;
    //Doc danh sach sinh vien tu file data.txt
    ifstream iFile;
    iFile.open(file);
    if (!iFile.is_open()) {
        cout << "Mo file that bai";
        return;
    }

    // lay du lieu tu 1 dong line, cho chay while cho den khi khong lay duoc line nao nua
    string line;
    while (getline(iFile, line)) {
        //cout << "lay tu file: " << line << endl;


        //tach thong tin tu 1 line
        int vt1 = line.find('-'); //lay vi tri cua dau gach ngang
        int vt2 = line.find('-', vt1 + 1); 
        int vt3 = line.find('-', vt2 + 1);
        int vt4 = line.find('-', vt3 + 1);

        //cout << "Vay vi tri dau dach ngang: " << endl;
        //cout << vt1 << "\t" << vt2 << "\t" << vt3 << "\t" << vt4 << endl;

        string mssv = line.substr(0, vt1);
        string ho = line.substr(vt1 + 1, vt2 - 1 - vt1); //vt2-1-vt1: do dai chuoi string
        string ten = line.substr(vt2 + 1, vt3 - 1 - vt2);
        string diem1 = line.substr(vt3 + 1, vt4 - 1 - vt3);
        string diem2 = line.substr(vt4 + 1);
        

        //check trung mssv hay khong
        bool trungMSSV = false;
        for (int i = 0;i < soLuong;i++) {
            if (DSSinhVien[i].MSSV == mssv) {
                trungMSSV = true;
                break;
            }
        }
        if (trungMSSV == true) {
            cout << "Bo qua sinh vien co ma so trung la: " << mssv<<endl;
        }
        else
        {
            DSSinhVien[soLuong].MSSV = mssv;
            DSSinhVien[soLuong].ho = ho;
            DSSinhVien[soLuong].ten = ten;
            DSSinhVien[soLuong].diem1 = stof(diem1);
            DSSinhVien[soLuong].diem2 = stof(diem2);
            soLuong++;
        }

        //cout << "Vay sau khi cat chuoi: " << endl;
        //cout << mssv << endl << ho << endl << ten << endl << diem1 << endl << diem2 << endl;
    }
}


//CAU B: TIM KIEM THEO MSSV (KHONG PHAN BIET IN HOA HAY THUONG)
string nhapMSSV() {
    string mssv;
    cout << "Nhap ma so sinh vien: ";
    cin >> mssv;

    return mssv;
}
string doiTextThuong(string str) {

    for (int i = 0; i < str.length();i++) {
        str[i] = tolower(str[i]);
    }
    //cout << "sau khi doi thanh text thuong: " << str << endl;
    return str;
}
int timViTriSVtheoMSSV(SinhVien DSSinhVien[], int &soLuong) {
    
    string findMSSV;
    findMSSV = nhapMSSV();

    //doi string nhap vao thanh text thuong het
    findMSSV = doiTextThuong(findMSSV);

    for (int i = 0;i < soLuong;i++) {
        string mssv = DSSinhVien[i].MSSV;
        mssv = doiTextThuong(mssv);
        if (findMSSV == mssv) {
            return i;
        }
    }
    return -1;
}

//In thong tin sinh vien do sau khi tim kiem 
void timKiemMSSV(SinhVien DSSinhVien[], int& soLuong) {
    
    int vitri = timViTriSVtheoMSSV(DSSinhVien, soLuong);
    if (vitri != -1) {
        xuatThongTinSV(DSSinhVien[vitri]);
    }
    else {
        cout << "Khong tim thay Sinh Vien co mssv nay" << endl;
    }
}

//CAU C: THEM VAO DS 1 SINH VIEN
SinhVien nhapSV() {
    SinhVien sv;
    cout << "Nhap sinh vien: " << endl;
    cout << "Nhap MSSV: ";
    cin >> sv.MSSV;
    cin.ignore();
    cout << "Nhap Ho: ";
    getline(cin, sv.ho);
    cout << "Nhap Ten: ";
    getline(cin, sv.ten);
    cout << "Nhap diem mon A: ";
    cin >> sv.diem1;
    cout << "Nhap diem mon B: ";
    cin >> sv.diem2;
    cin.ignore();
    return sv;

}

bool kiemTraTrungMSSV(string str1, string str2) {
    str1 = doiTextThuong(str1);
    str2 = doiTextThuong(str2);
    if (str1 == str2) {
        return true;
    }
    return false;
}

//mo tap tin, che do mo file de them
void themSVvaoDS(SinhVien DSSinhVien[], int& soLuong, string file) {
    
    
    SinhVien svMoi = nhapSV();
    for (int i = 0;i < soLuong;i++) {
        if (kiemTraTrungMSSV(svMoi.MSSV, DSSinhVien[i].MSSV) == true) {
            cout << "bi trung mssv";
            return;
        }
    }

    //ghi vao file
    //neu mssv khong trung thi ghi vao file, tang so luong len 1
    fstream fs;
    fs.open(file, ios::app);
    if (!fs.is_open()) {
        cout << "Mo file that bai";
        return;
    }
    
    fs << svMoi.MSSV << "-" << svMoi.ho << "-" << svMoi.ten << "-" << svMoi.diem1 << "-" << svMoi.diem2 << endl;
    soLuong++;

    //sau khi ghi vao file thi doc lai du lieu tu file
    nhapDSSVtuFile(DSSinhVien, soLuong, file);

    fs.close();

}

//CAU D: XOA SINH VIEN THEO MSSV, SAU KHI XOA, CAP NHAT THONG TIN TRONG FILE
    // 1. tìm sinh vien theo mssv. Nhập mssv -> check mssv có trong danh sách k. nếu có thì xóa, k thì báo k có mssv này
    //2. xóa sinh viên
    //3. xóa hết dữ liệu trong file txt
    //4. ghi lại du lieu vao file txt

    //3.Ham xoa du lieu tỏng file text
void xoaHetDuLieuTrongFile(string file) {
    ofstream fs;
    fs.open(file, ios::trunc);
    if (fs.is_open()) {
        fs.close();
    }
    else {
        cout << "Mo file that bai khu xoa het";
        return;
    }
}
    //4.ghi lai du lieu vao file text
void ghiDSSVvaoFile(SinhVien DSSinhVien[], int& soLuong, string file) {
    ofstream fs;
    fs.open(file);
    if (fs.is_open()) {
        //chay mang ghi vao file
        for (int i = 0;i < soLuong;i++) {
            fs << DSSinhVien[i].MSSV << "-" << DSSinhVien[i].ho << "-" << DSSinhVien[i].ten << "-" << DSSinhVien[i].diem1 << "-" << DSSinhVien[i].diem2 << endl;
        }
        nhapDSSVtuFile(DSSinhVien, soLuong, file);
        fs.close();
    }
    else {
        cout << "Mo file that bai khuc ghi";
        return;
    }
}
void xoaSV(SinhVien DSSinhVien[], int &soLuong, string file) {
    //nhap mssv-> ddooir tahnhf texxt thuong
    string mssvMuonXoa;
    cout << "Nhap MSSV muon xoa: ";
    
    int vitri = timViTriSVtheoMSSV(DSSinhVien, soLuong);
    if (vitri != -1) {
        //bat dau xoa. chay mang de xoa
        for (int i = vitri; i < soLuong; i++) {
            DSSinhVien[i] = DSSinhVien[i + 1];
        }
        soLuong--;
        xuatDSSinhVien(DSSinhVien, soLuong);
        xoaHetDuLieuTrongFile(file);
        //ghi lai mảng danh sách vào file
        ghiDSSVvaoFile(DSSinhVien, soLuong, file);
    }
    else {
        cout << "Khong co sinh vien trong danh sach nay" << endl;
    }
}

//CAU E: IN DANH SACH SINH VIEN THEO TEN TANG DAN
    //1. so sanh chuoi: chay vong lap 2 vong
void inDStheoTenTangDan( SinhVien DSSinhVien[], int &soLuong) {
    for (int i = 0; i < soLuong-1;i++) {
        for (int j = i + 1;j < soLuong;j++) {
            //neu so sánh chuoix ten a>b thì đổi vị trí. temp=a;a=b;b=temp
            string a = doiTextThuong(DSSinhVien[i].ten);
            string b = doiTextThuong(DSSinhVien[j].ten);
            if (a > b) {
                SinhVien temp = DSSinhVien[i];
                DSSinhVien[i] = DSSinhVien[j];
                DSSinhVien[j] = temp;
            }
        }
    }
    cout << "Vay danh sach tang dan theo ten la: "<<endl;
    xuatDSSinhVien(DSSinhVien, soLuong);
}
//CAU F: IN DANH SACH SINH VIEN THEO DIEM TRUNG BINH GIAM DAN
    //1. tao ham tinh diem trung binh (diem1+ diem2)/2
    //2. chạy 2 vòng for cho mang: vòng 1 có ham tinh tb cho i, vòng 2 có hàm tinh tb cho j, xong rùi if so sánh-> hoán đổi
    //3. in danh sách ra

float tinhDiemTB(SinhVien sv) {
    return (sv.diem1 + sv.diem2) / 2.0;
}
void inDStheoDiemTbGiamDan(SinhVien DSSinhVien[], int& soLuong) {
    for (int i = 0; i < soLuong - 1;i++) {
        for (int j = i + 1;j < soLuong;j++) {
            float tbi = tinhDiemTB(DSSinhVien[i]);
            float tbj = tinhDiemTB(DSSinhVien[j]);
            if (tbi < tbj) {
                SinhVien temp = DSSinhVien[i];
                DSSinhVien[i] = DSSinhVien[j];
                DSSinhVien[j] = temp;
            }
        }
    }
    cout << "Vay DSSV theo diem TB giam dan la: " << endl;
    xuatDSSinhVien(DSSinhVien, soLuong);
}
//CAU G: IN DANH SACH CAC SINH VIEN DAU TB>=5, ROT (TB<5)
    // chay vong for cho mang, neu diemtb(sv1)>5.0 thi dau, in ra;
    // chay vong for cho mang, neu diemtb(sv1)<5.0 thi rot, in ra;

void inDSDauRot(SinhVien DSSinhVien[], int &soLuong) {
    //in ds sv dau
    cout << "Danh sach sinh vien DAU (diem tb>=5.0): " << endl;
    for (int i = 0; i < soLuong;i++) {
        if (tinhDiemTB(DSSinhVien[i]) >= 5.0) {
            xuatThongTinSV(DSSinhVien[i]);
        }
    }
    //in ds sv rot
    cout << "Danh sach sinh vien ROT (diem tb<5.0): " << endl;
    for (int i = 0; i < soLuong;i++) {
        if (tinhDiemTB(DSSinhVien[i]) < 5.0) {
            xuatThongTinSV(DSSinhVien[i]);
        }
    }
}

int main()
{
    SinhVien DSSinhVien[MAX_SV];
    string file = "data.txt"; //Khai báo một chuỗi chứa tên của file văn bản chứa dữ liệu sinh viên
    int soLuong = 0;

    ///Cau a: nhap danh sach SV tu file
    nhapDSSVtuFile(DSSinhVien, soLuong, file);
    xuatDSSinhVien(DSSinhVien, soLuong);

    //Caub: tim kiem theo mssv, in thong tin sv do (khong phan biet chu hoa, thuong) (in ra mssv,ho, ten,diem1, diem 2)
    //timKiemMSSV(DSSinhVien, soLuong);

    //Cau c: them sinh vien vao danh sach
    //themSVvaoDS(DSSinhVien, soLuong, file);
    
    //Cau d: Xoa sinh vien theo MSSV, sau khi xoa, cap nhat thong tin trong file
    //xoaSV(DSSinhVien, soLuong, file);
    
    //Cau e: In Danh sach sinh vien theo ten tang dan
    //inDStheoTenTangDan(DSSinhVien, soLuong);

    //Cau f: In Danh sách sinh vien theo diem trung bình giam dan
    //inDStheoDiemTbGiamDan(DSSinhVien, soLuong);

    //Cau g: In danh sach sinh vien DAU (tb>5), ROT (tb<5)
    inDSDauRot(DSSinhVien, soLuong);

    return 0;
}


