#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 100;
struct Product {
	string Id;
	string Name;
	double Price;
};
//CAU A: NHAP DANH SACH CAC SAN PHAM, ID KHONG TRUNG, ID TU DONG CHUYEN SANG CHU IN HOA
	//ham nhap interger
void NhapInt(string label, int& n);
	//Ham viet hoa toan bo
void vietHoaToanBo(string& str);
	//kiem tra trung lap
bool kiemTraTrungId(Product DSProduct[], int& soLuong, string id);
	//Nhap danh sach cac sanr pham,id khong duoc trung
void NhapDS(Product DSProduct[], int& soLuong, int soLuongThem);
void InDS(Product DSProduct[], int soLuong);

//CAU B: GHI DANH SACH SAN PHAM VAO FILE NHI PHAN
	//ham ghi chuoi string
void GhiDSvaoFile(Product DSProduct[], int& soLuong, string file);

//CAU C: DOC DANH SACH SAN PHAM TU FILE NHI PHAN
void DocDStuFile(Product DSProduct[], int& soLuong, string file);

//CAU D: SAP XEP DANH SACH THEO GIA GIAM DAN
void SapXepDStheoGiaGiamDan(Product DSProduct[], int soLuong) {
	
	for (int i = 0;i < soLuong-1;i++) {
		for (int j = i+1;j < soLuong;j++) {
			if (DSProduct[i].Price < DSProduct[j].Price) {
				Product tmp = DSProduct[i];
				DSProduct[i] = DSProduct[j];
				DSProduct[j] = tmp;
			}
		}
	}
	cout << "Danh sach duoc sap xep giam dan theo gia la:" << endl;
	InDS(DSProduct, soLuong);
}

//SAP XEP DANH SACH THEO TEN SAN PHAM TANG DAN
void SapXepDStheoTenSPtangDan(Product DSProduct[], int soLuong) {

	for (int i = 0;i < soLuong - 1;i++) {
		for (int j = i+1;j < soLuong;j++) {
			if (DSProduct[i].Name > DSProduct[j].Name) {
				Product tmp = DSProduct[i];
				DSProduct[i] = DSProduct[j];
				DSProduct[j] = tmp;
			}
		}
	}
	cout << "Danh sach duoc sap xep tang dan theo ten sp :" << endl;
	InDS(DSProduct, soLuong);
}


int main() {
	int soLuong = 0;
	Product DSProduct[MAX];
	string file = "dataDe4.bin";
	int soLuongThem = 0;

	cout << " 1. Nhap Danh Sach cac san pham " << endl;
	cout << " 2. Ghi DS vao file nhi phan (DS->file) " << endl;
	cout << " 3. Doc DS tu file nhi phan (file->DS) " << endl;
	cout << " 4. Sap xep DS theo gia giam dan " << endl;
	cout << " 5. Sap xep DS theo ten SP tang dan " << endl;
	cout << " Other numbers: Exit " << endl;
	cout << " --------------------------------------------------------------------------------------------------- " << endl;
	int n;

	DocDStuFile(DSProduct, soLuong, file);
	do {
		cout << "Nhap lua chon: ";
		cin >> n;
		switch (n) {
		case 1:
			//cau a
			NhapDS(DSProduct, soLuong, soLuongThem);
			//InDS(DSProduct, soLuong);
			break;
		case 2:
			//caub
			GhiDSvaoFile(DSProduct, soLuong, file);
			break;
		case 3:
			//cau c
			DocDStuFile(DSProduct, soLuong, file);
			//InDS(DSProduct, soLuong);
			break;
		case 4:
			//cau d
			SapXepDStheoGiaGiamDan(DSProduct, soLuong);
			break;
		case 5:
			//cau e
			SapXepDStheoTenSPtangDan(DSProduct, soLuong);
			break;
		default:
			return 0;

		} 
	} while (true);
}

//CAU A: NHAP DANH SACH CAC SAN PHAM, ID KHONG TRUNG, ID TU DONG CHUYEN SANG CHU IN HOA
	//ham nhap interger
