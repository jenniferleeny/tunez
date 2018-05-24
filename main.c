#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"
#include "library.h"


int main(){
  
  song_node* lib[27] = { NULL };

  add_song(lib, "la la", "the cab");
  add_song(lib, "angels", "the intro");
  add_song(lib, "c jokes", "jonalf dyrland-weaver");
  add_song(lib, "appreciated", "rixton");
  add_song(lib, "miss jackson", "panic! at the disco");
  add_song(lib, "mama mia", "abba");
  add_song(lib, "you know you like it", "dj snake");
  add_song(lib, "centuries", "fall out boy");
  add_song(lib, "pumped up kicks", "foster the people");
  add_song(lib, "you're beautiful", "james blunt");
  add_song(lib, "sexyback", "justin timberlake");
  add_song(lib, "apologize", "one republic");
  add_song(lib, "life support", "sam smith");
  add_song(lib, "sound of your heart", "shawn hook");
  add_song(lib, "omg", "usher");
  add_song(lib, "Hello", "vixx");
  add_song(lib, "backstreet", "westlife");
  add_song(lib, "intro", "xx");
  add_song(lib, "find you", "zedd");
  add_song(lib, "beautiful now", "zedd");
  add_song(lib, "true colors", "zedd");
  add_song(lib, "clarity", "zedd");
  add_song(lib, "sing", "you+me");
  add_song(lib, "cs rules the world", "sally&jen");
  add_song(lib, "bad", "michael jackson");
  add_song(lib, "man in the mirror", "michael jackson");
  add_song(lib, "ref", "pentatonix");
  add_song(lib, "because of you", "ne-yo");
  add_song(lib, "clarinet concerto K. 622", "wolfgang amadeus mozart");
  add_song(lib, "rose gold", "pentatonix");
  add_song(lib, "upgrade u", "beyonce");
  add_song(lib, "word crimes", "weird al");
  add_song(lib, "my heart will go on", "celine dion");
  add_song(lib, "halo", "beyonce");
  add_song(lib, "partition", "beyonce");
  add_song(lib, "single ladies", "beyonce");
  add_song(lib, "sweet dreams", "beyonce");
  add_song(lib, "angel with a shotgun", "the cab");
  add_song(lib, "be somebody", "thousand foot crutch");
  add_song(lib, "asterisk", "*******");
  add_song(lib, "gang signs", "<123rockstar>");
  add_song(lib, "filthy rich", "$$$$$");
  printf("HERE IS THE LIBRARY:\n");
  print_lib(lib);

  printf("\n");
  printf("TESTING SEARCH_SONG:\n");
  printf("looking for *ROSE GOLD*\n");
  print_node(search_song(lib, "rose gold"));

  printf("looking for *HALO*\n");
  print_node(search_song(lib, "halo"));

  printf("looking for *WORD CRIMES*\n");
  print_node(search_song(lib, "word crimes"));

  printf("\n");
  printf("TESTING SEARCH_ARTIST:\n");
  printf("looking for *BEYONCE*\n");
  print_node(search_artist(lib, "beyonce"));

  printf("looking for *THE CAB*\n");
  print_node(search_artist(lib, "the cab"));

  printf("looking for *WEIRD AL*\n");
  print_node(search_artist(lib, "weird al"));

  printf("\n");
  printf("TESTING PRINT_ENTRIES:\n");
  printf("B entries:\n");
  print_entries(lib, 'b');
  printf("Misc entries:\n");
  print_entries(lib, '@');
  printf("P entries:\n");
  print_entries(lib, 'p');

  printf("\n");
  printf("TESTING PRINT_ARTIST:\n");
  printf("BEYONCE:\n");
  print_artist(lib, "beyonce");
  printf("WEIRD AL:\n");
  print_artist(lib, "weird al");

  printf("\n");
  printf("TESTING SHUFFLE:\n");
  shuffle(lib);
  printf("\n");
  printf("\n");
  
  printf("\n");
  printf("TESTING DELETE:\n");
  printf("Removing *beyonce - upgrade you*\n");
  printf("Removing *weird al - word crimes*\n");
  printf("Removing *beyonce - halo*\n");
  printf("Removing *james blunt - you're beautiful\n");

  delete(lib, "upgrade u", "beyonce");
  delete(lib, "word crimes", "weird al");
  delete(lib, "halo", "beyonce");
  delete(lib, "you're beautiful", "james blunt");

  printf("\n");
  printf("THE LIBRARY AFTER REMOVAL:\n");
  print_lib(lib);

  printf("\n");
  printf("DELETING ENTIRE LIBRARY GOODBYE\n");
  delete_all(lib);
  printf("There should be nothing in this library now:\n");
  print_lib(lib);
  
  return 0; 
}

