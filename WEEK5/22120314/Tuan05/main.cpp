#include "Message.h"

int main()
{
    string filein= "Input.txt";
    string fileout = "Output.txt";
    CListMessage listMessage;

    // Đọc danh sách tin nhắn từ file
    listMessage.Input(filein);

    // Xuất danh sách tin nhắn ra file
   // listMessage.Output(fileout);

    // In ra màn hình và ghi vào file mã số được nhiều người bình chọn nhất
    cout << listMessage.FindCode() << endl;

    // In ra màn hình và ghi vào file sdt nhắn tin nhiều nhất
    cout << listMessage.FindPhone() << endl;

    // In ra màn hình và ghi vào file ngày có nhiều người nhắn tin nhất
    listMessage.FindDay().OutputDate();

    // In ra màn hình và ghi vào file thời điểm có nhiều người bình chọn nhất.
    listMessage.FindTime().OutputTime();

    // In ra màn hình và ghi vào file Top 10 mã số được bình chọn nhiều nhất.
    listMessage.Top10();
}