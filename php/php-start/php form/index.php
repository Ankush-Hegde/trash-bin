<?php
  
  echo"<img class='zoo' src='zoo.jpeg' alt='zoo'>";
  
 echo '<div class= "m" >';
  
    echo "<title>travel form</title>".'<center><h2>Welcome to man VS wild form</h2></  center><p>NOTE:fill the form by tomorrow to confirm ur participation</p>';
    
    echo '<link rel="stylesheet" type="text/css" href="style.css">';
  
    echo "<script src='index.js'></script>";
    
 echo '</div>';
  
  echo '<div class= "l" >';
    echo "<form action='index.php';method='post'>";
    
    
    
    echo "<input type='text' name='username' id='username'  placeholder='USERNAME'>";echo "<br> ";echo "<br> ";
    echo "<input type='password' name='password' id='password' placeholder='PASSWORD'>";echo "<br> ";echo "<br> ";
    echo "<input type='password' name='password' id='password' placeholder='re-enter PASSWORD'>";echo "<br> <br>";
    echo "<input type='text' name='gender' id='gender'  placeholder='enter ur gender'>";echo "<br> <br>";
    echo "<input type='number' name='phone-number' id='number'  placeholder='enter ur lucky-number'>";echo "<br> <br>";
    echo "<input type='email' name='email' id='@gmail.com'  placeholder='enter ur email'>";echo "<br> <br>";
    echo"<input type='phone' name='phone' id='phone'  placeholder='enter ur phone'>";echo"<br><br>";
    echo"<textarea name='desc' color='desc' rows='10' cols='50' placeholder='comment'></textarea>";echo"<br><br>";
    echo "<input class='w' type='submit' name='submit'>";//this can be written as echo "<button class='btn'>submit</button>";
    
    
    echo "</form>";
    echo '</div>';
    echo "<p class='submitingmsg'>thanks for ur participation</p>"; 
?>  
