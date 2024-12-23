<?php
    
   $s = "this is string";
   echo $s."<br>";  
    
   $k = strlen($s);//her strlen is function in php used to count letters in $s
   
   echo "<br> length of string is : ". $k;
   
   echo "<br>number of words is : ". str_word_count ($s);// str_word_count is function used to count words in php
    
   echo "<br>reverse string is : ". strrev ($s);//strrev function is used to reverse string in php
   
   echo "<br>". 'the position of "is" in the string is : ' . strpos ($s,is);//strpos function is used to find first position of letters or word --- note:it starts to counts from 0 and it search words with in words (ex: or in word) and it gives position of only first word it gets
   
   echo "<br>the replaced string is : ". str_replace (is,at,$s);//str_replace function is used to replace letters,here every "is" is replaced by "at" 
   
?>
