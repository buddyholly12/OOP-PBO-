#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void main()
{
	
	fstream file;
	// 
	////file.open("Coba.txt",ios::out); //|ios::binary|ios::app);
	/////*
	//if(file.is_open())
	//{
	//	file<<"Pbo gampang";
	//	int m=12345;
	//	file<<m<<endl;
	//	file.close();
	//}
	//else
	//	cout<<"File can't open"<<endl;
	//*/
	//
	///*file.open("data.txt",ios::in);
	//if (file.is_open())
	//{
	//	int m,n;
	//	file>>m>>n;
	//	cout<<"m:"<<m<<"\tN:"<<n<<endl;
	//	file.close();
	//}
	//else
	//	cout<<"File can't open"<<endl;*/

	////string mode
	////file.open("data.txt",ios::in);
	////if (file.is_open())
	////{
	////	int m,n;
	////	char str[256];
	////	while(!file.eof())
	////	{
	////		file.getline(str,255);
	////	cout<<str<<endl;
	////	}
	////	file.close();
	////}
	////else
	////	cout<<"File can't open"<<endl;

/*
		file.open("data1.txt",ios::in);
	if (file.is_open())
	{
		int m,n;
		char str[256];
		while(!file.eof())
		{
			file>>m>>n;
			if(file.fail())
				break;
				cout<<m<<" "<<n<<endl;
		}
		file.close();
	}
	else
		cout<<"File can't open"<<endl;
*/

		file.open("input.txt",ios::in);
		int arr[100][100];
	if (file.is_open())
	{
		int m,n;
		char str[256];
		while(!file.eof())
		{
			
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++)
				{
					file>>arr[i][j];
				}
			}

		}
		file.close();
	}
	else
		cout<<"File can't open"<<endl;

	float hitung[4];
	for(int i=0;i<4;i++)
	{
		hitung[i]=0;
		for(int j=0;j<4;j++)
		{
			hitung[i]=hitung[i]+arr[i][j];
		}
		hitung[i]=hitung[i]/5;
	}

	file.open("Output.txt",ios::out);
	if (file.is_open())
	{
		for(int i=0;i<4;i++)
		{
			file<<hitung[i]<<endl;
			cout<<hitung[i]<<endl;
		}

		file.close();
	}
	else
		cout<<"File can't open"<<endl;

}