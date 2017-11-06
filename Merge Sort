// Takes in an array that has two sorted subarrays,
//  from [p..q] and [q+1..r], and merges the array
var merge = function(array, p, q, r) {
    var lowHalf = [];
    var highHalf = [];

    var k = p;
    var i;
    var j;
    for (i = 0; k <= q; i++, k++) {
        lowHalf[i] = array[k];
    }
    for (j = 0; k <= r; j++, k++) {
        highHalf[j] = array[k];
    }

    k = p;
    i = 0;
    j = 0;
    // Repeatedly compare the lowest untaken element in
    //  lowHalf with the lowest untaken element in highHalf
    //  and copy the lower of the two back into array
    while(i < q-p+1 && j < r-q ){
        if(lowHalf[i] < highHalf[j] ){
            array[k++]=lowHalf[i];
            i++; 
        }else {
            array[k++]=highHalf[j];
            j++; 
        }
        // println(i);
        // println(j);
         println(k);
        // println("Array after merging: " + array);
        
    }
    
    // Once one of lowHalf and highHalf has been fully copied
    //  back into array, copy the remaining elements from the
    //  other temporary array back into the array
     while( i < q-p+1 ){
        array[k++]=lowHalf[i++];
       
    }
    while(j < r-q){
        array[k++]=highHalf[j++];
    }
};


var array = [3, 7, 12, 14, 2, 6, 9, 11];
merge(array, 0,
    Math.floor((0 + array.length-1) / 2),
    array.length-1);
println("Array after merging: " + array);
Program.assertEqual(array, [2, 3, 6, 7, 9, 11, 12, 14]);


var array1 = [-3, 7, 12, 14, 0, 6, 9, 11];
merge(array1, 0,
    Math.floor((0 + array.length-1) / 2),
    array.length-1);
println("Array after merging: " + array1);
Program.assertEqual(array1, [-3, 0, 6, 7, 9, 11, 12, 14]);
