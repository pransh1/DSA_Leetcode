func isPalindrome(x int) bool {
    
    if x < 0 {
        return false;
    }
    
    copy := x
    rev := 0
    
    for copy != 0 {
        pop := copy % 10
        copy /= 10

        rev = (rev*10) + pop
    }

    if rev == x {
        return true;
    } else {
        return false;
    }
}