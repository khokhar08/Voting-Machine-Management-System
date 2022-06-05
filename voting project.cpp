#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;
int candidate_no=0;
class vote_bank{
	string id ;
	string name; 
	void save_info(){
		ofstream out;
		out.open("vote bank.txt",ios::app);
		out<<id<<"\n";
		out<<name<<"\n";
		out.close();
	}
	void delete_info(){
		string line;int r=0;
		ifstream in("vote bank.txt");
        if (!in.is_open()) {
            cout << "\n\t\t\tInput file failed to open\n";
        }
        ofstream out("outfile.txt");

        while (getline(in,line)) {
            if (line !=id )
                out << line << endl;
                else{
                getline(in,line);
				r=1;}
            }
            
        in.close();
        out.close();
    if(r==0){
    	system("CLS");
    	cout<<"\n\n\t\t\tI'd and name not found\n \nplease try again \n";
	}
	else cout<<"\n\n\t\t\tVoting data is deleted succesfull\n";
        remove("vote bank.txt");
        rename("outfile.txt", "vote bank.txt");
	}
	public:
		vote_bank(){
			id="NULL";
			name="NULL";
		}
		vote_bank(string i,string n){
			id=i;name=n;
		}
	void read_info(string i,string n);
	void delete_file();
	void delete_data(string i,string n);
	void display();
	bool cheak(string n,string i);
};
void vote_bank::read_info(string i,string n){
			id=i;name=n;
			save_info();
		}
void vote_bank::delete_file(){
			remove("vote bank.txt");
		}
void vote_bank::delete_data(string i,string n){
		id=i;name=n;
		delete_info();
	}
void vote_bank::display(){
			string line;
		ifstream in("vote bank.txt");
        if (!in.is_open()) {
            cout << "\n\t\t\tInput file failed to open\n";
        }

        while (getline(in,line)) {
                cout << line << endl;
	    }
	}
bool vote_bank::cheak(string n,string i){
		string line;
		ifstream in("vote bank.txt");
        if (!in.is_open()) {
            cout << "\n\t\t\tInput file failed to open\n";
        }

        while (getline(in,line)) {
               if(i==line){
                	getline(in, line);
                	if(n==line){
                	return 1;
						break;
					}
				}
	    }
	    if(in.eof()!=0){
	    	return 0;
		}
		return 0;
	}
		
class party_record{
		string party ; 
	void save_info(){
		candidate_no++;
		ofstream out;
		out.open("party record.txt",ios::app);
		out<<candidate_no<<". "<<party<<"\n";
		ofstream inewf;
		out.close();
		
	}
	void delete_info(){
		int count=0;
		string line;int r=0;
		ifstream in("party record.txt");
        if (!in.is_open()) {
            cout << "Input file failed to open\n";
        }
        ofstream out("outfile1.txt");

        while (getline(in,line)) {
        	string sub=line.substr(3,line.size());
            if (sub !=party ){
			count++;
                out <<count<<". "<< sub << endl;
            }    else{
				r=1;}
            }
            
        in.close();
        out.close();
    if(r==0){
    	system("CLS");
    	cout<<"\n\n\t\t\tParty name not found\n \n\n\t\t\tplease try again \n";
	}
	else{
	cout<<"\n\n\t\t\tParty data is deleted succesfull\n";candidate_no--;}
        remove("party record.txt");
        rename("outfile1.txt", "party record.txt");
	}
	public:
		
	void read_info(string i);
	void delete_file();
	void delete_data(string i);
	void display();
};
void party_record::read_info(string i){
			party=i;
			save_info();
		}
void party_record::delete_file(){
			remove("party record.txt");
		}
void party_record::delete_data(string i){
		party=i;
		delete_info();
	}
void party_record::display(){
			string line;
		ifstream in("party record.txt");
        if (!in.is_open()) {
            cout << "Input file failed to open\n";
        }
        while (getline(in,line)) {
                cout << line << endl;
	   }
	   in.close();
	}
