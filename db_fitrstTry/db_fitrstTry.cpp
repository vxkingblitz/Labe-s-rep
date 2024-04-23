#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Member
{
public:
	int id;
	char first_name[255];
	char middle_name[255];
	char last_name[255];
	char phone[25];
	char date_of_bitrh[25];
    char duration[10];
    char price[100];
};

Member members[100] = {};

void AddMember()
{
    for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
    {
        if (members[i].last_name[0] == '\0')
        {
            cout << "Vvedite imia" << endl;
            cin >> members[i].first_name;
            cout << "Vvedite otchestvo" << endl;
            cin >> members[i].middle_name;
            cout << "Vvedite familiy" << endl;
            cin >> members[i].last_name;
            cout << "Vvedite nomer telephona" << endl;
            cin >> members[i].phone;
            cout << "Vvedite daty roshdenia" << endl;
            cin >> members[i].date_of_bitrh;
            cout << "VVedite prodol abon" << endl;
            cin >> members[i].duration;
            cout << "Vvedite price" << endl;
            cin >> members[i].price;
            cout << endl;
            break;
        }
    }
}

void DeleteMember()
{
    x:
        int IdToDel = -1;
        cout << "Vvedite id udalyaemogo elementa" << endl;
        cin >> IdToDel;
        if (IdToDel <= 100 || IdToDel >= 0) {

            for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i].id == IdToDel) {
                    strcpy(members[i].first_name, "");
                    strcpy(members[i].middle_name, "");
                    strcpy(members[i].last_name, "");
                    strcpy(members[i].phone, "");
                    strcpy(members[i].date_of_bitrh, "");
                    strcpy(members[i].duration, "");
                    strcpy(members[i].price, "");
                    break;
                }
            }
        }
        else
        {
            goto x;
        }
}

void ShowTable()
{
    cout << "id\t" << "imia" << setw(20) << "otchestvo" << setw(20) << "familia" << setw(15) << "phone"<< setw(18) << "rojdenie"<< setw(12) << "duration" << setw(10) << "price" << endl;
	for (int i = 0; i < sizeof(members)/sizeof(Member); i++)
	{
        if (members[i].last_name[0] != '\0')
        {
            cout << endl;
            cout << setw(8) << left << members[i].id;
            cout << setw(15) << members[i].first_name;
            cout << setw(22) << members[i].middle_name;
            cout << setw(17) << members[i].last_name;
            cout << setw(15) << members[i].phone;
            cout << setw(15) << members[i].date_of_bitrh;
            cout << setw(12) << members[i].duration;
            cout << members[i].price;
            cout << endl;
        }
        else
        {
            continue;
        }
               
    }
}

