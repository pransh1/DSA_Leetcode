func thirdMax(nums []int) int {
    n := len(nums)
    largest := math.MinInt
    secondLargest := math.MinInt
    thirdLargest := math.MinInt

    for i := 0; i < n; i++ {
        if nums[i] == largest || nums[i] == secondLargest || nums[i] == thirdLargest {
            continue
        } 
        if nums[i] > largest {
            thirdLargest = secondLargest
            secondLargest = largest
            largest = nums[i]
        } else if nums[i] > secondLargest {
            thirdLargest = secondLargest
            secondLargest = nums[i]
        } else if nums[i] > thirdLargest {
            thirdLargest = nums[i]
        }
    }

    if thirdLargest == math.MinInt {
        return largest
    }
    return thirdLargest
}