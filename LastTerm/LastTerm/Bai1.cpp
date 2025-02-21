#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NhanVien
{
protected:
	string m_HoTen;
	long m_LuongCoBan;

public:
	NhanVien() : m_HoTen(""), m_LuongCoBan(0) {};
	virtual long tinhLuong()
	{
		return 1;
	}
	virtual void Xuat() = 0;
};


class AnhIT : public NhanVien
{
private:
	long m_LuongBonus;
public:

	AnhIT(string name, long tienluong, long bonus)
	{
		m_HoTen = name;
		m_LuongCoBan = tienluong;
		m_LuongBonus = bonus;
	}

	long tinhLuong()
	{
		return m_LuongBonus + m_LuongCoBan;
	}

	void Xuat()
	{
		cout << "Ho Ten: " << m_HoTen << ", Luong co ban: " << m_LuongCoBan << ", Luong them: " << m_LuongBonus << " .\n";
		cout << "Tong luong: " << tinhLuong() << " .\n";
	}
};

class AnhThietKe : public NhanVien
{
private:
	long m_SanPham;
public:

	AnhThietKe(string name, long tienluong, long sp)
	{
		m_HoTen = name;
		m_LuongCoBan = tienluong;
		m_SanPham = sp;
	}

	long tinhLuong()
	{
		return m_LuongCoBan + m_SanPham * 1500000;
	}

	void Xuat()
	{
		cout << "Ho Ten: " << m_HoTen << ", Luong co ban: " << m_LuongCoBan << ", So san pham da lam: " << m_SanPham << " .\n";
		cout << "Tong luong: " << tinhLuong() << " .\n";
	}
};

int main()
{
	vector<NhanVien*> nv
	{
		new AnhIT("Tai",15000000,5000000),
		new AnhIT("Dat",50000000,15000000),
		new AnhIT("Linh", 15000000, 2500000),
		new AnhThietKe("Tien Tai", 10000000, 10),
		new AnhThietKe("Tai Tai", 8000000, 8),
		new AnhThietKe("Tien Tai", 5000000, 5)
	};

	cout << "So nhan vien: " << nv.size() << endl;

	int sum = 0;
	for (int i = 0; i < nv.size(); i++)
	{

		cout << i + 1 << ". ";
		sum += nv[i]->tinhLuong();
		nv[i]->Xuat();
		cout << endl;
	}

	cout << "Tong luong phai tra cho nhan vien: " << sum << endl;
	return 0;
}