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
            <h2><center>this site is made by php</h2></center>
           <?php
            $age =11;
            if ($age>18){
//if age > 18 then print this                           
                         echo "u can go to the party";
                         }
            else if ($age==17)
                   {
//if age is not >18 but =17 then print this....__note____use =(equals) two times or it may take value 17 as <=17...And u can use else if more than once 
                    echo 'wait for 1 year';
                   }
            
            else{
//if age is not >18 or =17 then print this
                  echo "u r still a child";
                 }
//----------------------------------------------------------------------------------------
            
            ?>
            
           </div>

        </body>
</html>
