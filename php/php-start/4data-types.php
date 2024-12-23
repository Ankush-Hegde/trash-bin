<?php
       echo"<center><h3>data types in php</h3>"; echo"</center>";
       
   echo "<h3>String</h3>";
                  $a = 'hi.....wtf r u doing';
                  echo $a;echo"<br>";
                  echo var_dump($a);
                  
                  
                  echo"<br>";
                  
   echo "<h3>Integer</h3>";
                  $a = 24;
                  echo $a;echo"<br>";
                  echo var_dump($a);
                  
   echo "<h3>Float</h3>";
                  $a = 24.44;
                  echo $a;echo"<br>";
                  echo var_dump($a);
                  
                  
   echo "<h3>Boolean</h3>";
                  $a = true;
                  echo $a;echo"<br>";
                  echo var_dump($a);
                  
                  $b = false;
                  echo $b;echo"<br>";
                  echo var_dump($b);
                  
                  
   echo "<h3>Array</h3>";//must use[] in array
                 
                 
                 echo "<h5>Indexed Array</h5>";
                  $number= array ("one","two","three","four");
                  echo count($number);//count is used to count the number of elements in array
                  echo"<br>";
                  echo " this is " . $number[0] . " , " . $number[1] .  " and " . $number[3];echo"<br>";
                  
                  echo"<pre>";echo print_r($number);echo"</pre>";echo "<br>";
                  echo"<pre>";echo var_dump($number);echo"</pre>";
                  
                  echo "<h5>associatived Array</h5>";
                  $ages= array ("joy"=>12,14=>"jon","sam"=>13);
                  echo count($ages);echo"<br>";echo "14 is the age of ";
                  echo $ages["14"];echo"<br>";echo "sam's age is";
                  echo $ages["sam"];
                  
                  echo"<pre>";echo print_r($ages);echo"</pre>";echo "<br>";
                  echo"<pre>";echo var_dump($ages);echo"</pre>";
                  
                  
                 echo "<h5>Multidimensional Array</h5>";
                   $details=array (
                   array ("name"=>"sam","enail-id"=>"sam@nail.com"),
                   array ("name"=>"jon","enail-id"=>"jon@nail.com"),
                   array ("name"=>"joy","enail-id"=>"joy@nail.com"),
                   );
                   echo count($details);echo"<br>";echo "sam's enail-id is ";
                   echo $details[0]["enail-id"];
                   
                   echo"<pre>";echo print_r($details);echo"</pre>";echo "<br>";
                   echo"<pre>";echo var_dump($details);echo"</pre>";
                   
                   
                                        
   echo "<h3>Objects</h3>";echo"<br>";
                   echo "visit 5objects.php";
                   



?>
