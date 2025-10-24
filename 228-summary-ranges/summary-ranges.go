func summaryRanges(nums []int) []string {
    n := len(nums)
    var ans []string
    if n == 0 {return ans}
    start := nums[0]
    for i := 1; i <= n; i++ {
        if i == n || nums[i] != nums[i-1] + 1 { 
            if start == nums[i-1] {
                ans = append(ans, strconv.Itoa(start))
            } else {
                ans = append(ans, strconv.Itoa(start)+"->"+strconv.Itoa(nums[i-1]))
            } 
            if i < n {
                start = nums[i]
            }
        }
    }
    return ans
}