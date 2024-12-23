<?php


   echo "<h3>Objects and class</h3>";echo"<br>";
 
        class games {
                      const b = '<br>'; //constants can be used by .self::b; inside class
                      
                      public $price;
                      var $name;
                      public $photo;
                      
                      
                          public function print_games() {
                                                        echo $this->price.self::b;
                                                        echo $this->name.self::b;
                                                        echo $this->photo.self::b;
                                                        }
                     
                     }
$small_game = new games;
$small_game -> name = 'small_game';
$small_game -> price ='small_price';
$small_game -> photo ='small_photo';

$small_game -> print_games();

$big_game =new games;
$big_game-> photo = "big_photo";
$big_game-> name = "big_game";
$big_game-> price = "big_price";

$big_game -> print_games();

?>
