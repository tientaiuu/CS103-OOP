#include "Library.h"

// CCatalogue
CCatalogue::CCatalogue(string id, string title, string author, int count) 
    : m_ID(id), m_Title(title), m_Author(author), m_Count(count) {}



// CPaper
CPaper::CPaper(string id, string title, string author, int count, string journal, string year)
    : CCatalogue(id, title, author, count), m_Journal(journal), m_Year(year) {}

void CPaper::Output(ofstream& output) 
{
    output << this->m_ID << ", " << this->m_Title << ", " << this->m_Author << ", " << this->m_Count << ", " << this->m_Journal << ", " << this->m_Year << ".\n\n";
}

// CBook
CBook::CBook(string id, string title, string author, int count, string publisher, string version, string year)
    : CCatalogue(id, title, author, count), m_Publisher(publisher), m_Version(version), m_Year(year) {}

void CBook::Output(ofstream& output)  
{
    output << this->m_ID << ", " << this->m_Title << ", " << this->m_Author << ", " << this->m_Count << ", " << this->m_Publisher << ", " << this->m_Version << ", " << this->m_Year << ".\n\n";
}


// CThesis
CThesis::CThesis(string id, string title, string author, int count, string school, string faculty, string year)
    : CCatalogue(id, title, author, count), m_School(school), m_Faculty(faculty), m_Year(year) {}

void CThesis::Output(ofstream& output) 
{
    output << this->m_ID << ", " << this->m_Title << ", " << this->m_Author << ", " << this->m_Count << ", " << this->m_School << ", " << this->m_Faculty << ", " << this->m_Year << ".\n\n";
}

// CLibrary

CLibrary::~CLibrary()
{
    for (auto item : this->Library)
    {
        delete item;
    }
}

void CLibrary::Delete()
{
    ifstream file("DELETE.TXT");
    if (!file.is_open())
    {
        cout << "Error openning file: DELETE.TXT "  << endl;
        return;
    }

    string id;
    while (getline(file, id))
    {
        for (auto it = Library.begin(); it != Library.end(); )
        {
            if ((*it)->GetID() == id)
            {
                delete* it;
                it = Library.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    file.close();
}

void CLibrary::SortYear() 
{
    sort(this->Library.begin(), this->Library.end(), [](const CCatalogue* a, const CCatalogue* b) {
        return a->GetYear().substr(6, 4) != b->GetYear().substr(6, 4) ? a->GetYear().substr(6, 4) < b->GetYear().substr(6, 4)
            : a->GetYear().substr(3, 2) != b->GetYear().substr(3, 2) ? a->GetYear().substr(3, 2) < b->GetYear().substr(3, 2)
            : a->GetYear().substr(0, 2) < b->GetYear().substr(0, 2);
        });


    ofstream output("SORTYEAR.TXT");
    if (!output.is_open())
    {
        cerr << "Error opening file: SORTYEAR.TXT" << endl;
        return;
    }

    int i = 1;
    for (auto& item : this->Library)
    {
        output << i << ". ";
        item->Output(output);
        i++;
    }

    output.close();
}

void CLibrary::SortCount()
{
    sort(this->Library.begin(), this->Library.end(), [](const CCatalogue* a, const CCatalogue* b) {
        return a->GetCount() < b->GetCount();
        });

    ofstream output("SORTCOUNT.TXT");
    if (!output.is_open())
    {
        cerr << "Error opening file: SORTCOUNT.TXT" << endl;
        return;
    }

    int i = 1;
    for (auto& item : this->Library)
    {
        output << i << ". ";
        item->Output(output);
        i++;
    }

    output.close();
}

void CLibrary::Input()
{
    ifstream input("INPUT.TXT");

    if (!input) {
        cerr << "Error openning file: INPUT.TXT" << endl;
        return;
    }

    int numItems;
    input >> numItems;
    input.ignore();

    for (int i = 0; i < numItems; ++i)
    {
        string id, title, author, publisher, version, school, faculty, journal, year;
        int count;

        getline(input, id);

        char category = id[0];

        switch (category)
        {
        case 'B':
            getline(input, title);
            getline(input, author);
            input >> count;
            input.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(input, publisher);
            getline(input, version);
            getline(input, year);

            this->Library.push_back(new CBook(id, title, author, count, publisher, version, year));
            break;
        case 'P':
            getline(input, title);
            getline(input, author);
            input >> count;
            input.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(input, journal);
            getline(input, year);

            this->Library.push_back(new CPaper(id, title, author, count, journal, year));
            break;
        case 'T':
            getline(input, title);
            getline(input, author);
            input >> count;
            input.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(input, school);
            getline(input, faculty);
            getline(input, year);

            this->Library.push_back(new CThesis(id, title, author, count, school, faculty, year));
            break;
        }
    }

    input.close();
}

void CLibrary::Output()
{
    ofstream output("OUTPUT.TXT");
    if (!output.is_open())
    {
        cerr << "Error opening file: OUTPUT.TXT" << endl;
        return;
    }

    int i = 1;
    for (auto& item : this->Library)
    {
        output << i << ". ";
        item->Output(output);
        i++;
    }

    output.close();
}
