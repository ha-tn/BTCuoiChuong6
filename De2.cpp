#include<iostream>
#include<string>
#include<fstream>
const int MAX = 100;
using namespace std;
struct XeOTo {
	int soXe;
	string loaiXe;
	string mauSac;
	int namSX;
};

//cau a. doc DS san pham tu file text
bool kiemTraTrungMaSo(int maso1, int maso2);
	// in 1 xe o to
void InXe(XeOTo xe);
	// in DANH SACH xe o to
void InDS(XeOTo DSXeOTo[], int soLuong);
	//HAM CHINH CAU A
void DocDStuFile(XeOTo DSXeOTo[], int& soLuong, string file);

//cau b: Tim kiem, in thong tin xe theo so xa
	//1.Nhap thon tin ma so xe, so sanh trung thì in ra
void NhapInt(string label, int& n);
void NhapString(string label, string& str) {
	cout << label;
	getline(cin, str);
}
void InXeTheoMaSoXe(XeOTo DSXeOTo[], int& soLuong);

//Cau c: them vao danh sach 1 xe moi (kiem tra so xe khong duoc trung)
	//nhap xe -> ham ghi vao file (con tro ios::app), check trung xa xe
XeOTo NhapXe();
void GhiXeVaoFile(XeOTo DSXeOTo[], int& soLuong, string file);
void ThemXeVaoDS(XeOTo DSXeOTo[], int& soLuong, string file) {
	GhiXeVaoFile(DSXeOTo, soLuong, file);
}

//Cau d: Tim va xoa xe trong danh sach, theo so xe
	//1.nhap so xe -> chay vong for, trung so xe thf day i+1 thanh i, so luong --
void GhiDSXeVaoFileCheDoXoa(XeOTo DSXeOTo[], int& soLuong, string file);
void XoaXe(XeOTo DSXeOTo[], int& soLuong, string file);

//Cau e: In danh sach xe theo nam san xuat giam dan
void InDSTheoNamSXgiamDan(XeOTo DSXeOTo[], int soLuong);

//Cau f: In danh sach cac xe cung loại, với loại nhập từ bàn phím
void vietHoaChuDau(string& str);
void InDSCungLoaiXe(XeOTo DSXeOTo[], int soLuong);

//Cau G: Thong ke so luong xe theo tung loai
void SapXepDStheoLoaiXe(XeOTo DSXeOTo[], int soLuong);
void ThongKeSLxeTheoLoai(XeOTo DSXeOTo[], int soLuong);

//Cau h: In danh sach cac xe co bang so 9 nut
bool TongSoXeBang9(int n);
void InXeCoBangSo9Nut(XeOTo DSXeOTo[], int soLuong);

int main() {
	int soLuong=0;
	XeOTo DSXeOTo[MAX];
	string file = "dataXeOTo_de2.txt";

	//cau a. doc DS san pham tu file text
	DocDStuFile(DSXeOTo, soLuong, file);
	//in ra danh sacch
	InDS(DSXeOTo, soLuong);

	//cau b: tim va in thong tin xe theo ma so
	//InXeTheoMaSoXe(DSXeOTo, soLuong);

	//Cau c: them vao danh sach 1 xe moi (khong trung ma so)
	//ThemXeVaoDS(DSXeOTo, soLuong, file);

	//Cau D: xoa xe theo ma so xe
	//XoaXe(DSXeOTo, soLuong,file);

	//Cau E: In danh sach theo nam san xuat giam dan
	//InDSTheoNamSXgiamDan(DSXeOTo, soLuong);

	//Cau F: In danh sach cung loai xe, loai xe duoc nhap tu ban phim
	//InDSCungLoaiXe(DSXeOTo, soLuong);

	//Cau G: Thong ke so luong loai xe
	//SapXepDStheoLoaiXe(DSXeOTo, soLuong);
	ThongKeSLxeTheoLoai(DSXeOTo, soLuong);

	//Cau h: In danh sach cac xe co bang so 9 nut
	InXeCoBangSo9Nut(DSXeOTo, soLuong);

	return 0;
}

