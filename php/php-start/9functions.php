<!DOCTYPE HTML>
<html>

  <head>

    <title>php site</title>

  </head>
   
<style>
*{
margin:0;
padding:0;
box-sizing: border-box;
}
.container 
          { 
           max-width:100%;
           background-color:gray;
           margin:auto;
           padding:24px;

            }


</style>
 
        <body> 

           <div class=container>
           
           <?php 
                    function print1(){
                                      echo "one";
                                     }//this is the syntax to create function..
                    print1();//this is how to print function
                    
                    
                    function print_number($number){//this is ex second function
                                                   echo"<br>";
                                                   echo "this is a number ";
                                                   echo $number;
                                                   }
                    print_number(34);
                    print_number(45);
                    
                    function print_letter($p){//this is ex second function
                                                   echo"<br>";
                                                   echo "this is a number ";
                                                   echo $p;
                                                   }
                    print_letter(500);
                    print_letter(404);
            ?>   
            
                      
          </div>

</body>
</html>          
