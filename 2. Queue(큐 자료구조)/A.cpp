#include <iostream>
#include <queue>

using namespace std;

int menu;
char item;
queue<char> q;

void print_queue(queue<char> tmp){
    cout << "# State of Queue : [";
    while(!tmp.empty()){
        if(tmp.size() == 1){
            cout << tmp.front();
        }else{
            cout << tmp.front() << ", ";
        }
        tmp.pop();
    }
    cout << "]\n\n";
}

int main(){
    while(1){
        cout << "********** Queue Program **********\n";
        cout << "1. Insert to Queue\n";
        cout << "2. Delete item from Queue\n";
        cout << "3. Print Queue\n";
        cout << "4. Exit\n\n";
        
        cout << "Enter menu : ";
        cin >> menu;
        if(menu == 1){
            cout << "# Enter item to insert : ";
            cin >> item;
            q.push(item);
            cout << "# '" << item << "' is inserted.\n";
            print_queue(q);
        }else if(menu == 2){
            if(!q.empty()){
                cout << "# First item '" << q.front() << "' was removed.\n";
                q.pop();
                print_queue(q);
            }else{
                cout << "# Nothing to delete in queue.\n\n";
            }
        }else if(menu == 3){
            print_queue(q);
        }else{
            break;
        }
    }
}