//cau a. doc DS san pham tu file text
//ham check turng ma so xe
bool kiemTraTrungMaSo(int maso1, int maso2) {
	if (maso1 == maso2) {
		return true;
	}
	return false;
}
void InDS(XeOTo DSXeOTo[], int soLuong) {
	cout << "---------------DANH SACH XE OTO HIEN TAI------------------" << endl;
	cout << " So Xe \t\t" << "Loai Xe \t\t\t" << "Mau Sac\t\t" << "Nam San Xuat " << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	for (int i = 0;i < soLuong;i++) {
		cout << DSXeOTo[i].soXe << "\t\t" << DSXeOTo[i].loaiXe << "\t\t\t" << DSXeOTo[i].mauSac << "\t\t" << DSXeOTo[i].namSX << endl;
	}
}
void DocDStuFile(XeOTo DSXeOTo[], int& soLuong, string file) {
	ifstream docFile;
	docFile.open(file, ios::in);
	if (!docFile.is_open()) {
		cout << "Mo file that bai";
		return;
	}

	//lay du lieu tung dong line
	string line;
	while (getline(docFile, line)) {
		int vt1 = line.find('#', 0);			//sẽ tìm kiếm dấu gạch ngang đầu tiên tính từ đầu chuỗi(vị trí 0).
		int vt2 = line.find('#', vt1 + 1);	//sẽ tìm kiếm dấu gạch ngang đầu tiên tính từ vi tri dau # tiep theo + them 1.
		int vt3 = line.find('#', vt2 + 1);

		//bat dau lay chuoi gan vao
		string soxe_str = line.substr(0, vt1);						//Cắt từ đầu chuỗi (vị trí 0) đến ngay trước dấu gạch ngang thứ nhất (độ dài đúng bằng vt1).
		string loaixe = line.substr(vt1 + 1, vt2 - vt1 - 1);		//line.substr(vị_trí_bắt_đầu, số_lượng_ký_tự_muon_cat(do dai))
		string mausac = line.substr(vt2 + 1, vt3 - vt2 - 1);
		string namsanxuat = line.substr(vt3 + 1);			//k co tham so o sau nen lay het

		//ham check trung ma so thi bo qua masodo
		int soxe = stoi(soxe_str);			//ép kiểu string sang int để so sánh

		//kiem tra trung. neu trung thi skip, k thì them vao
		bool trungSoXe = false;
		for (int i = 0;i < soLuong;i++) {
			if (soxe == DSXeOTo[i].soXe) {
				trungSoXe = true;
				break;
			}
		}

		if (trungSoXe == true) {
			cout << "Trung Ma So Xe. Bo qua thong tin xe nay";
			continue;
		}
		else {
			DSXeOTo[soLuong].soXe = soxe;
			DSXeOTo[soLuong].loaiXe = loaixe;
			DSXeOTo[soLuong].mauSac = mausac;
			DSXeOTo[soLuong].namSX = stoi(namsanxuat);
			soLuong++;
		}

	}
	docFile.close();
}
void InXe(XeOTo xe) {
	//cout << "---------------XE OTO------------------" << endl;
	//cout << " So Xe \t\t" << "Loai Xe \t\t\t" << "Mau Sac\t\t" << "Nam San Xuat " << endl;
	//cout << "------------------------------------------------------------------------------------------" << endl;
	cout << xe.soXe << "\t\t" << xe.loaiXe << "\t\t\t" << xe.mauSac << "\t\t" << xe.namSX << endl;
}
//cau b: Tim kiem, in thong tin xe theo so xa
	//1.Nhap thon tin ma so xe, so sanh trung thì in ra
