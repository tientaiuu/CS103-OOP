#define _CRT_SECURE_NO_WARNINGS
#include "CStore.h"
#include <locale>
#include <codecvt>

void CStore::Input()
{
	while (!cin.eof())
	{

		CProduct* prod = new CProduct;
		char c;
		c = cin.peek();
		if (c == 'E')
		{
			prod = new CElectronic;
		}

		if (c == 'F')
		{
			prod = new CFood;
		}

		if (c == 'T')
		{
			prod = new CTerracotta;
		}
		prod->Input();
		m_products.push_back(prod);
	}
}

void CStore::Output()
{
	wstring str = L" Mặt hàng: \n";
	wstring_convert<codecvt_utf8<wchar_t>> converter;

	cout << m_products.size() << converter.to_bytes(str);
	for (int i = 0; i < m_products.size(); i++)
	{
		cout << i + 1 << ". ";
		m_products[i]->Output();
		cout << endl;
	}
}

void CStore::ViewExpDate()
{
	for (const auto& product : m_products)
	{
		CFood* foodProduct = dynamic_cast<CFood*>(product);
		if (foodProduct)
		{
			time_t now = time(0);
			struct tm* currentTime = localtime(&now);
			CMyDate currentDate(currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900);

			if (currentDate > foodProduct->getExp())
			{
				cout << foodProduct->getCode() << ", " << foodProduct->getName() << ", "
					<< foodProduct->getQuantity() << ", " << foodProduct->getExp() << std::endl;
			}
		}
	}

}
std::string GetDayOfWeek(int wday) 
{
	const string daysOfWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return daysOfWeek[wday];
}

void CStore::Buy()
{
	cin.clear();

	string customerCode;
	getline(cin, customerCode);

	time_t now = time(0);
	tm* currentTime = localtime(&now);
	CMyDate currentDate(currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900);
	string currentDayOfWeek = GetDayOfWeek(currentTime->tm_wday); 

	cout << customerCode << endl;
	cout << put_time(currentTime, "%H:%M:%S %A %d/%m/%Y") << endl;

	double totalAmount = 0.0;
	double totalDiscount = 0.0;
	int itemCount = 1;
	string line;
	while (getline(cin, line))
	{
		if (line.empty()) continue;

		stringstream ss(line);
		string code, name;
		int quantity;

		getline(ss, code, ',');
		ss.ignore(); 
		getline(ss, name, ',');
		ss.ignore(); 
		ss >> quantity;

		for (auto product : m_products) 
		{
			if (product->getCode() == code)
			{
				if (product->getQuantity() < quantity)
				{
					wstring str = L"Số lượng sản phẩm trong kho không đủ:  ";
					wstring_convert<codecvt_utf8<wchar_t>> converter;
					cout << converter.to_bytes(str)  << product->getName() << endl;
					continue;
				}

				double subtotal = product->getPrice() * quantity;
				totalAmount += subtotal;
				cout << itemCount++ << ". " << product->getCode() << ", " << product->getName() << ": " 
					<< quantity << " x " << product->getPrice() << " = " << fixed << setprecision(0) << subtotal << " VND" << endl;
				
				double discount = 0.0;
				if (dynamic_cast<CFood*>(product) && currentDayOfWeek == "Friday")
				{
					discount = subtotal * 0.20; 
				}
				else if (dynamic_cast<CElectronic*>(product) && (currentDayOfWeek == "Tuesday" || currentDayOfWeek == "Wednesday")) 
				{
					discount = subtotal * 0.15;
				}
				else if (dynamic_cast<CTerracotta*>(product) && (currentDayOfWeek == "Saturday" || currentDayOfWeek == "Sunday"))
				{
					discount = subtotal * 0.30; 
				}
				totalDiscount += discount;
				product->setQuantity(product->getQuantity() - quantity);
				break;
			}
			
		}
	}

	double specialDiscount = 0.0;
	if (totalAmount > 5000000)
	{
		specialDiscount = totalAmount * 0.10;
	}
	totalDiscount += specialDiscount;

	wstring str = L"Giảm giá: ";
	wstring_convert<codecvt_utf8<wchar_t>> converter;

	cout << converter.to_bytes(str) << fixed << setprecision(0) << totalDiscount << " VND" << endl;

	wstring str1 = L"Số tiền thanh toán: ";
	wstring_convert<codecvt_utf8<wchar_t>> converter1;
	double finalAmount = totalAmount - totalDiscount;
	cout << converter1.to_bytes(str1) << fixed << setprecision(0) << finalAmount << " VND" << endl;
}

void CStore::ViewQuantity() 
{
	int outOfStockCount = 0;
	vector<CProduct*> outOfStockProducts;

	for (auto product : m_products)
	{
		if (product->getQuantity() == 0)
		{
			outOfStockCount++;
			outOfStockProducts.push_back(product);
		}
	}

	cout << outOfStockCount << endl;

	int itemCount = 1;
	for (auto product : outOfStockProducts)
	{
		cout << itemCount++ << ". " << product->getCode() << ", " << product->getName() << endl;
	}

}

void CStore::Delete() 
{
	cin.clear();
	string codeToDelete;
	cin >> codeToDelete;

	bool found = false;
	for (auto it = m_products.begin(); it != m_products.end(); ++it) {
		if ((*it)->getCode() == codeToDelete) {
			delete* it; // Giải phóng bộ nhớ
			m_products.erase(it); // Xóa khỏi danh sách
			found = true;
			std::cout << "Product " << codeToDelete << " deleted successfully.\n";
			break;
		}
	}
	if (!found) {
		std::cout << "Product " << codeToDelete << " not found.\n";
	}

}