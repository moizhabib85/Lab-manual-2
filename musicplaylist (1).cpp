#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct song{
	int id;
	int duration;
	string title;
	string artist;
	song*p;
	song*n;
};
class doubly{
	private:
	song*start,*curr,*temp;
	public:
		doubly(){
			start=NULL;
		}
		void insert(){
			if(start==NULL){
				start=new song;
				cout<<"Enter the ID:";
				cin>>start->id;
				cout<<"Enter duration:";
				cin>>start->duration;
				cout<<"Enter the title:";
				cin>>start->title;
				cout<<"Enter the Artist:";
				cin>>start->artist;
				start->p=NULL;
				start->n=NULL;
			}
			else{
				curr=start;
				while(curr->n!=NULL){
					curr=curr->n;
				}
				temp=new song;
				cout<<"Enter the ID:";
				cin>>temp->id;
				cout<<"Enter duration:";
				cin>>temp->duration;
				cout<<"Enter the title:";
				cin>>temp->title;
				cout<<"Enter the Artist:";
				cin>>temp->artist;
				temp->n=NULL;
				temp->p=curr;
				curr->n=temp;
			}
		}
		void displaysong(){
			curr=start;
			while(curr->n!=NULL){
				cout<<curr->id<<endl;
				cout<<curr->duration<<endl;
				cout<<curr->title<<endl;
				cout<<curr->artist<<endl;
				curr=curr->n;
			}
			cout<<curr->id<<endl;
				cout<<curr->duration<<endl;
				cout<<curr->title<<endl;
				cout<<curr->artist<<endl;
		}
		void search(){
        int choice;
        cout<<"1.Title:";
        cout<<"2.Artist";
        cout<<"Enter choice:";
        cin>>choice;
        temp=start;
        if(choice==1){
            string t;
            cout<<"Enter title: ";
            cin>>t;
            while(temp!=NULL){
                if(temp->title==t){
                    cout<<temp->id<<endl;
                    cout<<temp->duration<<endl;
                    cout<<temp->title<<endl;
                    cout<<temp->artist<<endl;
                }
                temp=temp->n;
            }
        }
        else if(choice==2){
            string a;
            cout<<"Enter artist: ";
            cin>>a;
            while(temp!=NULL){
                if(temp->artist==a){
                    cout<<temp->id<<endl;
                    cout<<temp->duration<<endl;
                    cout<<temp->title<<endl;
                    cout<<temp->artist<<endl;
                }
                temp=temp->n;
            }
        }
            cout<<"Song not found"<<endl;
    }
    void modify(){
        int m;
        cout<<"Enter Song ID to modify: ";
        cin>>m;

        curr=start;
        while(curr!=NULL){
            if(curr->id==m){
                cout<<"Enter new title: ";
                cin>>curr->title;
                cout<<"Enter new artist: ";
                cin>>curr->artist;
                cout<<"Enter new duration: ";
                cin>>curr->duration;
                cout<<"Record Updated"<<endl;
            }
            curr=curr->n;
        }
        cout<<"Song not found"<<endl;
    }
    void playnext(){
        if(curr==NULL){
        	curr=start;
		}
        else if(curr->n!=NULL){
            curr=curr->n;
        }
        if(curr!=NULL){
        cout<<"Playing: ";
		cout<<curr->title;
		cout<<curr->artist<<endl;
        }
        else{
            cout<<"Playlist Empty"<<endl;
        }
    }
    void playprevious(){
        if(curr!=NULL&&curr->p!=NULL){
            curr=curr->p;
            cout<<"Playing: ";
			cout<<curr->title;
			cout<<curr->artist<<endl;
        }
        else{
            cout<<"No Previous Song"<<endl;
        }
    }
};
int main(int argc, char** argv) {
	doubly d;
    int choice;
    do{
        cout<<"1.Insert"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Modify"<<endl;
        cout<<"5.Play Next"<<endl;
        cout<<"6.Play Previous"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>choice;
        switch(choice){
        case 1:
        	d.insert();
			break;
		case 2:
			d.displaysong();
		    break;
        case 3:
		    d.search();
			break;
        case 4:
		    d.modify();
		    break;
        case 5:
		    d.playnext();
			break;
        case 6:
		    d.playprevious(); 
			break;
        }
    }
	while(choice!=7);
	return 0;
}
