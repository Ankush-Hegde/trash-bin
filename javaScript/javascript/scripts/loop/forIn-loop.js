//for in loop is mainly used for the objects
//instade of 'e' you can use any letters 


const symbols={ 
		1 :'one',
		2:'two',
		3:'three',
		4:'four',
		5:'five'
		}

for (const e in symbols){
	console.log('key is '+e); //this gives you the key
}

for (const e in symbols){
	console.log('value is '+symbols[e]); //this gives you the value
}

//for (const e in symbols){
//	console.log('key is : ${n} value is : ${symbols[e]}');
//	}
for (const e in symbols){
	console.log('key is: ' + e + ' value is : '+ symbols[e]);
	}
