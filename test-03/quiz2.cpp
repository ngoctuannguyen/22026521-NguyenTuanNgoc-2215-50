int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2) {
    bool isAscending = false;
    if (firstArr[0] < firstArr[1]) {
        isAscending = true;
    }
    
    int *mergeArr = new int [lenArr1 + lenArr2]; 
    int firstIndex = 0, secondIndex = 0, mergeIndex = 0;
    
    if (isAscending) {
        while (firstIndex < lenArr1 && secondIndex < lenArr2){
            if(firstArr[firstIndex] <= secondArr[secondIndex]){
                mergeArr[mergeIndex] = firstArr[firstIndex];
                firstIndex++;
            } else{
                mergeArr[mergeIndex] = secondArr[secondIndex];
                secondIndex++;
            }
            mergeIndex++;
        }
    }
    else {
        while (firstIndex < lenArr1 && secondIndex < lenArr2){
            if(firstArr[firstIndex] >= secondArr[secondIndex]){
                mergeArr[mergeIndex] = firstArr[firstIndex];
                firstIndex++;
            } else{
                mergeArr[mergeIndex] = secondArr[secondIndex];
                secondIndex++;
            }
            mergeIndex++;
        }   
    }
    
    while(firstIndex < lenArr1){
        // Nếu mảng firstArr còn phần tử thì thêm vào cuối mảng mergeArr
        mergeArr[mergeIndex] = firstArr[firstIndex];
        mergeIndex++;
        firstIndex++;
    }
    
    while(secondIndex < lenArr2){
        // Nếu mảng secondArr còn phần tử thì thêm vào cuối mảng mergeArr
        mergeArr[mergeIndex] = secondArr[secondIndex];
        mergeIndex++;
        secondIndex++;
    }
    return mergeArr;
}
