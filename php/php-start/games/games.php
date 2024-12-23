<?php

  echo"<title>games.php</title>";

  echo "<center> <h2>BUY A GAME FROM GAMES.PHP</h2> </center>";

class games
           {
           
           const B ="<br>";	
             
             var $name;
             var $photo;
             public $price; 
             var $dir ="posters/";
                      
                      public function brand_games(){
                                           echo "<dev style='float:left ; margine-right: 40px; '>";         
                                           echo "<font size= '5px'>{$this->name}</font>".self::B;
                                           echo "<img src='{$this->dir}{$this->photo}'width='200' hight='200'>".self::B;
                                           echo '$'. $this->price.self::B;
                                           echo "</dev>";
                                                  
                                                    }
            }

      $big_game = new games;
      $big_game -> price = 14.99;
      $big_game -> name = "big_game";
      $big_game -> photo='big_game.jpeg';

$big_game->brand_games();

      $fallout = new games;
      $fallout -> price = 17.1;
      $fallout -> name = 'fallout';
      $fallout -> photo ='fallout.jpeg';
      
$fallout -> brand_games();

      $halo = new games;
      $halo -> price = 12.5;
      $halo -> name = 'halo';
      $halo ->photo ='halo.jpeg';

$halo -> brand_games();

     $pung = new games;
     $pung -> price = 8.7;
     $pung -> name = 'pubg';
     $pung ->photo ='pubg.jpeg';

$pung -> brand_games();

     $uncharated = new games;
     $uncharated -> price = 9.99;
     $uncharated -> name = 'uncharated';
     $uncharated ->photo ='uncharated.jpeg';

$uncharated -> brand_games();

     $watch_dogs = new games;
     $watch_dogs -> price = 20.22;
     $watch_dogs -> name = 'watch_dogs';
     $watch_dogs ->photo ='watch_dogs.jpeg';

$watch_dogs -> brand_games();





?>
