#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "blowfish.h"

int main(int argc, char *argv[]){
  int DEBUG = 1;

  //char from[128], to[128];

  /* Temp buffer to store user input (user password) */
  char temp_buf[16];
  int len;

  /* define boolean ints for params */
  int deco, enco, vers, help, mmap, pass, opt;
  /* define a structure to hold the key */
  // BF_KEY key;

  /* initialize and check params */
  len = 128;
  deco = 0; enco = 0; vers = 0; help = 0; mmap = 0; pass = 0;
  while((opt = getopt(argc, argv, "devhmp:")) != -1) {
    switch(opt){
    case 'd':
      deco = 1;
      break;
    case 'e':
      enco = 1;
      break;
    case 'v':
      vers = 1;
      break;
    case 'h':
      help = 1;
      break;
    case 'm':
      mmap = 1;
      break;
    case 'p':
      strcpy(temp_buf, optarg);
      pass = 1;
      break;
    default:
      fprintf(stderr, "Usage: %s [-devhm] [-p PASSWORD] <infile> <outfile>\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }
  
  if(DEBUG==1){
    printf("\ndecode=%i \nencode=%i \nversion=%i \nhelp=%i \nmmap=%i \npass=%i \n", deco, enco, vers, help, mmap, pass);

    if(pass==1){
      printf("\ntemp_buf=%s\n",temp_buf);
    } else {
      printf("\ntemp_buf=<BLANK>\n");
    }
  }

  if(help==1){
    
  }
  
  /* don't worry about these two: just define/use them */
  // int n = 0;  /* internal blowfish variables */
  // unsigned char iv[8];  /* Initialization Vector */

  /* fill the IV with zeros (or any other fixed data) */
  // memset(iv, 0, 8);

  /* call this function once to setup the cipher key */
  // BF_set_key(&key, 16, temp_buf);

  /*
   * This is how you encrypt an input char* buffer "from", of length "len"
   * onto output buffer "to", using key "key".  Jyst pass "iv" and "&n" as
   * shown, and don't forget to actually tell the function to BF_ENCRYPT.
   */
  // BF_cfb64_encrypt(from, to, len, &key, iv, &n, BF_ENCRYPT);

  /* Decrypting is the same: just pass BF_DECRYPT instead */
  // BF_cfb64_encrypt(from, to, len, &key, iv, &n, BF_DECRYPT);
  
  return 0;
}