void Search() {
    int predel = -1;
    string InfoToFound;
    string InfoToFound_upper;
    string InfoToFound_lower;
    cout << "1.Poisk po vsei tabl" << endl;
    cout << "2.Poisk po verhnimu predelu " << endl;
    cout << "3.Poisk po nizhnemu predelu " << endl;
    cout << "4.Poisk po verhnimu i nizhnemu predelam" << endl;
    cin >> predel;
    switch (predel) {
    case 1:
    {
        cout << "Vvedite chto hotite naiti" << endl;
        cin >> InfoToFound;
        bool flag = false;
        for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
        {
            if (InfoToFound == to_string(members[i].id) || InfoToFound == members[i].first_name || InfoToFound == members[i].middle_name || InfoToFound == members[i].last_name || InfoToFound == members[i].phone || InfoToFound == members[i].date_of_bitrh || InfoToFound == members[i].duration || InfoToFound == members[i].price) {
                cout << "Informajia bila naidena tut: " << endl;
                cout << members[i].id << "\t";
                cout << members[i].first_name << "\t";
                cout << members[i].middle_name << "\t";
                cout << members[i].last_name << "\t";
                cout << members[i].phone << "\t";
                cout << members[i].date_of_bitrh << "\t";
                cout << members[i].duration << "\t";
                cout << members[i].price << "\t";
                cout << endl;
                flag = true;
            }
        }
        if (flag == false) { cout << "Takoi info net" << endl; }
        break;
    }
    case 2:
    {
        cout << "Vvedite verhnii predel" << endl;
        cin >> InfoToFound_upper;
        bool flag = false;
        for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
        {
            if (flag == false) {
                if (InfoToFound_upper == to_string(members[i].id) || InfoToFound_upper == members[i].first_name || InfoToFound_upper == members[i].middle_name || InfoToFound_upper == members[i].last_name || InfoToFound_upper == members[i].phone || InfoToFound_upper == members[i].date_of_bitrh || InfoToFound_upper == members[i].duration || InfoToFound_upper == members[i].price) {
                    cout << members[i].id << "\t";
                    cout << members[i].first_name << "\t";
                    cout << members[i].middle_name << "\t";
                    cout << members[i].last_name << "\t";
                    cout << members[i].phone << "\t";
                    cout << members[i].date_of_bitrh << "\t";
                    cout << members[i].duration << "\t";
                    cout << members[i].price << "\t";
                    cout << endl;
                    flag = true;
                }
            }
            else if (members[i].last_name[0] != '\0') {

                cout << members[i].id << "\t";
                cout << members[i].first_name << "\t";
                cout << members[i].middle_name << "\t";
                cout << members[i].last_name << "\t";
                cout << members[i].phone << "\t";
                cout << members[i].date_of_bitrh << "\t";
                cout << members[i].duration << "\t";
                cout << members[i].price << "\t";
                cout << endl;
            }
        }
        if (flag == false) { cout << "Takoi info net" << endl; }
        break;
    }
    case 3:
    {
        cout << "Vvedite nizhnii predel" << endl;
        cin >> InfoToFound_lower;
        for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
        {

            if (InfoToFound_lower == to_string(members[i].id) || InfoToFound_lower == members[i].first_name || InfoToFound_lower == members[i].middle_name || InfoToFound_lower == members[i].last_name || InfoToFound_lower == members[i].phone || InfoToFound_lower == members[i].date_of_bitrh || InfoToFound_lower == members[i].duration || InfoToFound_lower == members[i].price) {
                cout << members[i].id << "\t";
                cout << members[i].first_name << "\t";
                cout << members[i].middle_name << "\t";
                cout << members[i].last_name << "\t";
                cout << members[i].phone << "\t";
                cout << members[i].date_of_bitrh << "\t";
                cout << members[i].duration << "\t";
                cout << members[i].price << "\t";
                cout << endl;
                break;
            }
            cout << members[i].id << "\t";
            cout << members[i].first_name << "\t";
            cout << members[i].middle_name << "\t";
            cout << members[i].last_name << "\t";
            cout << members[i].phone << "\t";
            cout << members[i].date_of_bitrh << "\t";
            cout << members[i].duration << "\t";
            cout << members[i].price << "\t";
            cout << endl;
        }
        break;
    }
    case 4:
    {
        cout << "Vvedite verhnii predel" << endl;
        cin >> InfoToFound_upper;
        cout << "Vvedite nizhnii predel" << endl;
        cin >> InfoToFound_lower;
        bool flag = false;
        int i = 0;

        for (i; i < sizeof(members) / sizeof(Member); i++)
        {
            if (flag == false)
            {
                if (InfoToFound_upper == to_string(members[i].id) || InfoToFound_upper == members[i].first_name || InfoToFound_upper == members[i].middle_name || InfoToFound_upper == members[i].last_name || InfoToFound_upper == members[i].phone || InfoToFound_upper == members[i].date_of_bitrh || InfoToFound_upper == members[i].duration || InfoToFound_upper == members[i].price)
                {
                    
                    cout << endl;
                    flag = true;
                    break;
                }
            }
        }
        while (flag) {
            if (InfoToFound_lower == to_string(members[i].id) || InfoToFound_lower == members[i].first_name || InfoToFound_lower == members[i].middle_name || InfoToFound_lower == members[i].last_name || InfoToFound_lower == members[i].phone || InfoToFound_lower == members[i].date_of_bitrh || InfoToFound_lower == members[i].duration || InfoToFound_lower == members[i].price) {
                flag = false;
                cout << members[i].id << "\t";
                cout << members[i].first_name << "\t";
                cout << members[i].middle_name << "\t";
                cout << members[i].last_name << "\t";
                cout << members[i].phone << "\t";
                cout << members[i].date_of_bitrh << "\t";
                cout << members[i].duration << "\t";
                cout << members[i].price << "\t";
                cout << endl;
                break;
            }
            cout << members[i].id << "\t";
            cout << members[i].first_name << "\t";
            cout << members[i].middle_name << "\t";
            cout << members[i].last_name << "\t";
            cout << members[i].phone << "\t";
            cout << members[i].date_of_bitrh << "\t";
            cout << members[i].duration << "\t";
            cout << members[i].price << "\t";
            cout << endl;
            if ((i + 1) == (sizeof(members) / sizeof(Member)) - 2) {
                cout << "Nizhnii predel ne naiden" << endl;
                break;
            }
            i++;

        }
        break;
    }
    }
      
}

