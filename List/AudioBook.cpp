#include <iostream> 
#include <string>
#include "AudioBook.hpp"
using namespace std;

AudioBook::AudioBook(std::string title, double length, std::string genre,
	std::string author, std::string speaker) : PlaylistItem(title, length, genre) {
	author_ = author; 
	speaker_ = speaker; 

}


std::string AudioBook::getAuthor() const {
	return author_;
}

std::string AudioBook::getSpeaker() const {
	return speaker_;
}

void AudioBook::setAuthor(std::string author) {
	author_ = author;
}

void AudioBook::setSpeaker(std::string speaker) {
	speaker_ = speaker;
}

void AudioBook::display() const {
	cout << getTitle() << endl;
	cout << "Author:" << " " << author_ << endl;
	cout << "Narrator:" << " " << speaker_ << endl;
	cout << "Genre:" << " " << getGenre() << endl;
	cout << "Length:" << " " <<  getLength() << endl;
	cout << endl;
}