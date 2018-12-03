#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

class CPegawai
{
protected:
	char NIP[10];
	char Nama[100];
public:
	CPegawai(char nip[]="", char nama[]="")
	{
		strcpy(NIP,nip);
		strcpy(Nama,nama);
	}
	void SetNIP(char s[])
	{
		strcpy(NIP, s);
	}
	void SetNama(char s[])
	{
		strcpy(Nama, s);
	}
	char* GetNIP()
	{
		return NIP;
	}
	char* GetNama()
	{
		return Nama;
	}
	virtual int HitungGaji() = 0;
	virtual void PrintDetail()
	{
		printf("NIP: %s\n", NIP);
		printf("Nama: %s\n", Nama);
	}
	virtual void Input()
	{
		fflush(stdin);
		printf("NIP: ");
		gets(NIP);
		printf("Nama: ");
		gets(Nama);
	}

	virtual int GetType()
	{
		return 0;
	}

	virtual void WriteToFileStream(fstream &f)
	{
		f<<NIP<<endl;
		f<<Nama<<endl;
	}

};

class CPegawaiTetap: public CPegawai
{
protected:
	int GajiPokok;
public:
	CPegawaiTetap(char nip[]="", char nama[]="", int gaji=0): CPegawai(nip, nama)
	{
		GajiPokok = gaji;
	}
	void SetGajiPokok(int n)
	{
		GajiPokok = n;
	}
	int GetGajiPokok()
	{
		return GajiPokok;
	}
	int HitungGaji()
	{
		return GajiPokok;
	}
	void PrintDetail()
	{
		CPegawai::PrintDetail();
		printf("Gaji Pokok: %d\n", GajiPokok);
	}
	void Input()
	{
		CPegawai::Input();
		printf("Gaji Pokok: ");
		scanf("%d",&GajiPokok);
	}
	int GetType()
	{
		return 1;
	}
	void WriteToFileStream(fstream &f)
	{
		CPegawai::WriteToFileStream(f);
		f<<GajiPokok<<endl;
	}
};

class CManajer: public CPegawaiTetap
{
protected:
	int Tunjangan;
public:
	CManajer(char nip[]="", char nama[]="", int gaji=0, int tunjangan = 0): CPegawaiTetap(nip, nama, gaji)
	{
		Tunjangan = tunjangan;
	}
	void SetTunjangan(int n)
	{
		Tunjangan = n;
	}
	int GetTunjangan()
	{
		return Tunjangan;
	}
	int HitungGaji()
	{
		return GajiPokok + Tunjangan;
	}
	void PrintDetail()
	{
		CPegawaiTetap::PrintDetail();
		printf("Tunjangan: %d\n", Tunjangan);
	}
	void Input()
	{
		CPegawaiTetap::Input();
		printf("Tunjangan: ");
		scanf("%d",&Tunjangan);
	}
	int GetType()
	{
		return 3;
	}
	void WriteToFileStream(fstream &f)
	{
		CPegawaiTetap::WriteToFileStream(f);
		f<<Tunjangan<<endl;
	}
};

class CPegawaiHonorer: public CPegawai
{
protected:
	int JamKerja;
	int GajiPerJam;
public:
	CPegawaiHonorer(char nip[]="", char nama[]="", int jam=0, int gaji =0): CPegawai(nip, nama)
	{
		JamKerja = jam;
		GajiPerJam = gaji;
	}
	void SetJamKerja(int n)
	{
		JamKerja = n;
	}
	int GetJamKerja()
	{
		return JamKerja;
	}
	void SetGajiPerJam(int n)
	{
		GajiPerJam = n;
	}
	int GetGajiPerJam()
	{
		return GajiPerJam;
	}
	int HitungGaji()
	{
		return JamKerja * GajiPerJam;
	}
	void PrintDetail()
	{
		CPegawai::PrintDetail();
		printf("Jam Kerja: %d\n", JamKerja);
		printf("Gaji Per Jam: %d\n", GajiPerJam);
	}
	void Input()
	{
		CPegawai::Input();
		printf("Jam Kerja: ");
		scanf("%d",&JamKerja);
		printf("Gaji Per Jam: ");
		scanf("%d",&GajiPerJam);
	}
	int GetType()
	{
		return 2;
	}
	void WriteToFileStream(fstream &f)
	{
		CPegawai::WriteToFileStream(f);
		f<<GajiPerJam<<endl;
		f<<JamKerja<<endl;
	}
};

