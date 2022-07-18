#include <bits/stdc++.h>
using namespace std;

class SinhVien{
	private:
		string ma, ten, lop;
		float toan, ly, anh;
	public:
		SinhVien();
		SinhVien(string ma, string ten, string lop, float toan, float ly, float anh);
		string getName();
		string getId(); 
		void setName(string);
		void setClass(string);
		void setMath(float);
		void setPhysics(float);
		void setEnglish(float);
		friend ostream& operator << (ostream&, SinhVien);
		friend istream& operator >> (istream&, SinhVien&);	
		friend void nhap(vector<SinhVien>&); 
		friend void xuat(vector<SinhVien>);
		friend float tong(SinhVien);	
};

SinhVien::SinhVien(){		//ham khoi tao mac dinh khong chua tham so
	ma = ten = lop = "";
	toan = ly = anh = 0;
}

SinhVien::SinhVien(string ma, string ten, string lop, float toan, float ly, float anh){    //ham khoi tao chua tham so
	this->ma = ma;
	this->ten = ten;
	this->lop = lop;
	this->toan = toan;
	this->ly = ly;
	this->anh = anh; 
}

string SinhVien::getName(){
	return this->ten;
}

string SinhVien::getId(){
	return this->ma;
}


ostream& operator << (ostream& out, SinhVien a){
	out << setw(15) << a.ma;
	out << setw(30) << a.ten;
	out << setw(15) << a.lop;
	out << setw(10) << a.toan;
	out << setw(10) << a.ly;
	out << setw(10) << a.anh << endl;
	return out;
}

istream& operator >> (istream& in, SinhVien& a){
	cout << "Nhap ma SV: ";
	in >> a.ma;
	getchar(); 
	cout << "Nhap ten SV: ";
	getline(in,a.ten);
	cout << "Nhap lop: ";
	in >> a.lop;
	cout << "Nhap diem thanh phan theo thu tu toan, van, anh:  ";
	in >> a.toan >> a.ly >> a.anh;
	return in;
}

void SinhVien::setName(string ten){
	this->ten = ten;
}

void SinhVien::setClass(string lop){
	this->lop = lop;
}

void SinhVien::setMath(float toan){
	this->toan = toan;
}

void SinhVien::setPhysics(float ly){
	this->ly = ly;
}

void SinhVien::setEnglish(float anh){
	this->anh = anh;
}

void nhap(vector<SinhVien> &v){
	SinhVien tmp;
	cin >> tmp;
	v.push_back(tmp);
}

void xuat(vector<SinhVien> v){
	for(SinhVien x : v){
		cout << x;
	}
}

void hienThongTin(){
	cout << setw(15) << left << "Ma sinh vien";
	cout << setw(30) << left << "Ten";
	cout << setw(15) << left << "Lop";
	cout << setw(10) << left << "Diem toan";
	cout << setw(10) << left << "Diem ly";
	cout << setw(10) << left << "Diem anh" << endl;
	cout << setfill('-');
	cout << setw(90) << "-" << endl;
	cout << setfill(' ');
}

float tong(SinhVien a){		//tra ve tong diem toan van anh
	return a.toan + a.ly + a.anh;
}

bool cmp1(SinhVien a, SinhVien b){ //tra ve tong tang dan 
	return tong(a) < tong(b);
}

string tachTen(SinhVien a){	
	stringstream ss(a.getName());
	vector<string> tenSv;
	string tmp;
	while(ss >> tmp){
		tenSv.push_back(tmp);
	}
	return tenSv[tenSv.size()-1];
} 

bool cmp2(SinhVien a, SinhVien b){		//sap xep theo ten giam dan
	return tachTen(a) > tachTen(b);
}

