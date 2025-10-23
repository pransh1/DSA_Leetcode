func hasSameDigits(s string) bool {
    for len(s) > 2 {
        sub := []rune{} 
        for i := 0; i < len(s)-1; i++ {
            dig1 := s[i] - '0'
            dig2 := s[i+1] - '0'
            sum := (dig1 + dig2) % 10
            sub = append(sub, rune(sum+'0'))
        }

        s = string(sub)
    }    
    return s[0] == s[1]
}