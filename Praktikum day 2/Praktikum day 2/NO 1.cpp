#include<iostream>
#include<string.h>
#include<Windows.h>
using namespace std;
class pecahan
{
private:
	int pembilang;
	int penyebut;
	int pembilang1;
	int penyebut1;
	int hasil;
		int hasil1;
public:
	pecahan()
	{
		pembilang;
		penyebut;
	}
	void setpembilang(int a)
	{
		pembilang=a;
	}
	int getpembilang()
	{
		return pembilang;
	}
	void setpenyebut(int a)
	{
		penyebut=a;
	}
	int getpenyebut()
	{
		return penyebut;
	}
	void penjumlahan(pecahan n)
	{
		
		int pem=n.getpembilang();
		int pen=n.getpenyebut();
		int pem1=n.getpembilang();
		int pen1=n.getpenyebut();
		hasil=pem*pen1+pen*pem1;
		hasil1=pen*pen1;
	}

	void pengurangan(pecahan n)
	{
		int pem=n.getpembilang();
		int pen=n.getpenyebut();
		int pem1=n.getpembilang();
		int pen1=n.getpenyebut();
		hasil=pem*pen1-pen*pem1;
		hasil1=pen*pen1;
	}
	void perkalian(pecahan n)
	{
		int pem=n.getpembilang();
		int pen=n.getpenyebut();
		int pem1=n.getpembilang();
		int pen1=n.getpenyebut();
		hasil=pem*pen+pen1*pem1;
		hasil1=pen*pen1;
	}
	void pembagian(pecahan n)
	{
		int pem=n.getpembilang();
		int pen=n.getpenyebut();
		int pem1=n.getpembilang();
		int pen1=n.getpenyebut();
		hasil=pem*pen1;
		hasil1=pen*pem1;
	}
	void print()
	{
		cout<<hasil<<"\n--\n";
		cout<<hasil1<<"\n";
	}
};

void main()
{
	int x,y,x1,y1,hasil,chc=0;
	pecahan hitungan;

	while(chc!=5)
	{
	cout<<"Pilihan :"<<endl;
	cout<<"1.penjumlahan"<<endl;
	cout<<"2.pengurangan"<<endl;
	cout<<"3.perkalian"<<endl;
	cout<<"4.pembagian"<<endl;
	cout<<"5.exit"<<endl;
	cin>>chc;
	system("cls");

	if(chc==1)
	{
	cout<<"Masukkan pembilang"<<endl;
	cin>>x;
	cout<<"Masukkan penyebut"<<endl;
	cin>>y;
	cout<<"Masukkan pembilang1"<<endl;
	cin>>x1;
	cout<<"Masukkan penyebut1"<<endl;
	cin>>y1;
	hitungan.setpembilang(x);
	hitungan.setpenyebut(x);
	hitungan.setpembilang(y);
	hitungan.setpenyebut(y);
	hitungan.setpembilang(x1);
	hitungan.setpenyebut(x1);
	hitungan.setpembilang(y1);
	hitungan.setpenyebut(y1);
	hitungan.getpembilang();
	hitungan.getpenyebut();
	hitungan.penjumlahan(hitungan);
	cout<<"hasilnya "<<endl;
	hitungan.print();
	}
	else if(chc==2)
	{
	cout<<"Masukkan pembilang"<<endl;
	cin>>x;
	cout<<"Masukkan penyebut"<<endl;
	cin>>y;
	cout<<"Masukkan pembilang1"<<endl;
	cin>>x1;
	cout<<"Masukkan penyebut1"<<endl;
	cin>>y1;
	hitungan.setpembilang(x);
	hitungan.setpenyebut(x);
	hitungan.setpembilang(y);
	hitungan.setpenyebut(y);
	hitungan.setpembilang(x1);
	hitungan.setpenyebut(x1);
	hitungan.setpembilang(y1);
	hitungan.setpenyebut(y1);
	hitungan.getpembilang();
	hitungan.getpenyebut();
	hitungan.pengurangan(hitungan);
	cout<<"hasilnya "<<endl;
	hitungan.print();
	}
	else if (chc==3)
	{
		cout<<"Masukkan pembilang"<<endl;
	cin>>x;
	cout<<"Masukkan penyebut"<<endl;
	cin>>y;
	cout<<"Masukkan pembilang1"<<endl;
	cin>>x1;
	cout<<"Masukkan penyebut1"<<endl;
	cin>>y1;
	hitungan.setpembilang(x);
	hitungan.setpenyebut(x);
	hitungan.setpembilang(y);
	hitungan.setpenyebut(y);
	hitungan.setpembilang(x1);
	hitungan.setpenyebut(x1);
	hitungan.setpembilang(y1);
	hitungan.setpenyebut(y1);
	hitungan.getpembilang();
	hitungan.getpenyebut();
	hitungan.perkalian(hitungan);
	cout<<"hasilnya "<<endl;
	hitungan.print();
	}
	else if (chc==4)
	{
	cout<<"Masukkan pembilang"<<endl;
	cin>>x;
	cout<<"Masukkan penyebut"<<endl;
	cin>>y;
	cout<<"Masukkan pembilang1"<<endl;
	cin>>x1;
	cout<<"Masukkan penyebut1"<<endl;
	cin>>y1;
	hitungan.setpembilang(x);
	hitungan.setpenyebut(x);
	hitungan.setpembilang(y);
	hitungan.setpenyebut(y);
	hitungan.setpembilang(x1);
	hitungan.setpenyebut(x1);
	hitungan.setpembilang(y1);
	hitungan.setpenyebut(y1);
	hitungan.getpembilang();
	hitungan.getpenyebut();
	hitungan.pembagian(hitungan);
	cout<<"hasilnya "<<endl;
	hitungan.print();
	}
	}

}