void sua(vector<SinhVien> &v, SinhVien &tmp1,string idSua, int choice2, string ten, string lop, float toan, float ly, float anh){
	for(int i = 0; i < v.size(); i++){
		if(v[i].getId() == idSua){
			tmp1 = v[i];					
		}
	} 	
	do{
		cout << "Ban muon sua thong tin nao (1-ten, 2-lop, 3-diem toan, 4-diem ly, 5-diem anh, 0-xong)? ";
		cin >> choice2;
		cin.ignore();
		switch(choice2){
			case 1:
				cout << "Nhap ten moi: ";
				getline(cin,ten);
				tmp1.setName(ten);	
				break;
			case 2:
				cout << "Nhap lop moi: ";
				cin >> lop;
				tmp1.setClass(lop);	
				cin.ignore();
				break;
			case 3:
				cout << "Nhap diem toan moi: ";
				cin >> toan;
				tmp1.setMath(toan);
				cin.ignore();
				break;
			case 4:
				cout << "Nhap diem ly moi: ";
				cin >> ly;
				tmp1.setPhysics(ly);
				cin.ignore();
				break;
			case 5:
				cout << "Nhap diem anh moi: ";
				cin >> anh;
				tmp1.setEnglish(anh);
				cin.ignore();
				break;
		}		
	}
	while(choice2!=0);
	for(int i = 0; i < v.size(); i++){
		if(v[i].getId() == idSua){
			v[i] = tmp1;
		}
	}
} 

int main(){
	vector<SinhVien> v;		//vector luu danh sach sinh vien
	vector<SinhVien> v2;  	//vector phu 
	int choice;
	int dem = 0;	//dem so luong sinh vien da them
	int cnt = 0;  	//dem so sinh vien co tong diem lon hon 24
	string idXoa;   //ma sinh vien muon xoa 
	string idSua;   //ma sinh vien muon sua 
	SinhVien tmp;   //luu sinh vien khong muon xoa
	SinhVien tmp1;  //sinh vien muon sua
	string tenSua, lopSua;		//bien luu ten muon sua, lop muon sua
	float toanSua, anhSua, lySua;	//bien luu diem muon sua
	do{
		cout << "====================Menu====================\n";
		cout << "         Moi nhap lua chon cua ban!\n";
		cout << "1.Them sinh vien\n";
		cout << "2.Xoa sinh vien\n";
		cout << "3.Sua Sinh vien\n";
		cout << "4.Sap xep theo ten giam dan\n";
		cout << "5.Sap xep theo tong diem tang dan\n";
		cout << "6.In ra danh sach sinh vien\n";
		cout << "7.In ra so sinh vien co tong diem lon hon 24\n";
		cout << "0.Thoat\n";
		cout << "-->Lua chon cua ban la: ";	
		cin >> choice; 
		switch(choice){
			case 1:
				cout << "Nhap so luong sinh vien ban muon them: ";
				int n;	//so luong sinh vien them vao
				cin >> n;
				for(int i = 1; i <= n; i++){
					cout << "Sinh vien thu: " << i + dem << endl;
					nhap(v);
					cout << endl; 
				}	
				dem += n;		
				break;
			case 2:
				cout << "Nhap ma sinh vien ban muon xoa: "; 
				cin >> idXoa;					
				for(int i = 0; i < v.size(); i++){
					if(v[i].getId() != idXoa){
						v2.push_back(v[i]);
					}
				}	
				v.clear();
				v = v2;
				--dem;
				break;
			case 3:
				cout << "Nhap ma sinh vien ban muon sua: ";
				cin >> idSua; 
				int choice2;	//bien luu lua chon thanh phan muon thay doi		
				sua(v,tmp1,idSua,choice2,tenSua, lopSua,toanSua,lySua, anhSua);	
				break;
			case 4:
				sort(v.begin(), v.end(), cmp2);
				cout << "Danh sach sinh vien sap xep theo ten giam dan:\n";
				hienThongTin();
				xuat(v);
				break;
			case 5:	
				sort(v.begin(), v.end(), cmp1);	 
				hienThongTin();
				xuat(v);		
				break;	
			case 6:
				cout << "--DANH SACH SINH VIEN--\n"; 
				hienThongTin();
				xuat(v);
				break;
			case 7:	
				for(SinhVien x : v){
					if(tong(x) > 24){
						cnt++;
					}
				}
				cout << "So sinh vien co tong diem lon hon 24 la: " << cnt << endl;;
				cout << "Danh sach sinh vien co tong diem lon hon 24: \n";
				hienThongTin();
				for(SinhVien x : v){
					if(tong(x) > 24){
						cout << x;
					}
				}
				break;		
		}
	}
	while(choice != 0);
	return 0;
} 
