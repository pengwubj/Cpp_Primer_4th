#include <string>
#include <set>
#include <iostream>
class Folder;

class Message{
	friend class Folder;
public:
	Message(const std::string &str =""):contents(str) {}
	Message(const Message& m):contents(m.contents),folders(m.folders){
		put_msg_in_folders(m.folders);
	}
	Message& operator= (const Message&);
	~Message();
	void debug_print() const;
	void save(Folder&);
	void remove(Folder&);
private:
	std::string	contents;
	std::set<Folder*> folders;
	void put_msg_in_folders(const std::set<Folder*> &);
	void rm_msg_from_folders();

	void rmFolder(Folder*f){ folders.erase(f); }
	void addFolder(Folder* f){folders.insert(f);}
};

class Folder
{
	friend class Message;
public:
	Folder(const std::string& s1=""):folderName(s1){}

	Folder(const Folder& f):folderName(f.folderName),messages(f.messages){
		put_folder_in_messages(f.messages);
	}

	Folder& operator= (const Folder&);
	~Folder();
	void debug_print() const;
private:
	std::set<Message*> messages;
	std::string folderName;
	void rm_folder_from_messages( );
	void put_folder_in_messages(std::set<Message*> );
	void addMsg(Message*);
	void rmMsg (Message*);
	void save (Message&);
	void remove(Message&);
};
