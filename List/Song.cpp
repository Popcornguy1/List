#include <iostream>
#include <string>
#include "Song.hpp"
using namespace std;


Song::Song(std::string title, double length, std::string genre,
	std::string artist) : PlaylistItem(title, length, genre) {
	artist_ = artist; 

}


//Song::Song(std::string title, double length, std::string genre,
	//std::string artist): PlaylistItem(title, length, genre) {

//}

std::string Song::getArtist() const {
	return artist_;
}

void Song::setArtist(std::string artist) {
	artist_ = artist;
}

void Song::display() const {
	cout << getTitle() << endl;
	cout << "Artist:"<< " " << artist_ << endl;
	cout << "Genre:" << " " << getGenre() << endl;
	cout << "Length:" << " " <<  getLength() << endl;
	cout << endl;
}


