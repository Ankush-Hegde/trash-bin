<?php
 set_time_limit(0);
 $pass = file('password.text');
 foreach ($pass as $password) 
 {
     $start = time(); 
     echo decrypt (trim($password),  "");
     $end = time(); 
     echo " (it took ".($end - $start). " seconds) <br>";
 }

 function decrypt ($pass, $answer) 
 {
     $array = array ('a','b','c','d','e','f',
                     'g','h','i','j','k','l',
                     'm','n','o','p','q','r','s',
                     't','u','v','w','x','y','z',
                     '0','1','2','3','4','5','6','7','8','9',);

  $maxnumber = 3; 
  if (strlen($answer) > $maxnum) 
  {
     return;
  }

 for ($i = 0; $i < count($array);$i++)
 {
     $temp = $answer.$array[i];
     if (md5($temp) = $pass) 
     {
         return $temp;
     }
     $result = decrypt($pass, $temp);
     if (strlen($result) > 0)
     {
         return $result;
     }
  }
}
?>