void NhapInt(string label, int& n) {
	cout << label;
	cin >> n;
}
void InXeTheoMaSoXe(XeOTo DSXeOTo[], int& soLuong) {
	int soxe;
	NhapInt("Nhap So Xe muon in thong tin xe: ", soxe);
	for (int i = 0; i < soLuong;i++) {
		if (kiemTraTrungMaSo(soxe, DSXeOTo[i].soXe) == true) {
			cout << "Thong tin Xe co ma so " << soxe << " la: " << endl;
			InXe(DSXeOTo[i]);
		}
	}
}
//Cau c: them vao danh sach 1 xe moi (kiem tra so xe khong duoc trung)
	//nhap xe -> ham ghi vao file (con tro ios::app), check trung xa xe
XeOTo NhapXe() {
	XeOTo xe;
	cout << "Nhap ma so xe (5 so) can them vao DS: ";
	cin >> xe.soXe;
	cin.ignore();
	cout << " Nhap Loai Xe: ";
	getline(cin, xe.loaiXe);
	cout << "Nhap mau sac: ";
	getline(cin, xe.mauSac);
	cout << "Nhap nam san xuat ";
	cin >> xe.namSX;
	cin.ignore();

	vietHoaChuDau(xe.loaiXe);
	vietHoaChuDau(xe.mauSac);
	return xe;
}

void GhiXeVaoFile(XeOTo DSXeOTo[], int& soLuong, string file) {
	ofstream ghiFile;
	ghiFile.open(file, ios::app);
	if (!ghiFile.is_open()) {
		cout << "Mo file that bai ";
		return;
	}
	XeOTo xe = NhapXe();

	//trung xe thi thong bao va khong nhap vao file
	bool trungxe = false;
	for (int i = 0;i < soLuong;i++) {
		if (xe.soXe == DSXeOTo[i].soXe) {
			trungxe = true;
			break;
		}
	}
	if (trungxe == true) {
		cout << "Ma so xe bi trung " << endl;
		return;
	}
	else {
		cout << endl;
		ghiFile << xe.soXe << "#" << xe.loaiXe << "#" << xe.mauSac << "#" << xe.namSX << endl;
		soLuong++;
	}
	ghiFile.close();
}

//ghi xe vao file che do xoa het data truoc do
void GhiDSXeVaoFileCheDoXoa(XeOTo DSXeOTo[], int& soLuong, string file) {
	ofstream ghiFile;
	ghiFile.open(file, ios::out|ios::trunc);
	if (!ghiFile.is_open()) {
		cout << "Mo file that bai ";
		return;
	}

	for (int i = 0;i < soLuong;i++) { 
		bool trungSoXe =false;
		for (int j = 0; j < i;j++) {
			if (DSXeOTo[i].soXe == DSXeOTo[j].soXe) {
				trungSoXe = true;
				break;
			}
		}

		if (trungSoXe==true) {
			cout << "Ma so xe nay bi trung. Bo qua ma so xe nay " << endl;
			continue;
		}
		else {
			vietHoaChuDau(DSXeOTo[i].loaiXe);
			vietHoaChuDau(DSXeOTo[i].mauSac);
			ghiFile << DSXeOTo[i].soXe << "#" << DSXeOTo[i].loaiXe << "#" << DSXeOTo[i].mauSac << "#" << DSXeOTo[i].namSX << endl;
		}
	}
	ghiFile.close();
}
void XoaXe(XeOTo DSXeOTo[], int& soLuong, string file) {
	int soxe;
	NhapInt("Nhap so xe muon xoa: ", soxe);

	//tim vi tri. 
	int vitri = -1;
	for (int i = 0; i < soLuong;i++) {
		if (kiemTraTrungMaSo(soxe, DSXeOTo[i].soXe) == true) {
			vitri = i;
			break;
		}
	}

	//neu co thi tra ve i, con k co thi vitri=-1 va thong bao khong co ma so xe nay
	if (vitri != -1) {
		for (int i = vitri;i < soLuong;i++) {
			DSXeOTo[i] = DSXeOTo[i + 1];
		}
		soLuong--;
	}
	else {
		cout << "Khong co ma so xe can tim trong Danh Sach" << endl;
	}
	//in lai danh sach trong bo nho dem ra de check
	//InDS(DSXeOTo, soLuong);
	// 
	//ham ghi DS xe vao file, che do xoa het data cu
	GhiDSXeVaoFileCheDoXoa(DSXeOTo, soLuong, file);

}
//Cau e: In danh sach xe theo nam san xuat giam dan
void InDSTheoNamSXgiamDan(XeOTo DSXeOTo[], int soLuong) {
	for (int i = 0;i < soLuong - 1;i++) {
		for (int j = i + 1;j < soLuong;j++) {
			if (DSXeOTo[i].namSX < DSXeOTo[j].namSX) {
				XeOTo tmp = DSXeOTo[i];
				DSXeOTo[i] = DSXeOTo[j];
				DSXeOTo[j] = tmp;
			}
		}
	}

	cout << "Vay Danh sach duoc sap xep theo thu tu Nam San Xuat giam dan la " << endl;
	InDS(DSXeOTo, soLuong);
}


