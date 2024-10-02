#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int choice, score;
vector<int> v;

int main(){
    while(1){
        cout << "1. show ranking & mean of scores\n";
        cout << "2. Add scores\n";
        cout << "3. Delete a score\n";
        cout << "4. Exit\n\n";
        
        cout << "choice : ";
        cin >> choice;
        
        if(choice == 1){
            cout << "\nScore borad\n\n";
            cout << "====================\n";
            sort(v.rbegin(), v.rend());
            int sum = 0;
            for(int i=0; i<v.size(); i++){
                cout << i+1 << "\t\t" << v[i] << "\n";
                sum += v[i];
            }
            cout << "====================\n";
            cout << "Score mean : " << sum / v.size() << "\n\n";
        }else if(choice == 2){
            while(true){
                cout << "Enter score (0..100) (otherwise exit)\n";
                cout << "score : ";
                cin >> score;
                if(score == -1){
                    cout << "\n";
                    break;
                }
                v.push_back(score);
                cout << "[";
                for(int i=0; i<v.size(); i++){
                    if(i != v.size()-1){
                        cout << v[i] << ",";
                    }else{
                        cout << v[i];
                    }
                }
                cout << "]\n";
            }
        }else if(choice == 3){
            cout << "Enter a score to delete : ";
            cin >> score;
            for(int i=0; i<v.size(); i++){
                if(v[i] == score){
                    v.erase(v.begin()+i);
                    break;
                }
            }
            cout << "\n";
        }else{
            break;
        }
    }
}
