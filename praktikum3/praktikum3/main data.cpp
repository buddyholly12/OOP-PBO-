#include<iostream>
#include<vector>
#include <Windows.h>
#include<fstream>
using namespace std;

class Cbangun{
public:
	Cbangun(){}
	virtual void display(){}
	virtual void input(){}
	virtual float getarea(){return 0;}
	virtual float getperimeter(){return 0;}
	virtual void to_file(fstream &file){}
	virtual void from_file(fstream &file){}
};
class CLingkaran:public Cbangun
{
protected:
	float jari,luas,kel;
public:
	CLingkaran()
	{
		jari=0;
	}

	float getarea()
	{
		
		return 3.14*jari*jari;
	}
	float getPerimeter()
	{
		
		return 2*3.14*jari;
	}
	void display()
	{
		cout<<"Lingkaran:"<<endl;
		cout<<"Luas:\t"<<jari<<endl;
		cout<<"keliling:\t"<<jari<<endl;
	}
	void input()
	{
		cout<<"inputkan jari jari:"<<endl;
		cin>>jari;
	}
	void to_file(fstream &file)
	{
		file<<"1"<<endl;
		file<<jari<<endl;	
	}
	void from_file(fstream &file)
	{
		if(file.is_open())
		{
			file>>jari;
		}
	}

};
class CKotak:public Cbangun
{
protected:
	float  panjang,lebar,luas,keliling;
public:
	CKotak()
	{
		panjang=0;
		lebar=0;
	}
	float getarea()
	{
		return luas=panjang*lebar;
	}
	float getperimeter()
	{
		return keliling=2*panjang*lebar;
	}
	void display()
	{
		cout<<"Kotak:"<<endl;
		cout<<"Luas:\t"<<panjang<<endl;
		cout<<"keliling:"<<lebar<<endl;
	}
	void input()
	{
		cout<<"inputkan panjang persegipanjang :"<<endl;
		cin>>panjang;
		
		cout<<"inputkan Lebar persegipanjang :"<<endl;
		cin>>lebar;
	}
	void to_file(fstream &file)
	{
		
			file<<"2"<<endl;
			file<<panjang<<endl;
			file<<lebar<<endl;
	}
	void from_file(fstream &file)
	{

		if(file.is_open())
		{
			file>>luas;
			file>>lebar;
		}
	}

};
class CSegitiga:public Cbangun
{
	protected:
	float alas,tinggi;
	float luas,keliling;
public:
	CSegitiga()
	{
		alas=0;
		tinggi=0;
	}
	float getarea()
	{
		return 0.5*alas*tinggi;
	}
	float getperimeter()
	{
		return alas*alas*tinggi*tinggi;
	}
	void display()
	{
		cout<<"Segitiga:"<<endl;
		cout<<"Luas:"<<alas<<endl;
		cout<<"keliling:"<<tinggi<<endl;
	}
	void input()
	{
		cout<<"inputkan Alas :"<<endl;
		cin>>alas;
		cout<<"inputkan tinggi :"<<endl;
		cin>>tinggi;
	}
	void to_file(fstream &file)
	{
			file<<"3"<<endl;
			file<<alas<<endl;
			file<<tinggi<<endl;
		
	}
	void from_file(fstream &file)
	{
		
		if(file.is_open())
		{
			
				file>>alas;
				file>>tinggi;
		}
		file.close();
	}

};



void main()
{
	//vector<Cbangun*>bangun;
	Cbangun* temp;
	int count=0;
	int chc=0;
	int idx=0;
	while(chc!=6)
	{
	cout<<"\tMenu\n1.Addbangun\n2.View bangun\n3.Edit\n4.delete\n5.sort by area"<<endl;
	cin>>chc;
	system("cls");
	if(chc==1)
	{
		fstream file;
		//bangun.push_back(temp);
		system("cls");
		file.open("output.txt",ios::out);
		int pil=0;
		cout<<"Menu:\n1.Lingkaran\n2.Kotak\n3.Segitiga"<<endl;
		cin>>pil;
		if(pil==1)
		{
			temp=new CLingkaran();
			temp->input();
		}
		else if(pil==2)
		{
			temp=new CKotak();
			temp->input();
		}
		else if(pil==3)
		{
			temp=new CSegitiga();
			temp->input();
		}
		temp->to_file(file);
	}
	else if(chc==2)
	{
		fstream file;
		file.open("output.txt",ios::in);
		Cbangun*temp;
		int pil;
		if(file.is_open())
		{
		while(!file.eof())
		{
			file>>pil;
			//cout<<pil;
			if(!file.eof())
			{
				if(pil==1)
					temp=new CLingkaran();
				else if(pil==2)
					temp=new CKotak();
				else if(pil==3)
					temp=new CSegitiga();
				temp->from_file(file);
				temp->display();
			}
			//file.close();
		}
		delete[]temp;
		file.close();
		}
		
	}
	else if (chc==3)
	{	
		vector<Cbangun*>arr;
				int pil=0,indx;
		cout<<"Menu:\n1.Lingkaran\n2.Kotak\n3.Segitiga"<<endl;
		cin>>pil;
		cout<<"index ke:";
		cin>>indx;
		if(pil<0&&indx<0)
		{
			cout<<"index tidak boleh kurang dari 0";
		}
		if(pil==1)
		{
			arr[idx]=new CLingkaran();
			arr[idx]->input();
			indx++;
		}
		else if(pil==2)
		{
			arr[idx]=new CKotak();
			arr[idx]->input();
			indx++;
		}
		else if(pil==3)
		{
			arr[idx]=new CSegitiga();
			arr[idx]->input();
			indx++;
		}
	
	}
	else if(chc==4)
	{
		fstream file;
		vector<Cbangun*>bangun;
		int pil1;
		cin>>pil1;
		file>>pil1;
		while(!file.eof())
		{
			Cbangun*arr[100];
			file>>pil1;
			if(pil1==1)
			{
				temp=new CLingkaran();
			}
			else if(pil1==2){
				temp=new CKotak();}
			else if(pil1==3){
				temp=new CSegitiga();}
			temp->from_file(file);
		}
		delete[]temp;
	}
	else if(chc==5)
	{
			

	}
  }
}