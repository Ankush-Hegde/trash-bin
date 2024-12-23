//objects
let person={
    name:'Bob',
    age:30
};
console.log(person);//this is to create object and display it
//accessing name using dot notation
person.name='john';//changing name
console.log(person.name);
//accessing using bracket notation
let selection='name';
person[selection]='marry';
console.log(person['name']);
//or//person['name']='marry';
//console.log(person['name']);
