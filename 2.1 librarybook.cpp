#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct book{
	int isbn;
	int year;
	string title;
	string author;
	book*p;
	book*n;
};
class doubly{
	private:
		book*start,*curr,*temp;
		public:
		doubly(){
			start=NULL;
		}
		void insert(){
			if(start==NULL){
				start=new book;
				cout<<"Enter ISBN:";
				cin>>start->isbn;
				cout<<"Enter year:";
				cin>>start->year;
				cout<<"Enter title:";
				cin>>start->title;
				cout<<"Enter Author:";
				cin>>start->author;
				start->p=NULL;
				start->n=NULL;
			}
			else{
				curr=start;
				while(curr->n!=NULL){
					curr=curr->n;
				}
				temp=new book;
				cout<<"Enter ISBN:";
				cin>>temp->isbn;
				cout<<"Enter year:";
				cin>>temp->year;
				cout<<"Enter title:";
				cin>>temp->title;
				cout<<"Enter Author:";
				cin>>temp->author;
				temp->n=NULL;
				temp->p=curr;
				curr->n=temp;
			}
		}
		void search(){
			int x;
			cout<<"Enter ISBN to search:  ";
			cin>>x;
			
			temp=start;
			while(temp!=NULL){
				if(temp->isbn==x){
					cout<<"book found"<<endl;
					cout<<temp->isbn<<endl;
					cout<<temp->year<<endl;
					cout<<temp->title<<endl;
					cout<<temp->author<<endl;
				}
				temp=temp->n;
			}
			cout<<"book not found"<<endl;
		}
		void modify(){
			int w;
			cout<<"Enter ISBN to modify:  ";
			cin>>w;
			temp=start;
			while(temp!=NULL){
				if(temp->isbn==w){
				cout<<"Enter new title:";
				cin>>temp->title;
				cout<<" Enter new year:";	
				cin>>temp->year;
				cout<<"Enter new author";
				cin>>temp->author;
				cout<<"Record update"<<endl;
				}
				temp=temp->n;
				
			}
			cout<<"book not found"<<endl;
		}
		void display(){
			cout<<"Data in book"<<endl;
			curr=start;
			while(curr->n!=NULL){
				cout<<curr->isbn<<endl;
				cout<<curr->year<<endl;
				cout<<curr->title<<endl;
				cout<<curr->author<<endl;
				curr=curr->n;
			}
			cout<<curr->isbn<<endl;
				cout<<curr->year<<endl;
				cout<<curr->title<<endl;
				cout<<curr->author<<endl;
		}
};
int main(int argc, char** argv) {
	doubly d;
	int choice;
	do{
		cout<<"1. INSERT"<<endl;
		cout<<"2. SEARCH"<<endl;
		cout<<"3. MODIFY"<<endl;
		cout<<"4. DISPLAY"<<endl;
		cout<<"5. EXIT"<<endl;
		cout<<"PLEASE CHOOSE AN OPTION:";
		cin>>choice;
	
	switch(choice){
		case 1:
		d.insert();
		break;
        case 2:
		d.search();
		break;
        case 3:
		d.modify();
		break;
        case 4:
		d.display();
		break;
        case 5:
        cout<<"Exiting.."<<endl;
		break;
        default:
		cout << "Invalid Choice";
		break;
		}
		}
		while(choice!=5);
	return 0;
}
