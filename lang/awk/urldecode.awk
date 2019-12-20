 awk '
     {
         for (i = 0x20; i < 0x40; ++i) {
             repl = sprintf("%c", i);
             if ((repl == "&") || (repl == "\\"))
                 repl = "\\" repl;
             gsub(sprintf("%%%02X", i), repl);
             gsub(sprintf("%%%02x", i), repl);
         }
         print
     }
 '
