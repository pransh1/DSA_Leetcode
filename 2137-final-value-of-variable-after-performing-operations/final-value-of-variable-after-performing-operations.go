func finalValueAfterOperations(o []string) int {
    var x int = 0

    for _, val := range o {
        if val == "X++" || val == "++X" {
            x++
        } else {
            x--;
        }
    }
    return x
}