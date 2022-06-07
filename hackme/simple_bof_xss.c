#include <stdint.h> 
#include <stdio.h>
#include <string.h> 

#include <emscripten.h>

void EMSCRIPTEN_KEEPALIVE vulnerable_function(char *message) {
  char output[16] = "Hardcoded msg";
  char msg[16];

  strcpy(msg, message);

  /* Here we can do something else with the input message,
     but the buffer overflow has already occurred! */

  // Developer intention: Output "Hardcoded msg"
  EM_ASM({
    document.getElementById("xss").innerHTML =(UTF8ToString($0,$1));
  }, output, strlen(output));

}
