#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct SinhVien {
	string mssv;
	string hoTen;
	double diem;
};
int main() {

//START: DOC GHI DANH SACH (TAP TIN NHI PHAN)
	SinhVien arr[3] = { {"sv88","Tran Nhat Ha",8.1},{"sv21","Pham Minh Qui",4.8},{"sv09","Tran Thi Thuy Hien",9.3} };
	//ghi file
	ofstream ghiFile;
	ghiFile.open("testDocGhiFile.bin", ios::out | ios::binary);
	if (!ghiFile.is_open()) {
		cout << "Mo file that bai ";
		return 1;
	}
	else
	{
		ghiFile.write(reinterpret_cast<char*>(arr), 3*sizeof(SinhVien));
		ghiFile.close();
	}
	//doc file ra console de check
	ifstream docFile;
	docFile.open("testDocGhiFile.bin", ios::in | ios::binary);
	if (!docFile.is_open()) {
		cout << "Mo file that bai ";
		return 1;
	}
	else
	{
		docFile.read(reinterpret_cast<char*>(arr), 3*sizeof(SinhVien));
		docFile.close();
		cout << "vay danh sach da duoc doc tu file nhi phan la:" << endl;
		for (int i = 0;i < 3;i++) {
			cout << arr[i].mssv<<"\t"<<arr[i].hoTen << "\t" << arr[i].diem << endl;
		}
	}
//END: DOC GHI DANH SACH (TAP TIN NHI PHAN)

//// START: DOC, GHI TAP TIN NHI PHAN
//	SinhVien sv;
//	sv.hoTen = "Mai Van Tan";
//	sv.diem = 6.6;
//	//ghi file
//	ofstream ghiFile;
//	ghiFile.open("testDocGhiFile.bin", ios::out | ios::binary);
//	if (!ghiFile.is_open()) {
//		cout << "Mo file that bai ";
//		return 1;
//	}
//	else
//	{
//		ghiFile.write(reinterpret_cast<char*>(&sv), sizeof(SinhVien));
//		ghiFile.close();
//	}
//	//doc file ra console de check
//	ifstream docFile;
//	docFile.open("testDocGhiFile.bin", ios::in | ios::binary);
//	if (!docFile.is_open()) {
//		cout << "Mo file that bai ";
//		return 1;
//	}
//	else
//	{
//		docFile.read(reinterpret_cast<char*>(&sv), sizeof(SinhVien));
//		docFile.close();
//		cout << sv.hoTen << "\t" << sv.diem << endl;
//	}
//// END: DOC, GHI TAP TIN NHI PHAN

//BEGIN: DOC, GHI TAP TIN TXT
	//ghi vao file 2 sinh vien
	//ofstream oFs;
	//oFs.open("data.txt");
	//if (oFs.is_open()) {
	//	cout << "file mo thanh cong";
	//	oFs << "sv01-Nguyen Van-Thanh-7-6.5" << endl;
	//	oFs << "sv02-Tran Thanh-Tuan-8.5-5" << endl;
	//	oFs.close();
	//}
	//else {
	//	cout << "Mo file that bai";
	//}

	// doc lai data tu file 
	//string line;
	//ifstream iFs;
	//iFs.open("data.txt");
	//if (iFs.is_open()) {
	//	cout << "file mo thanh cong chuan bi doc file"<<endl;
	//	while (getline(iFs, line)) {
	//		cout << line << "\n";
	//	}
	//	
	//	iFs.close();
	//}
	//else {
	//	cout << "Mo file that bai";
	//}
//END: DOC, GHI TAP TIN TXT
	return 0;
}