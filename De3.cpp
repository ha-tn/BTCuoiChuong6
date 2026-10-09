#include<iostream>
#include<fstream>
#include<string>
//#include<cctype>
using namespace std;
const int MAX = 100;
struct Sach {
	char maSach[20];
	char tenSach[100];
	char tacGia[50];
	char nhaXuatBan[50];
	int namXuatBan;

};

//Cau a: Nhap danh sach cac quyen sach
void NhapDSSach(Sach DSSach[], int& soLuong, int soLuongThem);
	//In Danh Sach cac quyen sach
void InDSSach(Sach DSSach[], int& soLuong);
void InSach(Sach quyenSach);

//Cau b: Ghi DS vao file nhi phan
void GhiDSvaoFile(Sach DSSach[], int& soLuong, string file);

//Cau c: Doc DS tu file nhi phan
void DocDStuFile(Sach DSSach[], int& soLuong, string file);

//Cau d: Tim kiem, in thong tin sach theo MaSach
	//1. 1 ham Nhap ma sach (k phan biet hoa, thuong -> 1 ham doi CHU HOA HET, 1 Ham Doi Chu Hoa Cac Ky Tu Dau Cua Chu
	//2. so sanh ma sach bang cach chay vong for
	//viet ham lon -> nhap masach -> chuyen ma sach thanh in hoa het -> so sanh strcmp(a,b), dung thi goi ham in thon tin sach, sai thi bao k co
	//tuc trong ham nhap, khi nhap xong thi goi ham in hoa cho masach, ham viet chu hoa dau chu cho cac text khac
void vietHoaToanBo(char chuoi[]);
void vietHoaChuDau(char chuoi[]);
void InSachTheoMaSach(Sach DSSach[], int soLuong);

//Cau e: them mot quyen sach moi vao danh sach, kiem tra ma sach khong duoc trung
Sach NhapSach();
bool KiemTraTrungMaSach(Sach sach1, Sach sach2);
void ThemSachVaoDS(Sach DSSach[], int& soLuong, string file);

//Cau f: tim va xoa sach theo ma sach
int TimViTriSachTheoMaSach(Sach DSSach[], int soLuong);
void XoaSachTheoMaSach(Sach DSSach[], int soLuong, string file);

//Cau G: Tim va xoa theo ten tac gia, khong phan biet chu hoa hay chu thuong
	//1.Tao ham nhap chuoi -> chuyen chuoi thanh viethoatung chu cai dau
	//2. so sanhs chuoi bang nhau thif lay vi tri
	//xoa bang cach chay vongf for nhu tren
int TimViTriSachTheoTenTacGia(Sach DSSach[], int soLuong);
void XoaSachTheoTenTacGia(Sach DSSach[], int soLuong, string file);

//Cau H: In thong tin sach theo nha xuat ban
void InSachTheoNXB(Sach DSSach[], int soLuong);

//Cau I: In danh sach Sach theo nawm xuat ban giam dan
	//1. viet ham sap xep thu tu giam dan theonam. chay thuat toan, neu nam a< nam b thi doi vi tri temp=a, a=b, b=temp
