class CPecahan
{
private:
	int pembilang;
	int penyebut;
public:
	CPecahan(int pb=0, int py=1);
	int GetPembilang() const;
	int GetPenyebut() const;
	void SetPembilang(int n);
	void SetPenyebut(int n);
	void Println() const;
	CPecahan operator+(const CPecahan &p) const;
	bool operator>(const CPecahan &p) const;
	void operator+=(const CPecahan &p);
	CPecahan operator =(const CPecahan &p);
	CPecahan operator++();
	CPecahan operator++(int);

	double ToDouble() const;
};