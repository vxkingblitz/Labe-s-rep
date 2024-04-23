//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//#include <sstream>
//
//
//using namespace std;
//class Member
//{
//public:
//    int id;
//    char first_name[255];
//    char middle_name[255];
//    char last_name[255];
//    char phone[25];
//    char date_of_bitrh[25];
//    char duration[10];
//    char price[100];
//};
//
//Member members[100] = {};
//void ReadFromFile() {
//    string line;
//
//    ifstream in("db.txt");
//    if (in.is_open()) {
//        int j = 0;
//        int i = 0;
//        int k = 0;
//        char* newMass_id = new char[10000];
//        while (getline(in, line))
//        {
//            for (i; i < sizeof(members) / sizeof(Member); ) {
//                while (line[j] != '\t') {
//                    newMass_id[j] = (line[j]);
//                    j++;
//                }
//                members[i].id = atoi(newMass_id);
//                j++;
//                while (line[j] != '\t') {
//                    members[i].first_name[k] = line[j];
//                    j++;
//                    k++;
//                }j++;
//                k = 0;
//                while (line[j] != '\t') {
//                    members[i].middle_name[k] = line[j];
//                    j++;
//                    k++;
//                }j++;
//                k = 0;
//                while (line[j] != '\t') {
//                    members[i].last_name[k] = line[j];
//                    j++;
//                    k++;
//                }j++;
//                k = 0;
//                while (line[j] != '\t') {
//                    members[i].phone[k] = line[j];
//                    j++;
//                    k++;
//                }j++;
//                k = 0;
//                while (line[j] != '\t') {
//                    members[i].date_of_bitrh[k] = line[j];
//                    j++;
//                    k++;
//                }j++;
//                k = 0;
//                while (line[j] != '\t') {
//                    members[i].duration[k] = line[j];
//                    j++;
//                    k++;
//                }j++;
//                k = 0;
//                
//                while (line[j] != '\t') { 
//                    if ((j + 1) == size(line)) {
//                        members[i].price[k] = line[j];
//                        members[i].price[k+1] = line[j+1];
//                        break;
//                    }
//                    else {
//                        members[i].price[k] = line[j];
//                        j++;
//                        k++;
//                    }
//                }
//                j = 0;
//                k = 0;
//                i++;
//                
//                break;
//                
//            }
//            
//        }
//        delete[] newMass_id;
//
//    }
//    in.close();
//}
//
//void ShowTable()
//{
//    for (int i = 0; i < sizeof(members) / sizeof(Member); i++)
//    {
//        if (members[i].last_name[0] != '\0')
//        {
//            cout << endl;
//            cout << members[i].id << "\t";
//            cout << members[i].first_name << "\t";
//            cout << members[i].middle_name << "\t";
//            cout << members[i].last_name << "\t";
//            cout << members[i].phone << "\t";
//            cout << members[i].date_of_bitrh << "\t";
//            cout << members[i].duration << "\t";
//            cout << members[i].price << "\t";
//            cout << endl;
//        }
//        else
//        {
//            continue;
//        }
//
//    }
//}
//
//
//
//int main(){
//    ReadFromFile();
//    ShowTable();
//}