void InDSTheoNamXuatBanGiamDan(Sach DSSach[], int soLuong);


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
	int soLuong=0;
	Sach DSSach[MAX];
	string file = "textNhiPhanDe3.bin";
	//đọc trước khi nhập thêm sách, chớ không dữ liệu cũ trong file sẽ bị mất vì bị ghi đè
	//neu file chua co san se bi loi 
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
			cout << " so luong: " << soLuong<<endl;
			break;
		case 4:
			//Tim kiem, in thong tin sach theo MaSach
			//1. 1 ham Nhap ma sach (k phan biet hoa, thuong -> 1 ham doi CHU HOA HET, 1 Ham Doi Chu Hoa Cac Ky Tu Dau Cua Chu
			//2. so sanh ma sach bang cach chay vong for
			InSachTheoMaSach(DSSach, soLuong);
			break;
		case 5:
			//Them 1 quyen sach moi vao DS, kiem tra ma sach khong duoc trung
			ThemSachVaoDS(DSSach, soLuong, file);
			break;
		case 6:
			//Tim & Xoa sach theo MaSach
			XoaSachTheoMaSach(DSSach, soLuong, file);
			break;
		case 7:
			//Tim & Xoa sach theo TenTacGia
			XoaSachTheoTenTacGia(DSSach, soLuong, file);
			break;
		case 8:
			//In thong tin sach theo NhaXuatBan
			InSachTheoNXB(DSSach, soLuong);
			break;
		case 9:
			//In DS sach theo NamXuatBan giam dan
			InDSTheoNamXuatBanGiamDan(DSSach, soLuong);
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
		cin.getline(DSSach[i].maSach,20);
		cout << "Nhap TenSach: ";
		cin.getline(DSSach[i].tenSach,100);
		cout << "Nhap TacGia: ";
		cin.getline(DSSach[i].tacGia,50);
		cout << "Nhap NhaXuatBan: ";
		cin.getline(DSSach[i].nhaXuatBan,50);
		cout << "Nhap NamXuatBan: ";
		cin >> DSSach[i].namXuatBan;
		cin.ignore();
		//sau khi nhap thi cho chay danh sach ai lan nua de doi ki tu hoa, ki tu thuong cho chuan chinh
		vietHoaToanBo(DSSach[i].maSach);
		vietHoaChuDau(DSSach[i].tenSach);
		vietHoaChuDau(DSSach[i].tacGia);
		vietHoaChuDau(DSSach[i].nhaXuatBan);
	}
	soLuong = soLuong + soLuongThem;

}

//In 1 quyen sach
void InSach(Sach quyenSach) {
	cout << "Ma Sach" << "\t" << "Ten Sach " << "\t\t\t\t" << "Tac Gia " << "\t\t" << "Nha Xuat Ban" << "\t\t" << "Nam Xuat Ban " << endl;
	cout << "----------------------------------------------------------- " << endl;
	cout << quyenSach.maSach << "\t" << quyenSach.tenSach << "\t\t\t\t" << quyenSach.tacGia << "\t\t" << quyenSach.nhaXuatBan << "\t\t" << quyenSach.namXuatBan << endl;
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
	cout << "Da ghi thong tin sach vao file "<<endl;
}

	//ghi 1 quyen sach vao file
//ghi 1 quyen sach vao file
//void Ghi1SachvaoFile(Sach sach, int& soLuong, string file) {
//	//ghi sach
//	ofstream ghiFile;
//	ghiFile.open(file, ios::app | ios::binary);
//	if (!ghiFile.is_open()) {
//		cout << "Mo file that bai";
//		return;
//	}
//	ghiFile.write(reinterpret_cast<char*>(&sach), sizeof(Sach));
//	ghiFile.close();
//	cout << "Da ghi thong tin 1 quyen sach vao file " << endl;
//}

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

//Cau d: Tim Kiem, In thong tin sach theo MA SACH
	// viet hoa toan bo ki tu
void vietHoaToanBo(char chuoi[]) {
	for (int i = 0; chuoi[i] != '\0'; i++) {
		chuoi[i] = toupper(chuoi[i]);
	}
}

	// viet hoa toan bo chu cai dau tien
