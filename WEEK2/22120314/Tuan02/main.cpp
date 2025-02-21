#include "IntArray.h"

int main()
{
	CIntArray arr(6);

	arr.InputArray();
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;
	cout << "Xoa phan tu trung nhau: " << endl;
	arr.Remove();
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;
	cout << "Xoa tai vi tri bat ky ( vi tri so 3 ): " << endl;
	arr.Remove(3);
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;
	cout << "Thay the tat ca gia tri cu bang gia tri moi: ( 4, 13) " << endl;
	arr.Replace(4, 13);
	arr.OutputArray();
	cout << "-------------------------------------------" << endl;
	cout << "Add Head (13) : ";
	arr.AddHead(13);
	arr.OutputArray();

	cout << "Add Tail (20) : ";

	arr.AddTail(20);
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;
	cout << "Them vao vi tri k (value:10, k = 5 ):" << endl;
	arr.Insert(10,5);
	arr.OutputArray();
	 
	cout << " -------------------------------------------" << endl;
	cout << "Max Value: " << arr.Max() << endl;
	cout << "Min Value: " << arr.Min() << endl;

	cout << " -------------------------------------------" << endl;

	cout << "Ascending: ";
	arr.Ascending();
	arr.OutputArray();

	cout << "Descending: ";
	arr.Descending();
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;

	if (arr.IsSymmetry() == true) cout << "Symmetry!" << endl;
	else cout << "Not Symmetry!" << endl;

	cout << "-------------------------------------------" << endl;

	cout << "MoveForward: ";
	arr.MoveForward();
	arr.OutputArray();

	cout << "MoveForward (2):";
	arr.MoveForward(2);
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;

	cout << "MoveBehind: ";
	arr.MoveBeHind();
	arr.OutputArray();

	cout << "MoveBehind (2): ";
	arr.MoveBeHind(2);
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;

	cout << "Invert: ";
	arr.Invert();
	arr.OutputArray();

	cout << "-------------------------------------------" << endl;

	cout << "Appearance (5): " << arr.Appearance(5) << endl;

}