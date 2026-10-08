#include <iostream>
#include <string>
using namespace std;

class DonHang {
	private:
		string mdh;
		string tkh;
		string ndh;
		int slsp;
		long long ttien;
		double tlck;
		long long ttsck;
		
	public:
	    void nhap(){
			cout<<"Ma don hang: ";
			getline(cin, mdh);
			cout<<"Ten khach hang: ";
			getline(cin, tkh);
			cout<<"Ngay dat hang: ";
			getline(cin, ndh);
			cout<<"So luong san pham: ";
			cin>>slsp;
			cout<<"Tong tien: ";
			cin>>ttien;
			cout<<"Ty le chiet khau (%): ";
			cin>>tlck;
			ttsck = ttien - (ttien * tlck / 100);
			cin.ignore();
		}
		
		void xuat(){
			cout<<"Ma don hang: "<<mdh<<endl;
			cout<<"Ten khach hang: "<<tkh<<endl;
			cout<<"Ngay dat hang: "<<ndh<<endl;
			cout<<"So luong san pham: "<<slsp<<endl;
			cout<<"Tong tien: "<<ttien<<endl;
			cout<<"Ty le chiet khau: "<<tlck<<"%"<<endl;
			cout<<"Thanh tien sau chiet khau: "<<ttsck<<endl;
		}
		
		void sapxep (DonHang a[], int n){
			for(int i=0; i<n-1; i++){
				for(int j=i+1; j<n; j++){
					if(a[i].ttsck < a[j].ttsck){
						DonHang tam = a[i];
						a[i] = a[j];
						a[j] = tam;
					}
				}
			}
		}
		
		void timkiem (DonHang a[], int n){
			string ma;
			bool timthay = false;

			cout << "Nhap ma don hang can tim: ";
			getline(cin, ma);
			for (int i = 0; i < n; i++) {
				if (a[i].mdh == ma) {
					cout << "\nDon hang duoc tim thay:\n";
					a[i].xuat();
					timthay = true;
					break;
				}
			}
			if (timthay == false) {
				cout << "Khong tim thay don hang!" << endl;
			}
		}

		void bosung (DonHang a[], int*n){
			int vitri;
			cout<<"Vi tri can bo sung: ";
			cin>> vitri;
			if(vitri < 1|| vitri > *n+1){
			cout<<"Gia tri khong hop le: ";
			return;
			}
			for(int i=*n; i>= vitri; i--){
			a[i] = a[i-1];
			}
			cin.ignore();
			cout<<"Nhap don hang moi!\n ";
			a[vitri-1].nhap();
			(*n)++;
		}
		void xoa (DonHang a[], int*n){
			int vitri;
			cout<<"Vi tri can xoa: ";
			cin>> vitri;
			if(vitri < 1|| vitri > *n){
			cout<<"Vi tri khong hop le! ";
			return;
			}
			for(int i= vitri-1; i < *n-1; i++){
			a[i] = a[i+1];
			}
			(*n)--;
		}	
};

int main(){
	DonHang a[200];
	int n;
	do{
		cout<<"Nhap so luong don hang: ";
		cin>> n;
		cin.ignore();
		if (n<=0 || n>200){
		cout<<"So luong khong hop le! \n";
		}
	}while(n<=0 || n>200);
	cout << "\nNhap danh sach don hang: \n";
	for (int i = 0; i < n; i++) {
		cout << "\nDon hang thu " << i + 1 << ":\n";
		a[i].nhap();
	}
	cout << "\nDanh sach don hang: \n";
	for (int i = 0; i < n; i++) {
		cout << "\nDon hang thu " << i + 1 << ":\n";
		a[i].xuat();
	}
	a[0].sapxep(a, n);
	cout << "\nDanh sach sau sap xep: \n";
	for (int i = 0; i < n; i++) {
		cout << "\nDon hang thu " << i + 1 << ":\n";
		a[i].xuat();
	}
	cout << "\nTim kiem don hang: \n";
	a[0].timkiem(a, n);
	cout << "\nBo sung don hang: \n";
	a[0].bosung(a, &n);
	cout << "\nDanh sach sau khi bo sung: \n";
	for (int i = 0; i < n; i++) {
		cout << "\nDon hang thu " << i + 1 << ":\n";
		a[i].xuat();
	}
	cout <<"Xoa don hang: \n";
	a[0].xoa(a, &n);
	cout << "\nDanh sach sau khi xoa: \n";
	for (int i = 0; i < n; i++) {
		cout << "\nDon hang thu " << i + 1 << ":\n";
		a[i].xuat();
	}
	return 0;
}
