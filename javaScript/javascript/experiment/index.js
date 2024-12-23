console.log('Hello World');
//to print Hello World in terminal

//alert('hello');
//this is to get alert message

//let name='Hello World';
//console.log(name);
//to print a variable use 'var' or 'let' but var has few issues.
//there are few rules to declare a variable 
//1.name should not be started with numbers 
//2.name should not be reserved keywords like(if,var,let,else).
//3.name should be a meaningfull 
//4.cannot contain space or hypen(-)
//5.they are case-sensitive

//constants
//const pie=3.14
//console.log(pie);

//kind of values that can be assigned to a variable
//1.primitive(value type)
 //String
 //let name='hi';//string literal
 //numbers
 //let age =40;//number litteral
 //boolean
 //let approved =true;//boolean literal
 //undefined
 //let hey=undefined;//undefined u can write it as let= hey;
 //null
 //let hello=null;//this is used to clear the variable value like to remove colour from red to null

//2.reference type
 //objects
 //array
 //functions
//

//javascript is not a static language its an dynamic language where you can change variables to string,number,boolean anytime
//in javascript int,float are declared as number
//let num=10;
//console.log(typeof(num));
//console.log(num);
//num='donkey';
//console.log(typeof(num));
//console.log(num);
//num=true;
//console.log(typeof(num));
//console.log(num);
//num=null;
//console.log(typeof(num));
//console.log(num);

//objects
//let person={
    //name:'Bob',
    //age:30
//};
//console.log(person);//this is to create object and display it
//accessing name using dot notation
//person.name='john';//changing name
//console.log(person.name);
//accessing using bracket notation
//let selection='name';
//person[selection]='marry';
//console.log(person['name']);
//or//person['name']='marry';
//console.log(person['name']);

//arrays
//arrays are the objects in javascripts because u can use string and numbers in a single array
//let selected=['red','blue',1];
//console.log(selected);
//console.log(selected[1]);
//selected[3]='green';
//console.log(selected);
//console.log(selected.length);//prints length of array

//functions
//function greet(name,lastname){//here name and last name r paramater
    //console.log('hello ' +name+ '' +lastname );
//}
//greet('jhon', 'cena');//jhon and cena r arguments
//greet('big', 'show');

var audio = new Audio('file:///home/skull/!pgm/javascript/experiment/Anonymous.mp3');
audio.play();