void SortFormBigToSmall() {
    int ColToSort = -1;
    cout << "0.id(reverse)" << endl;
    cout << "1.imia" << endl;
    cout << "2.otchestvo" << endl;
    cout << "3.familia" << endl;
    cout << "4.data rojdenia" << endl;
    cout << "5.prod abonement" << endl;
    cout << "6.price" << endl;
    cin >> ColToSort;
    Member timeZone[1] = {};
    switch (ColToSort)
    {
    case 0:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i - 1].id < members[i].id)
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 1:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i - 1].first_name[0] < members[i].first_name[0])
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 2:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i - 1].middle_name[0] < members[i].middle_name[0])
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 3:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i - 1].last_name[0] < members[i].last_name[0])
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 4:
    {

        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                char ch_year[] = { members[i - 1].date_of_bitrh[6], members[i - 1].date_of_bitrh[7], members[i - 1].date_of_bitrh[8], members[i - 1].date_of_bitrh[9] };
                char ch_year_2[] = { members[i].date_of_bitrh[6], members[i].date_of_bitrh[7], members[i].date_of_bitrh[8], members[i].date_of_bitrh[9] };
                if (atoi(ch_year) > atoi(ch_year_2)) {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
                else if (atoi(ch_year) == atoi(ch_year_2)) {
                    char ch_month[] = { members[i - 1].date_of_bitrh[3], members[i - 1].date_of_bitrh[4] };
                    char ch_month_2[] = { members[i].date_of_bitrh[3], members[i].date_of_bitrh[4] };
                    if (atoi(ch_month) > atoi(ch_month_2)) {
                        swap(members[i - 1], members[i]);
                        swapped = true;
                    }
                    else if (atoi(ch_month) == atoi(ch_month_2)) {
                        char ch_day[] = { members[i - 1].date_of_bitrh[0], members[i - 1].date_of_bitrh[1] };
                        char ch_day_2[] = { members[i].date_of_bitrh[0], members[i].date_of_bitrh[1] };
                        if (atoi(ch_day) > atoi(ch_day_2)) {
                            swap(members[i - 1], members[i]);
                            swapped = true;
                        }
                    }
                }
            }

            if (swapped == false)
                break;
        }
        break;


    }
    case 5:
    {


        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                int duration_1 = atoi(members[i - 1].duration);
                int duration_2 = atoi(members[i].duration);
                if (duration_1 < duration_2)
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;


    }
    case 6:
    {


        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                int price_1 = atoi(members[i - 1].price);
                int price_2 = atoi(members[i].price);
                if (price_1 < price_2)
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;

    }
    default:
        cout << "Takoi komandi net" << endl;
    }
}

