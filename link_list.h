#ifndef FOO

#define FOO 33;

typedef struct song_node{
  char* name;
  char* artist;
  struct song_node* next;
} song_node;




song_node* insert_front( song_node*, char*, char*);

song_node* insert( song_node*, char*, char*);

void print_list( song_node*);

song_node* find_song( song_node*, char*);

song_node* find_first( song_node*, char*);

song_node* random_song( song_node*);
song_node*  remove_song(song_node*, char*, char*);

song_node* free_list( song_node*);

#endif
