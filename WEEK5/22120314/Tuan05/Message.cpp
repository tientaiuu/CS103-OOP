#include "Message.h"

void CMessage::Input(ifstream& fin) 
{
    string phone;
    int vote;
    string date;
    string time;

    // Đọc thông tin tin nhắn
    getline(fin, phone);
    fin >> vote;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(fin, date);
    getline(fin, time);

    CDate messageDate;
    CMyTime messageTime;

    // Phân tách ngày và thời gian từ dữ liệu đọc được
    size_t pos = date.find("/");
    int day = stoi(date.substr(0, pos));
    date.erase(0, pos + 1);
    pos = date.find("/");
    int month = stoi(date.substr(0, pos));
    int year = stoi(date.substr(pos + 1));

    pos = time.find(":");
    int hour = stoi(time.substr(0, pos));
    time.erase(0, pos + 1);
    pos = time.find(":");
    int minute = stoi(time.substr(0, pos));
    int second = stoi(time.substr(pos + 1));

    // Khởi tạo đối tượng CDate và CMyTime
    messageDate = CDate(day, month, year);
    messageTime = CMyTime(hour, minute, second);

    this->m_Number = phone;
    this->m_Vote = vote;
    this->m_Date = messageDate;
    this->m_Time = messageTime;
}



void CMessage::Output(ofstream& fout) 
{
	fout << this->m_Number << endl;
	fout << this->m_Vote << endl;
	this->m_Date.Output(fout);
	this->m_Time.Output(fout);
}


void CListMessage::Input(string& filename) 
{
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    // Xóa danh sách tin nhắn hiện tại (nếu có)
    this->m_Message.clear();

    fin >> this->m_Amount;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Đọc từng tin nhắn từ tệp tin
    for (int i = 0; i < this->m_Amount; i++) 
    {

        CMessage message;
        message.Input(fin);
        this->m_Message.push_back(message);
    }

    fin.close();
}

void CListMessage::Output( string& filename) 
{
	ofstream fout(filename);
	if (!fout.is_open())
    {
		cerr << "Error opening file!" << endl;
		return;
	}
	fout << this->m_Amount << endl;

	 // Ghi từng tin nhắn trong danh sách vào tập tin
	for ( CMessage& message : this->m_Message)
    {
		message.Output(fout);
	}

	fout.close();
}

int CListMessage::FindCode()
{
    map<int, int> voteCounts;

    // Lặp qua danh sách các tin nhắn và tính tổng số lượt bình chọn cho từng mã số
    for (const auto& message : this->m_Message)
    {
        int code = message.GetVote();
        voteCounts[code]++;
    }

    // Tìm mã số vote xuất hiện nhiều nhất
    int maxCount = 0;
    int maxCode = 0;
    for (const auto& codeCount : voteCounts)
    {
        int code = codeCount.first;
        int count = codeCount.second;
        if (count > maxCount)
        {
            maxCount = count;
            maxCode = code;
        }
    }

    // Trả về kết quả
    ofstream fout("Output.txt", ios_base::app);
    fout << maxCode << endl;
    fout.close();

    return maxCode;
}

string CListMessage::FindPhone()
{
    map<string, int> phoneCounts;

    // Duyệt qua danh sách tin nhắn và đếm số lần xuất hiện của mỗi số điện thoại
    for (const CMessage& message : this->m_Message) 
    {
        string phone = message.GetPhoneNumBer();
        phoneCounts[phone]++;
    }

    // Tìm số điện thoại xuất hiện nhiều nhất
    string maxPhone;
    int maxCount = 0;

    for (const auto& entry : phoneCounts) 
    {
        if (entry.second > maxCount)
        {
            maxCount = entry.second;
            maxPhone = entry.first;
        }
    }

    // Trả về số điện thoại xuất hiện nhiều nhất
    ofstream fout("Output.txt", ios_base::app);
    fout << maxPhone << endl;
    fout.close(); 

    return maxPhone;
}

CDate CListMessage::FindDay()
{
    vector<pair<CDate, int>> messageCounts;

    for (const CMessage& message : this->m_Message) 
    {
        CDate date = message.GetDate();

        bool found = false;
        for (auto& entry : messageCounts) 
        {
            if (entry.first == date) {
                entry.second++;
                found = true;
                break;
            }
        }

        if (!found) 
        {
            messageCounts.push_back(make_pair(date, 1));
        }
    }

    CDate maxDate;
    int maxCount = 0;

    for (const auto& entry : messageCounts)
    {
        if (entry.second > maxCount)
        {
            maxCount = entry.second;
            maxDate = entry.first;
        }
    }

    ofstream fout("Output.txt", ios_base::app);

    maxDate.Output(fout);
    fout.close();

    return maxDate;
}

CMyTime CListMessage::FindTime()
{
    vector<pair<CMyTime, int>> messageCounts;

    for (const CMessage& message : this->m_Message) 
    {
        CMyTime time = message.GetTime();
        bool found = false;

        for (pair<CMyTime, int>& entry : messageCounts)
        {
            if (entry.first == time) {
                entry.second++;
                found = true;
                break;
            }
        }

        if (!found) {
            messageCounts.push_back(std::make_pair(time, 1));
        }

    }
    CMyTime maxTime;
    int maxCount = 0;

    for (const std::pair<CMyTime, int>& entry : messageCounts) 
    {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            maxTime = entry.first;
        }

    }
    
    ofstream fout("Output.txt", ios_base::app);
    maxTime.Output(fout);
    fout.close();

    return maxTime;
}

void CListMessage::Top10()
{
    map<int, int> voteCounts;

    // Lặp qua danh sách các tin nhắn và tính tổng số lượt bình chọn cho từng mã số
    for (const auto& message : this->m_Message)
    {
        int code = message.GetVote();
        voteCounts[code]++;
    }

    // Tạo một vector chứa thông tin về mã số và số lượt bình chọn
    vector<pair<int, int>> voteCounts_2(voteCounts.begin(), voteCounts.end());

    // Sắp xếp vector codeCounts theo số lượt bình chọn giảm dần
    sort(voteCounts_2.begin(), voteCounts_2.end(), [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

    // In ra top 10 mã số được bình chọn nhiều nhất
    ofstream fout("Output.txt", ios_base::app);
    cout << "Top 10:\n";
    fout << "Top 10:\n";
    int count = 0;
    for (const auto& voteCount : voteCounts_2)
    {
        cout << voteCount.first << " - Votes: " << voteCount.second << endl;
        fout << voteCount.first << " - Votes: " << voteCount.second << endl;
        count++;
        if (count == 10)
            break;
    }
    fout.close();

}

