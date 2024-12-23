<!DOCTYPE HTML>

<html lang ="en">

   <head>
         <title> php 2nd page</title>
   </head>

 <body> 

            <dev class="container">


                <?php
                   
                      echo "DECODE THIS";
                      echo "<br>";
                      echo "stay @ 127.0.0.1 wear a 255.255.255.0";
                      echo "<br>";
                      echo "<br>";
                      echo "answer is: stay at home wear a mask";
                      echo "<p>------------------------------------------------------------------------</p>";
                      
                   $variable1 = 3 ; //variable r written using '$' sign 
                   $variable2 = 4 ;
                   
                           echo "<br>";
                           echo "$variable1 + $variable2 = ";
                           echo $variable1 + $variable2 ;
                           echo "<br>";
                           echo "$variable1 - $variable2 = ";
                           echo $variable1 - $variable2 ;
                           echo "<br>";
                           echo "$variable1 * $variable2 = ";
                           echo $variable1 * $variable2 ;
                           echo "<br>";
                           echo "$variable1 / $variable2 = ";
                           echo $variable1 / $variable2 ;
                           echo "<br>";
                           echo "<p>------------------------------------------------------------------------</p>";
                   echo "difference between ++$ variable ( or -- $ variable ) and $ variable ++ ( or $ variable -- ) ";echo "<br>";
                   
                   echo "++$variable1 is";//++$variable changes instantly 
                   echo ++$variable1;echo "<br>";
                   echo "$variable1-- is";
                   echo $variable1--;echo "<br>";//$variable-- changes take place after use of the variable once
                   echo "$variable1 is";
                   echo $variable1;echo "<br>";
                   
                ?>

            </dev>

 </body>

</html>