class voting{
	public:
	   void get_vote(int x);
	   void display_results();
};
void voting::get_vote(int x){
	   	
	   		ifstream infile("party record.txt");
        if (!infile.is_open()) {
            cout << "Input file failed to open\n";
        }
            string line ;        
                while (getline(infile,line)) {
                if(line[0]-'0'==x){
                	line.append(".txt");
					ifstream inewf;
					int n = line.length();
                    char ca[n + 1];
                    strcpy(ca, line.c_str());
                    inewf.open(ca);
                	int vo;
                	if (!inewf.is_open()) {
                		ofstream out(ca);
                		out<<"1";
                		out.close();
                    }
					else{
                	inewf>>vo;
                	inewf.close();
                	vo++;
					ofstream out(ca);
                	out<<vo;
                	out.close();}
                	break;
				}
	   }
	   infile.close();
	   }
void voting::display_results(){
	   	string line;
	   	ifstream infile("party record.txt");
	   	 while (getline(infile,line)) {
                cout<<line;
                	line.append(".txt");
					ifstream inewf;
					int n = line.length();
                    char ca[n + 1];
                    strcpy(ca, line.c_str());
    				inewf.open(ca);
    			    int vo;
					if (!inewf.is_open()) 
                		vo=0;
					else
                	inewf>>vo;
                	cout<<"\t"<<vo<<endl<<endl;
                	inewf.close();
	   }
	   infile.close();
	   }
