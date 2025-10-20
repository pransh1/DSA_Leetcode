func finalValueAfterOperations(o []string) int {
    var x int = 0

    for i := range o {
        if o[i] == "X++" || o[i]== "++X" {
            x++
        } else {
            x--;
        }
    }
    return x
}