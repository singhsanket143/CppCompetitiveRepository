function strict() {
    // Function-level strict mode syntax
    "use strict";
    function nested() { 
        content = "10";
        return 'And so am I!'; 
    }
    return "Hi!  I'm a strict mode function!  " + nested();
  }
function notStrict() { content = 10; return "I'm not strict."; }
notStrict();