class CDepartment
{
protected:
	CPegawai* data[100];
	int count;
public:
	CDepartment()
	{
		count = 0;
	}
	void AddPegawai(CPegawai *p)
	{
		if(count < 100)
		{
			data[count] = p;
			++count;
		}
	}
	void ViewAll()
	{
		for(int i=0;i<count;i++)
		{
			data[i]->PrintDetail();
			printf("-------------------------------\n");
		}
	}

	void SaveData(char filename[])
	{
		fstream file(filename, ios::out);
		if(file.is_open())
		{
			file<<count<<endl;
			for(int i=0;i<count;i++)
			{
				file<<data[i]->GetType()<<endl;
				data[i]->WriteToFileStream(file);
			}
			file.close();
		}
	}

	void LoadData(char filename[])
	{
		ofstream file(filename, ios::out);
		if (file.is_open())
		{
			file << count << endl;
			for (int i = 0; i<count; i++)
			{
				file << data[i]->GetType() << endl;
				
			}
			file.close();
		}
	}
	virtual void readfromfilestream(fstream &f)
	{
		f>>NIP;
		f>>NAMA;
	}
};


void main()
{
	//fstream file, output;

	//file.open("coba.txt", ios::out);

	//if(file.is_open())
	//{
	//	file<<"PBO Gampang!!!"<<endl;
	//	int n = 12345;
	//	file<<n<<endl;

	//	file.close();
	//}
	//else
	//	cout<<"File gagal dibuka..."<<endl;



	/*file.open("input.txt", ios::in);
	output.open("output.txt", ios::out);

	if(file.is_open() && output.is_open())
	{
		int total,n1,n2,n3,n4,n5;
		
		while(!file.eof())
		{
			file >> n1 >> n2 >> n3 >> n4 >> n5;
			if(file.fail())
				break;
			total = n1 + n2 + n3 + n4 + n5;
			output<< total / 5 << endl;
		}
		
	}
	else
		cout<<"File gagal dibuka..."<<endl;

	file.close();
	output.close();*/

	
	int chc=0;
	CDepartment d;
	do
	{
		system("CLS");
		cout<<"Menu: "<<endl;
		cout<<"1. Input Pegawai"<<endl;
		cout<<"2. View All Pegawai"<<endl;
		cout<<"3. Save Data"<<endl;
		cout<<"4. Load Data"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Choice: ";
		cin>>chc;
		if(chc==1)
		{
			system("CLS");
			int tipe=0;
			CPegawai *p=NULL;
			cout<<"Tipe Pegawai (1. Tetap, 2. Honorer, 3. Manajer): ";
			cin>>tipe;
			if(tipe==1)
				p = new CPegawaiTetap();
			else if(tipe==2)
				p = new CPegawaiHonorer();
			else if(tipe == 3)
				p = new CManajer();

			if(p)
			{
				p->Input();
				d.AddPegawai(p);
			}
			getch();
		}
		else if(chc==2)
		{
			system("CLS");
			d.ViewAll();
			getch();
		}
		else if(chc==3)
		{
			system("CLS");
			cout<<"Filename: ";
			char filename[256];
			fflush(stdin);
			cin.getline(filename,255);
			d.SaveData(filename);
		}
		else if(chc==4)
		{
			system("CLS");
			cout<<"Filename: ";
			char filename[256];
			fflush(stdin);
			cin.getline(filename,255);
			d.LoadData(filename);
		}
	}while(chc!=5);
}