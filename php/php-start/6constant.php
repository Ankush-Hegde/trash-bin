<?php

     echo"<center><h2>constant</h2></center>";

define (j,24);

echo j; //constant outside class
echo"<br>";

class games
           {
           
           const i ="<br>"; //constant inside class is used by .self::constant;
             
             var $name;
             var $photo;
             public $price; 
             
                      
                      public function brand_games(){
                                           
                           echo "<font size= '5px'>{$this->name}</font>".self::i;
                           echo "<img src='big_game.jpeg'>".self::i;
                           echo '$'. $this->price .self::i;
                                                
                                                    }
            }

      $big_game = new games;
      $big_game -> price = 14.99;
      $big_game -> name = "big_game";
      $big_game -> photo='big_game.jpeg';

$big_game->brand_games();

?>