void vietHoaChuDau(char chuoi[]) {
	for (int i = 0;i < chuoi[i] != '\0';i++) {
		//neu vi tri dau tien hoac vi tri truoc i la dau cach thi chuyen thanh ki tu in hoa, con lai in thuong
		if (i == 0 || chuoi[i - 1] == ' ') {
			chuoi[i] = toupper(chuoi[i]);
		}
		else {
			chuoi[i] = tolower(chuoi[i]);
		}
	}
}
//HAM CHINH cau d
void InSachTheoMaSach(Sach DSSach[], int soLuong) {
	cin.ignore();
	//dungf static den bien chuyen tu vung nho stack sang vung nho Data segment(toan cuc cua ctrinh)
	//no se khoi tao 1 lan duy nhat khi chay ctrinh va chi mat khi tat console
	static char masach[20];
	cout << " Nhap MaSach muon in thong tin: ";
	cin.getline(masach, 20);
	vietHoaToanBo(masach);

	//viet chuong trinh in
	for (int i = 0;i < soLuong;i++) {
		if (strcmp(masach, DSSach[i].maSach) == 0) {
			cout << "Thong tin sach can tim theo MaSach " << masach << "la: " << endl;
			InSach(DSSach[i]);
			return;
		}
	}
	cout << "Khong co sach phu hop voi MaSach " << masach << "da yeu cau tim." << endl;

}

//Cau e: them mot quyen sach moi vao danh sach, kiem tra ma sach khong duoc trung
Sach NhapSach() {
	Sach sach;
	cin.ignore();
	cout << "Them 1 quyen sach " << endl;
	cout << "Nhap MaSach: ";
	cin.getline(sach.maSach, 20);
	cout << "Nhap TenSach: ";
	cin.getline(sach.tenSach, 100);
	cout << "Nhap TacGia: ";
	cin.getline(sach.tacGia, 50);
	cout << "Nhap NhaXuatBan: ";
	cin.getline(sach.nhaXuatBan, 50);
	cout << "Nhap NamXuatBan: ";
	cin >> sach.namXuatBan;
	cin.ignore();
	//sau khi nhap thi doi ki tu hoa, ki tu thuong cho chuan chinh
	vietHoaToanBo(sach.maSach);
	vietHoaChuDau(sach.tenSach);
	vietHoaChuDau(sach.tacGia);
	vietHoaChuDau(sach.nhaXuatBan);

	return sach;
}
bool KiemTraTrungMaSach(Sach sach1, Sach sach2) {
	if (strcmp(sach1.maSach, sach2.maSach) == 0) {
		return true;
	}
	return false;
}


//HAM CHINH CAU E THEM 1 QUYEN SACH KHONG TRUNG MASACH
void ThemSachVaoDS(Sach DSSach[], int& soLuong, string file) {
	Sach sach_temp = NhapSach();
	//neu trung thi k goi ham ghi vao file
	for (int i = 0;i < soLuong;i++) {
		if (KiemTraTrungMaSach(sach_temp, DSSach[i]) == true) {
			cout << "Ma Sach bi trung trong Danh Sach co san " << endl;
			return;
		}
	}
	//neu khong trung, nap sach moi vao danh sach luon
	DSSach[soLuong] = sach_temp;
	soLuong++;
	//goi ham ghi file
	GhiDSvaoFile(DSSach, soLuong, file);

	cout << "Them 1 quyen sach vao file thanh cong" << endl;
}

//Cau f: tim va xoa sach theo ma sach
int TimViTriSachTheoMaSach(Sach DSSach[], int soLuong) {
	static char masach[20];
	cout << "Nhap ma sach muon xoa: ";
	cin.getline(masach, 20);
	vietHoaToanBo(masach);
	for (int i = 0;i < soLuong;i++) {
		if (strcmp(masach, DSSach[i].maSach) == 0) {
			return i;
		}
	}
	return -1;
}
void XoaSachTheoMaSach(Sach DSSach[], int soLuong, string file) {
	//nhap ma sach -> goi ham de masach thanh ki tu hoa
	// viet ham tim vi tri cua ma sach
	//chay vong for tu vitri den so luong, thay i=i+1, sau do so luong -1
	//goi ham ghi lai vao file
	cin.ignore();
	int viTri = TimViTriSachTheoMaSach(DSSach, soLuong);
	if (viTri == -1) {
		cout << "Khong tim thay MaSach nay trong Danh Sach hien tai " << endl;
		return;
	}
	else {
		//chay vong for de ghi de phan tu (xoa)
		for (int i = viTri;i < soLuong;i++) {
			DSSach[i] = DSSach[i + 1];
		}
		soLuong--;
		cout << " Xoa thanh cong thong tin Sach " << endl;
		//bat dau ghi lai Danh Sach vao file nhi phan
		GhiDSvaoFile(DSSach, soLuong, file);
	}
}
//Cau G: Tim va xoa theo ten tac gia, khong phan biet chu hoa hay chu thuong
	//1.Tao ham nhap chuoi -> chuyen chuoi thanh viethoatung chu cai dau
	//2. so sanhs chuoi bang nhau thif lay vi tri
	//xoa bang cach chay vongf for nhu tren