//Cau f: In danh sach cac xe cung loại, với loại nhập từ bàn phím
void vietHoaChuDau(string& str) {

	//doi het thanh chu thuong
	for (int i = 0;i < str.length();i++) {
		str[i] = tolower(str[i]);
	}
	//check o vi tri dau tien va vi tri co dau cach truoc do thì viet hoa
	for (int i = 0; i < str.length();i++) {
		if (i == 0 || str[i - 1] == ' ') {
			str[i] = toupper(str[i]);
		}
	}
}
void InDSCungLoaiXe(XeOTo DSXeOTo[], int soLuong) {
	string loaixe;
	NhapString("Nhap loai xe can in Danh Sach ", loaixe);
	vietHoaChuDau(loaixe);
	for (int i = 0;i < soLuong;i++) {
		if (loaixe == DSXeOTo[i].loaiXe) {
			InXe(DSXeOTo[i]);
		}
	}

}

//Cau G: Thong ke so luong xe theo tung loai
void SapXepDStheoLoaiXe(XeOTo DSXeOTo[], int soLuong) {
	for (int i = 0;i < soLuong - 1;i++) {
		for (int j = i + 1;j < soLuong;j++) {
			if (DSXeOTo[i].loaiXe < DSXeOTo[j].loaiXe) {
				XeOTo tmp = DSXeOTo[i];
				DSXeOTo[i] = DSXeOTo[j];
				DSXeOTo[j] = tmp;
			}
		}
	}

	cout << "Vay Danh sach duoc sap xep theo thu tu Nam San Xuat giam dan la " << endl;
	InDS(DSXeOTo, soLuong);
}
void ThongKeSLxeTheoLoai(XeOTo DSXeOTo[], int soLuong) {

	//sap xep loai xe 
	SapXepDStheoLoaiXe(DSXeOTo, soLuong);
	int dem = 1;
	//chay vong for. neu loai xe bang nhau thi dem++
	for (int i = 0;i < soLuong;i++) {
		if (DSXeOTo[i].loaiXe == DSXeOTo[i + 1].loaiXe) {
			dem++;
		}
		else {
			cout << "Loai Xe " << DSXeOTo[i].loaiXe << "co so luong la: " << dem << endl;
			dem = 1;
		}
	}
}

//Cau h: In danh sach cac xe co bang so 9 nut
bool TongSoXeBang9(int n) {
	int tong = 0;
	while (n > 0) {
		n = n / 10;
		tong = tong + (n % 10);
	}
	if (tong != 9) {
		return false;
	}
	return true;
}
void InXeCoBangSo9Nut(XeOTo DSXeOTo[], int soLuong) {

	cout << "Vay Danh Sach xe co bang so 9 nut la " << endl;
	for (int i = 0;i < soLuong;i++) {
		if (TongSoXeBang9(DSXeOTo[i].soXe)) {
			InXe(DSXeOTo[i]);
		}
	}

}
