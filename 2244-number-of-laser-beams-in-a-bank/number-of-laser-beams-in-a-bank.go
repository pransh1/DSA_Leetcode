func numberOfBeams(bank []string) int {
    prev := 0
    ans := 0

    for _, val := range(bank) {
        count := 0
        for _,inner_val := range(val) {
            if inner_val == '1' {
                count++
            }
        }
        if count != 0 {
            ans += prev*count
            prev = count
        }
    }   
    return ans
}