int TimViTriSachTheoTenTacGia(Sach DSSach[], int soLuong) {
	static char tenTacGia[50];
	cout << "Nhap ten tac gia muon xoa thong tin sach:";
	cin.getline(tenTacGia, 50);
	vietHoaChuDau(tenTacGia);

	for (int i = 0;i < soLuong;i++) {
		if (strcmp(tenTacGia, DSSach[i].tacGia) == 0) {
			return i;
		}
	}
	return -1;
}
void XoaSachTheoTenTacGia(Sach DSSach[], int soLuong, string file) {
	cin.ignore();
	int viTri = TimViTriSachTheoTenTacGia(DSSach, soLuong);
	if (viTri == -1) {
		cout << "Khong tim thay Tac Gia nay trong Danh Sach hien tai " << endl;
		return;
	}
	else {
		//chay vong for de ghi de phan tu (xoa)
		for (int i = viTri;i < soLuong;i++) {
			DSSach[i] = DSSach[i + 1];
		}
		soLuong--;
		cout << " Xoa thanh cong thong tin Sach thong qua ten tac gia " << endl;
		//bat dau ghi lai Danh Sach vao file nhi phan
		GhiDSvaoFile(DSSach, soLuong, file);
	}

}

//Cau H: In thong tin sach theo nha xuat ban
void InSachTheoNXB(Sach DSSach[], int soLuong) {
	cin.ignore();
	//dungf static den bien chuyen tu vung nho stack sang vung nho Data segment(toan cuc cua ctrinh)
	//no se khoi tao 1 lan duy nhat khi chay ctrinh va chi mat khi tat console
	static char nxb[50];
	cout << " Nhap nha xuat ban muon in thong tin sach: ";
	cin.getline(nxb, 50);
	vietHoaChuDau(nxb);

	//viet chuong trinh in
	for (int i = 0;i < soLuong;i++) {
		if (strcmp(nxb, DSSach[i].nhaXuatBan) == 0) {
			cout << "Thong tin sach can tim theo nha xuat ban " << nxb << " la: " << endl;
			InSach(DSSach[i]);
			return;
		}
	}
	cout << "Khong co sach phu hop voi Nha Xuat ban " << nxb << " da yeu cau tim." << endl;

}

//Cau I: In danh sach Sach theo nawm xuat ban giam dan
	//1. viet ham sap xep thu tu giam dan theonam. chay thuat toan, neu nam a< nam b thi doi vi tri temp=a, a=b, b=temp
void InDSTheoNamXuatBanGiamDan(Sach DSSach[], int soLuong) {
	for (int i = 0; i < soLuong - 1;i++) {
		for (int j = i + 1; j < soLuong; j++) {
			if (DSSach[i].namXuatBan < DSSach[j].namXuatBan) {
				int tmp = DSSach[i].namXuatBan;
				DSSach[i].namXuatBan = DSSach[j].namXuatBan;
				DSSach[j].namXuatBan = tmp;
			}
		}
	}
	cout << "DS Sach duoc xep theo nam giam dan la: " << endl;
	InDSSach(DSSach, soLuong);
}