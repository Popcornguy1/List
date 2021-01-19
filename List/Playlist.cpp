
#include "Playlist.hpp"
#include <iostream>
#include <string>
using namespace std;

Playlist::Playlist():DoublyLinkedList() {

}

double Playlist::getTotalTime() const {
    DoubleNode<PlaylistItem*>* time_ptr = head; 
    double total = 0; 
    while (time_ptr != NULL) {
        total += time_ptr->getItem()->getLength(); 
        time_ptr = time_ptr->getNext(); 
    }

}

void Playlist:: operator+=(Playlist& rhs) {

}

void Playlist:: operator-=(Playlist& rhs) {
}

void Playlist::skip() {

}

void Playlist::rewind() {
 
}

void Playlist::display() {
    DoubleNode<PlaylistItem*>* display_ptr = head;
    while (display_ptr != NULL)
    {
        display_ptr->getItem()->display();
        display_ptr = display_ptr->getNext();
    }
    display_ptr = NULL;
	
}