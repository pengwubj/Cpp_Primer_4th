#include <set>
#include <string>
#include <iostream>
using namespace std;
class Message{
public:
	Message(const string &str =""):contents(str) {}
	Message(const Message& m):contents(m.contents),folders(m.folders){
		put_msg_in_folders(m.folders);
	}
	Message& operator= (const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string	contents;
	set<Folder*> folders;
	void put_msg_in_folders(const set<Folder*> &);
	void rm_msg_from_folders();
};

Message& Message::operator= (const	Message& m){
	if(&m != this){
		contents= m.contents;
		folders = m.folders;
		put_msg_in_folders(m.folders);
	}
	return *this;
}
void Message::put_msg_in_folders(contents set<Folder*> &f){
	for(set<Folder*>::iterator iter= f.begin();iter != f.end();++iter)
		(*iter)->addMsg(this);
}
void Message::rm_msg_from_folders(){
	for(set<Folder*>::iterator iter=folders.begin();iter != folders.end();++iter)
		(*iter)->rmMsg(this);
}
Message::~Message()
{
	rm_msg_from_folders();
}
Message::save(Folder& f){
	folders.inset(&f);
	f.addMsg(this);
}
Message::remove(Folder &f){
	folders.erase(&f);
	f.rmMsg(this);
}

void Message::addFldr(Folder* f){
	folders.inset(f);
		
}
void Message::rmFldr(Folder* f){
	folders.erase(f);
}

class Folder
{
public:
	Folder(const string& s1=""):folederName(s1){}
	Folder(const Folder& );
	Folder& operator= (const Folder&);
	~Folder();
	void addMsg(Message*);
	void rmMsg (Message*);

private:
	set<Message*> messages;
	string folederName;
	void rm_folder_from_messages(set<Message*> );
	void put_folder_in_messages(set<Message*> );
};

	Folder::Folder(const Folder& f):folederName(f.folederName),messages(f.messages){
		put_folder_in_messages(f.messages);	
	}

	Folder& Folder::operator= (const Folder &f){
		
		if(this != &f){
			folederName = f.folederName;
			messages = f.messages;
			put_folder_in_messages(f.messages);
		}
		return *this;
	}
	void Folder::put_folder_in_messages(set<Message*> m){
		for(set<Message*>::iterator iter = m.begin();m != m.end();++m)
			(*iter).addFldr(this);
	}
	void Folder::rm_folder_from_messages(set<Message*> m){
		for(set<Message*>::iterator iter = m.begin();m != m.end();++m)
			(*iter).rmFldr(this);
	}
	Folder::~Folder(){
		rm_folder_from_messages();
	}