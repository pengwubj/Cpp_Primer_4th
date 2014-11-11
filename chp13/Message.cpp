#include "Message.h"

void Folder::put_folder_in_messages(std::set<Message*> m){
	for(std::set<Message*>::iterator iter= messages.begin();iter != m.end(); ++iter){
		(*iter)->addFolder(this);
	}
}

void Folder::rm_folder_from_messages(){
	for(std::set<Message*>::iterator iter= messages.begin();iter != messages.end(); ++iter){
		(*iter)->rmFolder(this);
	}
}

void Folder::rmMsg(Message* m){
	messages.erase(m);

}
void Folder::addMsg(Message *m){
	messages.insert(m);
}

Folder& Folder::operator=(const Folder& f){
	if(this != &f){
		folderName = f.folderName;
		messages = f.messages;
		put_folder_in_messages(f.messages);
	}
	return *this;
}

void Folder::save(Message &m){
	messages.insert(&m);
	m.addFolder(this);
}

void Folder::remove(Message &m){
	messages.erase(&m);
	m.rmFolder(this);
}

Folder::~Folder(){
	rm_folder_from_messages();
}

void Folder::debug_print() const {
		std::cout << folderName << " this FOLDER In the folders below :" << std::endl;
	for(std::set<Message*>::iterator iter= messages.begin() ; iter != messages.end();iter++)
		std::cout << (*iter)->contents << std::endl;
}

void Message::put_msg_in_folders(const std::set<Folder*> &f){
	for(std::set<Folder*>::iterator iter= f.begin() ; iter != f.end();iter++){
		(*iter)->addMsg(this);
	}
}
void Message::rm_msg_from_folders(){
	for(std::set<Folder*>::iterator iter= folders.begin() ; iter != folders.end();iter++)
		(*iter)->rmMsg(this);
}
void Message::save(Folder &f){
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder &f){
	folders.erase(&f);
	f.rmMsg(this);
}
Message::~Message(){
	rm_msg_from_folders();
}

void Message::debug_print() const {
		std::cout << contents << " this Message In the folders below :" << std::endl;
	for(std::set<Folder*>::iterator iter= folders.begin() ; iter != folders.end();iter++)
		std::cout << (*iter)->folderName << std::endl;
}


Message& Message::operator=(const Message& m){
	if(this != &m){
		contents = m.contents;
		folders = m.folders;
		put_msg_in_folders(m.folders);
	}
	return *this;
}