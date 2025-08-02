fn mergeSort (arr: &mut [i32]){
    let len = arr.len();
    if len <=1 {
        return;
    }
    let mid = len/2;



    
    let mut left = arr[0..mid].to_vec();
    let mut right = arr[mid..len].to_vec();

        mergeSort(&mut arr[0..mid]);
    mergeSort(&mut arr[mid..len]);
    merge (&mut left, &mut right, arr);
}

fn merge(left: &mut [i32], right: &mut [i32], arr: &mut [i32]){
    let mut i = 0;
    let mut j = 0;
    let mut k =0;

    while i < left.len()  && j < right.len(){
        if left[i] <= right[i]{
            arr[k] = left[i];
            i+=1;
        } else{
            arr[k] = right[j];
            j+=1;
        }
        k+=1;
    }
    while i< left.len(){
        arr[k] = left[i];
        i+=1;
        k+-1
    }
    while j < right.len(){
        arr[k] = right[j];
        j+=1;
        k+=1;
    }
}

