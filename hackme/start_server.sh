#/bin/bash
#emcc simple_bof_xss.c -o simple_bof_xss.js -fsanitize=address
emcc simple_bof_xss.c -o simple_bof_xss.js -fsanitize=address
npm install http-server -g
http-server -p 8080