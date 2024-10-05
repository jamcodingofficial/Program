#include <iostream>
#include <vector>
#include <iomanip> // setprecision을 사용하기 위해 필요
#include <algorithm>

using namespace std;
typedef pair<string, double> psd;

int menu;
string store;
double grade;
vector<psd> vp;

int search_store(string store){
    for(int i=0; i<vp.size(); i++){
        if(vp[i].first == store){
            return i;
        }
    }
    return -1;
}

int main(){
    while(true){
        cout << "1. Show all reviews\n";
        cout << "2. Add cafe review\n";
        cout << "3. Delete cafe review\n";
        cout << "4. Search cafe\n";
        cout << "5. Exit\n";
        cout << "menu : ";
        cin >> menu;
        if(menu == 1){
            cout << "\n Cafe Review\n\n";
            cout << "store\tGrade\n";
            cout << "===============\n"; 
            cout << fixed << setprecision(1); // 소수점 이하 1자리 고정
            for(int i=0; i<vp.size(); i++){
                cout << vp[i].first << "\t\t" << vp[i].second << "\n";
            }
            cout << "===============";
        }else if(menu == 2){
            cout << "Add store : ";
            cin >> store;
            cout << "Grade (1..5) : ";
            cin >> grade;
            vp.push_back({store, grade});
        }else if(menu == 3){
            cout << "Delete store : ";
            cin >> store;
            int idx = search_store(store);
            cout << "idx : " << idx << endl;
            vp.erase(vp.begin()+idx);
            cout << "Delete is completed\n";
        }else if(menu == 4){
            cout << "Search store :";
            cin >> store;
            int idx = search_store(store);
            cout << vp[idx].first << "\t:\t" << vp[idx].second << "\n";
        }else{
            break;
        }
        cout << "\n";
    }
}