void SortFromSmallToBig() {
    int ColToSort = -1;
    cout << "0.id" << endl;
    cout << "1.imia" << endl;
    cout << "2.otchestvo" << endl;
    cout << "3.familia" << endl;
    cout << "4.data rojdenia" << endl;
    cout << "5.prod abonement" << endl;
    cout << "6.price" << endl;
    cin >> ColToSort;
    Member timeZone[1] = {};
    switch (ColToSort) 
    {
    case 0:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i - 1].id > members[i].id)
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 1:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i-1].first_name[0] > members[i].first_name[0])
                {
                    swap(members[i-1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 2:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i - 1].middle_name[0] > members[i].middle_name[0])
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 3:
    {
        while (sizeof(members) / sizeof(Member))
        {
            bool swapped = false;

            for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
            {
                if (members[i - 1].last_name[0] > members[i].last_name[0])
                {
                    swap(members[i - 1], members[i]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        break;
    }
    case 4:
    {
        
            while (sizeof(members) / sizeof(Member))
            {
                bool swapped = false;

                for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
                {
                    char ch_year[] = { members[i-1].date_of_bitrh[6], members[i-1].date_of_bitrh[7], members[i-1].date_of_bitrh[8], members[i-1].date_of_bitrh[9] };
                    char ch_year_2[] = { members[i].date_of_bitrh[6], members[i].date_of_bitrh[7], members[i].date_of_bitrh[8], members[i].date_of_bitrh[9] };
                    if (atoi(ch_year) < atoi(ch_year_2)) {
                        swap(members[i - 1], members[i]);
                        swapped = true;
                    }
                    else if (atoi(ch_year) == atoi(ch_year_2)) {
                        char ch_month[] = { members[i-1].date_of_bitrh[3], members[i-1].date_of_bitrh[4] };
                        char ch_month_2[] = { members[i].date_of_bitrh[3], members[i].date_of_bitrh[4] };
                        if (atoi(ch_month) < atoi(ch_month_2)) {
                            swap(members[i - 1], members[i]);
                            swapped = true;
                        }
                        else if (atoi(ch_month) == atoi(ch_month_2)) {
                            char ch_day[] = { members[i-1].date_of_bitrh[0], members[i-1].date_of_bitrh[1] };
                            char ch_day_2[] = { members[i].date_of_bitrh[0], members[i].date_of_bitrh[1] };
                            if (atoi(ch_day) < atoi(ch_day_2)) {
                                swap(members[i - 1], members[i]);
                                swapped = true;
                            }
                        }
                    }
                }

                if (swapped == false)
                    break;
            }
            break;
            
        
    }
    case 5:
    {
        
        
            while (sizeof(members) / sizeof(Member))
            {
                bool swapped = false;

                for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
                {
                    int duration_1 = atoi(members[i-1].duration);
                    int duration_2 = atoi(members[i].duration);
                    if (duration_1 > duration_2)
                    {
                        swap(members[i - 1], members[i]);
                        swapped = true;
                    }
                }

                if (swapped == false)
                    break;
            }
            break;
        
        
    }
    case 6:
    {
        
            
            while (sizeof(members) / sizeof(Member))
            {
                bool swapped = false;

                for (int i = 1; i < sizeof(members) / sizeof(Member); i++)
                {
                    int price_1 = atoi(members[i-1].price);
                    int price_2 = atoi(members[i].price);
                    if (price_1 > price_2)
                    {
                        swap(members[i - 1], members[i]);
                        swapped = true;
                    }
                }

                if (swapped == false)
                    break;
            }
            break;
        
    }
    default:
        cout << "Takoi komandi net" << endl;
    }
}


void ReadFromFile() {
    string line;

    ifstream in("db.txt");
    if (in.is_open()) {
        int j = 0;
        int i = 0;
        int k = 0;
        char* newMass_id = new char[10000];
        while (getline(in, line))
        {
            for (i; i < sizeof(members) / sizeof(Member); ) {
                while (line[j] != '\t') {
                    newMass_id[j] = (line[j]);
                    j++;
                }
                members[i].id = atoi(newMass_id);
                j++;
                while (line[j] != '\t') {
                    members[i].first_name[k] = line[j];
                    j++;
                    k++;
                }j++;
                k = 0;
                while (line[j] != '\t') {
                    members[i].middle_name[k] = line[j];
                    j++;
                    k++;
                }j++;
                k = 0;
                while (line[j] != '\t') {
                    members[i].last_name[k] = line[j];
                    j++;
                    k++;
                }j++;
                k = 0;
                while (line[j] != '\t') {
                    members[i].phone[k] = line[j];
                    j++;
                    k++;
                }j++;
                k = 0;
                while (line[j] != '\t') {
                    members[i].date_of_bitrh[k] = line[j];
                    j++;
                    k++;
                }j++;
                k = 0;
                while (line[j] != '\t') {
                    members[i].duration[k] = line[j];
                    j++;
                    k++;
                }j++;
                k = 0;

                while (line[j] != '\t') {
                    if ((j + 1) == size(line)) {
                        members[i].price[k] = line[j];
                        members[i].price[k + 1] = line[j + 1];
                        break;
                    }
                    else {
                        members[i].price[k] = line[j];
                        j++;
                        k++;
                    }
                }
                j = 0;
                k = 0;
                i++;

                break;

            }

        }
        delete[] newMass_id;

    }
    in.close();
}

void WriteToFile() {
    ReadFromFile();
    ofstream out;
    out.open("db.txt");
    if (out.is_open()) {
        for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
        {
            if (members[i].last_name[0] != '\0')
            {
                out << members[i].id << "\t";
                out << members[i].first_name << "\t";
                out << members[i].middle_name << "\t";
                out << members[i].last_name << "\t";
                out << members[i].phone << "\t";
                out << members[i].date_of_bitrh << "\t";
                out << members[i].duration << "\t";
                out << members[i].price << "\t";
                out << endl;
            }
            else
            {
                continue;
            }

        }
    }
    out.close();
}

void PreSort()
{
    int ReverseOrNot = -1;
    cout << "1.FromSmallToBig" << endl;
    cout << "2.FromBigToSmall" << endl;
    cin >> ReverseOrNot;

    switch (ReverseOrNot) {

    case 1: {
        SortFromSmallToBig();
        break;
    }
    case 2: {
        SortFormBigToSmall();
        break;
    }
    default:
        cout << "Takoi comandi net" << endl;
    }

    
}

void InitMenu() {
    while (true)
    {
        cout << "1.Dobavit" << endl;
        cout << "2.Udalit" << endl;
        cout << "3.Show all" << endl;
        cout << "4.Sort" << endl;
        cout << "5.Search" << endl;
        cout << "6.Zapis v fail" << endl;
        cout << "7.Chtenie iz faila" << endl;
        cout << endl << endl;
        cout << "Exit" << endl;
        int choose = 0;
        cin >> choose;
        switch (choose)
        {
        case 1: {
            AddMember();
            break;
        }
        case 2: {
            DeleteMember();
            break;
        }
        case 3: {
            ShowTable();
            break;
        }
        case 4: {
            PreSort();
            break;
        }
        case 5: {
            Search();
            break;
        }
        case 6: {
            WriteToFile();
            break;
        }
        case 7: {
            ReadFromFile();
            break;
        }
        case 0: {
            exit(1);
        }
        default:
            cout << "Takoi comandi net" << endl;
        }
    }
}

int main()
{
    for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
    {
        members[i].id = i;
        strcpy(members[i].first_name, "");
        strcpy(members[i].middle_name, "");
        strcpy(members[i].last_name, "");
        strcpy(members[i].phone, "");
        strcpy(members[i].date_of_bitrh, "");
        strcpy(members[i].duration, "");
        strcpy(members[i].price, "");
        
    }
    InitMenu();
}