void NhapInt(string label, int& n) {
	cout << label;
	cin >> n;
}
//Ham viet hoa toan bo
void vietHoaToanBo(string& str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
}
//kiem tra trung lap
bool kiemTraTrungId(Product DSProduct[], int& soLuong, string id) {
	for (int i = 0; i < soLuong;i++) {
		if (id == DSProduct[i].Id) {
			return true;
		}
	}
	return false;
}
//Nhap danh sach cac sanr pham,id khong duoc trung
void NhapDS(Product DSProduct[], int& soLuong, int soLuongThem) {
	NhapInt("Nhap so luong san pham muon them vao DS: ", soLuongThem);
	cin.ignore();
	for (int i = soLuong; i < soLuong + soLuongThem;i++) {
		cout << "Nhap san pham thu " << i + 1 << endl;
		cout << "Nhap Id: ";
		getline(cin, DSProduct[i].Id);
		vietHoaToanBo(DSProduct[i].Id);
		while (kiemTraTrungId(DSProduct, i, DSProduct[i].Id)) {
			cout << "Id San pham bi trung. Vui long nhap lai Id: ";
			getline(cin, DSProduct[i].Id);
			vietHoaToanBo(DSProduct[i].Id);
		}
		cout << "Nhap ten san pham: ";
		getline(cin, DSProduct[i].Name);
		cout << "Nhap gia: ";
		cin >> DSProduct[i].Price;
		cin.ignore();
		//sau khi nhap thi cho chay danh sach ai lan nua de doi ki tu hoa, ki tu thuong cho chuan chinh


	}
	soLuong = soLuong + soLuongThem;
}
void InDS(Product DSProduct[], int soLuong) {
	cout << "---------------DANH SACH XE OTO HIEN TAI------------------" << endl;
	cout << " Id \t\t" << "Product \t\t\t" << "Price\t\t" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0;i < soLuong;i++) {
		cout << DSProduct[i].Id << "\t\t" << DSProduct[i].Name << "\t\t\t" << DSProduct[i].Price << "\t\t" << endl;
	}
}

//CAU B: GHI DANH SACH SAN PHAM VAO FILE NHI PHAN
	//ham ghi chuoi string

void GhiDSvaoFile(Product DSProduct[], int& soLuong, string file) {
	//ghi ds
	ofstream ghiFile;
	ghiFile.open(file, ios::out | ios::binary);
	if (!ghiFile.is_open()) {
		cout << "Mo file that bai";
		return;
	}
	ghiFile.write(reinterpret_cast<char*>(&soLuong), sizeof(int));					//ghi so luong truoc

	//xu ly chuoi string, duyet tung san pham, trong san pham lai viet cau lenh cho tung truong
	for (int i = 0;i < soLuong;i++) {

		// A. Ghi chuỗi Id
		int idLen = DSProduct[i].Id.length(); // Lấy độ dài THẬT của chuỗi Id
		ghiFile.write(reinterpret_cast<char*>(&idLen), sizeof(int)); // Ghi độ dài vào file trước
		ghiFile.write(DSProduct[i].Id.c_str(), idLen);               // Ghi chuỗi ký tự thô của Id vào sau
		//Chuyển đổi một chuỗi kiểu string (C++) thành một chuỗi ký tự thô kiểu const char*

		// B. Ghi chuỗi Name
		int nameLen = DSProduct[i].Name.length(); // Lấy độ dài THẬT của chuỗi Name
		ghiFile.write(reinterpret_cast<char*>(&nameLen), sizeof(int)); // Ghi độ dài vào file trước
		ghiFile.write(DSProduct[i].Name.c_str(), nameLen);             // Ghi chuỗi ký tự thô của Name vào sau


		ghiFile.write(reinterpret_cast<char*>(&DSProduct[i].Price), sizeof(double));	//ghi so thuc
	}
	ghiFile.close();
	cout << "Da ghi thong tin san pham vao file " << endl;
}

//CAU C: DOC DANH SACH SAN PHAM TU FILE NHI PHAN
void DocDStuFile(Product DSProduct[], int& soLuong, string file) {
	//doc ds
	ifstream docFile;
	docFile.open(file, ios::in | ios::binary);
	if (!docFile.is_open()) {
		cout << "Mo file that bai";
		return;
	}
	docFile.read(reinterpret_cast<char*>(&soLuong), sizeof(int));					//ghi so luong truoc

	//xu ly chuoi string, duyet tung san pham, trong san pham lai viet cau lenh cho tung truong
	for (int i = 0;i < soLuong;i++) {

		int idLen;
		docFile.read(reinterpret_cast<char*>(&idLen), sizeof(int)); // Đọc con số độ dài từ file trước (ví dụ: 3)
		DSProduct[i].Id.resize(idLen);                              // Tạo 1 vùng trống 3 ký tự trong RAM để hứng
		docFile.read(&DSProduct[i].Id[0], idLen);                    // Đổ dữ liệu từ file vào vùng trống vừa tạo

		int nameLen;
		docFile.read(reinterpret_cast<char*>(&nameLen), sizeof(int)); // Đọc con số độ dài từ file trước (ví dụ: 3)
		DSProduct[i].Name.resize(nameLen);                              // Tạo 1 vùng trống 3 ký tự trong RAM để hứng
		docFile.read(&DSProduct[i].Name[0], nameLen);                    // Đổ dữ liệu từ file vào vùng trống vừa tạo

		docFile.read(reinterpret_cast<char*>(&DSProduct[i].Price), sizeof(double));	//ghi so thuc
	}
	docFile.close();
	cout << "Da doc thong tin san pham tu file " << endl;
}