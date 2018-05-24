#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "link_list.h"
#include "library.h"



//takes a char
//returns the index of lib matching that char
//1 - 27 for a - z
//0 for other characters
int get_index(char c){
  int pos = (int)c - (int)'a';
  if (pos < 0 || pos > 26)
    pos = 0;
  else
    pos++;
  return pos;
}

//takes a title and an artist
//creates and adds song into the correct slot in the right order
//slots arranged by artist
//lists sorted by song title
void add_song(song_node* lib[], char* n, char* a){
  int pos = get_index(*a);
  lib[pos] = insert(lib[pos], n, a);  
}


//takes a song name
//returns a pointer to that song_node
song_node* search_song(song_node* lib[], char* n){
  int i;
  for (i = 0; i < 27; i++){
    song_node* tmp = find_song(lib[i], n);
    if (tmp != NULL)
      return tmp;
  }
  return NULL;
}


//takes a song artist
//returns a pointer to that song_node
song_node* search_artist(song_node* lib[], char* a){
  int pos = get_index(*a);
  return find_first(lib[pos], a);
}


//takes a char letter
//prints out all the entries under that letter
void print_entries(song_node* lib[], char letter){
  int pos = get_index(letter);
  print_list(lib[pos]);
}


//takes a song artist
//prints out all songs by that artist
void print_artist(song_node* lib[], char* a){
  int pos = get_index(*a);
  song_node* tmp = lib[pos];
  tmp = find_first(tmp, a);
  while (tmp){
    print_node(tmp);
    tmp = tmp -> next;
    tmp = find_first(tmp, a);
  }
}


//print out entire library
void print_lib(song_node* lib[]){ 
  int i = 0;
  song_node* tmp;
  while (i < 26){
    tmp = lib[i];
    print_list(tmp);
    i++;
  }
}

//print out a series of randomly chosen songs
void shuffle(song_node* lib[]){
  int length = 0;
  int i;
  srand(time(NULL));
  rand();
  for (i = 0; i < 27; i++) 
    length +=list_len(lib[i]);
  int r;
  for (r = rand() % length; r > 0; r--) {
    int s = rand() % 27;
    while (!lib[s]) 
      s = rand() % 27;
    print_node(random_song(lib[s]));
  }
}

//takes a song name
//deletes that song
void delete(song_node* lib[], char* title, char* singer){
  int i = get_index(singer[0]);
    lib[i] = remove_song(lib[i], title, singer);
}

//delete all nodes in the library
void delete_all(song_node* lib[]){
  int i;
  for (i = 0; i < 27; i++) {
    lib[i] = free_list(lib[i]);
  }
}




