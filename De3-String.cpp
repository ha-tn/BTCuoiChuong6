#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 100;
struct Sach {
	string maSach;
	string tenSach;
	string tacGia;
	string nhaXuatBan;
	int namXuatBan;

};

//Cau a: Nhap danh sach cac quyen sach
void NhapDSSach(Sach DSSach[], int& soLuong, int soLuongThem);
//In Danh Sach cac quyen sach
void InDSSach(Sach DSSach[], int& soLuong);


//Cau b: Ghi DS vao file nhi phan
void GhiDSvaoFile(Sach DSSach[], int& soLuong, string file);
//Cau c: Doc DS tu file nhi phan
void DocDStuFile(Sach DSSach[], int& soLuong, string file);
int main() {

	cout << " 1. Nhap DS cac quyen sach " << endl;
	cout << " 2. Ghi DS ra file nhi phan " << endl;
	cout << " 3. Doc DS tu file nhi phan " << endl;
	cout << " 4. Tim kiem, in thong tin sach theo MaSach " << endl;
	cout << " 5. Them 1 quyen sach moi vao DS " << endl;
	cout << " 6. Tim & Xoa sach theo MaSach " << endl;
	cout << " 7. Tim & Xoa sach theo TenTacGia " << endl;
	cout << " 8. In thong tin sach theo NhaXuatBan " << endl;
	cout << " 9. In DS sach theo NamXuatBan giam dan " << endl;
	cout << " Other numbers: Exit " << endl;
	cout << " --------------------------------------------------------------------------------------------------- " << endl;
	int n;
	int soLuong = 0;
	Sach DSSach[MAX];
	string file = "textNhiPhanDe3-String.bin";
	//đọc trước khi nhập thêm sách, chớ không dữ liệu cũ trong file sẽ bị mất vì bị ghi đè
	DocDStuFile(DSSach, soLuong, file);
	do {
		cout << "Nhap lua chon: ";
		cin >> n;
		switch (n) {
		case 1:
			//Cau a: Nhap danh sach cac quyen sach
			//1. Nhap so luong sach can them, bien int soLuongMoi
			//2. Tao 1 mang Danh Sach[MAX], chay vong for tư 0-> soLuongMoi de nhap sach 
			//3. Goi ham Nhap sach-> In ra danh sach
			int soLuongThem;
			cout << "Nhap so luong Sach can them: ";
			cin >> soLuongThem;
			cin.ignore();
			NhapDSSach(DSSach, soLuong, soLuongThem);
			InDSSach(DSSach, soLuong);
			GhiDSvaoFile(DSSach, soLuong, file);
			break;
		case 2:
			//Cau b: Ghi DS vao file nhi phan
			GhiDSvaoFile(DSSach, soLuong, file);
			break;
		case 3:
			//Cau c: Doc DS tu file nhi phan
			DocDStuFile(DSSach, soLuong, file);
			cout << " so luong: " << soLuong << endl;
			break;
		case 4:
			//Tim kiem, in thong tin sach theo MaSach
			//1. Nhap 
			break;
		case 5:
			//Them 1 quyen sach moi vao DS
			break;
		case 6:
			//Tim & Xoa sach theo MaSach
			break;
		case 7:
			//Tim & Xoa sach theo TenTacGia
			break;
		case 8:
			//In thong tin sach theo NhaXuatBan
			break;
		case 9:
			//In DS sach theo NamXuatBan giam dan
			break;
		default:
			//Other numbers: Exit
			return 0;
		}

	} while (true);




	//ofstream ghiFile;
	//ghiFile.open("textNhiPhanDe3.bin", ios::binary);
	//if (!ghiFile.is_open()) {
	//	cout << "Mo file that bai ";
	//	return 1;
	//}

	return 0;
}

//Cau a: Nhap danh sach cac quyen sach
	//1. Nhap so luong sach can them, bien int soLuongMoi
	//2. Tao 1 mang Danh Sach[MAX], chay vong for tư soluong-> soluong + soLuongMoi de nhap sach 
	//3. Goi ham Nhap sach (tao 2 ham di, 1 ham NhapSach, 1 ham NhapDSSach) 2 ham In (1 ham InSach, 1 ham InDSSach)
void NhapDSSach(Sach DSSach[], int& soLuong, int soLuongThem) {
	for (int i = soLuong; i < soLuong + soLuongThem;i++) {
		cout << "Nhap quyen sach thu " << i + 1 << endl;
		cout << "Nhap MaSach: ";
		cin >> DSSach[i].maSach;
		cin.ignore();
		cout << "Nhap TenSach: ";
		getline(cin,DSSach[i].tenSach);
		cout << "Nhap TacGia: ";
		getline(cin,DSSach[i].tacGia);
		cout << "Nhap NhaXuatBan: ";
		getline(cin,DSSach[i].nhaXuatBan);
		cout << "Nhap NamXuatBan: ";
		cin >> DSSach[i].namXuatBan;
		cin.ignore();
	}
	soLuong = soLuong + soLuongThem;
}


//In Danh Sach cac quyen sach
void InDSSach(Sach DSSach[], int& soLuong) {
	cout << "--------------DANH SACH CAC QUYEN SACH HIEN CO------------- " << endl;
	cout << "Ma Sach" << "\t" << "Ten Sach " << "\t\t\t\t" << "Tac Gia " << "\t\t" << "Nha Xuat Ban" << "\t\t" << "Nam Xuat Ban " << endl;
	cout << "----------------------------------------------------------- " << endl;
	for (int i = 0; i < soLuong;i++) {
		cout << DSSach[i].maSach << "\t" << DSSach[i].tenSach << "\t\t\t\t" << DSSach[i].tacGia << "\t\t" << DSSach[i].nhaXuatBan << "\t\t" << DSSach[i].namXuatBan << endl;
	}
}

//Cau b: Ghi DS vao file nhi phan
void GhiDSvaoFile(Sach DSSach[], int& soLuong, string file) {
	//ghi ds
	ofstream ghiFile;
	ghiFile.open(file, ios::out | ios::binary);
	if (!ghiFile.is_open()) {
		cout << "Mo file that bai";
		return;
	}
	ghiFile.write(reinterpret_cast<char*>(&soLuong), sizeof(int));
	ghiFile.write(reinterpret_cast<char*>(DSSach), soLuong * sizeof(Sach));
	ghiFile.close();
	cout << "Da ghi thong tin sach vao file " << endl;
}

//Cau c: Doc DS tu file nhi phan
void DocDStuFile(Sach DSSach[], int& soLuong, string file) {
	//ghi ds
	ifstream docFile;
	docFile.open(file, ios::in | ios::binary);
	if (!docFile.is_open()) {
		cout << "Mo file that bai";
		return;
	}
	docFile.read(reinterpret_cast<char*>(&soLuong), sizeof(int));
	docFile.read(reinterpret_cast<char*>(DSSach), soLuong * sizeof(Sach));
	docFile.close();
	for (int i = 0; i < soLuong;i++) {
		cout << DSSach[i].maSach << "\t" << DSSach[i].tenSach << "\t\t\t\t" << DSSach[i].tacGia << "\t\t" << DSSach[i].nhaXuatBan << "\t\t" << DSSach[i].namXuatBan << endl;
	}
	//InDSSach(DSSach, soLuong);
}