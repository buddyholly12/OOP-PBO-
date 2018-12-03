#include<iostream>
#include<vector>
#include <Windows.h>
#include<math.h>
using namespace std;

class Cbangun{
public:
	Cbangun(){}
	virtual void display(){}
	virtual void input(){}
	virtual float getarea(){return 0;}
	virtual float getperimeter(){return 0;}
};
class CLingkaran:public Cbangun
{
protected:
	int jari,luas,kel;
public:
	CLingkaran()
	{
		jari=1;
	}

	float getarea()
	{
		return luas=jari*jari*3.14;
		
	}
	float getPerimeter()
	{
		kel=2*3.14*jari;
		return kel;
	}
	void display()
	{
		cout<<"Lingkaran:"<<endl;
		cout<<"Luas:"<<getarea()<<endl;
		cout<<"keliling:"<<getPerimeter()<<endl;
	}
	void input()
	{
		cout<<"inputkan jari jari:"<<endl;
		cin>>jari;
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
		return keliling=2*(panjang*lebar);
	}
	void display()
	{
		cout<<"Kotak:"<<endl;
		cout<<"Luas:\t:"<<getarea()<<endl;
		cout<<"keliling:"<<getperimeter()<<endl;
	}
	void input()
	{
		cout<<"inputkan panjang persegipanjang :"<<endl;
		cin>>panjang;
		
		cout<<"inputkan Lebar persegipanjang :"<<endl;
		cin>>lebar;
	}

};
class CSegitiga:public Cbangun
{
	protected:
	int alas,tinggi;
	float luas,keliling;
public:
	CSegitiga()
	{
		alas=0;
		tinggi=0;
	}
	float getarea()
	{
		return luas=0.5*alas*tinggi;
	}
	float getperimeter()
	{
		return keliling=alas*alas*tinggi*tinggi;
	}
	void display()
	{
		cout<<"Segitiga:"<<endl;
		cout<<"Luas:"<<getarea()<<endl;
		cout<<"keliling:"<<getperimeter()<<endl;
	}
	void input()
	{
		cout<<"inputkan Alas :"<<endl;
		cin>>alas;
		cout<<"inputkan tinggi :"<<endl;
		cin>>tinggi;
	}

};

void main()
{
	vector<Cbangun*> bangun;
	Cbangun* temp1;
	//tmp[0] = new CLingkaran();
	//tmp[1] = new CKotak();
	//tmp[2] = new CSegitiga();
	//
	//tmp[0]->input();
	//tmp[1]->input();
	//tmp[2]->input();

	//if(tmp[0]->getarea() > tmp[1]->getarea())
	//{
	//	Cbangun* cadangan = tmp[0];
	//	tmp[0] = tmp[1];
	//	tmp[1] = cadangan;
	//}
	int count;
	int chc=0;
	int idx=0;
	while(chc!=6)
	{
	cout<<"\nMenu:\n1.Addbangun\n2.View bangun\n3.sorting bangun\n4.delete bangun\n5.edit bangun"<<endl;
	cin>>chc;
	//system("cls");
	if(chc==1)
	{
		bangun.push_back(temp1);
		//system("cls");
		int pil=0;
		cout<<"Menu:\n1.Lingkaran\n2.Kotak\n3.Segitiga"<<endl;
		cin>>pil;
		if(pil==1)
		{
			bangun[idx]=new CLingkaran();
			bangun[idx]->input();
			idx++;
		}
		else if(pil==2)
		{
			bangun[idx]=new CKotak();
			bangun[idx]->input();
			idx++;
		}
		else if(pil==3)
		{
			bangun[idx]=new CSegitiga();
			bangun[idx]->input();
			idx++;
		}

	}
	else if(chc==2)
	{
		//system("cls");
		for(int i=0;i<idx;i++)
		{
			bangun[i]->display();
		}
		
	}
	
	else if(chc==4)
	{

		vector<float> temp;
			for (int i = 0; i < bangun.size(); i++)
			{
				temp.push_back(bangun[i]->getarea());
			}
			for (int i = 0; i < temp.size() - 1; i++)
			{
				for (int j = i + 1; j < temp.size(); j++)
				{
					if (temp[i] > temp[j])
					{
						float temp1 = temp[i];
						temp[i] = temp[j];
						temp[j] = temp1;
						Cbangun*tmp = bangun[i];
						bangun[i] = bangun[j];
						bangun[j] = tmp;
					}
				}
			}
	}
	
	else if (chc==3)
	{
		
	}
	else if (chc==5)
	{
		
	}	






	}
}