int main(int argc, char** argv){ 
     ifstream i("candidate count.txt");
     i>>candidate_no;
     i.close();
      start:
	  int x;
	  cout<<"\n\n\t\t\t     *****************************";
cout<<"\n\t\t\t     * WELCOME TO VOTING PROGRAM *";
cout<<"\n\t\t\t     *****************************";
    cout<<"\n\n\n\n\t\t\t*************************************\n\t\t\t* 1. Make new election              *";
	cout<<"\n\t\t\t* 2. Start election                 *";
	cout<<"\n\t\t\t* 3. Want to see result of election *\n\t\t\t* 4. EXIT                           *";
	cout<<"\n\t\t\t*************************************\n\t\t\t";
       cin>>x;
    if(x==1){
    	head:
    	string pass;
    	string user;
    	system("CLS");
    	cout<<"\n\n\t\t\t***********************************************\n\t\t\t";
		cout<<"* This is a window for election officer only *\n\t\t\t***********************************************\n\n";
		cout<<"\t\t\t*************\n";
    	cout<<"\t\t\t* USER NAME *\n\t\t\t*************\n\t\t\t";
    	cin>>user;
    	cout<<"\t\t\t************\n";
    	cout<<"\t\t\t* PASSWARD *\n\t\t\t************\n\t\t\t";
    	cin>>pass;
    	if(pass=="admin@123"&&user=="admin"){
    		system("CLS");
    		cout<<"\n\n\n\t\t\t****************************\n\t\t\t* Welcome to the vote bank *\n\t\t\t****************************\n\n\n";
    		int help;
    		election_comition:
    		cout<<"\n\t\t\t****************************\n\t\t\t* 1. Voter's record        *\n\t\t\t* 2. Candidate's record    *";
			cout<<"\n\t\t\t* 3. Back                  *\n\t\t\t****************************\n\t\t\t";
    		cin>>help;
    		if(help==1){
			vote_bank v;string name;string id;
    		system("CLS");
			cout<<"\t\t\t****************************\n";
cout<<"\t\t\t* 1. New voting record     *\n";
cout<<"\t\t\t* 2. Add new voters        *\n";
cout<<"\t\t\t* 3. Delete voter's record *\n";
cout<<"\t\t\t* 4. Back                  *\n";
cout<<"\t\t\t****************************\n\t\t\t";
    		int n;
    		cin>>n;
    		if(n==1){
			system("CLS");
    			cout<<"\n\t\t\tDo you want to creata new voting record ?\n";
    			cout<<"\n\t\t\tWarning! : if you click yes all record of last election get erase(y/n) : ";
    			char a,b;
    			fflush(stdin);
    			cin>>a;
    			fflush(stdin);
    			if(a=='y'){
    				v.delete_file();
    				read_again:
    				system("CLS");
			        cout<<"\t\t\tEnter the name of voter :\n\t\t\t";
			        getline(cin,name);
			        cout<<"\t\t\tEnter the i'd of voter :\n\t\t\t";
			        cin>>id;
			        v.read_info(id,name);
			        cout<<"\n\t\t\tVoting data is saved succesfull\n";
					 cout<<"\n\t\t\tDo you want to add more data ?(y/n/b), 'b' for Back ";
				    fflush(stdin);
					cin>>b;
					fflush(stdin);
				    if(b=='y'){
					    goto read_again;
				    }
				    else if(b=='b'){
				    	system("CLS");
				    	goto election_comition;
					}
				    else{
				     	system("CLS");
					    goto start;
					}
			   }
			}
            else if(n==2){
            	char b;
            		add_again:
			        system("CLS");
					cout<<"\t\t\tEnter the name of voter :\n\t\t\t";
			        fflush(stdin);
			        getline(cin,name);
			        cout<<"\t\t\tEnter the i'd of voter :\n\t\t\t";
			        fflush(stdin);
			        cin>>id;
			        v.read_info(id,name);
			        system("CLS");
					cout<<"\n\n\t\t\tVoting data is saved succesfull\n";
				    cout<<"\n\n\t\t\tDo you want to add more data ?(y/n/b), 'b' for Back ";
				    fflush(stdin);
					cin>>b;
					fflush(stdin);
				    if(b=='y'){
					    goto add_again;
				    }
				    else if(b=='b'){
				    	system("CLS");
				    	goto election_comition;
					}
				    else{
				     	system("CLS");
					    goto start;
					}
			}
			else if(n==3){
				char b;
				delete_again:
					system("CLS");
					cout<<"\n\t\t\tEnter the details for deleting voting data\n ";
			        cout<<"\t\t\tEnter the name of voter :\n\t\t\t";
			        fflush(stdin);
			        getline(cin,name);
			        cout<<"\t\t\tEnter the i'd of voter :\n\t\t\t";
			        fflush(stdin);
			        cin>>id;
			        v.delete_data(id,name);
			        system("CLS");
			        cout<<"\n\n\t\t\tVoting data is deleted succesfull\n";
				    cout<<"\n\n\t\t\tDo you want to delete more data ?(y/n/b), 'b' for Back ";
				    fflush(stdin);
					cin>>b;
					fflush(stdin);
				    if(b=='y'){
					    goto delete_again;
				    }
				    else if(b=='b'){
				    	system("CLS");
				    	goto election_comition;
					}
				    else{
				     	system("CLS");
					    goto start;
					}
			}
			else if(n==4){
				system("CLS");
				goto election_comition;
			}
		}
		else if(help==2){
			party:
				string name;
			party_record p;
			system("CLS");
			cout<<"\t\t\t********************************\n";
cout<<"\t\t\t* 1. New candidate record      *\n";
cout<<"\t\t\t* 2. Add new candidates        *\n";
cout<<"\t\t\t* 3. Delete candidate's record *\n";
cout<<"\t\t\t* 4. Back                      *\n";
cout<<"\t\t\t********************************\n\t\t\t";
				int n;
    		cin>>n;
    		if(n==1){
    			system("CLS");
    			cout<<"\n\t\t\tDo you want to creata new party record ?\n";
    			cout<<"\n\t\t\twarning! : if you click yes all record of last election get erase(y/n) : ";
    			char a,b;
    			fflush(stdin);
    			cin>>a;
    			fflush(stdin);
    			if(a=='y'){
    				p.delete_file();
    				read_again1:
    					system("CLS");
			        cout<<"\n\t\t\tEnter the name of party :";
			        getline(cin,name);
			        p.read_info(name);
			        system("CLS");
			        cout<<"\n\n\t\t\tParty data is saved succesfull\n";
				    cout<<"\n\n\t\t\tDo you want to add more data ?(y/n/b), 'b' for Back ";
				    fflush(stdin);
					cin>>b;
					fflush(stdin);
				    if(b=='y'){
					    goto read_again1;
				    }
				    else if(b=='b'){
				    	system("CLS");
				    	goto election_comition;
					}
				    else{
				     	system("CLS");
					    goto start;
					}
			   }
			}
            else if(n==2){
            	char b;
            		add_again1:
            			system("CLS");
			        cout<<"\n\t\t\tEnter the name of party :\n\t\t\t";
			        fflush(stdin);
			        getline(cin,name);
			        p.read_info(name);
			        system("CLS");
			        cout<<"\n\t\t\tParty data is saved succesfull\n";
				    cout<<"\n\t\t\tDo you want to add more data ?(y/n/b), 'b' for Back \n\t\t\t";
				    fflush(stdin);
					cin>>b;
					fflush(stdin);
				    if(b=='y'){
					    goto add_again1;
				    }
				    else if(b=='b'){
				    	system("CLS");
				    	goto election_comition;
					}
				    else{
				     	system("CLS");
					    goto start;
					}
			}
			else if(n==3){
				char b;
				delete_again1:
					system("CLS");
					cout<<"\n\t\t\tEnter the details for deleting party data\n\n\t\t\t ";
			        cout<<"\n\t\t\tEnter the name of party :\n\t\t\t";
			        fflush(stdin);
			        getline(cin,name);
			        p.delete_data(name);
				    cout<<"\n\n\t\t\t Do you want to add more data ?(y/n/b), 'b' for Back \n\t\t\t";
				    fflush(stdin);
					cin>>b;
					fflush(stdin);
				    if(b=='y'){
					    goto delete_again1;
				    }
				    else if(b=='b'){
				    	system("CLS");
				    	goto election_comition;
					}
				    else{
				     	system("CLS");
					    goto start;
					}
			}
			else if(n==4){
				system("CLS");
				goto election_comition;
			}
			else {
				system("CLS");
			cout<<"\n\t\t\tEnter a valid input ";
			goto party;
		}
		}
		else if(help==3){
			system("CLS");
			goto start;
		}
		else {
			system("CLS");
			cout<<"\n\t\t\tEnter a valid input ";
			goto election_comition;
		}
		}
		else{
			system("CLS");
		cout<<"\n\n\t\t\tinvalid user name and password\n";
    	goto head;
		}
	}
	else if(x==2){
		head1:
	string pass;
    	string user;
    	system("CLS");
    	cout<<"\n\n\t\t\t***********************************************\n\t\t\t";
		cout<<"* This is a window for election officer only *\n\t\t\t***********************************************\n\n";
		cout<<"\t\t\t*************\n";
    	cout<<"\t\t\t* USER NAME *\n\t\t\t*************\n\t\t\t";
    	cin>>user;
    	cout<<"\t\t\t************\n";
    	cout<<"\t\t\t* PASSWARD *\n\t\t\t************\n\t\t\t";
    	cin>>pass;
    	if(user=="admin"&&pass=="admin@123"){
		party_record p;
		time_t timer1;
		time(&timer1);
		double h,m,s;vote_bank v;voting vot;
		system("CLS");
		cout<<"\n\t\tEnter the time upto which you want to do election hh:mm:ss\n\t\t\t";
		cin>>h>>m>>s;
		double timer=(h*3600)+(m*60)+s;
		double second;
		time_t  timer2;
		while(1){
			int vote;
			time(&timer2);
	       second = difftime(timer2 ,timer1);
			if(second>=timer){
			break;
			}
			string name,id;
			fflush(stdin);
			system("CLS");
			cout<<"\n\t\t\tEnter your name : \n\t\t\t";
			getline(cin,name);
			fflush(stdin);
			cout<<"\n\t\t\tEnter your i'd : \n\t\t\t";
			cin>>id;
			fflush(stdin);
			if(v.cheak(name,id)){
				system("CLS");
				p.display();
				fflush(stdin);
				cout<<"\n\t\t\tEnter your choise\n\t\t\t";
				cin>>vote;
				vot.get_vote(vote);
				system("CLS");
				cout<<"\n\t\t\tYour vote has been added succesfully"<<endl;
				v.delete_data(id,name);
				
				PlaySound(TEXT("voting audio.wav"),NULL,SND_SYNC);
			}
			else{
				system("CLS");
				cout<<"\n\n\t\t\tPlease enter a valid name and i'd \n";
				PlaySound(TEXT("audio for alert.wav"),NULL,SND_SYNC);
			}
			
		}
	}
	else{
		system("CLS");
		cout<<"\n\n\t\t\tinvalid user name and password\n";
    	goto head1;
		}
	}
	else if(x==3){
		voting v;
		system("CLS");
		v.display_results();
	}
	else if(x==4){
		system("CLS");
		ofstream o("candidate count.txt");
	o<<candidate_no;
	o.close();
		cout<<"\n\n\t\t\tTHANK YOU TO USE THIS PROGRAM ";
		return 0;
	}
	else {
		system("CLS");
		cout<<"\n\n\t\t\tEnter a valid no.\n";
	goto start;
	}
	ofstream o("candidate count.txt");
	o<<candidate_no;
	o.close();
	return 0;
}

