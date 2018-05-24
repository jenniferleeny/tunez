#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "link_list.h"


void print_node( song_node* front){
  printf("%s - %s\n", front -> artist, front -> name);
}


//takes a pointer to the front of the list
//creates a node with the information
//inserts to front and returns pointer to new front of list
song_node* insert_front( song_node* front, char* n, char* a){
  song_node* new = (song_node*)malloc(sizeof(song_node));
  new -> name = n;
  new -> artist = a;
  new -> next = front;
  return new;
}


//takes a pointer to the front of the list
//creates a node with the information
//inserts in order
//returns a pointer to the front of the list
song_node* insert( song_node* front, char* n, char* a){
  if (front == NULL || 
      strcmp(n, front -> name) < 0)
    return insert_front(front, n, a);

  song_node* top = front;
 
  while (front -> next){
    char* str = (front -> next) -> name;
    if (strcmp(n, str) < 0){
      front -> next = insert_front(front -> next, n, a);
      return top;
    }
    front = front -> next;
  }
  front -> next = insert_front(front -> next, n, a);
  return top; 
}



//print out all songs in list
void print_list( song_node* front){
  while (front){
    print_node(front);
    front = front -> next;
  }
}



//takes a pointer to the front and a song name
//returns a pointer to the song with that name
song_node* find_song( song_node* front, char* n){
  while (front){
    if (strcmp(front -> name, n) == 0)
      return front;
    front = front -> next;
  }
  return front;
}


//take a pointer to the front and an artist name
//returns a pointer to the first song by that artist
song_node* find_first( song_node* front, char* a){
  while (front){
    if (strcmp(front -> artist, a) == 0)
      return front;
    front = front -> next;
  }
  return front;
}


//takes a pointer to the front
//returns the length of the list
int list_len( song_node* front){
  int len = 0;
  while (front){
    len++;
    front = front -> next;
  }
  return len;
}


//takes a pointer to the front
//returns a pointer to a random song in the list
song_node* random_song( song_node* front) {
  song_node* random = front;
  int length = list_len(front);
  int r = rand() % length;
  for (; r > 0; r--)
    random = random->next;
  return random;
}


//takes a pointer to the front and a song name
//removes the corresponding node
//returns pointer to the front in case front was target of removal
song_node* remove_song( song_node* front, char* n, char* a) {
  song_node* holder = front;
  if (front && 
      strcmp(n, front->name) == 0 && 
      strcmp(a, front->artist) == 0) {
    holder = front -> next;
    free(front);
    front = NULL;
    return holder;
  }
  song_node* tmp;
  while (front->next) {
    if (strcmp(n, front->next->name) == 0 && 
	strcmp(a, front->next->artist) == 0) {
      tmp = front -> next;
      front -> next = front -> next -> next;
      free(tmp);
      tmp = NULL;
      return holder;
    }
    front = front->next;
  }
  return holder;
}


//takes a pointer to the front
//frees all nodes in the list
//returns a pointer to the front, which will be null
song_node* free_list( song_node* front){
  song_node* curr = front;
  song_node* next;
  while (curr){
    next = curr -> next;
    free(curr);
    curr = next;
  }
  front = NULL;
  return front;
}
