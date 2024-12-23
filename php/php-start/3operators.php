<?php

      $a =4 ;
      $b =2 ;
      
       echo"<center>";     echo "<h3>a=$a,b=$b</h3>";   echo"</center>";
      
   echo"<center>";     echo "<h3>arithematic operators</h3>";   echo"</center>";
        
                  echo "<br>";
        
                  echo "$a+$b=";
                  echo $a+$b;
        
          echo "<br>";//html tags can be used using echo
                  echo "$a-$b=";
                  echo $a-$b;
        
          echo "<br>";
                  echo "$a*$b=";
                  echo $a*$b;
        
          echo "<br>";
                  echo "$a/$b=";
                  echo $a/$b;
                  
           echo "<br>-------------------------------------------------------------------------</br>";
                  
                  echo "a=$a,b=$b";
                  echo "<br>-------------------------------------------------------------------------</br>";
                  
   echo"<center>";     echo "<h3>assignment operators</h3>";     echo"</center>";
                 
                 $newvar = $a;
                       
                       echo "newvarible is a"; echo "<br>";
                       echo "$newvar + $b = "; 
                 $newvar +=2;
                 echo $newvar;
           
           echo "<br>";
                       
                       
                       echo "newvarible is 6"; echo "<br>";
                       echo "$newvar - $b = ";
                 $newvar -=2;
                 echo $newvar;
                 
           echo "<br>";
                       
                       echo "newvarible is 4"; echo "<br>";
                       echo "$newvar * $b = ";
                 $newvar *=2;
                 echo $newvar;
           
           echo "<br>";
                       
                        echo "newvarible is 8"; echo "<br>";
                        echo "$newvar / $b = ";
                 $newvar /=2;
                 echo $newvar;
           
           echo "<br>";
           
                       echo "newvarible is 4"; echo "<br>";
                       echo "$newvar + $b = "; 
                 $newvar +=2;
                 echo $newvar;
           echo "<br>";
            
           echo "<br>-------------------------------------------------------------------------</br>";
                         
                       
                       echo "a=$a,b=$b,newvarible=$newvar";
                       echo "<br>-------------------------------------------------------------------------</br>";
       echo"<center>";     echo "<h3>comparison operator</h3>";     echo"</center>";           
                    echo "2==4 is ";
                    echo var_dump(2==4);echo"<br>";//var_dump or print_r is used to define print_r gives less informations
                    
                    echo "2!=4 is ";
                    echo var_dump(2!=4);echo"<br>";
                    
                    echo "2<=4 is ";
                    echo var_dump(2<=4);echo"<br>";
                    
                    echo "2>=4 is ";
                    echo var_dump(2>=4);echo"<br>";  
                      
        echo"<center>";     echo "<h3>increment/decrement operator</h3>";     echo"</center>"; 
                    echo "a=4 then echo ++$ a is ";
                    echo ++$a;echo"<br>";
                    echo "a=$a";echo "<br>";
                    
                    echo "a=5 then echo --$ a is ";
                    echo --$a;echo"<br>";
                    echo "a=$a";echo "<br>";
                    
                    echo "a=4 then echo $ a++ is ";
                    echo $a++;echo"<br>";
                    echo "a=$a";echo "<br>";
                    
                    echo "a=5 then echo $ a-- is ";
                    echo $a--;echo"<br>";
                    echo "a=$a";echo "<br>";
           
           echo"<center>";     echo "<h3>logical operator</h3>";     echo"</center>";  
                    echo "<h5>and (&&) operator</h5>";
                    
                    $c= (true and true);//must use brackets or u get some value false
                    echo var_dump($c);
                    $c= (true && true);
                    echo var_dump($c);echo"<br>";
         
                    $c= (false and true);
                    echo var_dump($c);
                    $c= (false && true);
                    echo var_dump($c);echo"<br>";
                    
                    $c= (false and false);
                    echo var_dump($c);
                    $c= (false && false)  ;
                    echo var_dump($c);echo"<br>";
                    
                    $c= (true and false) ;
                    echo var_dump($c);
                    $c= (true && false) ;
                    echo var_dump($c);
                      
                   echo "<h5>or (||) operator</h5>";
                   
                   $c= (true or true);
                    echo var_dump($c);
                    $c= (true || true);
                    echo var_dump($c);echo"<br>";
         
                    $c= (false or true);
                    echo var_dump($c);
                    $c= (false || true);
                    echo var_dump($c);echo"<br>";
                    
                    $c= (false or false);
                    echo var_dump($c);
                    $c= (false || false)  ;
                    echo var_dump($c);echo"<br>";
                    
                    $c= (true or false) ;
                    echo var_dump($c);
                    $c= (true || false) ;
                    echo var_dump($c);
                    
                    echo "<h5>xor operator</h5>";
                   
                    $c= (true xor true);
                    echo var_dump($c);
                    echo"<br>";
                    
                    $c= (false xor true);
                    echo var_dump($c);
                    echo"<br>";
                    
                    $c= (false xor false);
                    echo var_dump($c);
                    echo"<br>";
                    
                    $c= (true xor false) ;
                    echo var_dump($c);
                    echo"<br>";
                    
                    echo "<h5>not (!) operator</h5>";
                   
                    $c= (true);
                    echo var_dump(!$c);echo"<br>";
         
                    $c= (false);
                    echo var_dump(!$c);echo"<br>";
                    
                    
                    
                    
                    
                    
                         
?>
